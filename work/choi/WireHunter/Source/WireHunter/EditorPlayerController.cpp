// Fill out your copyright notice in the Description page of Project Settings.

#include "EditorPlayerController.h"

void AEditorPlayerController::OnPossess(APawn* InPawn){
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
		//UE_LOG(LogTemp, Warning, TEXT("Y: %f"), WorldLocation.Y);
		auto TempLocation = WorldDirection * OriginalDistance + WorldLocation;
		auto TempT = RelativeGrabLocation;
		/*TempT를 트랜스폼으로 변환 후 TempLocation과 Inverse 한 뒤 
		GrabbedComp->SetWorldLocation();*/

		GrabbedComp->SetWorldLocation(WorldLocation, false, false);
	}
}

void AEditorPlayerController::Click() {
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);
	if (Hit.bBlockingHit) {
		GrabMode = true;
		
		OriginalDistance = Hit.Distance;
		UE_LOG(LogTemp, Warning, TEXT("Original Distance: %f"), OriginalDistance);

		GrabbedComp = Hit.GetComponent();
		
		////////////////////////////////////////////////////////////

		auto TmpLocation = (FVector)Hit.Location;
	
		auto TmpT = GrabbedComp->GetComponentLocation();

		/*TmpT를 트랜스폼으로 변환 후 TmpLocation과 inverse 한 뒤 
		RelativeGrabLocation set*/
	}
}

void AEditorPlayerController::Release() {
	UE_LOG(LogTemp, Warning, TEXT("Release"));

	GrabMode = false;
}

float AEditorPlayerController::GetOriginalDistance(){
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