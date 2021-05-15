// Fill out your copyright notice in the Description page of Project Settings.

#include "Boss.h"
#include "GameFramework/Actor.h"
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

void ABoss::AStar() {

}

void ABoss::h() {

}

void ABoss::g() {

}

void ABoss::f() {

}

// Called when the game starts or when spawned
void ABoss::BeginPlay()
{
	Super::BeginPlay();

	Controller = Cast<ABossAIController>(GetController());

	//////////////////////////////////////////////////////////////////////


}

// Called every frame
void ABoss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FindPlayer();
	FacePlayer();

	UE_LOG(LogTemp, Warning, TEXT("TargetLoc : %s"), *this->TargetLocation.ToString());
	UE_LOG(LogTemp, Warning, TEXT("1111111111111111111111111111111111111111111111111 : %s"), *this->GetActorLocation().ToString());
	UE_LOG(LogTemp, Warning, TEXT("TargetRot : %s"), *this->TargetRotation.ToString());
	UE_LOG(LogTemp, Warning, TEXT("222222222222222222222222222222222222222222222222222 : %s"), *this->GetActorRotation().ToString());

	auto movement = FMath::VInterpTo(this->GetActorLocation(), TargetLocation, GetWorld()->GetDeltaSeconds(), 0.5f);
	auto rot = FMath::RInterpTo(this->GetActorRotation(), TargetRotation, GetWorld()->GetDeltaSeconds(), 2.5f);

	this->SetActorLocationAndRotation(movement, rot);


}

// Called to bind functionality to input
void ABoss::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}