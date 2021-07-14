// Copyright Epic Games, Inc. All Rights Reserved.
// Print String Code : 	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("This is an on screen message!"));

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

	HealthWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("HealthBar"));
	HealthWidget->SetupAttachment(RootComponent);

	cppWire = CreateDefaultSubobject<UCableComponent>(TEXT("cppWire"));
	cppWire->SetupAttachment(this->GetRootComponent());
	//cppWire->SetAttachEndTo(this, RootComponent->GetDefaultSceneRootVariableName());
	cppWire->SetAttachEndTo(NULL, NAME_None);
	cppWire->bAttachStart = true;
	// Set Cable's Parameters
	cppWire->CableWidth = 8.f;
	cppWire->CableLength = 100.f;
	cppWire->EndLocation = FVector(0.f, 0.f, 0.f);
	cppWire->bEnableStiffness = true;
	//cppWire->bEnableCollision = true;
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

void AWireHunterCharacter::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AWireHunterCharacter, cppWire);
	DOREPLIFETIME(AWireHunterCharacter, Health);
}

void AWireHunterCharacter::BeginPlay()
{
	Super::BeginPlay();

	UHealthBar* HealthBar = Cast<UHealthBar>(HealthWidget->GetUserWidgetObject());
	HealthBar->SetOwnerCharacter(this);

	TimerBetweenShots = 0.1f;
	Bullets = 30;

	SetFloatingPos(GetActorLocation());
}

//////////////////////////////////////////////////////////////////////////
// Input

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

void AWireHunterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetisClimbing())
	{
		LedgeTrace();
		SetActorLocation(GetFloatingPos());
		UpdateWallNormal();

		FRotator TargetRotator = FRotator(GetActorRotation().Pitch, UKismetMathLibrary::MakeRotFromX(GetCppWallNormal()).Yaw, GetActorRotation().Roll) - FRotator(0, 180, 0);
		FRotator SmoothRotator = FMath::RInterpTo(GetActorRotation(), TargetRotator, DeltaTime, 50.f);
		SetActorRotation(SmoothRotator);
	}

	if (GetisWithdrawing())
	{
		FVector dist = GetActorLocation() - GetCppHookLocation();
		GEngine->AddOnScreenDebugMessage(-1, 200, FColor::Green, FString::Printf(TEXT("%f"), dist.Size()));
		if (dist.Size() < 60.f)
		{
			SetisWithdrawing(false);
		}
	}

	if (cppHooked)
	{
		WireSwing();
	}
	//Launch Character
	if (GetCppisLaunching())
	{
		Withdraw();
	}

	WireTrace();

	// Game Over
	if (Health <= 0|| GetActorLocation().Z < 300.f)
	{
		UGameplayStatics::OpenLevel(this, "GameMenuLevel");
	}
	if (Bullets == 0 && isBulletEmpty == false)
	{
		Reload();
		isBulletEmpty = true;
	}
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

void AWireHunterCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);

		if (GetisClimbing())
		{
			SetFloatingPos(GetFloatingPos() + (UKismetMathLibrary::GetUpVector(UKismetMathLibrary::MakeRotFromX(GetCppWallNormal())) * 500 * Value * GetWorld()->GetDeltaSeconds()));
		}
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

void AWireHunterCharacter::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);

		if (GetisClimbing())
		{
			SetFloatingPos(GetFloatingPos() + (UKismetMathLibrary::GetRightVector(UKismetMathLibrary::MakeRotFromX(GetCppWallNormal())) * 500 * -Value * GetWorld()->GetDeltaSeconds()));
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

void AWireHunterCharacter::StartFire()
{
	FireShot();
	GetWorldTimerManager().SetTimer(TimerHandle_HandleRefire, this, &AWireHunterCharacter::FireShot, TimerBetweenShots, true);
	//애니메이션aa
}

void AWireHunterCharacter::StopFire()
{
	GetWorldTimerManager().ClearTimer(TimerHandle_HandleRefire);
}

void AWireHunterCharacter::FireShot()
{
	if (GetBullets() > 0)
	{
		SetBullets(GetBullets() - 1);
		FHitResult Hit;

		const float GunRange = 50000.f;
		const FVector StartTrace = (FollowCamera->GetForwardVector() * 200) + FollowCamera->GetComponentLocation();
		const FVector EndTrace = (FollowCamera->GetForwardVector() * GunRange) + FollowCamera->GetComponentLocation();

		FCollisionQueryParams QueryParams = FCollisionQueryParams(SCENE_QUERY_STAT(WeaponTrace), false, this);
		QueryParams.AddIgnoredActor(this);

		if (GetWorld()->LineTraceSingleByChannel(Hit, StartTrace, EndTrace, ECC_Visibility, QueryParams))
		{
			if (Hit.Actor->IsA(ABoss::StaticClass()))
			{
				ABoss* TargetBoss = Cast<ABoss>(Hit.Actor);
				TargetBoss->SetHealth(TargetBoss->GetHealth() - 1.f);
				GEngine->AddOnScreenDebugMessage(-1, 200, FColor::Green, FString::Printf(TEXT("%f"), TargetBoss->GetHealth()));

			}
			if (ImpactParticle)
			{
				UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactParticle, FTransform(Hit.ImpactNormal.Rotation(), Hit.ImpactPoint), true, EPSCPoolMethod::AutoRelease);
			}
		}

		if (MuzzleParticle)
		{
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), MuzzleParticle, Gun->GetSocketTransform(FName("muzzle_socket")));
		}
	}
}

void AWireHunterCharacter::Reload()
{
	isBulletEmpty = false;
	PlayAnimMontage(ReloadAnim, 1, NAME_None);
}

void AWireHunterCharacter::WireTrace()
{
	const float WireRange = 7000.f;
	const FVector StartTrace = (FollowCamera->GetForwardVector() * 200.f) + (FollowCamera->GetComponentLocation());
	const FVector EndTrace = StartTrace + (FollowCamera->GetForwardVector() * WireRange);


	FCollisionQueryParams QueryParams = FCollisionQueryParams(SCENE_QUERY_STAT(WireTrace), false, this);
	QueryParams.AddIgnoredActor(this);
	GetWorld()->LineTraceSingleByChannel(WireHit, StartTrace, EndTrace, ECC_Visibility, QueryParams);

	if (WireHit.bBlockingHit)
	{
		if (!GetCppHooked() && !GetisClimbing())
		{
			WirePointLight->SetVisibility(true);
		}

		WirePointLight->AttenuationRadius = WireHit.Distance * 0.035f;
		if (WirePointLight->AttenuationRadius < 30.f)
		{
			WirePointLight->AttenuationRadius = 30.f;
		}

		if (WireHit.Actor->GetName() != FString(TEXT("Boss_1")))
		{
			WirePointLight->SetWorldLocation(WireHit.Location + WireHit.Normal * 15);
		}
		//GEngine->AddOnScreenDebugMessage(-1, 200, FColor::Green, FString::Printf(TEXT("%s"), *(WireHit.Location + WireHit.Normal * 15).ToString()));
	}
	else
	{
		WirePointLight->SetVisibility(false);
	}

}

void AWireHunterCharacter::HookWire()
{
	//if (GetCharacterMovement()->IsFalling())
	if (true)
	{
		// 와이어가 꽂혀있을 경우 와이어를 회수
		if (GetCppHooked())
		{
			BreakHook();
		}

		// 와이어가 꽂혀있지 않을 경우 트레이싱 히트 시 해당 지점에 와이어 꽂기
		else
		{
			// 크로스헤어 지점으로 트레이싱
			//FHitResult Hit;

			//const float WireRange = 6000.f;
			//const FVector StartTrace = (FollowCamera->GetForwardVector() * 200.f) + (FollowCamera->GetComponentLocation());
			//const FVector EndTrace = StartTrace + (FollowCamera->GetForwardVector() * WireRange);

			//FCollisionQueryParams QueryParams = FCollisionQueryParams(SCENE_QUERY_STAT(WireTrace), false, this);
			//QueryParams.AddIgnoredActor(this);
			//GetWorld()->LineTraceSingleByChannel(Hit, StartTrace, EndTrace, ECC_Visibility, QueryParams);
			////

			if (WireHit.bBlockingHit)
			{
				//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Hit"));
			}

			// 트레이싱이 충돌하면 와이어를 꽂기
			if (WireHit.bBlockingHit)
			{
				WirePointLight->SetVisibility(false);

				// 먼저 플레이어 캐릭터를 와이어를 꽂을 방향으로 회전 (일단 지움. 현재는 마우스 이동에 따라 플레이어 캐릭터가 따라서 회전하는 상태이므로)
				// FRotator WireShotRotation = FRotator(0.f, UKismetMathLibrary::FindLookAtRotation(this->GetActorLocation(), Hit.Location).Yaw, 0.f);
				// this->SetActorRotation(WireShotRotation);

				cppWire->SetVisibility(true);

				SetCppHookLocation(WireHit.Location);
				//GEngine->AddOnScreenDebugMessage(-1, 200, FColor::Green, FString::Printf(TEXT("%s"), *GetCppHookLocation().ToString()));

				FVector NewLocation;
				NewLocation = FMath::VInterpTo(cppWire->GetComponentLocation(), GetCppHookLocation(), GetWorld()->GetDeltaSeconds(), 50.f);
				cppWire->SetWorldLocation(GetCppHookLocation());
				//cppWire->EndLocation = GetActorLocation();
				float NewWireLength = (GetActorLocation() - GetCppHookLocation()).Size() - 300.f;
				SetCppHookedWireLength(NewWireLength);
				cppWire->CableLength = GetCppHookedWireLength();
				SetCppHooked(true);
				float distance = (GetActorLocation() - GetCppHookLocation()).Size();

				// 와이어 부착 후 Swing 힘을 더 세게
				// GetCharacterMovement()->AddForce(FollowCamera->GetForwardVector() * 150000000.f);
				GetCharacterMovement()->AddForce(FVector(0.f, 0.f, -150000000.f));

			}
			else
			{
				// 와이어 회수 상태로
			}
		}
	}
}

void AWireHunterCharacter::WireSwing()
{
	if (GetCppHooked())
		if (GetCppHooked())
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

void AWireHunterCharacter::Withdraw()
{
	if (GetCppHooked())
	{
		FVector dist = GetActorLocation() - GetCppHookLocation();
		cppWire->CableLength = dist.Size();
		FVector launchVel = (GetCppHookLocation() - GetActorLocation()) * (GetWorld()->GetDeltaSeconds() * 2000.f);
		LaunchCharacter(launchVel, true, true);
	}
}

void AWireHunterCharacter::PressWithdraw()
{
	if (!GetCppisLaunching())
	{
		SetCppisLaunching(true);
		SetisWithdrawing(true);
	}
	else
	{
		BreakHook();
	}
}

void AWireHunterCharacter::Climb()
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Press Climb"));
	if (!GetisClimbing())
	{
		ClimbTrace();
	}
	else
	{
		//GetCharacterMovement()->bOrientRotationToMovement = true;
		SetisClimbing(false);
		GEngine->AddOnScreenDebugMessage(-1, 200, FColor::Green, FString::Printf(TEXT("%s"), *(UKismetMathLibrary::GetUpVector(UKismetMathLibrary::MakeRotFromX(GetCppWallNormal())) * 50000000).ToString()));
		//GetCharacterMovement()->AddForce(UKismetMathLibrary::GetUpVector(UKismetMathLibrary::MakeRotFromX(GetCppWallNormal())) * 50000000);
		GetCharacterMovement()->AddForce(GetCppWallNormal() * 20000000);
	}
}

void AWireHunterCharacter::ClimbTrace()
{
	FHitResult Hit;
	SetCppWallNormal(Hit.Normal);

	const float ClimbRange = 200.f;
	const FVector StartTrace = GetActorLocation();
	const FVector EndTrace = GetActorLocation() + (UKismetMathLibrary::GetForwardVector(FRotator(0.f, GetActorRotation().Yaw, 0.f)) * ClimbRange);

	FCollisionQueryParams QueryParams = FCollisionQueryParams(SCENE_QUERY_STAT(WireTrace), false, this);
	QueryParams.AddIgnoredActor(this);
	GetWorld()->LineTraceSingleByChannel(Hit, StartTrace, EndTrace, ECC_Visibility, QueryParams);
	//DrawDebugLine(GetWorld(), Hit.TraceStart, Hit.TraceEnd, FColor::Red, false, 100.f, 0, 1.f);
	if (Hit.bBlockingHit)
	{
		//GetCharacterMovement()->bOrientRotationToMovement = false;
		BreakHook();
		GetCharacterMovement()->Velocity = FVector(0.f, 0.f, 0.f);
		//GetCharacterMovement()->SetMovementMode(MOVE_Flying);
		SetisClimbing(true);
		SetFloatingPos(GetActorLocation());
	}
}

void AWireHunterCharacter::UpdateWallNormal()
{
	FHitResult Hit;

	const float ClimbRange = 200.f;
	const FVector StartTrace = GetActorLocation();
	const FVector EndTrace = GetActorLocation() + (UKismetMathLibrary::GetForwardVector(FRotator(0.f, GetActorRotation().Yaw, 0.f)) * ClimbRange);

	FCollisionQueryParams QueryParams = FCollisionQueryParams(SCENE_QUERY_STAT(WireTrace), false, this);
	QueryParams.AddIgnoredActor(this);
	GetWorld()->LineTraceSingleByChannel(Hit, StartTrace, EndTrace, ECC_Visibility, QueryParams);
	//DrawDebugLine(GetWorld(), Hit.TraceStart, Hit.TraceEnd, FColor::Red, false, 100.f, 0, 1.f);
	if (Hit.bBlockingHit)
	{
		SetCppWallNormal(Hit.Normal);
	}
}

void AWireHunterCharacter::LedgeTrace()
{
	FHitResult Hit;

	const float ClimbRange = 1000.f;
	const FVector StartTrace = (GetActorLocation() - (UKismetMathLibrary::GetForwardVector(FRotator(0.f, GetActorRotation().Yaw, 0.f)) * ClimbRange / 10.f)) + FVector(0.f, 0.f, 100.f);
	const FVector EndTrace = (GetActorLocation() + (UKismetMathLibrary::GetForwardVector(FRotator(0.f, GetActorRotation().Yaw, 0.f)) * ClimbRange)) + FVector(0.f, 0.f, 100.f);

	FCollisionQueryParams QueryParams = FCollisionQueryParams(SCENE_QUERY_STAT(WireTrace), false, this);
	QueryParams.AddIgnoredActor(this);
	GetWorld()->LineTraceSingleByChannel(Hit, StartTrace, EndTrace, ECC_Visibility, QueryParams);
	//DrawDebugLine(GetWorld(), Hit.TraceStart, Hit.TraceEnd, FColor::Blue, false, 100.f, 0, 1.f);
	if (!Hit.bBlockingHit)
	{
		SetisClimbing(false);
		GetCharacterMovement()->SetMovementMode(MOVE_Flying);
		PlayAnimMontage(LedgeClimb, 1, NAME_None);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Ledge Climb On!!"));
		
	}
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