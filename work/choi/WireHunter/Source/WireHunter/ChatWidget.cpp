// Fill out your copyright notice in the Description page of Project Settings.


#include "ChatWidget.h"

void UChatWidget::NativeConstruct()
{
	Super::NativeConstruct();

	MessageForm->OnTextCommitted.AddDynamic(this, &UChatWidget::MessageCommitted);

}

void UChatWidget::MessageCommitted(const FText& Text, ETextCommit::Type CommitMethod)
{

}