// Fill out your copyright notice in the Description page of Project Settings.

#include "EditorGameMode.h"
#include "EditorPlayerController.h"//to PC

AEditorGameMode::AEditorGameMode() {
	PlayerControllerClass = AEditorPlayerController::StaticClass();

	//EditorPC�� �������� �����ϰڴٴ� ���� �ۼ�
	//�� PC�� ���콺�� ����� ��ȣ�ۿ� ����


}