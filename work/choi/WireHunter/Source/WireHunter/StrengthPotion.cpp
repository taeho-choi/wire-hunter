// Fill out your copyright notice in the Description page of Project Settings.


#include "StrengthPotion.h"

// Sets default values
AStrengthPotion::AStrengthPotion()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Game/ThirdPersonCPP/GraphicResources/Potion/liquidmedicine_strong_low_uv_id.liquidmedicine_strong_low_uv_id'"));
	UStaticMesh* Asset = MeshAsset.Object;
	PickupMesh->SetStaticMesh(Asset);
}

// Called when the game starts or when spawned
void AStrengthPotion::BeginPlay()
{
	Super::BeginPlay();
	
}

void AStrengthPotion::OnPlayerEnterPickupBox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AWireHunterCharacter* TargetCharacter = Cast<AWireHunterCharacter>(OtherActor);
	//TargetCharacter->SetHealth(TargetCharacter->GetHealth() + 100.0f);
	PickupMesh->SetVisibility(false);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Ate StrengthPotion!"));
}

// Called every frame
void AStrengthPotion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

