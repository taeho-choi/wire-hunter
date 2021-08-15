// Copyright Epic Games, Inc. All Rights Reserved.

#include "WireHunterCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/PointLightComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/WidgetComponent.h"
#include "HealthBar.h"
#include "Particles/ParticleSystemComponent.h"
#include "DrawDebugHelpers.h"
#include "CableComponent.h"
#include "Math/Vector.h"
#include "Math/UnrealMathUtility.h"
#include "Components/SceneComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Dragon.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraSystem.h"
//R
#include "Net/UnrealNetwork.h"
#include "Engine/Engine.h"

AWireHunterCharacter::AWireHunterCharacter()
{
	isWithdrawing = false;
	isClimbing = false;
	isBulletEmpty = false;
	cppHooked = false;

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a springArm (Mini map)
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->SetWorldRotation(FRotator(-90.f, 0.f, 0.f));

	MinimapCapture = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("MinimapCapture"));
	MinimapCapture->SetupAttachment(SpringArm);

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	cppWire = CreateDefaultSubobject<UCableComponent>(TEXT("cppWire"));
	cppWire->SetupAttachment(this->GetRootComponent());
	cppWire->SetAttachEndTo(NULL, NAME_None);
	cppWire->bAttachStart = true;
	cppWire->CableWidth = 8.f;
	cppWire->CableLength = 100.f;
	cppWire->EndLocation = FVector(0.f, 0.f, 0.f);
	cppWire->bEnableStiffness = true;
	cppWire->SetIsReplicated(true);

	WirePointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("WirePointLight"));
	WirePointLight->SetupAttachment(this->GetRootComponent());
	WirePointLight->SetLightColor(FLinearColor(0.f, 255.f, 0.f));
	WirePointLight->SetWorldLocation(FVector(108.f, 0.f, -76.f));
	WirePointLight->SetVisibility(false);

	PlayerPointer = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("PlayerPointer"));
	PlayerPointer->SetupAttachment(this->GetRootComponent());
	PlayerPointer->SetWorldRotation(FRotator(0.f, 90.f, -90.f));
	PlayerPointer->SetOwnerNoSee(true);
	PlayerPointer->SetWorldScale3D(FVector(5.f, 5.f, 5.f));
	PlayerPointer->SetWorldLocation(FVector(0.f, 0.f, 10000.f));

	Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Gun"));
	Gun->SetupAttachment(this->GetMesh(), TEXT("Rifle"));

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)

	//R
	MaxBullets = 30;
	MaxHealth = 100.f;
	Health = MaxHealth - 30.f;
	Bullets = MaxBullets;

	bReplicates = true;

	static ConstructorHelpers::FObjectFinder<UNiagaraSystem> ImpactParticleAsset(TEXT("NiagaraSystem'/Game/ThirdPersonCPP/GraphicResources/WHFX/Impact/NS_Impact.NS_Impact'"));
	UNiagaraSystem* NS_Impact = ImpactParticleAsset.Object;
	ImpactParticle = NS_Impact;

	static ConstructorHelpers::FObjectFinder<UNiagaraSystem> MuzzleParticleAsset(TEXT("NiagaraSystem'/Game/ThirdPersonCPP/GraphicResources/WHFX/MuzzleFlash/NS_MuzzleFlash.NS_MuzzleFlash'"));
	UNiagaraSystem* NS_MuzzleFlash = MuzzleParticleAsset.Object;
	MuzzleParticle = NS_MuzzleFlash;
}

void AWireHunterCharacter::BeginPlay()
{
	Super::BeginPlay();

	TimerBetweenShots = 0.1f;

	SetBullets(MaxBullets);
}

void AWireHunterCharacter::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AWireHunterCharacter, Health);

	DOREPLIFETIME(AWireHunterCharacter, Bullets);
	DOREPLIFETIME(AWireHunterCharacter, isBulletEmpty);

	DOREPLIFETIME(AWireHunterCharacter, cppHooked);
	DOREPLIFETIME(AWireHunterCharacter, cppHookLocation);
	DOREPLIFETIME(AWireHunterCharacter, cppHookedWireLength);

	DOREPLIFETIME(AWireHunterCharacter, isWithdrawing);
	DOREPLIFETIME(AWireHunterCharacter, isClimbing);

	DOREPLIFETIME(AWireHunterCharacter, cppWallNormal);
	DOREPLIFETIME(AWireHunterCharacter, MoveForwardValue);
	DOREPLIFETIME(AWireHunterCharacter, MoveRightValue);
}

void AWireHunterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!cppHooked)
	{
		SetPointLight();
	}

	if (isWithdrawing)
	{
		Withdraw();
	}

	if (cppHooked)
	{
		WireSwing();
	}

	if (isClimbing)
	{
		UpdateWallNormal();

		LedgeTrace();

		UpdateRot(DeltaTime);
	}

	// Game Over
	if (Health <= 0.f || GetActorLocation().Z < 7500.f)
	{
		UGameplayStatics::OpenLevel(this, "GameMenuLevel");
	}
}

void AWireHunterCharacter::SetPointLight_Implementation()
{
	FHitResult Hit;

	const float WireRange = 7000.f;
	const FVector StartTrace = (FollowCamera->GetForwardVector() * 200.f) + (FollowCamera->GetComponentLocation());
	const FVector EndTrace = StartTrace + (FollowCamera->GetForwardVector() * WireRange);
	FCollisionQueryParams QueryParams = FCollisionQueryParams(SCENE_QUERY_STAT(WireTrace), false, this);
	QueryParams.AddIgnoredActor(this);
	GetWorld()->LineTraceSingleByChannel(Hit, StartTrace, EndTrace, ECC_Visibility, QueryParams);

	if (Hit.bBlockingHit)
	{
		if (!cppHooked && !isClimbing)
		{
			WirePointLight->SetVisibility(true);
		}

		WirePointLight->AttenuationRadius = Hit.Distance * 0.035f;
		if (WirePointLight->AttenuationRadius < 30.f)
		{
			WirePointLight->AttenuationRadius = 30.f;
		}

		if (Hit.Actor->GetName() != FString(TEXT("Boss_1")))
		{
			WirePointLight->SetWorldLocation(Hit.Location + Hit.Normal * 15);
		}
	}
	else
	{
		WirePointLight->SetVisibility(false);
	}
}

void AWireHunterCharacter::HookWire_Implementation()
{
	if (cppHooked)
	{
		BreakHook();
	}
	else
	{
		FHitResult Hit;

		const float WireRange = 7000.f;
		const FVector StartTrace = (FollowCamera->GetForwardVector() * 200.f) + (FollowCamera->GetComponentLocation());
		const FVector EndTrace = StartTrace + (FollowCamera->GetForwardVector() * WireRange);
		FCollisionQueryParams QueryParams = FCollisionQueryParams(SCENE_QUERY_STAT(WireTrace), false, this);
		QueryParams.AddIgnoredActor(this);
		GetWorld()->LineTraceSingleByChannel(Hit, StartTrace, EndTrace, ECC_Visibility, QueryParams);

		if (Hit.bBlockingHit)
		{
			/*if (!HasAuthority())
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("TEST_HOOKWIRE"));
			}*/
			WirePointLight->SetVisibility(false);

			cppWire->SetVisibility(true);

			cppHookLocation = Hit.Location;

			FVector NewLocation;
			NewLocation = FMath::VInterpTo(cppWire->GetComponentLocation(), cppHookLocation, GetWorld()->GetDeltaSeconds(), 50.f);
			cppWire->SetWorldLocation(cppHookLocation);
			float NewWireLength = (GetActorLocation() - cppHookLocation).Size() - 300.f;
			cppHookedWireLength = NewWireLength;
			cppWire->CableLength = cppHookedWireLength;
			cppHooked = true;

			GetCharacterMovement()->AddForce(FVector(0.f, 0.f, -150000000.f));
		}
	}
}

void AWireHunterCharacter::PressWithdraw_Implementation()
{
	if (cppHooked)
	{
		isWithdrawing = true;
	}
}

void AWireHunterCharacter::Withdraw_Implementation()
{
	FVector distance = GetActorLocation() - cppHookLocation;
	cppWire->CableLength = distance.Size();
	FVector launchVel = (cppHookLocation - GetActorLocation()) * (GetWorld()->GetDeltaSeconds() * 400.f);
	LaunchCharacter(launchVel, true, true);

	if (distance.Size() < 60.f)
	{
		isWithdrawing = false;
	}
}

void AWireHunterCharacter::BreakHook_Implementation()
{
	cppHooked = false;
	isWithdrawing = false;

	cppWire->CableLength = 100.f;
	cppWire->EndLocation = FVector(0.f, 0.f, 30.f);
	cppWire->SetWorldLocation(GetActorLocation());
	cppWire->SetVisibility(false);
}

void AWireHunterCharacter::WireSwing_Implementation()
{
	cppWire->SetWorldLocation(cppHookLocation);
	FVector dist = GetActorLocation() - cppHookLocation;
	float dot = FVector::DotProduct(GetVelocity(), dist);
	dist.Normalize();
	GetCharacterMovement()->AddForce(dist * dot * -2.f);
	if (!isWithdrawing)
	{
		cppWire->CableLength = cppHookedWireLength - 300.f;
	}
	GetCharacterMovement()->AirControl = 1.f;
}

void AWireHunterCharacter::Climb_Implementation()
{
	auto temp = GetCharacterMovement();

	if (!isClimbing)
	{
		FHitResult Hit;

		const float ClimbRange = 200.f;
		const FVector StartTrace = GetActorLocation();
		const FVector EndTrace = GetActorLocation() + (UKismetMathLibrary::GetForwardVector(FRotator(0.f, GetActorRotation().Yaw, 0.f)) * ClimbRange);
		FCollisionQueryParams QueryParams = FCollisionQueryParams(SCENE_QUERY_STAT(WireTrace), false, this);
		QueryParams.AddIgnoredActor(this);
		GetWorld()->LineTraceSingleByChannel(Hit, StartTrace, EndTrace, ECC_Visibility, QueryParams);

		if (Hit.bBlockingHit)
		{
			isClimbing = true;

			BreakHook();

			temp->SetMovementMode(MOVE_Flying);

			temp->Velocity = FVector(0.f, 0.f, 0.f);
		}
	}
	else
	{
		isClimbing = false;

		temp->AddForce(cppWallNormal * 20000000);////////////////////////////////////

		temp->SetMovementMode(MOVE_Walking);
	}
}

void AWireHunterCharacter::UpdateWallNormal_Implementation()
{
	FHitResult Hit;

	const float ClimbRange = 200.f;
	const FVector StartTrace = GetActorLocation();
	const FVector EndTrace = GetActorLocation() + (UKismetMathLibrary::GetForwardVector(FRotator(0.f, GetActorRotation().Yaw, 0.f)) * ClimbRange);
	FCollisionQueryParams QueryParams = FCollisionQueryParams(SCENE_QUERY_STAT(WireTrace), false, this);
	QueryParams.AddIgnoredActor(this);
	GetWorld()->LineTraceSingleByChannel(Hit, StartTrace, EndTrace, ECC_Visibility, QueryParams);

	if (Hit.bBlockingHit)
	{
		cppWallNormal = Hit.Normal;
	}
}

void AWireHunterCharacter::MoveForward(float Value)////////////////////////////////////super?&ÀÌ°Å Æ½ »°´Âµ¥ ¿Ö´ï?
{
	if ((Controller != NULL) && (Value != 0.f))
	{
		if (!isClimbing)
		{
			const FRotator Rotation = Controller->GetControlRotation();
			const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
			const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		
			AddMovementInput(Direction, Value);

			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("walking"));
		}
	}

	if (isClimbing)
	{
		InMoveForward(Value);
	}
}

void AWireHunterCharacter::InMoveForward_Implementation(float Value)
{
	if ((int)Value * 10 < GetMoveForwardValue())
	{
		SetMoveForwardValue(GetMoveForwardValue() - 1);
	}
	else if ((int)Value * 10 > GetMoveForwardValue())
	{
		SetMoveForwardValue(GetMoveForwardValue() + 1);
	}
}

void AWireHunterCharacter::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.f))
	{
		if (!isClimbing)
		{
			const FRotator Rotation = Controller->GetControlRotation();
			const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
			const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

			AddMovementInput(Direction, Value);
		}
	}

	if (isClimbing)
	{
		InMoveRight(Value);
	}

}

void AWireHunterCharacter::InMoveRight_Implementation(float Value)
{
	if ((int)Value * 10 < GetMoveRightValue())
	{
		SetMoveRightValue(GetMoveRightValue() - 1);
	}
	else if ((int)Value * 10 > GetMoveRightValue())
	{
		SetMoveRightValue(GetMoveRightValue() + 1);
	}
}

void AWireHunterCharacter::LedgeTrace_Implementation()//ÀÌ°Å °î¼±?
{
	FHitResult Hit;
	
	const float ClimbRange = 1000.f;
	const FVector StartTrace = (GetActorLocation() - (UKismetMathLibrary::GetForwardVector(FRotator(0.f, GetActorRotation().Yaw, 0.f)) * ClimbRange / 10.f)) + FVector(0.f, 0.f, 100.f);
	const FVector EndTrace = (GetActorLocation() + (UKismetMathLibrary::GetForwardVector(FRotator(0.f, GetActorRotation().Yaw, 0.f)) * ClimbRange)) + FVector(0.f, 0.f, 100.f);
	FCollisionQueryParams QueryParams = FCollisionQueryParams(SCENE_QUERY_STAT(WireTrace), false, this);
	QueryParams.AddIgnoredActor(this);
	GetWorld()->LineTraceSingleByChannel(Hit, StartTrace, EndTrace, ECC_Visibility, QueryParams);

	if (!Hit.bBlockingHit)
	{
		isClimbing = false;

		PlayLedgeAnim();

		GetCharacterMovement()->SetMovementMode(MOVE_Walking);

		SetActorRotation(UKismetMathLibrary::MakeRotator(0.f, 0.f, GetActorRotation().Yaw));
	}
}

void AWireHunterCharacter::PlayLedgeAnim_Implementation()
{
	PlayAnimMontage(LedgeClimb, 1, NAME_None);
}

void AWireHunterCharacter::UpdateRot_Implementation(float DeltaTime)
{
	FRotator TargetRotator = FRotator(GetActorRotation().Pitch, UKismetMathLibrary::MakeRotFromX(GetCppWallNormal()).Yaw, GetActorRotation().Roll) - FRotator(0, 180, 0);
	FRotator SmoothRotator = FMath::RInterpTo(GetActorRotation(), TargetRotator, DeltaTime, 50.f);
	SetActorRotation(SmoothRotator);
}

void AWireHunterCharacter::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void AWireHunterCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	Jump();
}

void AWireHunterCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
	StopJumping();
}

void AWireHunterCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &AWireHunterCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AWireHunterCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AWireHunterCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AWireHunterCharacter::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &AWireHunterCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AWireHunterCharacter::TouchStopped);

	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &AWireHunterCharacter::OnResetVR);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AWireHunterCharacter::StartFire);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &AWireHunterCharacter::StopFire);

	// Bind WireShot
	PlayerInputComponent->BindAction("WireShot", IE_Pressed, this, &AWireHunterCharacter::HookWire);

	// Bind Launch
	PlayerInputComponent->BindAction("Climb", IE_Pressed, this, &AWireHunterCharacter::Climb);

	// Bind Withdraw
	PlayerInputComponent->BindAction("Withdraw", IE_Pressed, this, &AWireHunterCharacter::PressWithdraw);

	// Reload
	PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &AWireHunterCharacter::Reload);
}

void AWireHunterCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AWireHunterCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AWireHunterCharacter::StartFire_Implementation()
{
	FireShot();

	GetWorldTimerManager().SetTimer(TimerHandle_HandleRefire, this, &AWireHunterCharacter::FireShot, TimerBetweenShots, true);
}

void AWireHunterCharacter::StopFire_Implementation()
{
	GetWorldTimerManager().ClearTimer(TimerHandle_HandleRefire);
}

void AWireHunterCharacter::FireShot_Implementation()
{
	if (GetBullets() > 0)
	{
		auto world = GetWorld();

		UNiagaraFunctionLibrary::SpawnSystemAtLocation(world, MuzzleParticle, Gun->GetSocketTransform(FName("muzzle_socket")).GetLocation(), Gun->GetSocketTransform(FName("muzzle_socket")).Rotator());

		Bullets -= 1;

		FHitResult Hit;

		const float GunRange = 50000.f;//
		const FVector StartTrace = (FollowCamera->GetForwardVector() * 200) + FollowCamera->GetComponentLocation();
		const FVector EndTrace = (FollowCamera->GetForwardVector() * GunRange) + FollowCamera->GetComponentLocation();
		FCollisionQueryParams QueryParams = FCollisionQueryParams(SCENE_QUERY_STAT(WeaponTrace), false, this);
		QueryParams.AddIgnoredActor(this);

		if (world->LineTraceSingleByChannel(Hit, StartTrace, EndTrace, ECC_Visibility, QueryParams))
		{
			if (Hit.Actor->IsA(ADragon::StaticClass()))
			{
				ADragon* TargetBoss = Cast<ADragon>(Hit.Actor);
				TargetBoss->SetHealth(TargetBoss->GetHealth() - 1.f);
			}
			GenParticles(Hit, world);
		}
	}
}

void AWireHunterCharacter::GenParticles_Implementation(FHitResult Hit, UWorld* world)
{
	UNiagaraFunctionLibrary::SpawnSystemAtLocation(world, ImpactParticle, Hit.ImpactPoint, Hit.ImpactNormal.Rotation(), FVector(1.f, 1.f, 1.f));
}

void AWireHunterCharacter::Reload_Implementation()
{
	isBulletEmpty = false;

	PlayReloadAnim();

	Bullets = MaxBullets;
}

void AWireHunterCharacter::PlayReloadAnim_Implementation()
{
	PlayAnimMontage(ReloadAnim, 1, NAME_None);
}

void AWireHunterCharacter::Knockback_Implementation(FVector force)
{
	auto temp = GetCharacterMovement();

	temp->AddForce(force);

	BreakHook();

	temp->SetMovementMode(MOVE_Walking);
}

float AWireHunterCharacter::TakeDamage(float DamageTaken, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) 
{
	float damageApplied = Health - DamageTaken;
	SetHealth(damageApplied);

	Knockback((GetActorRotation().Vector() + FVector(0.f, 0.f, 0.5f)) * 10000000);

	return damageApplied;
}

//R

void AWireHunterCharacter::OnRep_isWithdrawingTest()
{
	if (isWithdrawing)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("isWithdrawing-True"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("isWithdrawing-False"));
	}
}

void AWireHunterCharacter::OnRep_cppHookedTest()
{
	if (cppHooked)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("cppHooked-True"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("cppHooked-False"));
	}
}

void AWireHunterCharacter::OnRep_isClimbingTest()
{
	if (isClimbing)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("isClimbing-True"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("isClimbing-False"));
	}
}