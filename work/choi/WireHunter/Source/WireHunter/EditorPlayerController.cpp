// Fill out your copyright notice in the Description page of Project Settings.

#include "EditorPlayerController.h"
#include "Kismet/KismetMathLibrary.h"
//#include "Components/SceneComponent.h"
//#include <algorithm>
#include "Rendering/SkeletalMeshRenderData.h"

//BoneNode AEditorPlayerController::MakeBoneNode(FString boneName, FVector location)
//{
//
//}

AEditorPlayerController::AEditorPlayerController()
{
	//BoneTree[0].Push(BoneNode(FString("pelvis"), FVector(0.f, 0.f, 0.f)));
}

void AEditorPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	bShowMouseCursor = true;
	bEnableClickEvents = true;
	//DefaultMouseCursor = EMouseCursor::GrabHand;
	DefaultClickTraceChannel = ECollisionChannel::ECC_Visibility;
	HitResultTraceDistance = 10000.f;

	GrabMode = false;

	ConsoleCommand("ShowFlag.Bones 1");
}

void AEditorPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Click", IE_Pressed, this, &AEditorPlayerController::Click);
	InputComponent->BindAction("Click", IE_Released, this, &AEditorPlayerController::Release);

	InputComponent->BindAction(TEXT("AddYaw"), IE_Pressed, this, &AEditorPlayerController::AddYaw);
	InputComponent->BindAction(TEXT("AddRoll"), IE_Pressed, this, &AEditorPlayerController::AddRoll);
	InputComponent->BindAction(TEXT("AddPitch"), IE_Pressed, this, &AEditorPlayerController::AddPitch);

	InputComponent->BindAction(TEXT("SubYaw"), IE_Pressed, this, &AEditorPlayerController::SubYaw);
	InputComponent->BindAction(TEXT("SubRoll"), IE_Pressed, this, &AEditorPlayerController::SubRoll);
	InputComponent->BindAction(TEXT("SubPitch"), IE_Pressed, this, &AEditorPlayerController::SubPitch);

	InputComponent->BindAction(TEXT("Undo"), IE_Pressed, this, &AEditorPlayerController::Undo);
}

void AEditorPlayerController::Tick(float DeltaTime)
{
	if (GrabMode) {
		FVector WorldLocation, WorldDirection;
		DeprojectMousePositionToWorld(WorldLocation, WorldDirection);

		auto TempLocation = WorldDirection * OriginalDistance + WorldLocation;
		auto TempT = RelativeGrabLocation;

		if (GrabbedComp->IsSimulatingPhysics()) {
			PhysicsHandle->SetTargetLocation(TempLocation);
		}
		else {
			NewLocation = UKismetMathLibrary::InverseTransformLocation(FTransform(TempT), TempLocation);

			if (AvatarHandle.Num() > 0) {
				AvatarHandle[0]->SetBoneLocationByName(BoneName, NewLocation, EBoneSpaces::WorldSpace);
			}
			GrabbedComp->SetWorldLocation(NewLocation, false, false);
		}
	}
}

void AEditorPlayerController::Click()
{
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);

	if (Hit.bBlockingHit) {
		GrabMode = true;

		OriginalDistance = Hit.Distance;

		GrabbedComp = Hit.GetComponent();

		BoneName = FName(Hit.GetActor()->GetName());

		UE_LOG(LogTemp, Warning, TEXT("Bone: %s"), *BoneName.ToString());

		if (Bones.Contains(*BoneName.ToString())) {
			auto avatar = Hit.GetActor()->GetAttachParentActor();
			avatar->GetComponents(AvatarHandle);

			GrabbedComp->SetWorldLocation(AvatarHandle[0]->GetBoneLocationByName(BoneName, EBoneSpaces::WorldSpace));//to Sync
			GrabbedComp->SetWorldRotation(AvatarHandle[0]->GetBoneRotationByName(BoneName, EBoneSpaces::WorldSpace));

			PrevBoneTransforms.Push(AvatarHandle[0]->GetBoneTransformByName(BoneName, EBoneSpaces::WorldSpace));
			PrevBoneNames.Push(BoneName);
			PrevGrabbedComps.Push(GrabbedComp);

			FSkeletalMeshRenderData* renderData = AvatarHandle[0]->GetSkeletalMeshRenderData();
			//FSkeletalMeshLODRenderData
			
			for (int32 LODIndex = 0; LODIndex < renderData->LODRenderData.Num(); ++LODIndex)
			{
				for (uint32 Index = 0; Index < renderData->LODRenderData[LODIndex].SkinWeightVertexBuffer.GetNumVertices(); ++Index)
				{
					//GetBoneWeight;
					renderData->LODRenderData[LODIndex].SkinWeightVertexBuffer.ResetVertexBoneWeights(Index);
				}
			}
		}

		if (GrabbedComp->IsSimulatingPhysics()) {
			PhysicsHandle->GrabComponentAtLocation(GrabbedComp, BoneName, (FVector)Hit.Location);
		}
		else {
			auto TmpLocation = (FVector)Hit.Location;

			auto TmpT = GrabbedComp->GetComponentLocation();

			RelativeGrabLocation = UKismetMathLibrary::InverseTransformLocation(FTransform(TmpT), TmpLocation);
		}
	}
}

void AEditorPlayerController::Release()
{
	if (GrabMode) {
		if (GrabbedComp->IsSimulatingPhysics()) {
			PhysicsHandle->ReleaseComponent();
		}
		GrabMode = false;

		UE_LOG(LogTemp, Warning, TEXT("%s \n"), *NewLocation.ToString());
	}
}

void AEditorPlayerController::AddYaw()//1
{
	if (AvatarHandle.Num() > 0) {
		auto rot = AvatarHandle[0]->GetBoneRotationByName(BoneName, EBoneSpaces::WorldSpace);
		auto newRot = rot.Add(0.f, 0.f, RotVal);

		AvatarHandle[0]->SetBoneRotationByName(BoneName, newRot, EBoneSpaces::WorldSpace);
		GrabbedComp->SetWorldRotation(newRot);

		PrevBoneTransforms.Push(AvatarHandle[0]->GetBoneTransformByName(BoneName, EBoneSpaces::WorldSpace));
		PrevBoneNames.Push(BoneName);
		PrevGrabbedComps.Push(GrabbedComp);

		UE_LOG(LogTemp, Warning, TEXT("Bone: %s  Rotate: %s"), *BoneName.ToString(), *newRot.ToString());
	}
}

void AEditorPlayerController::SubYaw()//2
{
	if (AvatarHandle.Num() > 0) {
		auto rot = AvatarHandle[0]->GetBoneRotationByName(BoneName, EBoneSpaces::WorldSpace);
		auto newRot = rot.Add(0.f, 0.f, -RotVal);

		AvatarHandle[0]->SetBoneRotationByName(BoneName, newRot, EBoneSpaces::WorldSpace);
		GrabbedComp->SetWorldRotation(newRot);

		PrevBoneTransforms.Push(AvatarHandle[0]->GetBoneTransformByName(BoneName, EBoneSpaces::WorldSpace));
		PrevBoneNames.Push(BoneName);
		PrevGrabbedComps.Push(GrabbedComp);

		UE_LOG(LogTemp, Warning, TEXT("Bone: %s  Rotate: %s"), *BoneName.ToString(), *newRot.ToString());
	}
}

void AEditorPlayerController::AddRoll()//3
{
	if (AvatarHandle.Num() > 0) {
		auto rot = AvatarHandle[0]->GetBoneRotationByName(BoneName, EBoneSpaces::WorldSpace);
		auto newRot = rot.Add(RotVal, 0.f, 0.f);

		AvatarHandle[0]->SetBoneRotationByName(BoneName, newRot, EBoneSpaces::WorldSpace);
		GrabbedComp->SetWorldRotation(newRot);

		PrevBoneTransforms.Push(AvatarHandle[0]->GetBoneTransformByName(BoneName, EBoneSpaces::WorldSpace));
		PrevBoneNames.Push(BoneName);
		PrevGrabbedComps.Push(GrabbedComp);

		UE_LOG(LogTemp, Warning, TEXT("Bone: %s  Rotate: %s"), *BoneName.ToString(), *newRot.ToString());
	}
}

void AEditorPlayerController::SubRoll()//4
{
	if (AvatarHandle.Num() > 0) {
		auto rot = AvatarHandle[0]->GetBoneRotationByName(BoneName, EBoneSpaces::WorldSpace);
		auto newRot = rot.Add(-RotVal, 0.f, 0.f);

		AvatarHandle[0]->SetBoneRotationByName(BoneName, newRot, EBoneSpaces::WorldSpace);
		GrabbedComp->SetWorldRotation(newRot);

		PrevBoneTransforms.Push(AvatarHandle[0]->GetBoneTransformByName(BoneName, EBoneSpaces::WorldSpace));
		PrevBoneNames.Push(BoneName);
		PrevGrabbedComps.Push(GrabbedComp);

		UE_LOG(LogTemp, Warning, TEXT("Bone: %s  Rotate: %s"), *BoneName.ToString(), *newRot.ToString());
	}
}

void AEditorPlayerController::AddPitch()//5
{
	if (AvatarHandle.Num() > 0) {
		auto rot = AvatarHandle[0]->GetBoneRotationByName(BoneName, EBoneSpaces::WorldSpace);
		auto newRot = rot.Add(0.f, RotVal, 0.f);

		AvatarHandle[0]->SetBoneRotationByName(BoneName, newRot, EBoneSpaces::WorldSpace);
		GrabbedComp->SetWorldRotation(newRot);

		PrevBoneTransforms.Push(AvatarHandle[0]->GetBoneTransformByName(BoneName, EBoneSpaces::WorldSpace));
		PrevBoneNames.Push(BoneName);
		PrevGrabbedComps.Push(GrabbedComp);

		UE_LOG(LogTemp, Warning, TEXT("Bone: %s  Rotate: %s"), *BoneName.ToString(), *newRot.ToString());
	}
}

void AEditorPlayerController::SubPitch()//6
{
	if (AvatarHandle.Num() > 0) {
		auto rot = AvatarHandle[0]->GetBoneRotationByName(BoneName, EBoneSpaces::WorldSpace);
		auto newRot = rot.Add(0.f, -RotVal, 0.f);

		AvatarHandle[0]->SetBoneRotationByName(BoneName, newRot, EBoneSpaces::WorldSpace);
		GrabbedComp->SetWorldRotation(newRot);

		PrevBoneTransforms.Push(AvatarHandle[0]->GetBoneTransformByName(BoneName, EBoneSpaces::WorldSpace));
		PrevBoneNames.Push(BoneName);
		PrevGrabbedComps.Push(GrabbedComp);

		UE_LOG(LogTemp, Warning, TEXT("Bone: %s  Rotate: %s"), *BoneName.ToString(), *newRot.ToString());
	}
}

void AEditorPlayerController::Undo()//num0
{
	if (AvatarHandle.Num() > 0 && PrevBoneTransforms.Num() != 0) {
		auto b = PrevBoneNames.Pop();
		AvatarHandle[0]->SetBoneTransformByName(b, PrevBoneTransforms.Pop(), EBoneSpaces::WorldSpace);

		PrevGrabbedComps.Pop()->SetWorldLocationAndRotation(AvatarHandle[0]->GetBoneLocationByName(b, EBoneSpaces::WorldSpace),
			AvatarHandle[0]->GetBoneRotationByName(b, EBoneSpaces::WorldSpace));

		UE_LOG(LogTemp, Warning, TEXT("Undo %d"),PrevBoneNames.Num());
	}
}