// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthBar.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UHealthBar::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (!OwnerCharacter.IsValid())
		return;

	HealthBar->SetPercent(OwnerCharacter->GetHealth() / OwnerCharacter->GetMaxHealth());

	FNumberFormattingOptions Options;
	Options.SetMaximumFractionalDigits(0);
	CurrentHealthLabel->SetText(FText::AsNumber(OwnerCharacter->GetHealth(), &Options));
	MaxHealthLabel->SetText(FText::AsNumber(OwnerCharacter->GetMaxHealth(), &Options));
}