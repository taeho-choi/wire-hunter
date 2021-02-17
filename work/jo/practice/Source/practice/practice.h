// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "EngineMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(practice, Log, All);//to use UE_LOG
#define MYLOG_INFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))
#define MYLOG(Verbosity, ...) UE_LOG(practice, Verbosity, TEXT("%s %s"), *MYLOG_INFO, *FString::Printf(##__VA_ARGS__))
#define MYLOG_S(Verbosity) UE_LOG(practice, Verbosity, TEXT("%s"), *MYLOG_INFO)