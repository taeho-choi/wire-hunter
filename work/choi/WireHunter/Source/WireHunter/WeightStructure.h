// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NodeStructure.h"
#include "WeightStructure.generated.h"

UCLASS()
class WIREHUNTER_API AWeightStructure : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeightStructure();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

USTRUCT(Atomic, BlueprintType)
struct FStructWeight
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int weight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FStructNode node;
};
