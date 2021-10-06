// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Actor.h"
#include "EditorManequinn.generated.h"

UCLASS()
class WIREHUNTER_API AEditorManequinn : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEditorManequinn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	USkeletalMeshComponent* SK;

	/// <summary>
	/// ////////////////////////////
	/// </summary>

	UPROPERTY(EditAnywhere)
		FVector HeadLoc;

	UPROPERTY(EditAnywhere)
		FVector RHandLoc;

	UPROPERTY(EditAnywhere)
		FVector LHandLoc;

	UPROPERTY(EditAnywhere)
		FVector RFootLoc;

	UPROPERTY(EditAnywhere)
		FVector LFootLoc;



	UPROPERTY(EditAnywhere)
		FRotator HeadRot;

	UPROPERTY(EditAnywhere)
		FRotator RHandRot;

	UPROPERTY(EditAnywhere)
		FRotator LHandRot;

	UPROPERTY(EditAnywhere)
		FRotator RFootRot;

	UPROPERTY(EditAnywhere)
		FRotator LFootRot;

	/// <summary>
	/// //////////////////////////////////////
	/// </summary>

	UFUNCTION()
	FVector GetHeadLoc() { return HeadLoc; }

	UFUNCTION()
		FVector GetRHandLoc() { return RHandLoc; }

	UFUNCTION()
		FVector GetLHandLoc() { return LHandLoc; }

	UFUNCTION()
		FVector GetRFootLoc() { return RFootLoc; }

	UFUNCTION()
		FVector GetLFootLoc() { return LFootLoc; }



	UFUNCTION()
		FRotator GetHeadRot() { return HeadRot; }

	UFUNCTION()
		FRotator GetRHandRot() { return RHandRot; }

	UFUNCTION()
		FRotator GetLHandRot() { return LHandRot; }

	UFUNCTION()
		FRotator GetRFootRot() { return RFootRot; }

	UFUNCTION()
		FRotator GetLFootRot() { return LFootRot; }

	/// <summary>
	/// ////////////////////////////////////////////////
	/// </summary>

	UFUNCTION()
		void SetHeadLoc(FVector newLoc) { HeadLoc = newLoc; }

	UFUNCTION()
		void SetRHandLoc(FVector newLoc) { RHandLoc = newLoc; }

	UFUNCTION()
		void SetLHandLoc(FVector newLoc) { LHandLoc = newLoc; }

	UFUNCTION()
		void SetRFootLoc(FVector newLoc) { RFootLoc = newLoc; }

	UFUNCTION()
		void SetLFootLoc(FVector newLoc) { LFootLoc = newLoc;}



	UFUNCTION()
		void SetHeadRot(FRotator newRot) { HeadRot = newRot; }

	UFUNCTION()
		void SetRHandRot(FRotator newRot) { RHandRot = newRot; }

	UFUNCTION()
		void SetLHandRot(FRotator newRot) { LHandRot = newRot; }

	UFUNCTION()
		void SetRFootRot(FRotator newRot) { RFootRot = newRot; }

	UFUNCTION()
		void SetLFootRot(FRotator newRot) { LFootRot = newRot; }
};