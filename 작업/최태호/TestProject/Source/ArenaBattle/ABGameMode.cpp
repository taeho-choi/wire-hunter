// Fill out your copyright notice in the Description page of Project Settings.


#include "ABGameMode.h"
#include "MyCharacter.h"
#include "ABPlayerController.h"

AABGameMode::AABGameMode()
{
	FString path = L"";
	path = L"Blueprint'/Game/Blueprints/MyCharacter_BP.MyCharacter_BP_C'";
	ConstructorHelpers::FClassFinder<APawn>player(*path);
	if (player.Succeeded())
	{
		DefaultPawnClass = player.Class;
	}
	//DefaultPawnClass = AMyCharacter::StaticClass();
	//DefaultPawnClass = AMyCharacter::StaticClass();
	PlayerControllerClass = AABPlayerController::StaticClass();
}

