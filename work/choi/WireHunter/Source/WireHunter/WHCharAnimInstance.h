// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "Animation/AnimInstance.h"
#include "WHCharAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class WIREHUNTER_API UWHCharAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UWHCharAnimInstance();
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
		bool HookStart;
};