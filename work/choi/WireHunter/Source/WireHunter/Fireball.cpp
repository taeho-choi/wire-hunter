// Fill out your copyright notice in the Description page of Project Settings.


#include "Fireball.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "WireHunterCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "Obstacle.h"

// Sets default values
AFireball::AFireball()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FireballRoot = CreateDefaultSubobject<USceneComponent>(TEXT("FireballRoot"));
	RootComponent = FireballRoot;
	FireballRoot->SetWorldScale3D(FVector(3.f, 3.f, 3.f));

	FireballMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FireballMesh"));
	FireballMesh->AttachToComponent(FireballRoot, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	FireballMesh->SetWorldScale3D(FVector(7.f, 7.f, 7.f));
	FireballMesh->SetWorldLocation(GetActorLocation() + FVector(0.f, 0.f, 0.f));
	FireballMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	static ConstructorHelpers::FObjectFinder<UMaterial>MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Fireball.M_Fireball'"));
	UStaticMesh* Asset = MeshAsset.Object;
	UMaterial* Material = MaterialAsset.Object;
	FireballMesh->SetStaticMesh(Asset);
	FireballMesh->SetMaterial(0, Material);
	FireballMesh->SetWorldScale3D(FVector(1.f, 1.f, 1.f));
	FireballMesh->SetVisibility(true);
	FireballMesh->SetWorldLocation(FVector(0.f, 0.f, -50.f));

	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	SphereCollision->SetGenerateOverlapEvents(true);
	SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &AFireball::OnHit);
	SphereCollision->AttachToComponent(FireballRoot, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	SphereCollision->SetWorldScale3D(FVector(1.6f, 1.6f, 1.6f));
}

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
	SetActorLocation(GetActorLocation() + (TargetRotation.Vector() * 40));

}

void AFireball::OnHit(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA(AWireHunterCharacter::StaticClass()) || OtherActor->IsA(AObstacle::StaticClass()))
	{
		if (OtherActor->IsA(AWireHunterCharacter::StaticClass()))
		{
			AWireHunterCharacter* TargetCharacter = Cast<AWireHunterCharacter>(OtherActor);
			TargetCharacter->SetHealth(TargetCharacter->GetHealth() - 1);
			TargetCharacter->BreakHook();
			TargetCharacter->SetisClimbing(false);
			TargetCharacter->Knockback((TargetRotation.Vector() + FVector(0.f, 0.f, 0.5f)) * 10000000);
		}
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactParticle, FTransform(GetActorRotation(), GetActorLocation()));
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Attacked"));
		this->Destroy();
	}

}

