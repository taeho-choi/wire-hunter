// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyPlayerController.h"
#include "Kismet/GameplayStatics.h"

void ALobbyPlayerController::CreateServer()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("GameLevel"), true, ((FString)(L"Listen")));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Press CreateServer"));
}

void ALobbyPlayerController::JoinServer()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("192.168.219.110")); // Level �̸� ��� IP �ּ�.
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Press JoinServer"));
}