// Fill out your copyright notice in the Description page of Project Settings.


#include "EditorPlayerController.h"

void AEditorPlayerController::OnPossess(APawn* InPawn){
	
	Super::OnPossess(InPawn);

	bShowMouseCursor = true;
	bEnableClickEvents = true;
	//DefaultMouseCursor = EMouseCursor::GrabHand;
	DefaultClickTraceChannel = ECollisionChannel::ECC_Visibility;
	HitResultTraceDistance = 10000.f;

	/*FHitResult Hit;
	GetHitResultUnderCursorForObjects(ECC_Visibility, false, Hit);
	if (Hit.bBlockingHit) {
		
	}*/
}