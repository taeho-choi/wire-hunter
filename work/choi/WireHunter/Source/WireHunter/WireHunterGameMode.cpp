// Copyright Epic Games, Inc. All Rights Reserved.

#include "WireHunterGameMode.h"
#include "WireHunterCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWireHunterGameMode::AWireHunterGameMode()
{
	// set default pawn class to our Blueprinted character
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("Blueprint'/Game/ThirdPersonCPP/Blueprints/BP_WHCharacter.BP_WHCharacter'"));
	//if (PlayerPawnBPClass.Class != NULL)
	//{
	//	DefaultPawnClass = PlayerPawnBPClass.Class;
	//}


}
