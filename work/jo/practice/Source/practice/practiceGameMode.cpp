// Copyright Epic Games, Inc. All Rights Reserved.

#include "practiceGameMode.h"
#include "practiceCharacter.h"
#include "UObject/ConstructorHelpers.h"

ApracticeGameMode::ApracticeGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
