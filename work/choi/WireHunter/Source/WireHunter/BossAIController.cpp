// Fill out your copyright notice in the Description page of Project Settings.

#include "BossAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Dragon.h"

ABossAIController::ABossAIController()
{
	static ConstructorHelpers::FObjectFinder<UBlackboardData> BBObject(TEXT("BlackboardData'/Game/ThirdPersonCPP/AI/BB_Boss.BB_Boss'"));
	if (BBObject.Succeeded()) {
		BBAsset = BBObject.Object;
	}

	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BTObject(TEXT("BehaviorTree'/Game/ThirdPersonCPP/AI/BT_Boss.BT_Boss'"));
	if (BTObject.Succeeded()) {
		BTAsset = BTObject.Object;
	}
}

void ABossAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	RunBehaviorTree(BTAsset);

	Dragon = Cast<ADragon>(InPawn);

	BB = GetBlackboardComponent();
}

void ABossAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

	if (BB->GetValueAsBool("SetBreath"))
	{
		Dragon->BreathOnMulti();
	}

	if (!(BB->GetValueAsBool("SetBreath")))
	{
		Dragon->BreathOffMulti();
	}
}