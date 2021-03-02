// Fill out your copyright notice in the Description page of Project Settings.

#include "EditorPlayerController.h"

void AEditorPlayerController::OnPossess(APawn* InPawn){
	
	Super::OnPossess(InPawn);

	bShowMouseCursor = true;
	bEnableClickEvents = true;
	//DefaultMouseCursor = EMouseCursor::GrabHand;
	DefaultClickTraceChannel = ECollisionChannel::ECC_Visibility;
	HitResultTraceDistance = 10000.f;

	//OnClicked 함수 만들어서 거기에 1 넣기

	/*GetHitResultUnderCursor(ECC_Visibility, false, Hit);
	if (Hit.bBlockingHit) {
		OriginalDistance = Hit.Distance;
		UE_LOG(LogTemp, Warning, TEXT("Original Distance: %f"), OriginalDistance);
	}.............................................................................1번*/

	//Onclicked는 충돌체에 넣는거?
}