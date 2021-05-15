// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Character.h"
#include "BossAIController.h"

#include "Containers/Map.h"
#include "Kismet/KismetMathLibrary.h"

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

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	void FindPlayer();

	void FacePlayer();

	void SetInterpolationLocation();

	void SetInterpolationRotation();

	void AStar();

	void h();

	void g();

	void f();

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

	typedef TTuple<float, float> Node;
	typedef TTuple<int, Node> Weight;

	TArray<Node> Path;


};