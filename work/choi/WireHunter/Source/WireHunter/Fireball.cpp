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
#include "NiagaraFunctionLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraComponent.h"

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
		StaticMesh->SetRelativeLocation(FVector(-420.f, -6.666f, -200.f));
		StaticMesh->SetRelativeScale3D(FVector(4.f, 12.f, 4.f));
		StaticMesh->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
	}

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SubMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	SubStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SubMesh"));
	SubStaticMesh->SetupAttachment(RootComponent);
	if (SubMesh.Succeeded())
	{
		SubStaticMesh->SetStaticMesh(SubMesh.Object);
		SubStaticMesh->SetRelativeLocation(FVector(-70.f, 0.f, -100.f));
		SubStaticMesh->SetRelativeScale3D(FVector(2.f, 4.f, 2.f));
		SubStaticMesh->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
	}

	static ConstructorHelpers::FObjectFinder<UParticleSystem> DefaultExposionEffect(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));
	if (DefaultExposionEffect.Succeeded()) 
	{
		ExplosionEffect = DefaultExposionEffect.Object;
	}

	static ConstructorHelpers::FObjectFinder<UNiagaraSystem> MeteorSmokeParticleAsset(TEXT("NiagaraSystem'/Game/ThirdPersonCPP/AI/GunImpactParticles/Particles/Concrete/PS_Concrete.PS_Concrete'"));
	UNiagaraSystem* NS_MeteorSmokeParticle = MeteorSmokeParticleAsset.Object;
	MeteorSmokeParticle = NS_MeteorSmokeParticle;

	static ConstructorHelpers::FObjectFinder<UMaterial>MaterialAsset(TEXT("Material'/Game/ThirdPersonCPP/AI/MT_Meteor.MT_Meteor'"));
	UMaterial* Material = MaterialAsset.Object;
	StaticMesh->SetMaterial(0, Material);

	static ConstructorHelpers::FObjectFinder<UMaterial>SubMaterialAsset(TEXT("Material'/Game/ThirdPersonCPP/AI/MT_BossRock.MT_BossRock'"));
	UMaterial* SubMaterial = SubMaterialAsset.Object;
	SubStaticMesh->SetMaterial(0, SubMaterial);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovementComponent->SetUpdatedComponent(SphereComponent);
	ProjectileMovementComponent->InitialSpeed = 14000.f;
	ProjectileMovementComponent->MaxSpeed = 14000.f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;//이 발사체는 각 프레임의 회전을 속도 방향에 맞게 업데이트한다.
	ProjectileMovementComponent->ProjectileGravityScale = 0.f;

	DamageType = UDamageType::StaticClass();

	RootComponent->SetWorldScale3D(FVector(2.f, 2.f, 2.f));
}

// Called when the game starts or when spawned
void AFireball::BeginPlay()
{
	Super::BeginPlay();

	//FVector DragonLocation;
	//FVector DragonForwardVector;
	//FVector TargetLocation;

	//for (const auto& e : TActorRange<ADragon>(GetWorld())) {
	//	DragonLocation = e->GetActorLocation();
	//	DragonForwardVector = e->GetActorForwardVector();
	//	TargetLocation = e->GetTargetLocation();
	//}

	//auto spawnLocation = DragonLocation + DragonForwardVector * 3000.f;

	//FVector outVelocity = FVector::ZeroVector;   // 결과 Velocity
	//if (UGameplayStatics::SuggestProjectileVelocity_CustomArc(this, outVelocity, spawnLocation, TargetLocation, GetWorld()->GetGravityZ(), 0.5f))
	//{
	//	FPredictProjectilePathParams predictParams(20.0f, spawnLocation, outVelocity, 15.0f);   // 20: tracing 보여질 프로젝타일 크기, 15: 시물레이션되는 Max 시간(초)
	//	predictParams.DrawDebugTime = 4.f;     //디버그 라인 보여지는 시간 (초)
	//	predictParams.DrawDebugType = EDrawDebugTrace::Type::ForDuration;  // DrawDebugTime 을 지정하면 EDrawDebugTrace::Type::ForDuration 필요.
	//	predictParams.OverrideGravityZ = GetWorld()->GetGravityZ();
	//	FPredictProjectilePathResult result;
	//	UGameplayStatics::PredictProjectilePath(this, predictParams, result);
	//}
	//ProjectileMovementComponent->AddForce(outVelocity); // objectToSend는 발사체
}

// Called every frame
void AFireball::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFireball::Destroyed() 
{
	FVector spawnLocation = GetActorLocation();
	//UGameplayStatics::SpawnEmitterAtLocation(this, ExplosionEffect, spawnLocation, FRotator::ZeroRotator, true, EPSCPoolMethod::AutoRelease);
	UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, MeteorSmokeParticle, spawnLocation);
}

void AFireball::OnProjectileImpact(UPrimitiveComponent* HitComponent, AActor* otherActor, UPrimitiveComponent* otherComp, FVector NormalImpuse, const FHitResult& Hit) 
{
	if (otherActor->IsA(AWireHunterCharacter::StaticClass()))
	{
		if (HasAuthority())
		{
			AWireHunterCharacter* TargetCharacter = Cast<AWireHunterCharacter>(otherActor);
			TargetCharacter->SetHealth(TargetCharacter->GetHealth() - 5.f);
			TargetCharacter->KnockbackServer();
		}
		//UGameplayStatics::ApplyPointDamage(TargetCharacter, Damage, NormalImpuse, Hit, GetInstigator()->Controller, this, DamageType);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "c");
	}
	Destroy();
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "o");
}