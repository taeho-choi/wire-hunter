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

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Status", Replicated)
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

	UPROPERTY(ReplicatedUsing= OnRep_isWithdrawingTest, BlueprintReadWrite, EditDefaultsOnly, Category = "Floating")
	bool isWithdrawing;

	UFUNCTION()
		void OnRep_isWithdrawingTest();

	UPROPERTY(ReplicatedUsing= OnRep_isClimbingTest, BlueprintReadWrite, EditAnywhere, Category = "Floating")
	bool isClimbing;

	UFUNCTION()
		void OnRep_isClimbingTest();

	UPROPERTY(ReplicatedUsing= OnRep_cppHookedTest, BlueprintReadWrite, EditDefaultsOnly, Category = "WireSystem")
	bool cppHooked;

	UFUNCTION()
		void OnRep_cppHookedTest();

	UPROPERTY(Replicated, BlueprintReadWrite, EditDefaultsOnly, Category = "WireSystem")
	float cppHookedWireLength;

	UPROPERTY(Replicated, BlueprintReadWrite, EditDefaultsOnly, Category = "WireSystem")
	FVector cppHookLocation;

	UPROPERTY(Replicated, BlueprintReadWrite, EditDefaultsOnly, Category = "WireSystem")
	FVector cppWallNormal;

	FTimerHandle TimerHandle_HandleRefire;

public:

	UFUNCTION(Client, Reliable)
	void SetPointLight();

	UFUNCTION(Server, Reliable)
	void HookWire();

	UFUNCTION(Server, Reliable)
	void PressWithdraw();

	UFUNCTION(Server, Reliable)
	void Withdraw();

	UFUNCTION(Server, Reliable)
	void WireSwing();

	UFUNCTION(Server, Reliable)
	void BreakHook();

	UFUNCTION(Server, Reliable)
	void Climb();

	UFUNCTION(Server, Reliable)
	void UpdateWallNormal();

	void MoveForward(float Value);

	UFUNCTION(Server, Reliable)
	void InMoveForward(float value);

	void MoveRight(float Value);

	UFUNCTION(Server, Reliable)
	void InMoveRight(float value);

	UFUNCTION(Server, Reliable)
	void UpdateRot(float DeltaTime);

	UFUNCTION(Server, Reliable)
	void LedgeTrace();

	UFUNCTION(NetMulticast, Reliable)
	void PlayLedgeAnim();

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

	UFUNCTION(Server, Reliable)
	void Knockback(FVector force);

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

	float GetHealth() const { return Health; }

	void SetHealth(float health) {
		if (HasAuthority())
		{
			Health = health;
		}
	}

	float GetMaxHealth() const { return MaxHealth; }

	void SetisClimbing(bool b) { isClimbing = b; }

	FVector GetCppWallNormal() const { return cppWallNormal; }

	//void OnHit(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	//R

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};