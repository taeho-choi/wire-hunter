// Fill out your copyright notice in the Description page of Project Settings.

#include "EditorGameMode.h"
#include "EditorPlayerController.h"//to PC
#include "EditorPawn.h"

AEditorGameMode::AEditorGameMode() {
	PlayerControllerClass = AEditorPlayerController::StaticClass();
	DefaultPawnClass = AEditorPawn::StaticClass();

	//EditorPC�� �������� �����ϰڴٴ� ���� �ۼ�
	//�� PC�� ���콺�� ����� ��ȣ�ۿ� ����


}