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
		float MaxHealth = 10;

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly)
		TArray<FString> BoneList = 
	{ 
		"Bip001-Head", "Bip001-Neck2", "Bip001-Neck1", "Bip001-Neck", "Bip001-Spine3", "Bip001-Spine2", "Bip001-Spine1", "Bip001-Spine", "Bip001-Pelvis", 
		"Bip001-Tail", "Bip001-Tail1", "Bip001-Tail2", "Bip001-Tail3", "Bip001-Tail4",
	};

	TArray<AActor*> Players;

	UPROPERTY(BlueprintReadWrite)
	TSubclassOf<class AFireball> ProjectileClass;

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

	bool ToFace;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AFireball> ToSpawn;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ALightning> ToLightning;

	UPROPERTY(EditAnywhere)
		USceneComponent* BossRoot;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
		FVector FindPlayer();

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

	UFUNCTION(BlueprintCallable)
		void Lightning();

	UFUNCTION(BlueprintCallable)
		bool GetToFace() const { return ToFace; }

	UFUNCTION(BlueprintCallable)
		void SetToFace(bool b) { ToFace = b; }

	UFUNCTION(BlueprintCallable)
		void DetectKick();

	UFUNCTION(BlueprintCallable)
		float GetHealth() const { return Health; }

	void SetHealth(float value) { 
		if (HasAuthority())
		{
			Health = value;
		}
	}

	UFUNCTION(BlueprintCallable)
		float GetMaxHealth() const { return MaxHealth; }

	void SetMaxHealth(float value) { MaxHealth = value; }

	UFUNCTION(BlueprintCallable, Server, Reliable)
		void Spawn();

	UFUNCTION(BlueprintCallable)
	FString GetBoneListAt(int idx) const { return BoneList[idx]; }

	UFUNCTION(BlueprintCallable)
		TArray<AActor*> GetPlayers() const { return Players; }
};