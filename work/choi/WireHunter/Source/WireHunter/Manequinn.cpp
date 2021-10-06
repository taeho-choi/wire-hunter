// Fill out your copyright notice in the Description page of Project Settings.

#include "Manequinn.h"

// Sets default values
AManequinn::AManequinn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
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
void AManequinn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AManequinn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AManequinn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

FVector AManequinn::GetHeadLoc()
{
	return HeadLoc;
}

FVector AManequinn::GetRHandLoc()
{
	return RHandLoc;
}

FVector AManequinn::GetLHandLoc()
{
	return LHandLoc;
}

FVector AManequinn::GetRFootLoc()
{
	return RFootLoc;
}

FVector AManequinn::GetLFootLoc()
{
	return LFootLoc;
}

FRotator AManequinn::GetHeadRot()
{
	return HeadRot;
}

FRotator AManequinn::GetRHandRot()
{
	return RHandRot;
}

FRotator AManequinn::GetLHandRot()
{
	return LHandRot;
}

FRotator AManequinn::GetRFootRot()
{
	return RFootRot;
}

FRotator AManequinn::GetLFootRot()
{
	return LFootRot;
}


void AManequinn::SetHeadLoc(FVector newLoc)
{
	HeadLoc = newLoc;
}

void AManequinn::SetRHandLoc(FVector newLoc)
{
	RHandLoc = newLoc;
}

void AManequinn::SetLHandLoc(FVector newLoc)
{
	LHandLoc = newLoc;
}

void AManequinn::SetRFootLoc(FVector newLoc)
{
	RFootLoc = newLoc;
}

void AManequinn::SetLFootLoc(FVector newLoc)
{
	LFootLoc = newLoc;
}

void AManequinn::SetHeadRot(FRotator newRot)
{
	HeadRot = newRot;
}

void AManequinn::SetRHandRot(FRotator newRot)
{
	RHandRot = newRot;
}

void AManequinn::SetLHandRot(FRotator newRot)
{
	LHandRot = newRot;
}

void AManequinn::SetRFootRot(FRotator newRot)
{
	RFootRot = newRot;
}

void AManequinn::SetLFootRot(FRotator newRot)
{
	LFootRot = newRot;
}