// Fill out your copyright notice in the Description page of Project Settings.

#include "Boss.h"
#include "GameFramework/Actor.h"
#include "Kismet/KismetMathLibrary.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
ABoss::ABoss()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ABoss::FindPlayer()
{
	TargetLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
}

void ABoss::FacePlayer()
{
	TargetRotation = UKismetMathLibrary::FindLookAtRotation(this->GetActorLocation(), TargetLocation);
}

void ABoss::SetInterpolationRotation()//per tick
{
	YawValue = abs(this->GetActorRotation().Yaw - TargetRotation.Yaw) / 100;
	RollValue = abs(this->GetActorRotation().Roll - TargetRotation.Roll) / 100;
	PitchValue = abs(this->GetActorRotation().Pitch - TargetRotation.Pitch) / 100;
}

void ABoss::SetInterpolationLocation()//per tick
{
	XValue = abs(this->GetActorLocation().X - TargetLocation.X) / 1000;
	YValue = abs(this->GetActorLocation().Y - TargetLocation.Y) / 1000;
	ZValue = abs(this->GetActorLocation().Z - TargetLocation.Z) / 1000;
}

// Called when the game starts or when spawned
void ABoss::BeginPlay()
{
	Super::BeginPlay();

	Controller = Cast<ABossAIController>(GetController());

	//////////////////////////////////////////////////////////////////////

	FindPlayer();
	FacePlayer();

	SetInterpolationLocation();
	SetInterpolationRotation();
}

// Called every frame
void ABoss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto goalRot = TargetRotation;
	auto goalLoc = TargetLocation;

	auto movement = FMath::VInterpTo(this->GetActorLocation(), TargetLocation, DeltaTime, 1000.f);

	if(abs(this->GetActorLocation().X - TargetLocation.X) > movement.X){
		this->SetActorLocation(this->GetActorLocation() + movement);
	}
	else {
		this->SetActorLocation(TargetLocation);
	}

	UE_LOG(LogTemp, Error, TEXT("movement : %s"), *movement.ToString());
	UE_LOG(LogTemp, Warning, TEXT("T : %s"), *TargetLocation.ToString());
}

// Called to bind functionality to input
void ABoss::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}