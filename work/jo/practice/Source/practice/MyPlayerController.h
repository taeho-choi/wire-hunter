// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "practice.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICE_API AMyPlayerController : public APlayerController{
	GENERATED_BODY()

public:
	virtual void PostInitializeComponents() override;
	virtual void OnPossess(APawn* InPawn) override;
};