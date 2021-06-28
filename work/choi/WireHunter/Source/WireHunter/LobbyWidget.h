// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "LobbyWidget.generated.h"

/**
 * 
 */
UCLASS()
class WIREHUNTER_API ULobbyWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;

private:
	UPROPERTY(Meta = (BindWidget))
		class UButton* CreateServerBtn;
	UPROPERTY(Meta = (BindWidget))
		class UButton* JoinServerBtn;

	UFUNCTION()
		void CreateServerHandler();
	UFUNCTION()
		void JoinServerHandler();
	
};
