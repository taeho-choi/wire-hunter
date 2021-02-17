// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameModeBase.h"
#include "MyCharacter.h"
#include "MyPawn.h"
#include "MyPlayerController.h"

AMyGameModeBase::AMyGameModeBase(){
	DefaultPawnClass = AMyCharacter::StaticClass();//to assign for player - 1 
	PlayerControllerClass = AMyPlayerController::StaticClass();//to assign for player - 2

	//MYLOG(Warning, TEXT("TEST"));
}

void AMyGameModeBase::PostLogin(APlayerController* NewPlayer){
	MYLOG(Warning, TEXT("PostLogin Begin"));
	Super::PostLogin(NewPlayer);
	MYLOG(Warning, TEXT("PostLogin End"));
}