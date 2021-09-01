//test
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WireHunterCharacter.generated.h"

UCLASS(config = Game)
class AWireHunterCharacter : public ACharacter
{
    GENERATED_BODY()

        UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
        class USpringArmComponent* CameraBoom;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
        class USpringArmComponent* SpringArm;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
        class UCameraComponent* FollowCamera;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = cable, meta = (AllowPrivateAccess = "true"))
        class UCableComponent* cppWire;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = cable, meta = (AllowPrivateAccess = "true"))
        class UPointLightComponent* WirePointLight;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = animation, meta = (AllowPrivateAccess = "true"))
        class UAnimMontage* LedgeClimb;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = animation, meta = (AllowPrivateAccess = "true"))
        class UAnimMontage* ReloadAnim;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = animation, meta = (AllowPrivateAccess = "true"))
        class UAnimMontage* RollAnim;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Minimap, meta = (AllowPrivateAccess = "true"))
        class USceneCaptureComponent2D* MinimapCapture;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Minimap, meta = (AllowPrivateAccess = "true"))
        class UPaperSpriteComponent* PlayerPointer;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gun, meta = (AllowPrivateAccess = "true"))
        class USkeletalMeshComponent* Gun;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
        class UNiagaraSystem* ImpactParticle;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
        class UNiagaraSystem* MuzzleParticle;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
        class UNiagaraSystem* MuzzleSmokeParticle;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
        class UWidgetComponent* HealthWidget;

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
        class UNiagaraComponent* YellowAuraEffect;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
        class UNiagaraComponent* RedAuraEffect;

public:

    AWireHunterCharacter();

protected:

    virtual void BeginPlay() override;

    virtual void Tick(float DeltaSeconds) override;

    void OnResetVR();

    void TurnAtRate(float Rate);

    void LookUpAtRate(float Rate);

    void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

    void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    float TimerBetweenShots;

    float BaseTurnRate;

    float BaseLookUpRate;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Status", ReplicatedUsing = OnRep_Health)
        float Health;

    UFUNCTION()
        void OnRep_Health();

    void OnHealthUpdate();

    float MaxHealth;

    UPROPERTY(Replicated, BlueprintReadWrite, EditDefaultsOnly, Category = "Status")
        int Bullets;

    int MaxBullets;

    UPROPERTY(Replicated, BlueprintReadWrite, EditDefaultsOnly, Category = "Floating")
        bool isBulletEmpty;

    UPROPERTY(Replicated, BlueprintReadWrite, EditDefaultsOnly, Category = "Status")
        int MoveForwardValue;

    UPROPERTY(Replicated, BlueprintReadWrite, EditDefaultsOnly, Category = "Status")
        int MoveRightValue;

    UPROPERTY(Replicated, BlueprintReadWrite, EditDefaultsOnly, Category = "Floating")
        bool isWithdrawing;

    UPROPERTY(Replicated, BlueprintReadWrite, EditAnywhere, Category = "Floating")
        bool isClimbing;

    UPROPERTY(Replicated, BlueprintReadWrite, EditDefaultsOnly, Category = "WireSystem")
        bool cppHooked;

    UPROPERTY(Replicated, BlueprintReadWrite, EditDefaultsOnly, Category = "WireSystem")
        float cppHookedWireLength;

    UPROPERTY(Replicated, BlueprintReadWrite, EditDefaultsOnly, Category = "WireSystem")
        FVector cppHookLocation;

    UPROPERTY(Replicated, BlueprintReadWrite, EditDefaultsOnly, Category = "WireSystem")
        FVector cppWallNormal;

    FTimerHandle TimerHandle_HandleRefire;
    FTimerHandle TimerHandle_YellowAura;
    FTimerHandle TimerHandle_RedAura;

    UPROPERTY(Replicated)
        bool isEnd;

    UPROPERTY(Replicated)
        bool isEnd2;

    UPROPERTY(Replicated)
        bool isBossWireSwing;
    UPROPERTY(Replicated)
        AActor* dragon;


public:

    UFUNCTION(Client, Reliable)
        void SetPointLight();

    UFUNCTION(Server, Reliable, WithValidation)
        void HookWireServer();
    void HookWireServer_Implementation();
    bool HookWireServer_Validate();

    UFUNCTION(Server, Reliable, WithValidation)
        void BreakHookServer();
    void BreakHookServer_Implementation();
    bool BreakHookServer_Validate();

    UFUNCTION(Server, Reliable, WithValidation)
        void PressWithdrawServer();
    void PressWithdrawServer_Implementation();
    bool PressWithdrawServer_Validate();

    UFUNCTION(NetMulticast, Reliable)
        void PressWithdrawMulti();
    void PressWithdrawMulti_Implementation();

    UFUNCTION(Server, Reliable, WithValidation)
        void WithdrawServer();
    void WithdrawServer_Implementation();
    bool WithdrawServer_Validate();

    UFUNCTION(Server, Reliable, WithValidation)
        void OffWithdrawServer();
    void OffWithdrawServer_Implementation();
    bool OffWithdrawServer_Validate();

    UFUNCTION(NetMulticast, Reliable)
        void OffWithdrawMulti();
    void OffWithdrawMulti_Implementation();

    UFUNCTION(Server, Reliable, WithValidation)
        void WireSwingServer();
    void WireSwingServer_Implementation();
    bool WireSwingServer_Validate();

    UFUNCTION(Server, Reliable, WithValidation)
        void ClimbServer();
    void ClimbServer_Implementation();
    bool ClimbServer_Validate();

    UFUNCTION(NetMulticast, Reliable)
        void ClimbMulti(bool b);
    void ClimbMulti_Implementation(bool b);

    UFUNCTION(Server, Reliable, WithValidation)
        void UpdateWallNormalServer();
    void UpdateWallNormalServer_Implementation();
    bool UpdateWallNormalServer_Validate();

    UFUNCTION(Server, Reliable, WithValidation)
        void UpdateRotServer(float DeltaTime);
    void UpdateRotServer_Implementation(float DeltaTime);
    bool UpdateRotServer_Validate(float DeltaTime);

    UFUNCTION(Server, Reliable, WithValidation)
        void LedgeTraceServer();
    void LedgeTraceServer_Implementation();
    bool LedgeTraceServer_Validate();

    UFUNCTION(Server, Reliable, WithValidation)
        void PlayLedgeAnimServer();
    void PlayLedgeAnimServer_Implementation();
    bool PlayLedgeAnimServer_Validate();

    UFUNCTION(NetMulticast, Reliable)
        void PlayLedgeAnimMulti();
    void PlayLedgeAnimMulti_Implementation();

    UFUNCTION(Server, Reliable, WithValidation)
    void KnockbackServer();
    void KnockbackServer_Implementation();
    bool KnockbackServer_Validate();

    UFUNCTION()
        void SetYellowAuraOn();
    void SetRedAuraOn();
    void SetYellowAuraOff();
    void SetRedAuraOff();

    void MoveForward(float Value);//

    UFUNCTION(Server, Reliable)
        void InMoveForward(float value);//

    void MoveRight(float Value);//

    UFUNCTION(Server, Reliable)
        void InMoveRight(float value);//

    UFUNCTION(Server, Reliable, BlueprintCallable)
        void StartFire();

    UFUNCTION(Server, Reliable)
        void StopFire();

    UFUNCTION(Server, Reliable)
        void FireShot();

    UFUNCTION(NetMulticast, Reliable)
        void GenParticles(FHitResult Hit, UWorld* world);

    UFUNCTION(Server, Reliable)
        void Reload();

    UFUNCTION(NetMulticast, Reliable)
        void PlayReloadAnim();

    UFUNCTION(BlueprintCallable)
        float GetBullets() const { return Bullets; }

    UFUNCTION(BlueprintCallable)
        void SetBullets(int val) { Bullets = val; }

    UFUNCTION(BlueprintCallable)
        float GetMaxBullets() const { return MaxBullets; }

    UFUNCTION(BlueprintCallable)
        int GetMoveForwardValue() const { return MoveForwardValue; }

    void SetMoveForwardValue(int val) { MoveForwardValue = val; }

    UFUNCTION(BlueprintCallable)
        int GetMoveRightValue() const { return MoveRightValue; }

    void SetMoveRightValue(int val) { MoveRightValue = val; }

    UFUNCTION(BlueprintCallable)
        bool GetisWithdrawing() const { return isWithdrawing; }

    UFUNCTION(BlueprintCallable)
        bool GetisClimbing() const { return isClimbing; }
    void GhostTrail();
    FTimerHandle SpawnTimerHandle;

    UFUNCTION(BlueprintCallable)
        float GetHealth() const { return Health; }

    void SetHealth(float health);

    UFUNCTION(BlueprintCallable)
        float GetMaxHealth() const { return MaxHealth; }

    void SetisClimbing(bool b) { isClimbing = b; }

    FVector GetCppWallNormal() const { return cppWallNormal; }

    UFUNCTION(BlueprintCallable, Category = "Health")
        float TakeDamage(float DamageTaken, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

    //R

    void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};