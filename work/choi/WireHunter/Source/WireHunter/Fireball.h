// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Fireball.generated.h"

UCLASS()
class WIREHUNTER_API AFireball : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFireball();

	FVector TargetLocation;
	FRotator TargetRotation;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		USceneComponent* FireballRoot;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* FireballMesh;

	UPROPERTY(EditAnywhere)
		UShapeComponent* SphereCollision;

	UPROPERTY(EditAnywhere, Category = Gameplay)
		UParticleSystem* ImpactParticle;

	UFUNCTION()
		virtual void OnHit(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
