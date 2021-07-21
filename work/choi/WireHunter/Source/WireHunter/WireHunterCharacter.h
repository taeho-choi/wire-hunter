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

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* SpringArm;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere)
		class UWidgetComponent* HealthWidget;

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

public:

	AWireHunterCharacter();

	//R
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// Character's Status
	UFUNCTION(BlueprintPure, Category = "Health")
		FORCEINLINE float GetHealth() const { return Health; }

	UFUNCTION(BlueprintCallable, Category = "Health")
		void SetHealth(float healthValue);

	UFUNCTION(BlueprintPure, Category = "Health")
		FORCEINLINE float GetMaxHealth() const { return MaxHealth; }

	UFUNCTION(BlueprintCallable, Category = "Health")
		float TakeDamage(float DamageTaken, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	void SetMaxHealth(float val) { MaxHealth = val; }

	float GetBullets() const { return Bullets; }
	void SetBullets(float val) { Bullets = val; }

	float GetMaxBullets() const { return MaxBullets; }
	void SetMaxBullets(float val) { MaxBullets = val; }

	int GetMoveRightValue() const { return MoveRightValue; }
	void SetMoveRightValue(int val) { MoveRightValue = val; }

	int GetMoveForwardValue() const { return MoveForwardValue; }
	void SetMoveForwardValue(int val) { MoveForwardValue = val; }

	// Floating
	bool GetisWithdrawing() const { return isWithdrawing; }
	void SetisWithdrawing(bool val) { isWithdrawing = val; }

	FVector GetFloatingPos() const { return FloatingPos; }
	void SetFloatingPos(FVector val) { FloatingPos = val; }

	bool GetisClimbing() const { return isClimbing; }
	void SetisClimbing(bool val) { isClimbing = val; }

	bool GetisLedgeClimbing() const { return isLedgeClimbing; }
	void SetisLedgeClimbing(bool val) { isLedgeClimbing = val; }

	FRotator GetFloatingRot() const { return FloatingRot; }
	void SetFloatingRot(FRotator val) { FloatingRot = val; }

	FVector GetWallUpVector() const { return WallUpVector; }
	void SetWallUpVector(FVector val) { WallUpVector = val; }

	FVector GetWallRightVector() const { return WallRightVector; }
	void SetWallRightVector(FVector val) { WallRightVector = val; }

	// WireSystem
	bool GetHooked() const { return Hooked; }
	void SetHooked(bool val) { Hooked = val; }

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay)
	class UParticleSystem* ImpactParticle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay)
	class UParticleSystem* MuzzleParticle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float TimerBetweenShots;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

protected:

	// Character's Status
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Status", ReplicatedUsing=OnRep_CurrentHealth)
		float Health;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Status")
		float MaxHealth;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Status")
		int MaxBullets = 30;
	UPROPERTY(Replicated, BlueprintReadWrite, EditDefaultsOnly, Category = "Status")
		int Bullets;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Status")
		int MoveForwardValue;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Status")
		int MoveRightValue;

	// Floating
	UPROPERTY(Replicated, BlueprintReadWrite, EditDefaultsOnly, Category = "Floating")
		bool isWithdrawing = false;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Floating")
		FVector FloatingPos;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Floating")
		FRotator FloatingRot;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Floating")
		bool isClimbing = false;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Floating")
		bool isLedgeClimbing = false;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Floating")
		bool isBulletEmpty = false;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Floating")
		FVector WallUpVector;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Floating")
		FVector WallRightVector;

	// WireSystem
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Floating")
		bool Hooked = false;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	// Fire
	UFUNCTION(Server, Reliable)
	void StartFire();

	UFUNCTION(Server, Reliable)
	void StopFire();
	
	UFUNCTION(NetMulticast, Reliable)//////////////////////////////////
	void FireShot();
	
	void Reload();
	void Reloaded();

	FTimerHandle TimerHandle_HandleRefire;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GamePlay)
		FVector MuzzleOffset;

	// Wire System
public:

	bool GetCppHooked() const { return cppHooked; }
	void SetCppHooked(bool val) { cppHooked = val; }

	FVector GetCppHookLocation() const { return cppHookLocation; }
	void SetCppHookLocation(FVector val) { cppHookLocation = val; }

	float GetCppHookedWireLength() const { return cppHookedWireLength; }
	void SetCppHookedWireLength(float val) { cppHookedWireLength = val; }

	bool GetCppisLaunching() const { return cppisLaunching; }
	void SetCppisLaunching(bool val) { cppisLaunching = val; }

	/*FVector GetCppWireDistance() const { return cppWireDistance; }
	void SetCppWireDistance(FVector val) { cppWireDistance = val; }*/

	FVector GetCppWallNormal() const { return cppWallNormal; }
	void SetCppWallNormal(FVector val) { cppWallNormal = val; }

	UFUNCTION(Server, Reliable)
	void HookWire();

	UFUNCTION(Server, Reliable)
	void PressWithdraw();

	UFUNCTION(Server, Reliable)
		void Withdraw();

	void WireSwing();

	UFUNCTION(Server, Reliable)
	void BreakHook();

	void Climb();
	void ClimbTrace();
	void UpdateWallNormal();
	void LedgeTrace();
	void WireTrace();

	void Knockback(FVector force);

	//void OnHit(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:

	UPROPERTY(Replicated, BlueprintReadWrite, EditDefaultsOnly, Category = "WireSystem")
	bool cppHooked = false;

	UPROPERTY(Replicated, BlueprintReadWrite, EditDefaultsOnly, Category = "WireSystem")
	float cppHookedWireLength;

	UPROPERTY(Replicated, BlueprintReadWrite, EditDefaultsOnly, Category = "WireSystem")
	bool cppisLaunching = false;

	/*FVector cppWireDistance;*/

	UPROPERTY(Replicated, BlueprintReadWrite, EditDefaultsOnly, Category = "WireSystem")
	FVector cppHookLocation;
	
	FVector cppWallNormal;
	FHitResult WireHit;

	//R

	UFUNCTION()
		void OnRep_CurrentHealth();

	void OnHealthUpdate();

	void TesT();
};