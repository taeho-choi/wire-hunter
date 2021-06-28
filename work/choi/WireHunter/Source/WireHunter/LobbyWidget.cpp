// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyWidget.h"
#include "Kismet/GameplayStatics.h"
#include "LobbyPlayerController.h"
#include "Kismet/GameplayStatics.h"

void ULobbyWidget::NativeConstruct()
{
	Super::NativeConstruct();

	CreateServerBtn->OnClicked.AddDynamic(this, &ULobbyWidget::CreateServerHandler);
	JoinServerBtn->OnClicked.AddDynamic(this, &ULobbyWidget::JoinServerHandler);
}

void ULobbyWidget::CreateServerHandler()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("GameLevel"), true, ((FString)(L"Listen")));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Press CreateServer"));

	//ALobbyPlayerController* PC = Cast<ALobbyPlayerController>(GetOwningPlayer());
	//if (PC)
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Falling"));
	//	PC->CreateServer();
	//}
}

void ULobbyWidget::JoinServerHandler()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("124.57.148.59")); // Level 이름 대신 IP 주소.
	//ALobbyPlayerController* PC = Cast<ALobbyPlayerController>(GetOwningPlayer());
	//if (PC)
	//{
	//	PC->JoinServer();
	//}
}