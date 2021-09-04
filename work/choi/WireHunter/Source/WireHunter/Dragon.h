// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Character.h"
#include "NodeStructure.h"
#include "WeightStructure.h"
#include "Fireball.h"
#include "Lightning.h"

#include "Dragon.generated.h"

UCLASS()
class WIREHUNTER_API ADragon : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADragon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(Replicated, VisibleInstanceOnly, Category = "Status")
		float Health;
	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category = "Status")
		float MaxHealth = 1000;

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly)
		TArray<FString> BoneList = 
	{ 
		"Bip001-Head", "Bip001-Neck2", "Bip001-Neck1", "Bip001-Neck", "Bip001-Spine3", "Bip001-Spine2", "Bip001-Spine1", "Bip001-Spine", "Bip001-Pelvis", 
		"Bip001-Tail", "Bip001-Tail1", "Bip001-Tail2", "Bip001-Tail3", "Bip001-Tail4",
	};

	UPROPERTY(BlueprintReadWrite)
	TSubclassOf<class AFireball> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
	class UNiagaraSystem* BloodParticle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
	class UNiagaraSystem* BreathParticle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = animation, meta = (AllowPrivateAccess = "true"))
		class UAnimMontage* TestAnim;

private:
	char Map[10][10];

	FVector TargetLocation;
	FRotator TargetRotation;
	FStructNode Start, Goal;

	TArray<FStructWeight> Min;
	TArray<FStructNode> Closed;
	int ScoreF[10][10];
	int ScoreG[10][10];
	int ScoreH[10][10];

	FVector RealMap[10][10];

	TArray<FStructNode> Path;

	TArray<FVector> Obstacles;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AFireball> ToSpawn;

	TArray<FVector> Players;

	bool NotPrecious;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	FVector FindPlayer();

	UFUNCTION(BlueprintCallable)
	void FacePlayer();

	void h(FStructNode next, FStructNode end);

	void g(FStructNode next, int plus);

	void f(FStructNode next);

	void AStar(char map[10][10], FStructNode start, FStructNode goal);

	void MakeMap();

	FStructNode FindTop();

	int FindElement(float x, float y);

	TArray<FStructNode> Regulate();

	float FindDistance(FVector a, FVector b);

	UFUNCTION(BlueprintCallable)
	FVector GetGoal();

	UFUNCTION(BlueprintCallable)
	TArray<FStructNode> DoAStar();

	UFUNCTION(BlueprintCallable)
	FVector GetPath();

	UFUNCTION(BlueprintCallable, Server, Reliable, WithValidation)
	void DetectKickServer();
	void DetectKickServer_Implementation();
	bool DetectKickServer_Validate();

	UFUNCTION(BlueprintCallable)
	float GetHealth() const { return Health; }

	void SetHealth(float value) { 
		if (GetLocalRole() == ROLE_Authority)
		{
			Health = value;
		}
	}

	UFUNCTION(BlueprintCallable)
	float GetMaxHealth() const { return MaxHealth; }
	UFUNCTION(BlueprintCallable)
	void CheatHealth() { Health = -1; }

	void SetMaxHealth(float value) { MaxHealth = value; }

	UFUNCTION(BlueprintCallable, Server, Reliable)
	void Spawn();

	UNiagaraSystem* GetBloodParticle() const { return BloodParticle; }

	UFUNCTION(BlueprintCallable)
	void Breath();

	UFUNCTION(BlueprintCallable)
	void BreathTrace();

	UFUNCTION(BlueprintCallable)
	void Test();
};