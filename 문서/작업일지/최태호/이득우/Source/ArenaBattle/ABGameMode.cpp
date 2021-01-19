// Fill out your copyright notice in the Description page of Project Settings.


#include "ABGameMode.h"
#include "MyCharacter.h"
#include "ABPlayerController.h"

AABGameMode::AABGameMode()
{
	DefaultPawnClass = AMyCharacter::StaticClass();
	PlayerControllerClass = AABPlayerController::StaticClass();
}

