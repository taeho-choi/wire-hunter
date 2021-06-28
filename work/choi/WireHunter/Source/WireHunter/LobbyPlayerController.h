// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LobbyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class WIREHUNTER_API ALobbyPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	void CreateServer();
	void JoinServer();
};