// Copyright Epic Games, Inc. All Rights Reserved.

#include "WireHunterGameMode.h"
#include "WireHunterCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "MyPlayerController.h"

AWireHunterGameMode::AWireHunterGameMode()
{
	PlayerControllerClass = AMyPlayerController::StaticClass();

	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/BP_WHCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	/*DefaultPawnClass = AWireHunterCharacter::StaticClass();*/
}