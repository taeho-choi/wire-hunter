// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUp.h"
#include "HealingPotion.generated.h"

UCLASS()
class WIREHUNTER_API AHealingPotion : public APickUp
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHealingPotion();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// PickUp Event
	virtual void OnPlayerEnterPickupBox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
