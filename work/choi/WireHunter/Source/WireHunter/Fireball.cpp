// Fill out your copyright notice in the Description page of Project Settings.


#include "Fireball.h"
#include "Kismet/GameplayStatics.h"
#include "WireHunterCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "Boss.h"

//R

#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GameFramework/DamageType.h"
#include "Particles/ParticleSystem.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AFireball::AFireball()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FireballRoot = CreateDefaultSubobject<USceneComponent>(TEXT("FireballRoot"));
	RootComponent = FireballRoot;
	FireballRoot->SetWorldScale3D(FVector(3.f, 3.f, 3.f));

	FireballMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FireballMesh"));
	FireballMesh->SetupAttachment(FireballRoot);
	FireballMesh->SetWorldScale3D(FVector(7.f, 7.f, 7.f));
	FireballMesh->SetWorldLocation(GetActorLocation() + FVector(0.f, 0.f, 0.f));
	FireballMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	static ConstructorHelpers::FObjectFinder<UMaterial>MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Fireball.M_Fireball'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem>Particle(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));
	UStaticMesh* Asset = MeshAsset.Object;
	UMaterial* Material = MaterialAsset.Object;
	UParticleSystem* ParticleAsset = Particle.Object;
	ImpactParticle = ParticleAsset;
	FireballMesh->SetStaticMesh(Asset);
	FireballMesh->SetMaterial(0, Material);
	FireballMesh->SetWorldScale3D(FVector(1.f, 1.f, 1.f));
	FireballMesh->SetVisibility(true);
	FireballMesh->SetWorldLocation(FVector(0.f, 0.f, -50.f));

	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	SphereCollision->SetupAttachment(FireballRoot);
	SphereCollision->SetGenerateOverlapEvents(true);
	SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &AFireball::OnHit);
	SphereCollision->SetWorldScale3D(FVector(1.6f, 1.6f, 1.6f));

	//R

	/*if (HasAuthority()) {
		SphereCollision->OnComponentHit.AddDynamic(this, &AFireball::OnProjectileImpact);
	}*/

	bReplicates = true;
	
	/*SphereCollision->SetCollisionProfileName(TEXT("BlockAllDynamic"));

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovementComponent->SetUpdatedComponent(FireballRoot);
	ProjectileMovementComponent->InitialSpeed = 1500.f;
	ProjectileMovementComponent->MaxSpeed = 1500.f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->ProjectileGravityScale = 0.f;

	DamageType = UDamageType::StaticClass();
	Damage = 10.f;*/
}

//R
//void AFireball::Destroyed()
//{
//	FVector spawnLocation = GetActorLocation();
//	UGameplayStatics::SpawnEmitterAtLocation(this, ImpactParticle, spawnLocation, FRotator::ZeroRotator, true, EPSCPoolMethod::AutoRelease);
//}
//
//void AFireball::OnProjectileImpact(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
//{
//	if (OtherActor)
//	{
//		UGameplayStatics::ApplyPointDamage(OtherActor, Damage, NormalImpulse, Hit, GetInstigator()->Controller, this, DamageType);
//	}
//	Destroy();
//}

// Called when the game starts or when spawned
void AFireball::BeginPlay()
{
	Super::BeginPlay();

	TargetLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	TargetRotation = UKismetMathLibrary::FindLookAtRotation(this->GetActorLocation(), TargetLocation);
	SetActorRotation(TargetRotation);
}

// Called every frame
void AFireball::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetActorLocation(GetActorLocation() + (TargetRotation.Vector() * 80));
	if (GetActorLocation().Z < 0.f){
		this->Destroy();
	}
}

void AFireball::OnHit(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OtherActor->IsA(ABoss::StaticClass())){
		if (OtherActor->IsA(AWireHunterCharacter::StaticClass())){
			AWireHunterCharacter* TargetCharacter = Cast<AWireHunterCharacter>(OtherActor);
			TargetCharacter->SetHealth(TargetCharacter->GetHealth() - 1);
			TargetCharacter->BreakHook();
			TargetCharacter->SetisClimbing(false);
			TargetCharacter->Knockback((TargetRotation.Vector() + FVector(0.f, 0.f, 0.5f)) * 10000000);
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Attacked"));
		}
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactParticle, FTransform(GetActorRotation(), GetActorLocation()));
		this->Destroy();
	}
}