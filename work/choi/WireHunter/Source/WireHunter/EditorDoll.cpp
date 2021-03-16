// Fill out your copyright notice in the Description page of Project Settings.

#include "EditorDoll.h"

// Sets default values
AEditorDoll::AEditorDoll()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SK = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SK"));
	PM = CreateDefaultSubobject<UPoseableMeshComponent>(TEXT("PM"));

	RootComponent = SK;
	PM->SetupAttachment(SK);
}

// Called when the game starts or when spawned
void AEditorDoll::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEditorDoll::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FString name = FString("neck_01");
	auto location = PM->GetBoneLocationByName(FName(*name), EBoneSpaces::WorldSpace);
	auto newLocation = FVector(location.X, location.Y, location.Z);
	PM->SetBoneLocationByName(FName(*name), newLocation, EBoneSpaces::WorldSpace);
}