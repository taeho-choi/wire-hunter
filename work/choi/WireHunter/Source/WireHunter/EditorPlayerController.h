// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"//Àü¹æ
#include "Components/PoseableMeshComponent.h"

#include "EditorPlayerController.generated.h"

UCLASS()
class AEditorPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	struct BoneNode
	{
	public:
		FString boneName;
		FVector location;
	};

public:
	AEditorPlayerController();

	virtual void OnPossess(APawn* InPawn) override;

	virtual void Tick(float DeltaTime) override;

	//UFUNCTION()
	void Click();

	void Release();

	/*void AddYaw();

	void AddRoll();

	void AddPitch();

	void SubYaw();

	void SubRoll();

	void SubPitch();

	void Undo();

	BoneNode MakeBoneNode(FString boneName, FVector location);*/

protected:
	virtual void SetupInputComponent() override;

private:
	UPhysicsHandleComponent* PhysicsHandle;

	float OriginalDistance;

	FHitResult Hit;

	bool GrabMode;

	FVector RelativeGrabLocation;

	UPrimitiveComponent* GrabbedComp;

	FName BoneName;

	FVector NewLocation;

	class AManequinn* GrabbedActor;

	TArray<UPoseableMeshComponent*> AvatarHandle;

	TSet<FString> Bones = { 
	FString("Bip001-Head"), FString("Bip001-R-Hand"), FString("Bip001-L-Hand"), FString("Bip001-R-Foot"), FString("Bip001-L-Foot"),
	};

	float RotVal = 2.f;

	const int BoneNum = 17;

	TArray<TArray<BoneNode>> BoneTree;

	TArray<FTransform> PrevBoneTransforms;
	TArray<FName> PrevBoneNames;
	TArray<UPrimitiveComponent*> PrevGrabbedComps;
};