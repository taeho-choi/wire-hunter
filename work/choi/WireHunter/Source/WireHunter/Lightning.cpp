// Fill out your copyright notice in the Description page of Project Settings.

#include "Lightning.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "WireHunterCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "Boss.h"

// Sets default values
ALightning::ALightning()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LightningRoot = CreateDefaultSubobject<USceneComponent>(TEXT("LightningRoot"));
	RootComponent = LightningRoot;
	LightningRoot->SetWorldScale3D(FVector(3.f, 3.f, 3.f));

	LightningMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LightningMesh"));
	LightningMesh->SetupAttachment(LightningRoot);
	LightningMesh->SetWorldScale3D(FVector(7.f, 7.f, 7.f));
	LightningMesh->SetWorldLocation(GetActorLocation() + FVector(0.f, 0.f, 0.f));
	LightningMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	static ConstructorHelpers::FObjectFinder<UMaterial>MaterialAsset(TEXT("Material'/Game/ThirdPersonCPP/AI/MT_BossRock.MT_BossRock'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem>Particle(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));
	UStaticMesh* Asset = MeshAsset.Object;
	UMaterial* Material = MaterialAsset.Object;
	UParticleSystem* ParticleAsset = Particle.Object;
	ImpactParticle = ParticleAsset;
	LightningMesh->SetStaticMesh(Asset);
	LightningMesh->SetMaterial(0, Material);
	LightningMesh->SetWorldScale3D(FVector(1.f, 1.f, 1.f));
	LightningMesh->SetVisibility(true);
	LightningMesh->SetWorldLocation(FVector(0.f, 0.f, -50.f));

	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	SphereCollision->SetGenerateOverlapEvents(true);
	SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &ALightning::OnHit);
	SphereCollision->SetupAttachment(LightningRoot);
	SphereCollision->SetWorldScale3D(FVector(1.6f, 1.6f, 1.6f));

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("L Spawn"));

	bReplicates = true;
}

// Called when the game starts or when spawned
void ALightning::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ALightning::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto pos = this->GetActorLocation();
	this->SetActorLocation(pos - FVector(0.f, 0.f, 80.f));
}

void ALightning::OnHit(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	/*if (!OtherActor->IsA(ABoss::StaticClass())) {
		if (OtherActor->IsA(AWireHunterCharacter::StaticClass())) {
			AWireHunterCharacter* TargetCharacter = Cast<AWireHunterCharacter>(OtherActor);
			TargetCharacter->SetHealth(TargetCharacter->GetHealth() - 1);
			TargetCharacter->BreakHook();
			TargetCharacter->SetisClimbing(false);
			TargetCharacter->Knockback((TargetRotation.Vector() + FVector(0.f, 0.f, 0.5f)) * 10000000);
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("PPPAttacked"));
		}
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("1111Attacked"));
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactParticle, FTransform(GetActorRotation(), GetActorLocation()));
		this->Destroy();
	}*/
}