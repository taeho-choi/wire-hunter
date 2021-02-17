// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "practice.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class PRACTICE_API UMyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public :
	UMyAnimInstance();
	virtual void NativeUpdateAnimation(float DeltaSeconds) override; 

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, category = Pawn, Meta = (AllowPrivateAccess = true))
	float CurrentPawnSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, category = Pawn, Meta = (AllowPrivateAccess = true))
	bool IsInAir;
};
