// Fill out your copyright notice in the Description page of Project Settings.

#include "EditorManequinn.h"

// Sets default values
AEditorManequinn::AEditorManequinn()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SK = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MESH"));

	RootComponent = SK;
	SK->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -88.f), FRotator(0.f, -90.f, 0.f));
	
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SKSK(TEXT("SkeletalMesh'/Game/ThirdPersonCPP/GraphicResources/Character/RiggedCharacter/CapeCharacter/CapeCharacter.CapeCharacter'"));
	if (SKSK.Succeeded()) {
		SK->SetSkeletalMesh(SKSK.Object);
	}
}

// Called when the game starts or when spawned
void AEditorManequinn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEditorManequinn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

