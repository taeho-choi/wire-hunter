// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Character.h"
#include "BossAIController.h"
#include "NodeStructure.h"
#include "WeightStructure.h"
#include "Obstacle.h"
#include "TimerManager.h"
#include "Fireball.h"

#include "Boss.generated.h"

UCLASS()
class WIREHUNTER_API ABoss : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABoss();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
		void Spawn();
	UPROPERTY(EditAnywhere)
		TSubclassOf<AFireball> ToSpawn;

	FTimerHandle SpawnTimerHandle;

private:
	FVector TargetLocation;

	FRotator TargetRotation;

	ABossAIController* Controller;

	FStructNode Start, Goal;
	TArray<FStructWeight> Min;
	TArray<FStructNode> Path;
	TArray<FStructNode> Closed;
	int ScoreF[10][10];
	int ScoreG[10][10];
	int ScoreH[10][10];

	FVector RealMap[10][10];
	char Map[10][10];//how to mark the player loc?

	FVector RealGoal;

	int PathIdx;

	bool bMoveReady;

	float Delta;

	bool bAStarReady;

	float Top;

	bool bFireballReady;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void FindPlayer();

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

	void SetRealGoal();

	void DoAStar();
};