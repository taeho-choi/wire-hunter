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
		StaticMesh->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
		StaticMesh->SetRelativeScale3D(FVector(6.f, 12.f, 6.f));
		StaticMesh->SetRelativeRotation(FRotator(0.f, 0.f, 0.f));
	}

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SubMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	SubStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SubMesh"));
	SubStaticMesh->SetupAttachment(RootComponent);
	if (SubMesh.Succeeded())
	{
		SubStaticMesh->SetStaticMesh(SubMesh.Object);
		SubStaticMesh->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
		SubStaticMesh->SetRelativeScale3D(FVector(4.f, 6.f, 4.f));
		SubStaticMesh->SetRelativeRotation(FRotator(0.f, 0.f, 0.f));
	}

	static ConstructorHelpers::FObjectFinder<UParticleSystem> DefaultExposionEffect(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));
	if (DefaultExposionEffect.Succeeded()) 
	{
		ExplosionEffect = DefaultExposionEffect.Object;
	}

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
	ProjectileMovementComponent->bRotationFollowsVelocity = true;//�� �߻�ü�� �� �������� ȸ���� �ӵ� ���⿡ �°� ������Ʈ�Ѵ�.
	ProjectileMovementComponent->ProjectileGravityScale = 0.f;

	DamageType = UDamageType::StaticClass();

	RootComponent->SetWorldRotation(FRotator(-90.f, 0.f, 0.f));
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

	//FVector outVelocity = FVector::ZeroVector;   // ��� Velocity
	//if (UGameplayStatics::SuggestProjectileVelocity_CustomArc(this, outVelocity, spawnLocation, TargetLocation, GetWorld()->GetGravityZ(), 0.5f))
	//{
	//	FPredictProjectilePathParams predictParams(20.0f, spawnLocation, outVelocity, 15.0f);   // 20: tracing ������ ������Ÿ�� ũ��, 15: �ù����̼ǵǴ� Max �ð�(��)
	//	predictParams.DrawDebugTime = 4.f;     //����� ���� �������� �ð� (��)
	//	predictParams.DrawDebugType = EDrawDebugTrace::Type::ForDuration;  // DrawDebugTime �� �����ϸ� EDrawDebugTrace::Type::ForDuration �ʿ�.
	//	predictParams.OverrideGravityZ = GetWorld()->GetGravityZ();
	//	FPredictProjectilePathResult result;
	//	UGameplayStatics::PredictProjectilePath(this, predictParams, result);
	//}
	//ProjectileMovementComponent->AddForce(outVelocity); // objectToSend�� �߻�ü
}

// Called every frame
void AFireball::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFireball::Destroyed() 
{
	FVector spawnLocation = GetActorLocation();
	UGameplayStatics::SpawnEmitterAtLocation(this, ExplosionEffect, spawnLocation, FRotator::ZeroRotator, true, EPSCPoolMethod::AutoRelease);
}

void AFireball::OnProjectileImpact(UPrimitiveComponent* HitComponent, AActor* otherActor, UPrimitiveComponent* otherComp, FVector NormalImpuse, const FHitResult& Hit) 
{
	UGameplayStatics::ApplyPointDamage(otherActor, Damage, NormalImpuse, Hit, GetInstigator()->Controller, this, DamageType);
	//Destroy();
}