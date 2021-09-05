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
#include "Components/ArrowComponent.h"
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
#include "NiagaraComponent.h"
#include "TimerManager.h"
//R
#include "Net/UnrealNetwork.h"
#include "Engine/Engine.h"

AWireHunterCharacter::AWireHunterCharacter()
{
    isWithdrawing = false;
    isClimbing = false;
    isBulletEmpty = false;
    cppHooked = false;
    isEnd = false;
    isEnd2 = false;

    // Set size for collision capsule
    GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

    // set our turn rates for input
    BaseTurnRate = 45.f;
    BaseLookUpRate = 45.f;

    GetCharacterMovement()->bUseControllerDesiredRotation = true;

    // Don't rotate when the controller rotates. Let that just affect the camera.
    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = false;
    bUseControllerRotationRoll = false;

    // Configure character movement
    //GetCharacterMovement()->bOrientRotationToMovement = false; // Character moves in the direction of input...   
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

    HealthWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("HealthWidget"));
    HealthWidget->SetupAttachment(this->GetRootComponent());

    Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Gun"));
    Gun->SetupAttachment(this->GetMesh(), TEXT("Rifle"));

    // Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
    // are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)

    //R
    MaxBullets = 30;
    MaxHealth = 100.f;
    Health = MaxHealth - 60.f;
    Bullets = MaxBullets;

    GetCharacterMovement()->AirControl = 1.f;

    bReplicates = true;

    static ConstructorHelpers::FObjectFinder<UNiagaraSystem> ImpactParticleAsset(TEXT("NiagaraSystem'/Game/ThirdPersonCPP/GraphicResources/WHFX/Impact/NS_Impact.NS_Impact'"));
    UNiagaraSystem* NS_Impact = ImpactParticleAsset.Object;
    ImpactParticle = NS_Impact;

    static ConstructorHelpers::FObjectFinder<UNiagaraSystem> MuzzleParticleAsset(TEXT("NiagaraSystem'/Game/ThirdPersonCPP/GraphicResources/WHFX/MuzzleFlash/NS_MuzzleFlash.NS_MuzzleFlash'"));
    UNiagaraSystem* NS_MuzzleFlash = MuzzleParticleAsset.Object;
    MuzzleParticle = NS_MuzzleFlash;

    static ConstructorHelpers::FObjectFinder<UNiagaraSystem> MuzzleSmokeParticleAsset(TEXT("NiagaraSystem'/Game/ThirdPersonCPP/AI/WeaponPack/MuzzleFlashPack/Particles/NS_RealisticMuzzleFlash4.NS_RealisticMuzzleFlash4'"));
    UNiagaraSystem* NS_MuzzleSmokeFlash = MuzzleSmokeParticleAsset.Object;
    MuzzleSmokeParticle = NS_MuzzleSmokeFlash;

    static ConstructorHelpers::FObjectFinder<UNiagaraSystem> BossBloodParticleAsset(TEXT("NiagaraSystem'/Game/ThirdPersonCPP/AI/GunImpactParticles/Particles/Blood/NS_Blood.NS_Blood'"));
    UNiagaraSystem* NS_BossBloodParticle = BossBloodParticleAsset.Object;
    BossBloodParticle = NS_BossBloodParticle;

    YellowAuraEffect = CreateDefaultSubobject<UNiagaraComponent>(TEXT("YellowAuraEffect"));
    YellowAuraEffect->SetupAttachment(this->GetRootComponent());

    RedAuraEffect = CreateDefaultSubobject<UNiagaraComponent>(TEXT("RedAuraEffect"));
    RedAuraEffect->SetupAttachment(this->GetRootComponent());

    static ConstructorHelpers::FObjectFinder<UNiagaraSystem> YellowAuraEffectAsset(TEXT("NiagaraSystem'/Game/ThirdPersonCPP/GraphicResources/WHFX/Aura/NS_YellowAura.NS_YellowAura'"));
    UNiagaraSystem* NS_YellowAuraEffect = YellowAuraEffectAsset.Object;
    YellowAuraEffect->SetAsset(NS_YellowAuraEffect);
    YellowAuraEffect->SetVisibility(false);

    static ConstructorHelpers::FObjectFinder<UNiagaraSystem> RedAuraEffectAsset(TEXT("NiagaraSystem'/Game/ThirdPersonCPP/GraphicResources/WHFX/Aura/NS_GreenAura.NS_GreenAura'"));
    UNiagaraSystem* NS_RedAuraEffect = RedAuraEffectAsset.Object;
    RedAuraEffect->SetAsset(NS_RedAuraEffect);
    RedAuraEffect->SetVisibility(false);
}

void AWireHunterCharacter::BeginPlay()
{
    Super::BeginPlay();

    TimerBetweenShots = 0.1f;

    UHealthBar* HealthBar = Cast<UHealthBar>(HealthWidget->GetUserWidgetObject());
    HealthBar->SetOwnerCharacter(this);
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

    DOREPLIFETIME(AWireHunterCharacter, isEnd);
    DOREPLIFETIME(AWireHunterCharacter, isEnd2);
}

void AWireHunterCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

   /* if (isBossWireSwing)
    {
        auto BossVel = LinkedBoss->GetVelocity();

        FString healthMessage = FString::Printf(TEXT("%s"), *BossVel.ToString());
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, healthMessage);

        LaunchCharacter((FVector(1.f, 1.f, -9.8f) * BossVel * 0.1f), true, true);
    }*/
    if (!cppHooked && !isClimbing)//
    {
        SetPointLight();
    }

    if (isWithdrawing)
    {
        WithdrawServer();
    }

    if (isEnd)
    {
        OffWithdrawServer();
    }

    if (cppHooked)
    {
       WireSwingServer();
    }

    if (isClimbing)
    {
        UpdateWallNormalServer();

        UpdateRotServer(DeltaTime);

        LedgeTraceServer();
    }

    if (isEnd2)
    {
        PlayLedgeAnimServer();
    }

    /// <summary>
    /// /
    /// </summary>
    /// <param name="DeltaTime"></param>

    if (GetActorLocation().Z < 7500.f)
    {
        if (IsLocallyControlled())
        {
            Destroy();
        }

        if (GetLocalRole() == ROLE_Authority)
        {
            Destroy();

            if (GetFName() == "BP_WHCharacter_C_0")
            {
                UGameplayStatics::OpenLevel(this, "GameMenuLevel");
            }
        }
    }
}

void AWireHunterCharacter::GhostTrail_Implementation()
{
    UObject* SpawnActor = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("Blueprint'/Game/ThirdPersonCPP/GraphicResources/WHFX/GhostTrail/BP_GhostTrail.BP_GhostTrail'")));

    UBlueprint* GeneratedBP = Cast<UBlueprint>(SpawnActor);
    if (!SpawnActor)
    {
        GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("CANT FIND OBJECT TO SPAWN")));
        return;
    }

    UClass* SpawnClass = SpawnActor->StaticClass();
    if (SpawnClass == NULL)
    {
        GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("CLASS == NULL")));
        return;
    }

    UWorld* World = GetWorld();
    FActorSpawnParameters SpawnParams;
    SpawnParams.Owner = this;
    SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
    World->SpawnActor<AActor>(GeneratedBP->GeneratedClass, GetActorLocation() - FVector(0.f, 0.f, 100.f), GetActorRotation() - FRotator(0.f, 100.f, 0.f), SpawnParams);
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

        WirePointLight->SetWorldLocation(Hit.Location + Hit.Normal * 15);
    }
    else
    {
        WirePointLight->SetVisibility(false);
    }
}

void AWireHunterCharacter::PlayBackRollAnim_Implementation()
{
    PlayAnimMontage(RollAnim, 1, NAME_None);
}

void AWireHunterCharacter::HookWireServer_Implementation()
{
    if (cppHooked)
    {
        PlayBackRollAnim();
        BreakHookServer();
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
            if (Hit.Actor->IsA(ADragon::StaticClass()))
            {
                isBossWireSwing = true;
                GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("BossFound")));
                LinkedBoss = Cast<ADragon>(Hit.Actor);

                WirePointLight->SetVisibility(false);
                cppWire->SetVisibility(true);
                cppHookLocation = LinkedBoss->GetActorLocation();
               
                cppWire->SetWorldLocation(cppHookLocation);
                float NewWireLength = (GetActorLocation() - cppHookLocation).Size() - 300.f;
                cppHookedWireLength = NewWireLength;
                

                cppHooked = true;
                GetCharacterMovement()->AddForce(FVector(0.f, 0.f, -150000000.f));
            }
            else
            {
                WirePointLight->SetVisibility(false);

                cppWire->SetVisibility(true);

                cppHookLocation = Hit.Location;

                cppWire->SetWorldLocation(cppHookLocation);
                float NewWireLength = (GetActorLocation() - cppHookLocation).Size() - 300.f;
                cppHookedWireLength = NewWireLength;
                //cppWire->CableLength = cppHookedWireLength;

                cppHooked = true;
                GetCharacterMovement()->AddForce(FVector(0.f, 0.f, -150000000.f)); 
            }
        }
    }
}

bool AWireHunterCharacter::HookWireServer_Validate()
{
    return true;
}

void AWireHunterCharacter::PressWithdrawServer_Implementation()
{
    PressWithdrawMulti();
}

bool AWireHunterCharacter::PressWithdrawServer_Validate()
{
    return true;
}

void AWireHunterCharacter::PressWithdrawMulti_Implementation()
{
    if (cppHooked)
    {
        isWithdrawing = true;
        if (HasAuthority())
        {
            GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &AWireHunterCharacter::GhostTrail, 0.1f, true, 0.f);
        }
    }
}

void AWireHunterCharacter::OffWithdrawServer_Implementation()
{
    if (GetLocalRole() == ROLE_Authority)
        isEnd = false;

    OffWithdrawMulti();
}

bool AWireHunterCharacter::OffWithdrawServer_Validate()
{
    return true;
}

void AWireHunterCharacter::OffWithdrawMulti_Implementation()
{
    isWithdrawing = false;
    BreakHookServer();
    //ClimbServer();
}

void AWireHunterCharacter::WithdrawServer_Implementation()
{
    FVector distance = GetActorLocation() - cppHookLocation;
    cppWire->CableLength = distance.Size();
    FVector launchVel = (cppHookLocation - GetActorLocation()) * (GetWorld()->GetDeltaSeconds() * 400.f);
    LaunchCharacter(launchVel, true, true);
  
    if (distance.Size() < 500.f && isBossWireSwing)
    {
        isWithdrawing = false;
    }
    if (distance.Size() < 60.f)
    {
        isEnd = true;
        //ClimbServer();
    }
}

bool AWireHunterCharacter::WithdrawServer_Validate()
{
    return true;
}

void AWireHunterCharacter::BreakHookServer_Implementation()
{
    isWithdrawing = false;
    cppHooked = false;
    GetWorldTimerManager().ClearTimer(SpawnTimerHandle);

    cppWire->CableLength = 100.f;
    cppWire->EndLocation = FVector(0.f, 0.f, 30.f);
    cppWire->SetWorldLocation(GetActorLocation());
    cppWire->SetVisibility(false);
    isBossWireSwing = false;
}

bool AWireHunterCharacter::BreakHookServer_Validate()
{
    return true;
}

void AWireHunterCharacter::WireSwingServer_Implementation()
{
    if (isBossWireSwing)
    {
        cppHookLocation = LinkedBoss->GetActorLocation();
    }
    cppWire->SetWorldLocation(cppHookLocation);
    FVector dist = GetActorLocation() - cppHookLocation;
    float dot = FVector::DotProduct(GetVelocity(), dist);
    dist.Normalize();
    GetCharacterMovement()->AddForce(dist * dot * -2.f);
    if (!isWithdrawing)
    {
        //cppWire->CableLength = cppHookedWireLength;
    }
}

bool AWireHunterCharacter::WireSwingServer_Validate()
{
    return true;
}

void AWireHunterCharacter::ClimbServer_Implementation()
{
    auto temp = GetCharacterMovement();

    if (!isClimbing)
    {
        FHitResult Hit;

        const float ClimbRange = 2000.f;
        const FVector StartTrace = GetActorLocation();
        const FVector EndTrace = GetActorLocation() + (UKismetMathLibrary::GetForwardVector(FRotator(0.f, GetActorRotation().Yaw, 0.f)) * ClimbRange);
        FCollisionQueryParams QueryParams = FCollisionQueryParams(SCENE_QUERY_STAT(WireTrace), false, this);
        QueryParams.AddIgnoredActor(this);
        GetWorld()->LineTraceSingleByChannel(Hit, StartTrace, EndTrace, ECC_Visibility, QueryParams);

        if (Hit.bBlockingHit)
        {
            ClimbMulti(true);
            GetCharacterMovement()->bUseControllerDesiredRotation = false;
            bUseControllerRotationYaw = false;
            BreakHookServer();
            GetCharacterMovement()->SetMovementMode(MOVE_Flying);

            temp->Velocity = FVector(0.f, 0.f, 0.f);
            
        }
    }
    else
    {
        ClimbMulti(false);
        GetCharacterMovement()->bUseControllerDesiredRotation = true;
        bUseControllerRotationYaw = true;

        temp->AddForce(cppWallNormal * 4000000);////////////////////////////////////

        temp->SetMovementMode(MOVE_Walking);
    }
}

bool AWireHunterCharacter::ClimbServer_Validate()
{
    return true;
}

void AWireHunterCharacter::ClimbMulti_Implementation(bool b)
{
    if (b)
    {
        isClimbing = true;
    }
    else
    {
        isClimbing = false;
    }
}

void AWireHunterCharacter::UpdateWallNormalServer_Implementation()
{
    FHitResult Hit;

    const float ClimbRange = 200.f;
    const FVector StartTrace = GetActorLocation();
    const FVector EndTrace = GetActorLocation() + (UKismetMathLibrary::GetForwardVector(FRotator(0.f, GetActorRotation().Yaw, 0.f)) * ClimbRange);
    FCollisionQueryParams QueryParams = FCollisionQueryParams(SCENE_QUERY_STAT(WireTrace), false, this);
    QueryParams.AddIgnoredActor(this);
    GetWorld()->LineTraceSingleByChannel(Hit, StartTrace, EndTrace, ECC_Visibility, QueryParams);
    DrawDebugLine(GetWorld(), StartTrace, EndTrace, FColor::Green, false, 1, 0, 1);
    if (Hit.bBlockingHit)
    {
        if (GetLocalRole() == ROLE_Authority)
            cppWallNormal = Hit.Normal;
    }
}

bool AWireHunterCharacter::UpdateWallNormalServer_Validate()
{
    return true;
}

void AWireHunterCharacter::UpdateRotServer_Implementation(float DeltaTime)
{
    FRotator TargetRotator = FRotator(GetActorRotation().Pitch, UKismetMathLibrary::MakeRotFromX(GetCppWallNormal()).Yaw, GetActorRotation().Roll) - FRotator(0, 180, 0);
    FRotator SmoothRotator = FMath::RInterpTo(GetActorRotation(), TargetRotator, DeltaTime, 15.f);
    SetActorRotation(SmoothRotator);
}

bool AWireHunterCharacter::UpdateRotServer_Validate(float DeltaTime)
{
    return true;
}

void AWireHunterCharacter::LedgeTraceServer_Implementation()//ÀÌ°Å °î¼±?
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

        isEnd2 = true;

        SetActorRotation(UKismetMathLibrary::MakeRotator(0.f, 0.f, GetActorRotation().Yaw));
    }
}

bool AWireHunterCharacter::LedgeTraceServer_Validate()
{
    return true;
}

void AWireHunterCharacter::PlayLedgeAnimServer_Implementation()
{
    isEnd2 = false;

    PlayLedgeAnimMulti();
}

bool AWireHunterCharacter::PlayLedgeAnimServer_Validate()
{
    return true;
}

void AWireHunterCharacter::PlayLedgeAnimMulti_Implementation()
{
    PlayAnimMontage(LedgeClimb, 1, NAME_None);
}

void AWireHunterCharacter::KnockbackServer_Implementation()
{
    auto LaunchForce = GetActorForwardVector() * -1 * 100.f;
    LaunchCharacter(LaunchForce, true, true);

    BreakHookServer();

    GetCharacterMovement()->SetMovementMode(MOVE_Flying);
}

bool AWireHunterCharacter::KnockbackServer_Validate()
{
    return true;
}

void AWireHunterCharacter::MoveForward(float Value)
{
    if ((Controller != NULL) && (Value != 0.f))
    {
        if (!isClimbing)
        {
            const FRotator Rotation = Controller->GetControlRotation();
            const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
            const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

            AddMovementInput(Direction, Value);
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
        auto val = GetMoveForwardValue() - 1;
        SetMoveForwardValue(val);
    }
    else if ((int)Value * 10 > GetMoveForwardValue())
    {
        auto val = GetMoveForwardValue() + 1;
        SetMoveForwardValue(val);
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
        auto val = GetMoveRightValue() - 1;
        SetMoveRightValue(val);
    }
    else if ((int)Value * 10 > GetMoveRightValue())
    {
        auto val = GetMoveRightValue() + 1;
        SetMoveRightValue(val);
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
    PlayerInputComponent->BindAction("WireShot", IE_Pressed, this, &AWireHunterCharacter::HookWireServer);

    // Bind Climb
    PlayerInputComponent->BindAction("Climb", IE_Pressed, this, &AWireHunterCharacter::ClimbServer);

    // Bind Withdraw
    PlayerInputComponent->BindAction("Withdraw", IE_Pressed, this, &AWireHunterCharacter::PressWithdrawServer);

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

        GenParticles2(world);

        Bullets -= 1;

        FHitResult Hit;

        const float GunRange = 20000.f;//
        const FVector StartTrace = (FollowCamera->GetForwardVector() * 200) + FollowCamera->GetComponentLocation();
        const FVector EndTrace = (FollowCamera->GetForwardVector() * GunRange) + FollowCamera->GetComponentLocation();
        FCollisionQueryParams QueryParams = FCollisionQueryParams(SCENE_QUERY_STAT(WeaponTrace), false, this);
        QueryParams.AddIgnoredActor(this);

        if (world->LineTraceSingleByChannel(Hit, StartTrace, EndTrace, ECC_Visibility, QueryParams))
        {
            if (Hit.Actor->IsA(ADragon::StaticClass()))
            {
                ADragon* TargetBoss = Cast<ADragon>(Hit.Actor);
                float damage = 1.f;
                if (Hit.BoneName == "Bip001-Ponytail1")
                {
                    damage *= 4;
                }
                if (HasAuthority())
                {
                    TargetBoss->SetHealth(TargetBoss->GetHealth() - damage);
                }
                GenBloodParticle(Hit, world);
            }
            else
            {
                GenParticles(Hit, world);
            }
        }
    }
    else
    {
        isBulletEmpty = true;
    }
}

void AWireHunterCharacter::GenParticles_Implementation(FHitResult Hit, UWorld* world)
{
    UNiagaraFunctionLibrary::SpawnSystemAtLocation(world, ImpactParticle, Hit.ImpactPoint, Hit.ImpactNormal.Rotation(), FVector(1.f, 1.f, 1.f));
}

void AWireHunterCharacter::GenParticles2_Implementation(UWorld* world)
{
    UNiagaraFunctionLibrary::SpawnSystemAtLocation(world, MuzzleParticle, Gun->GetSocketTransform(FName("muzzle_socket")).GetLocation(), Gun->GetSocketTransform(FName("muzzle_socket")).Rotator());
    UNiagaraFunctionLibrary::SpawnSystemAtLocation(world, MuzzleSmokeParticle, Gun->GetSocketTransform(FName("muzzle_socket")).GetLocation(), Gun->GetSocketTransform(FName("muzzle_socket")).Rotator());
}

void AWireHunterCharacter::GenBloodParticle_Implementation(FHitResult Hit, UWorld* world)
{
    UNiagaraFunctionLibrary::SpawnSystemAtLocation(world, BossBloodParticle, Hit.ImpactPoint, Hit.ImpactNormal.Rotation());
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

float AWireHunterCharacter::TakeDamage(float DamageTaken, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
    float damageApplied = Health - DamageTaken;
    SetHealth(damageApplied);

    KnockbackServer();

    return damageApplied;
}

//R

void AWireHunterCharacter::OnHealthUpdate()
{
    //Client-specific functionality
    if (IsLocallyControlled())
    {
        FString healthMessage = FString::Printf(TEXT("You now have %f health remaining."), Health);
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, healthMessage);

        if (Health <= 0)
        {
            Destroy();
        }
    }

    //Server-specific functionality
    if (GetLocalRole() == ROLE_Authority)
    {
        FString healthMessage = FString::Printf(TEXT("%s now has %f health remaining."), *GetFName().ToString(), Health);
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, healthMessage);

        if (Health <= 0)
        {
            Destroy();

            if (GetFName() == "BP_WHCharacter_C_0")
            {
                UGameplayStatics::OpenLevel(this, "GameMenuLevel");
            }
        }
    }

    //Functions that occur on all machines. 
    /*
       Any special functionality that should occur as a result of damage or death should be placed here.
    */
}

void AWireHunterCharacter::OnRep_Health()
{
    OnHealthUpdate();
}

void AWireHunterCharacter::SetHealth(float health)
{
    if (GetLocalRole() == ROLE_Authority)
    {
        Health = health;
        OnHealthUpdate();
    }
}

void AWireHunterCharacter::SetYellowAuraOff()
{
    YellowAuraEffect->SetVisibility(false);
    GetWorldTimerManager().ClearTimer(TimerHandle_YellowAura);
}

void AWireHunterCharacter::SetRedAuraOff()
{
    RedAuraEffect->SetVisibility(false);
    GetWorldTimerManager().ClearTimer(TimerHandle_RedAura);
}

void AWireHunterCharacter::SetYellowAuraOn()
{
    YellowAuraEffect->SetVisibility(true);
    GetWorldTimerManager().SetTimer(TimerHandle_YellowAura, this, &AWireHunterCharacter::SetYellowAuraOff, 5.f, false, 20.f);
}

void AWireHunterCharacter::SetRedAuraOn()
{
    RedAuraEffect->SetVisibility(true);
    GetWorldTimerManager().SetTimer(TimerHandle_RedAura, this, &AWireHunterCharacter::SetRedAuraOff, 5.f, false, 20.f);
}