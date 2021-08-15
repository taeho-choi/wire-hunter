//test
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WireHunterCharacter.generated.h"

UCLASS(config=Game)
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
	class UWidgetComponent* HealthWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
	class UNiagaraComponent* AuraEffect;

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

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Status", ReplicatedUsing=OnRep_CurrentHealth)
	float Health;

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
	bool isWithdrawing;/////////////////////////////////////////////////////////////////

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

public:

	void Reloaded();

	bool GetCppHooked() const { return cppHooked; }
	void SetCppHooked(bool val) { cppHooked = val; }

	FVector GetCppHookLocation() const { return cppHookLocation; }
	void SetCppHookLocation(FVector val) { cppHookLocation = val; }

	float GetCppHookedWireLength() const { return cppHookedWireLength; }
	void SetCppHookedWireLength(float val) { cppHookedWireLength = val; }

	FVector GetCppWallNormal() const { return cppWallNormal; }
	void SetCppWallNormal(FVector val) { cppWallNormal = val; }

	UFUNCTION(Client, Reliable)
	void SetPointLight();

	UFUNCTION(Server, Reliable)
	void HookWire();

	UFUNCTION(Server, Reliable)
	void PressWithdraw();

	UFUNCTION(NetMulticast, Reliable)
	void Withdraw();

	//UFUNCTION(Server, Reliable)
	void BreakHook();

	void WireSwing();

	UFUNCTION(Server, Reliable)
	void Climb();

	UFUNCTION(Server, Reliable)
	void UpdateWallNormal();

	UFUNCTION(NetMulticast, Reliable)
	void MoveForward(float Value);

	UFUNCTION(NetMulticast, Reliable)
	void MoveRight(float Value);

	UFUNCTION(Server, Reliable)
	void LedgeTrace();

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

	void Knockback(FVector force);

	float GetHealth() const { return Health; }
	void SetHealth(float healthValue);

	float GetMaxHealth() const { return MaxHealth; }
	void SetMaxHealth(float val) { MaxHealth = val; }

	float TakeDamage(float DamageTaken, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(BlueprintCallable)
	float GetBullets() const { return Bullets; }

	UFUNCTION(BlueprintCallable)
		void SetBullets(int val) { Bullets = val; }

	UFUNCTION(BlueprintCallable)
		float GetMaxBullets() const { return MaxBullets; }

	void SetMaxBullets(int val) { MaxBullets = val; }

	UFUNCTION(BlueprintCallable)
	int GetMoveForwardValue() const { return MoveForwardValue; }

	void SetMoveForwardValue(int val) { MoveForwardValue = val; }

	UFUNCTION(BlueprintCallable)
	int GetMoveRightValue() const { return MoveRightValue; }

	void SetMoveRightValue(int val) { MoveRightValue = val; }

	UFUNCTION(BlueprintCallable)
	bool GetisWithdrawing() const { return isWithdrawing; }

	void SetisWithdrawing(bool val) { isWithdrawing = val; }

	UFUNCTION(BlueprintCallable)
	bool GetisClimbing() const { return isClimbing; }

	UFUNCTION(BlueprintCallable)
	void GhostTrail();
	FTimerHandle SpawnTimerHandle;

	void SetisClimbing(bool val) { isClimbing = val; }

	//void OnHit(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	//R

	UFUNCTION()
	void OnRep_CurrentHealth();

	void OnHealthUpdate();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};