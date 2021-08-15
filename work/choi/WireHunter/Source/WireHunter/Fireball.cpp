// Fill out your copyright notice in the Description page of Project Settings.

#include "Fireball.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GameFramework/DamageType.h"
#include "Particles/ParticleSystem.h"
#include "UObject/Constructorhelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

#include "Net/UnrealNetwork.h"
#include "Engine/Engine.h"

// Sets default values
AFireball::AFireball()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bReplicates = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	SphereComponent->InitSphereRadius(37.5f);
	SphereComponent->SetCollisionProfileName(TEXT("BlockAllDynamic"));
	RootComponent = SphereComponent;

	if (HasAuthority()) 
	{
		SphereComponent->OnComponentHit.AddDynamic(this, &AFireball::OnProjectileImpact);
	}

	static ConstructorHelpers::FObjectFinder<UStaticMesh> DefaultMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	StaticMesh->SetupAttachment(RootComponent);
	if (DefaultMesh.Succeeded()) 
	{
		StaticMesh->SetStaticMesh(DefaultMesh.Object);
		StaticMesh->SetRelativeLocation(FVector(0.f, 0.f, 37.5f));
		StaticMesh->SetRelativeScale3D(FVector(3.f, 3.f, 3.f));
	}

	static ConstructorHelpers::FObjectFinder<UParticleSystem> DefaultExposionEffect(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));
	if (DefaultExposionEffect.Succeeded()) 
	{
		ExplosionEffect = DefaultExposionEffect.Object;
	}

	static ConstructorHelpers::FObjectFinder<UMaterial>MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Fireball.M_Fireball'"));
	UMaterial* Material = MaterialAsset.Object;
	StaticMesh->SetMaterial(0, Material);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovementComponent->SetUpdatedComponent(SphereComponent);
	ProjectileMovementComponent->InitialSpeed = 1500.f;
	ProjectileMovementComponent->MaxSpeed = 1500.f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;//이 발사체는 각 프레임의 회전을 속도 방향에 맞게 업데이트한다.
	ProjectileMovementComponent->ProjectileGravityScale = 0.f;

	DamageType = UDamageType::StaticClass();

	Damage = 10.f;
}

// Called when the game starts or when spawned
void AFireball::BeginPlay()
{
	Super::BeginPlay();

	TargetLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();// +FVector(0.f, 0.f, -100.f);
	TargetRotation = UKismetMathLibrary::FindLookAtRotation(this->GetActorLocation(), TargetLocation);
	SetActorRotation(TargetRotation);
}

// Called every frame
void AFireball::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorLocation(GetActorLocation() + (TargetRotation.Vector() * 100));
	if (GetActorLocation().Z < 0.f) 
	{
		this->Destroy();
	}
}

void AFireball::Destroyed() 
{
	FVector spawnLocation = GetActorLocation();
	UGameplayStatics::SpawnEmitterAtLocation(this, ExplosionEffect, spawnLocation, FRotator::ZeroRotator, true, EPSCPoolMethod::AutoRelease);
}

void AFireball::OnProjectileImpact(UPrimitiveComponent* HitComponent, AActor* otherActor, UPrimitiveComponent* otherComp, FVector NormalImpuse, const FHitResult& Hit) 
{
	if ( !( otherActor->IsA(ADragon::StaticClass()) ) )
	{
		UGameplayStatics::ApplyPointDamage(otherActor, Damage, NormalImpuse, Hit, GetInstigator()->Controller, this, DamageType);
		Destroy();
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "HitTest");
}