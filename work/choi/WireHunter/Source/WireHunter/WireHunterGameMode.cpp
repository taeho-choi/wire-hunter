// Copyright Epic Games, Inc. All Rights Reserved.

#include "WireHunterGameMode.h"
#include "WireHunterCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWireHunterGameMode::AWireHunterGameMode()
{
	// set default pawn class to our Blueprinted character
	///////////////////////////////////////////////////////////////////////Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/BP_WHCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
