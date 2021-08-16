// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WireHunterCharacter.h"
#include "NiagaraComponent.h"
#include "NiagaraSystem.h"
#include "PickUp.generated.h"


UCLASS()
class WIREHUNTER_API APickUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Spawn")
	bool isSpawned = false;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	USceneComponent* PickupRoot;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* PickupMesh;

	UPROPERTY(EditAnywhere)
	UShapeComponent* PickupBox;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay)
	class UParticleSystem* PickParticle;

	UFUNCTION()
	virtual void OnPlayerEnterPickupBox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void RandomSpawn();

	FTimerHandle SpawnTimerHandle;
};
