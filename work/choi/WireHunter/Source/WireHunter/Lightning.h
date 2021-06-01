// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Lightning.generated.h"

UCLASS()
class WIREHUNTER_API ALightning : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALightning();

	FVector TargetLocation;
	FRotator TargetRotation;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		USceneComponent* LightningRoot;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* LightningMesh;

	UPROPERTY(EditAnywhere)
		UShapeComponent* SphereCollision;

	UPROPERTY(EditAnywhere, Category = Gameplay)
		UParticleSystem* ImpactParticle;

	UFUNCTION()
		virtual void OnHit(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
