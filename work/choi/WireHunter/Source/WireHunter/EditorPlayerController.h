// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EditorPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class WIREHUNTER_API AEditorPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void OnPossess(APawn* InPawn) override;
	
	float OriginalDistance;

	FHitResult Hit;

	virtual void Tick(float DeltaTime) override;
};
