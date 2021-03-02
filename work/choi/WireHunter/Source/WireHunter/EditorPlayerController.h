// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EditorPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class AEditorPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void OnPossess(APawn* InPawn) override;

	virtual void Tick(float DeltaTime) override;

	float GetOriginalDistance();

	FHitResult GetHit();

	bool GetGrabMode();

	//UFUNCTION()
	void Click();

	void Release();

	FVector GetRelativeGrabLocation();

protected:
	virtual void SetupInputComponent() override;

private:
	float OriginalDistance;

	FHitResult Hit;

	bool GrabMode;

	FVector RelativeGrabLocation;

	UPrimitiveComponent* GrabbedComp;
};