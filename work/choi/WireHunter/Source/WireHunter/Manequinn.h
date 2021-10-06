// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Pawn.h"
#include "Manequinn.generated.h"

UCLASS()
class WIREHUNTER_API AManequinn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AManequinn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

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

	UFUNCTION(BlueprintCallable)
		FVector GetHeadLoc();

	UFUNCTION(BlueprintCallable)
		FVector GetRHandLoc();

	UFUNCTION(BlueprintCallable)
		FVector GetLHandLoc();

	UFUNCTION(BlueprintCallable)
		FVector GetRFootLoc();

	UFUNCTION(BlueprintCallable)
		FVector GetLFootLoc();



	UFUNCTION(BlueprintCallable)
		FRotator GetHeadRot();

	UFUNCTION(BlueprintCallable)
		FRotator GetRHandRot();

	UFUNCTION(BlueprintCallable)
		FRotator GetLHandRot();

	UFUNCTION(BlueprintCallable)
		FRotator GetRFootRot();

	UFUNCTION(BlueprintCallable)
		FRotator GetLFootRot();

	/// <summary>
	/// ////////////////////////////////////////////////
	/// </summary>

	UFUNCTION(BlueprintCallable)
		void SetHeadLoc(FVector newLoc);

	UFUNCTION(BlueprintCallable)
		void SetRHandLoc(FVector newLoc);

	UFUNCTION(BlueprintCallable)
		void SetLHandLoc(FVector newLoc);

	UFUNCTION(BlueprintCallable)
		void SetRFootLoc(FVector newLoc);

	UFUNCTION(BlueprintCallable)
		void SetLFootLoc(FVector newLoc);



	UFUNCTION(BlueprintCallable)
		void SetHeadRot(FRotator newRot);

	UFUNCTION(BlueprintCallable)
		void SetRHandRot(FRotator newRot);

	UFUNCTION(BlueprintCallable)
		void SetLHandRot(FRotator newRot);

	UFUNCTION(BlueprintCallable)
		void SetRFootRot(FRotator newRot);

	UFUNCTION(BlueprintCallable)
		void SetLFootRot(FRotator newRot);

};