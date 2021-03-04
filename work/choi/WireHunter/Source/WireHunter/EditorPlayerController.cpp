// Fill out your copyright notice in the Description page of Project Settings.

#include "EditorPlayerController.h"
#include "Kismet/KismetMathLibrary.h"

void AEditorPlayerController::OnPossess(APawn* InPawn) {
	Super::OnPossess(InPawn);

	bShowMouseCursor = true;
	bEnableClickEvents = true;
	//DefaultMouseCursor = EMouseCursor::GrabHand;
	DefaultClickTraceChannel = ECollisionChannel::ECC_Visibility;
	HitResultTraceDistance = 10000.f;

	GrabMode = false;
}

void AEditorPlayerController::SetupInputComponent() {
	Super::SetupInputComponent();

	InputComponent->BindAction("Click", IE_Pressed, this, &AEditorPlayerController::Click);
	InputComponent->BindAction("Click", IE_Released, this, &AEditorPlayerController::Release);
}

void AEditorPlayerController::Tick(float DeltaTime) {
	if (GrabMode) {
		FVector WorldLocation, WorldDirection;
		DeprojectMousePositionToWorld(WorldLocation, WorldDirection);

		auto TempLocation = WorldDirection * OriginalDistance + WorldLocation;
		auto TempT = RelativeGrabLocation;

		auto newLocation = UKismetMathLibrary::InverseTransformLocation(FTransform(TempT), TempLocation);

		GrabbedComp->SetWorldLocation(newLocation, false, false);
	}
}

void AEditorPlayerController::Click() {
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);
	if (Hit.bBlockingHit) {
		GrabMode = true;

		OriginalDistance = Hit.Distance;

		GrabbedComp = Hit.GetComponent();

		auto TmpLocation = (FVector)Hit.Location;

		auto TmpT = GrabbedComp->GetComponentLocation();

		RelativeGrabLocation = UKismetMathLibrary::InverseTransformLocation(FTransform(TmpT), TmpLocation);
	}
}

void AEditorPlayerController::Release() {
	GrabMode = false;
}

float AEditorPlayerController::GetOriginalDistance() {
	return OriginalDistance;
}

FHitResult AEditorPlayerController::GetHit() {
	return Hit;
}

bool AEditorPlayerController::GetGrabMode() {
	return GrabMode;
}

FVector AEditorPlayerController::GetRelativeGrabLocation() {
	return RelativeGrabLocation;
}