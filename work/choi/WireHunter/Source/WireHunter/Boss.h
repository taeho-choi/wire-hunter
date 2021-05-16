// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Character.h"
#include "BossAIController.h"
#include "NodeStructure.h"
#include "WeightStructure.h"
#include "Obstacle.h"

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

private:
	FVector TargetLocation;

	FRotator TargetRotation;

	float YawValue;
	float RollValue;
	float PitchValue;

	float XValue;
	float YValue;
	float ZValue;

	ABossAIController* Controller;

	static int InterpolationValueLoc;
	static int InterpolationValueRot;

	FStructNode Start, Goal;
	TArray<FStructWeight> Min;
	TArray<FStructNode> Path;
	TArray<FStructNode> Closed;
	int ScoreF[10][10];
	int ScoreG[10][10];
	int ScoreH[10][10];

	FVector RealMap[10][10];
	char Map[10][10];//how to mark the player loc?

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
};