// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/EditableTextBox.h"
#include "Components/ScrollBox.h"
#include "ChatWidget.generated.h"

/**
 * 
 */
UCLASS()
class WIREHUNTER_API UChatWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;


private:
	UPROPERTY(Meta = (BindWidget))
		class UScrollBox* MessageList;
	UPROPERTY(Meta = (BindWidget))
		class UEditableTextBox* MessageForm;

	void MessageCommitted(const FText& Text, ETextCommit::Type CommitMethod);

};
