// Fill out your copyright notice in the Description page of Project Settings.

#include "WHCharAnimInstance.h"
#include "WireHunterCharacter.h"
#include "Manequinn.h"

UWHCharAnimInstance::UWHCharAnimInstance()
{
	HookStart = false;
}

void UWHCharAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner();
	if (::IsValid(Pawn)) {
		auto Char = Cast<AWireHunterCharacter>(Pawn);

		HookStart = Char->GetHookStart();

		HeadLoc = Char->GetHeadLoc();
		RHandLoc = Char->GetRHandLoc();
		LHandLoc = Char->GetLHandLoc();
		RFootLoc = Char->GetRFootLoc();
		LFootLoc = Char->GetLFootLoc();
	}
}