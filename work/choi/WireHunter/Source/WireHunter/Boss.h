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
class WIREHUNTER_API ABoss : public APawn
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

	UPROPERTY(EditAnywhere)
		USceneComponent* BossRoot;

	UPROPERTY(EditAnywhere)
		USkeletalMeshComponent* BossSkeletalMesh;

	UPROPERTY(EditAnywhere)
		UShapeComponent* SphereCollision;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Status")
		float Health;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Status")
		float MaxHealth = 100;

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

	//

	float GetHealth() const { return Health; }

	void SetHealth(float value) { Health = value; }

	float GetMaxHealth() const { return MaxHealth; }

	void SetMaxHealth(float value) { MaxHealth = value; }

	void OnHit(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	/*UFUNCTION(BlueprintCallable)
	void DetectKick();*/
};