// Fill out your copyright notice in the Description page of Project Settings.


#include "SpeedPotion.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASpeedPotion::ASpeedPotion()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Game/ThirdPersonCPP/GraphicResources/Potion/liquidmedicine_fast_low_uv_id.liquidmedicine_fast_low_uv_id'"));
	UStaticMesh* Asset = MeshAsset.Object;
	PickupMesh->SetStaticMesh(Asset);

	bReplicates = true;
}

// Called when the game starts or when spawned
void ASpeedPotion::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASpeedPotion::OnPlayerEnterPickupBox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (PickupMesh->IsVisible() == true && OtherActor->IsA(AWireHunterCharacter::StaticClass()))
	{
		AWireHunterCharacter* TargetCharacter = Cast<AWireHunterCharacter>(OtherActor);
		TargetCharacter->SetHealth(TargetCharacter->GetHealth() + 10.0f);
		PickupMesh->SetVisibility(false);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Ate SpeedPotion!"));
		GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &APickUp::RandomSpawn, 5.f, false, 5.f);
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), PickParticle, GetTransform());
	}
}

// Called every frame
void ASpeedPotion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}