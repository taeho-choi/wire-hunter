// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayerController.h"

void AMyPlayerController::PostInitializeComponents(){
	Super::PostInitializeComponents();
	MYLOG_S(Warning);
}

void AMyPlayerController::OnPossess(APawn* InPawn){
	MYLOG_S(Warning);
	Super::OnPossess(InPawn);

	bShowMouseCursor = true;
	bEnableClickEvents = true;
	DefaultMouseCursor = EMouseCursor::GrabHand;
	DefaultClickTraceChannel = ECollisionChannel::ECC_Visibility;
	HitResultTraceDistance = 10000.f;


}