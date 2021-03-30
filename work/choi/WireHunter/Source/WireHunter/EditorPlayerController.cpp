// Fill out your copyright notice in the Description page of Project Settings.

#include "EditorPlayerController.h"
#include "Kismet/KismetMathLibrary.h"
//#include "Components/SceneComponent.h"

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

			GrabbedComp->SetWorldLocation(NewLocation, false, false);

			if (AvatarHandle.Num() > 0) {
				AvatarHandle[0]->SetBoneLocationByName(BoneName, NewLocation, EBoneSpaces::WorldSpace);
			}
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

			//UE_LOG(LogTemp, Warning, TEXT("%s"), *AvatarHandle[0]->GetBoneLocation(BoneName).ToString());

			GrabbedComp->SetWorldLocation(AvatarHandle[0]->GetBoneLocation(BoneName), false, false);//to Sync
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

void AEditorPlayerController::AddYaw()
{
	if (AvatarHandle.Num() > 0) {
		auto rot = AvatarHandle[0]->GetBoneRotationByName(BoneName, EBoneSpaces::ComponentSpace);
		auto newRot = rot.Add(0.f, 0.f, RotVal);
		AvatarHandle[0]->SetBoneRotationByName(BoneName, newRot, EBoneSpaces::ComponentSpace);

		//GrabbedComp->SetWorldRotation(newRot);

		UE_LOG(LogTemp, Warning, TEXT("Bone: %s  Rotate: %s"), *BoneName.ToString(), *newRot.ToString());
	}
}

void AEditorPlayerController::SubYaw()
{
	if (AvatarHandle.Num() > 0) {
		auto rot = AvatarHandle[0]->GetBoneRotationByName(BoneName, EBoneSpaces::ComponentSpace);
		auto newRot = rot.Add(0.f, 0.f, -RotVal);
		AvatarHandle[0]->SetBoneRotationByName(BoneName, newRot, EBoneSpaces::ComponentSpace);

		//GrabbedComp->SetWorldRotation(newRot);

		UE_LOG(LogTemp, Warning, TEXT("Bone: %s  Rotate: %s"), *BoneName.ToString(), *newRot.ToString());
	}
}

void AEditorPlayerController::AddRoll()
{
	if (AvatarHandle.Num() > 0) {
		auto rot = AvatarHandle[0]->GetBoneRotationByName(BoneName, EBoneSpaces::ComponentSpace);
		auto newRot = rot.Add(RotVal, 0.f, 0.f);
		AvatarHandle[0]->SetBoneRotationByName(BoneName, newRot, EBoneSpaces::ComponentSpace);

		//GrabbedComp->SetWorldRotation(newRot);

		UE_LOG(LogTemp, Warning, TEXT("Bone: %s  Rotate: %s"), *BoneName.ToString(), *newRot.ToString());
	}
}

void AEditorPlayerController::SubRoll()
{
	if (AvatarHandle.Num() > 0) {
		auto rot = AvatarHandle[0]->GetBoneRotationByName(BoneName, EBoneSpaces::ComponentSpace);
		auto newRot = rot.Add(-RotVal, 0.f, 0.f);
		AvatarHandle[0]->SetBoneRotationByName(BoneName, newRot, EBoneSpaces::ComponentSpace);

		//GrabbedComp->SetWorldRotation(newRot);

		UE_LOG(LogTemp, Warning, TEXT("Bone: %s  Rotate: %s"), *BoneName.ToString(), *newRot.ToString());
	}
}

void AEditorPlayerController::AddPitch()
{
	if (AvatarHandle.Num() > 0) {
		auto rot = AvatarHandle[0]->GetBoneRotationByName(BoneName, EBoneSpaces::ComponentSpace);
		auto newRot = rot.Add(0.f, RotVal, 0.f);
		AvatarHandle[0]->SetBoneRotationByName(BoneName, newRot, EBoneSpaces::ComponentSpace);

		//GrabbedComp->SetWorldRotation(newRot);

		UE_LOG(LogTemp, Warning, TEXT("Bone: %s  Rotate: %s"), *BoneName.ToString(), *newRot.ToString());
	}
}

void AEditorPlayerController::SubPitch()
{
	if (AvatarHandle.Num() > 0) {
		auto rot = AvatarHandle[0]->GetBoneRotationByName(BoneName, EBoneSpaces::ComponentSpace);
		auto newRot = rot.Add(0.f, -RotVal, 0.f);
		AvatarHandle[0]->SetBoneRotationByName(BoneName, newRot, EBoneSpaces::ComponentSpace);

		//GrabbedComp->SetWorldRotation(newRot);

		UE_LOG(LogTemp, Warning, TEXT("Bone: %s  Rotate: %s"), *BoneName.ToString(), *newRot.ToString());
	}
}