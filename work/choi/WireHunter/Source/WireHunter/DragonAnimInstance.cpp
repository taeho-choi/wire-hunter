// Fill out your copyright notice in the Description page of Project Settings.

#include "DragonAnimInstance.h"
#include "Dragon.h"

UDragonAnimInstance::UDragonAnimInstance()
{
	bFirstBreathAnim = false;
	bSecondBreathAnim = false;
	bMeteorAnim = false;
}

void UDragonAnimInstance::NativeUpdateAnimation(float DeltaSecond)
{
	Super::NativeUpdateAnimation(DeltaSecond);

	auto Pawn = TryGetPawnOwner();
	if (::IsValid(Pawn))
	{
		auto Dragon = Cast<ADragon>(Pawn);

		bFirstBreathAnim = Dragon->GetFirstBreathTrigger();
		bSecondBreathAnim = Dragon->GetSecondBreathTrigger();
		bMeteorAnim = Dragon->GetMeteorTrigger();
	}
}