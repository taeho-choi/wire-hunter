// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"//Àü¹æ
#include "EditorPlayerController.generated.h"

/**
 *
 */
UCLASS()
class AEditorPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AEditorPlayerController();

	virtual void OnPossess(APawn* InPawn) override;

	virtual void Tick(float DeltaTime) override;

	//UFUNCTION()
	void Click();

	void Release();

	UPROPERTY(VisibleAnywhere)
		UPhysicsHandleComponent* PhysicsHandle;

protected:
	virtual void SetupInputComponent() override;

private:
	float OriginalDistance;

	FHitResult Hit;

	bool GrabMode;

	FVector RelativeGrabLocation;

	UPrimitiveComponent* GrabbedComp;

	FName BoneName;
};