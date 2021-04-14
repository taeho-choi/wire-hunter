// Copyright Epic Games, Inc. All Rights Reserved.

#include "WireHunterGameMode.h"
#include "WireHunterCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWireHunterGameMode::AWireHunterGameMode()
{
	// set default pawn class to our Blueprinted character
<<<<<<< Updated upstream
	/*static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
=======
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Character/Blueprint/BP_WireHunterCharacter"));
>>>>>>> Stashed changes
	if (PlayerPawnBPClass.Class != NULL)
	{*/
		DefaultPawnClass = PlayerPawnBPClass.Class;
	/*}*/
}
