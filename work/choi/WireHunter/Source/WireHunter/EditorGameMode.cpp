// Fill out your copyright notice in the Description page of Project Settings.

#include "EditorGameMode.h"
#include "EditorPlayerController.h"//to PC
#include "EditorPawn.h"

AEditorGameMode::AEditorGameMode() {
	PlayerControllerClass = AEditorPlayerController::StaticClass();
	DefaultPawnClass = AEditorPawn::StaticClass();

	//EditorPC를 유저에게 배정하겠다는 것을 작성
	//그 PC는 마우스로 월드와 상호작용 가능


}