// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUp.h"
#include "Components/BoxComponent.h"
#include "TimerManager.h"
#include "WireHunterCharacter.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APickUp::APickUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PickupRoot = CreateDefaultSubobject<USceneComponent>(TEXT("PuckupRoot"));
	RootComponent = PickupRoot;
	PickupRoot->SetWorldScale3D(FVector(3.f, 3.f, 3.f));
	
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	PickupMesh->SetupAttachment(PickupRoot);
	PickupMesh->SetVisibility(false);
	PickupMesh->SetWorldScale3D(FVector(7.f, 7.f, 7.f));
	PickupMesh->SetWorldLocation(GetActorLocation() + FVector(0.f, 0.f, -35.f));
	PickupMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	PickupBox = CreateDefaultSubobject<UBoxComponent>(TEXT("PuckupBox"));
	PickupBox->SetGenerateOverlapEvents(true);
	PickupBox->OnComponentBeginOverlap.AddDynamic(this, &APickUp::OnPlayerEnterPickupBox);
	PickupBox->SetupAttachment(PickupRoot);
	PickupBox->SetWorldScale3D(FVector(0.5f, 0.5f, 1.f));

	isSpawned = false;
}

// Called when the game starts or when spawned
void APickUp::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &APickUp::RandomSpawn, 5.f, false, 0.f);
}

// Called every frame
void APickUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APickUp::OnPlayerEnterPickupBox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void APickUp::RandomSpawn()
{
	PickupMesh->SetVisibility(true);
}