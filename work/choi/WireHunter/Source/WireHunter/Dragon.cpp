// Fill out your copyright notice in the Description page of Project Settings.


#include "Dragon.h"

// Sets default values
ADragon::ADragon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DragonRoot = CreateDefaultSubobject<USceneComponent>(TEXT("PuckupRoot"));
	RootComponent = DragonRoot;

	DragonMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	DragonMesh->AttachToComponent(DragonRoot, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Game/ThirdPerson/Meshes/Bump_StaticMesh.Bump_StaticMesh'"));
	UStaticMesh* Asset = MeshAsset.Object;

	DragonMesh->SetStaticMesh(Asset);

}

// Called when the game starts or when spawned
void ADragon::BeginPlay()
{
	Super::BeginPlay();
	SetActorLocation(FVector(1350.0f, 1950.0f, 460.0f));
}

// Called every frame
void ADragon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (MoveType == 0)
	{
		SetActorLocation(GetActorLocation() + FVector(0.f, -20.f, 0.f));
		if (GetActorLocation().Y <= -720.0f)
		{
			bool temp = FMath::RandBool();
			if (temp)
				MoveType++;
			else
				MoveType = 3;
		}
	}
	else if (MoveType == 1)
	{
		SetActorLocation(GetActorLocation() + FVector(-20.f, 0.f, 0.f));
		if (GetActorLocation().X <= -1290.0f)
		{
			bool temp = FMath::RandBool();
			if (temp)
				MoveType++;
			else
				MoveType--;
		}
	}
	else if (MoveType == 2)
	{
		SetActorLocation(GetActorLocation() + FVector(0.f, 20.f, 0.f));
		if (GetActorLocation().Y >= 1950.0f)
		{
			bool temp = FMath::RandBool();
			if (temp)
				MoveType++;
			else
				MoveType--;
		}
	}
	else if (MoveType == 3)
	{
		SetActorLocation(GetActorLocation() + FVector(20.f, 0.f, 0.f));
		if (GetActorLocation().X >= 1350.0f)
		{
			bool temp = FMath::RandBool();
			if (temp)
				MoveType = 0;
			else
				MoveType--;
		}
	}

}

