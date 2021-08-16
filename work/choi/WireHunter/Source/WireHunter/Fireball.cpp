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
#include "WireHunterCharacter.h"
#include "EngineUtils.h"
#include "Dragon.h"

#include "Net/UnrealNetwork.h"
#include "Engine/Engine.h"

// Sets default values
AFireball::AFireball()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bReplicates = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	SphereComponent->InitSphereRadius(200.f);
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
		StaticMesh->SetRelativeLocation(FVector(0.f, 0.f, -140.f));
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
	ProjectileMovementComponent->InitialSpeed = 1000.f;
	ProjectileMovementComponent->MaxSpeed = 1000.f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;//이 발사체는 각 프레임의 회전을 속도 방향에 맞게 업데이트한다.
	ProjectileMovementComponent->ProjectileGravityScale = 0.f;

	DamageType = UDamageType::StaticClass();

	Damage = 10.f;
}

// Called when the game starts or when spawned
void AFireball::BeginPlay()
{
	Super::BeginPlay();

	//TArray<FVector> Players;

	////Players.Empty();

	//for (const auto& e : TActorRange<AWireHunterCharacter>(GetWorld())) {
	//	Players.Push(e->GetActorLocation());
	//}

	//auto idx = rand() % 2;
	//TargetLocation = Players[idx];

	//TargetLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	/*TargetRotation = UKismetMathLibrary::FindLookAtRotation(this->GetActorLocation(), TargetLocation);
	SetActorRotation(TargetRotation);*/
}

// Called every frame
void AFireball::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//InTick();

	/*if (!HasAuthority())
	{
		InTick2();
	}*/

	//ProjectileMovementComponent->ComputeHomingAcceleration(FVector(0.f, 0.f, 0.f), DeltaTime);
}

void AFireball::InTick_Implementation()
{
	SetActorLocation(GetActorLocation() + (TargetRotation.Vector() * 200));
	if (GetActorLocation().Z < 0.f)
	{
		this->Destroy();
	}
}

void AFireball::InTick2_Implementation()
{
	SetActorLocation(GetActorLocation() + (TargetRotation.Vector() * 200));
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
	//////////////////////////////////////////////////////////////////////////////////////////
}

void AFireball::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	/*DOREPLIFETIME(AFireball, Health);*/
}