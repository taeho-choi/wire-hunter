// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Actor.h"
#include "Dragon.h"

#include "Fireball.generated.h"

UCLASS()
class WIREHUNTER_API AFireball : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFireball();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")//to collision
		class USphereComponent* SphereComponent;//전방선언

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		class UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		class UProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
		class UParticleSystem* ExplosionEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
		TSubclassOf<class UDamageType> DamageType; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
		float Damage;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Destroyed() override;

	UFUNCTION(Category = "Projectile")
		void OnProjectileImpact(UPrimitiveComponent* HitComponent, AActor* otherActor, UPrimitiveComponent* otherComp, FVector NormalImpuse, const FHitResult& Hit);

private:

	FVector TargetLocation;
	FRotator TargetRotation;
};