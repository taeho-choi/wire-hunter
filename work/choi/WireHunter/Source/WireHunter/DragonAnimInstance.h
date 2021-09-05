// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "Animation/AnimInstance.h"
#include "DragonAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class WIREHUNTER_API UDragonAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UDragonAnimInstance();

	virtual void NativeUpdateAnimation(float DeltaSecond) override;
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Meta = (AllowPrivateAccess = true))
		bool bFirstBreathAnim;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Meta = (AllowPrivateAccess = true))
		bool bSecondBreathAnim;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Meta = (AllowPrivateAccess = true))
		bool bMeteorAnim;
};
