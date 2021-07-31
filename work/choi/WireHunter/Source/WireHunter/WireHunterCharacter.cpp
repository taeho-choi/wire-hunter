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
#include "Boss.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"
//R
#include "Net/UnrealNetwork.h"
#include "Engine/Engine.h"

AWireHunterCharacter::AWireHunterCharacter()
{
	isWithdrawing = false;
	isClimbing = false;
	isLedgeClimbing = false;
	isBulletEmpty = false;
	Hooked = false;
	cppHooked = false;
	cppisLaunching = false;
	//bp로직 보면서 필요없는거 정리

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
	MaxHealth = 100.f;
	Health = MaxHealth - 30;

	bReplicates = true;

	static ConstructorHelpers::FObjectFinder<UParticleSystem> ImpactParticleAsset(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));
	UParticleSystem* ParticleAsset = ImpactParticleAsset.Object;
	ImpactParticle = ParticleAsset;
}

void AWireHunterCharacter::BeginPlay()
{
	Super::BeginPlay();

	TimerBetweenShots = 0.1f;

	SetBullets(MaxBullets);

	if (!HasAuthority())
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("TEST TEXT"));
	}
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
	DOREPLIFETIME(AWireHunterCharacter, cppisLaunching);
	DOREPLIFETIME(AWireHunterCharacter, isWithdrawing);

	DOREPLIFETIME(AWireHunterCharacter, isClimbing);
	DOREPLIFETIME(AWireHunterCharacter, cppWallNormal);
	DOREPLIFETIME(AWireHunterCharacter, FloatingPos);
	DOREPLIFETIME(AWireHunterCharacter, MoveForwardValue);
	DOREPLIFETIME(AWireHunterCharacter, MoveRightValue);
}

void AWireHunterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetPointLight();

	if (GetCppisLaunching())
	{
		Withdraw();
	}

	if (GetCppHooked())
	{
		WireSwing();
	}

	if (GetisWithdrawing())
	{
		FVector dist = GetActorLocation() - GetCppHookLocation();
		if (dist.Size() < 60.f)
		{
			SetisWithdrawing(false);
		}
	}

	if (GetisClimbing())
	{
		GetCharacterMovement()->SetMovementMode(MOVE_Flying);

		UpdateWallNormal();

		//LedgeTrace();

		FRotator TargetRotator = FRotator(GetActorRotation().Pitch, UKismetMathLibrary::MakeRotFromX(GetCppWallNormal()).Yaw, GetActorRotation().Roll) - FRotator(0, 180, 0);
		FRotator SmoothRotator = FMath::RInterpTo(GetActorRotation(), TargetRotator, DeltaTime, 50.f);
		SetActorRotation(SmoothRotator);
		//이것도 문제
	}
	/*else
	{
		GetCharacterMovement()->SetMovementMode(MOVE_Walking);
	}*/

	// Game Over
	if (Health <= 0 || GetActorLocation().Z < 7500.f)
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
		if (!GetCppHooked() && !GetisClimbing())
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
	if (GetCppHooked())
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
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Hit"));
		}

		if (Hit.bBlockingHit)
		{
			/*if (!HasAuthority())
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("TEST_HOOKWIRE"));
			}*/
			WirePointLight->SetVisibility(false);

			cppWire->SetVisibility(true);

			SetCppHookLocation(Hit.Location);

			FVector NewLocation;
			NewLocation = FMath::VInterpTo(cppWire->GetComponentLocation(), GetCppHookLocation(), GetWorld()->GetDeltaSeconds(), 50.f);
			cppWire->SetWorldLocation(GetCppHookLocation());
			float NewWireLength = (GetActorLocation() - GetCppHookLocation()).Size() - 300.f;
			SetCppHookedWireLength(NewWireLength);
			cppWire->CableLength = GetCppHookedWireLength();
			SetCppHooked(true);

			GetCharacterMovement()->AddForce(FVector(0.f, 0.f, -150000000.f));
		}
	}
}

void AWireHunterCharacter::PressWithdraw_Implementation()
{
	if (!GetCppisLaunching())
	{
		SetCppisLaunching(true);
		SetisWithdrawing(true);
	}
}

void AWireHunterCharacter::Withdraw_Implementation()
{
	if (GetCppHooked())
	{
		FVector dist = GetActorLocation() - GetCppHookLocation();
		cppWire->CableLength = dist.Size();
		FVector launchVel = (GetCppHookLocation() - GetActorLocation()) * (GetWorld()->GetDeltaSeconds() * 400.f);
		LaunchCharacter(launchVel, true, true);
	}
}

void AWireHunterCharacter::BreakHook()
{
	SetCppHooked(false);
	cppWire->CableLength = 100.f;
	cppWire->EndLocation = FVector(0.f, 0.f, 30.f);
	cppWire->SetWorldLocation(GetActorLocation());
	cppWire->SetVisibility(false);
	SetCppisLaunching(false);
}

void AWireHunterCharacter::WireSwing()
{
	cppWire->SetWorldLocation(GetCppHookLocation());
	FVector dist = GetActorLocation() - GetCppHookLocation();
	float dot = FVector::DotProduct(GetVelocity(), dist);
	dist.Normalize();
	GetCharacterMovement()->AddForce(dist * dot * -2.f);
	if (!GetCppisLaunching())
	{
		cppWire->CableLength = GetCppHookedWireLength() - 300.f;
	}
	GetCharacterMovement()->AirControl = 1.f;
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

void AWireHunterCharacter::Climb_Implementation()
{
	if (!GetisClimbing())
	{
		ClimbTrace();
	}
	else
	{
		SetisClimbing(false);

		GetCharacterMovement()->AddForce(GetCppWallNormal() * 20000000);
	}
}

void AWireHunterCharacter::ClimbTrace_Implementation()
{
	FHitResult Hit;

	SetCppWallNormal(Hit.Normal);

	const float ClimbRange = 200.f;
	const FVector StartTrace = GetActorLocation();
	const FVector EndTrace = GetActorLocation() + (UKismetMathLibrary::GetForwardVector(FRotator(0.f, GetActorRotation().Yaw, 0.f)) * ClimbRange);
	FCollisionQueryParams QueryParams = FCollisionQueryParams(SCENE_QUERY_STAT(WireTrace), false, this);
	QueryParams.AddIgnoredActor(this);
	GetWorld()->LineTraceSingleByChannel(Hit, StartTrace, EndTrace, ECC_Visibility, QueryParams);

	if (Hit.bBlockingHit)
	{
		SetisClimbing(true);

		BreakHook();

		GetCharacterMovement()->Velocity = FVector(0.f, 0.f, 0.f);/////////////////////////////////

		SetFloatingPos(GetActorLocation());

		SetActorLocation(GetFloatingPos());
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
		SetCppWallNormal(Hit.Normal);
	}
}

void AWireHunterCharacter::MoveForward_Implementation(float Value)/////////////////////////////////////////super
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		if (!GetisClimbing())
		{
			AddMovementInput(Direction, Value);
		}
		//클라이밍 모드일때 밸류 수정


	}
	if ((int)Value * 10 < GetMoveForwardValue())
	{
		SetMoveForwardValue(GetMoveForwardValue() - 1);
	}
	else if ((int)Value * 10 > GetMoveForwardValue())
	{
		SetMoveForwardValue(GetMoveForwardValue() + 1);
	}
}

void AWireHunterCharacter::MoveRight_Implementation(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		if (!GetisClimbing())
		{
			AddMovementInput(Direction, Value);
		}

	}
	if ((int)Value * 10 < GetMoveRightValue())
	{
		SetMoveRightValue(GetMoveRightValue() - 1);
	}
	else if ((int)Value * 10 > GetMoveRightValue())
	{
		SetMoveRightValue(GetMoveRightValue() + 1);
	}
}

void AWireHunterCharacter::LedgeTrace_Implementation()
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
		SetisClimbing(false);

		PlayAnimMontage(LedgeClimb, 1, NAME_None);
	}
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

		SetBullets(GetBullets() - 1);

		FHitResult Hit;

		const float GunRange = 50000.f;
		const FVector StartTrace = (FollowCamera->GetForwardVector() * 200) + FollowCamera->GetComponentLocation();
		const FVector EndTrace = (FollowCamera->GetForwardVector() * GunRange) + FollowCamera->GetComponentLocation();
		FCollisionQueryParams QueryParams = FCollisionQueryParams(SCENE_QUERY_STAT(WeaponTrace), false, this);
		QueryParams.AddIgnoredActor(this);

		if (world->LineTraceSingleByChannel(Hit, StartTrace, EndTrace, ECC_Visibility, QueryParams))
		{
			if (Hit.Actor->IsA(ABoss::StaticClass()))
			{
				ABoss* TargetBoss = Cast<ABoss>(Hit.Actor);
				TargetBoss->SetHealth(TargetBoss->GetHealth() - 1.f);
			}
			GenParticles(Hit, world);
		}
	}
}

void AWireHunterCharacter::GenParticles_Implementation(FHitResult Hit, UWorld* world)
{
	UGameplayStatics::SpawnEmitterAtLocation(world, ImpactParticle, FTransform(Hit.ImpactNormal.Rotation(), Hit.ImpactPoint), true, EPSCPoolMethod::AutoRelease);
	UGameplayStatics::SpawnEmitterAtLocation(world, MuzzleParticle, Gun->GetSocketTransform(FName("muzzle_socket")));
}

void AWireHunterCharacter::Reload_Implementation()
{
	isBulletEmpty = false;

	PlayAnimMontage(ReloadAnim, 1, NAME_None);
}

void AWireHunterCharacter::Knockback(FVector force)
{
	GetCharacterMovement()->AddForce(force);
}

//void AWireHunterCharacter::OnHit(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//	if (OtherActor->IsA(ABoss::StaticClass())) {
//		this->SetHealth(this->GetHealth() - 1);
//		this->BreakHook();
//		this->SetisClimbing(false);
//		this->Knockback((this->GetActorRotation().Vector() + FVector(0.f, 0.f, 0.5f)) * 10000000);
//		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Kick!!!!!!!!!!!!!!!!!!!!"));
//	}GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("On Hit"));
//}

//void AWireHunterCharacter::AnimNotify_LedgeClimbEnd()
//{
//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("LedgeClimbing False!!!!!!!!!"));
//	SetisLedgeClimbing(false);
//}

//R

void AWireHunterCharacter::OnHealthUpdate()
{
	if (IsLocallyControlled())
	{
		FString healthMessage = FString::Printf(TEXT("You now have %f health remaining."), Health);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, healthMessage);

		if (Health <= 0)
		{
			FString deathMessage = FString::Printf(TEXT("You have been killed."));
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, deathMessage);
		}
	}

	if (GetLocalRole() == ROLE_Authority)
	{
		FString healthMessage = FString::Printf(TEXT("%s now has %f health remaining."), *GetFName().ToString(), Health);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, healthMessage);
	}
}

void AWireHunterCharacter::OnRep_CurrentHealth()
{
	OnHealthUpdate();
}

void AWireHunterCharacter::SetHealth(float healthValue)
{
	if (GetLocalRole() == ROLE_Authority)
	{
		Health = FMath::Clamp(healthValue, 0.f, MaxHealth);
		OnHealthUpdate();
	}
}

float AWireHunterCharacter::TakeDamage(float DamageTaken, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float damageApplied = Health - DamageTaken;
	SetHealth(damageApplied);
	return damageApplied;
}