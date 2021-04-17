// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BossAIController.generated.h"

/**
 * 
 */
UCLASS()
class WIREHUNTER_API ABossAIController : public AAIController
{
	GENERATED_BODY()

	void doBT();
};
