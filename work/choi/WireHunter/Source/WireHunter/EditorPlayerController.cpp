// Fill out your copyright notice in the Description page of Project Settings.

#include "EditorPlayerController.h"
#include "Kismet/KismetMathLibrary.h"
//#include "Components/SceneComponent.h"

void AEditorPlayerController::OnPossess(APawn* InPawn) {
	Super::OnPossess(InPawn);

	bShowMouseCursor = true;
	bEnableClickEvents = true;
	//DefaultMouseCursor = EMouseCursor::GrabHand;
	DefaultClickTraceChannel = ECollisionChannel::ECC_Visibility;
	HitResultTraceDistance = 10000.f;

	GrabMode = false;

	ConsoleCommand("ShowFlag.Bones 1");
}

void AEditorPlayerController::SetupInputComponent() {
	Super::SetupInputComponent();

	InputComponent->BindAction("Click", IE_Pressed, this, &AEditorPlayerController::Click);
	InputComponent->BindAction("Click", IE_Released, this, &AEditorPlayerController::Release);
}

void AEditorPlayerController::Tick(float DeltaTime) {
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

void AEditorPlayerController::Click() {
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

void AEditorPlayerController::Release() {
	if (GrabMode) {
		if (GrabbedComp->IsSimulatingPhysics()) {
			PhysicsHandle->ReleaseComponent();
		}
		GrabMode = false;

		UE_LOG(LogTemp, Warning, TEXT("%s \n"), *NewLocation.ToString());
	}
}