// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WireHunter/Boss.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBoss() {}
// Cross Module References
	WIREHUNTER_API UClass* Z_Construct_UClass_ABoss_NoRegister();
	WIREHUNTER_API UClass* Z_Construct_UClass_ABoss();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_WireHunter();
	WIREHUNTER_API UScriptStruct* Z_Construct_UScriptStruct_FStructNode();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	WIREHUNTER_API UClass* Z_Construct_UClass_ALightning_NoRegister();
	WIREHUNTER_API UClass* Z_Construct_UClass_AFireball_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ABoss::execDetectKick)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DetectKick();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABoss::execSetToFace)
	{
		P_GET_UBOOL(Z_Param_b);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetToFace(Z_Param_b);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABoss::execGetToFace)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetToFace();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABoss::execLightning)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Lightning();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABoss::execGetPath)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->GetPath();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABoss::execDoAStar)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FStructNode>*)Z_Param__Result=P_THIS->DoAStar();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABoss::execGetGoal)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->GetGoal();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABoss::execFindPlayer)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->FindPlayer();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABoss::execSpawn)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Spawn();
		P_NATIVE_END;
	}
	void ABoss::StaticRegisterNativesABoss()
	{
		UClass* Class = ABoss::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "DetectKick", &ABoss::execDetectKick },
			{ "DoAStar", &ABoss::execDoAStar },
			{ "FindPlayer", &ABoss::execFindPlayer },
			{ "GetGoal", &ABoss::execGetGoal },
			{ "GetPath", &ABoss::execGetPath },
			{ "GetToFace", &ABoss::execGetToFace },
			{ "Lightning", &ABoss::execLightning },
			{ "SetToFace", &ABoss::execSetToFace },
			{ "Spawn", &ABoss::execSpawn },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ABoss_DetectKick_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoss_DetectKick_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Boss.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABoss_DetectKick_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoss, nullptr, "DetectKick", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABoss_DetectKick_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoss_DetectKick_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABoss_DetectKick()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABoss_DetectKick_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABoss_DoAStar_Statics
	{
		struct Boss_eventDoAStar_Parms
		{
			TArray<FStructNode> ReturnValue;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_ABoss_DoAStar_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Boss_eventDoAStar_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ABoss_DoAStar_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FStructNode, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABoss_DoAStar_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABoss_DoAStar_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABoss_DoAStar_Statics::NewProp_ReturnValue_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoss_DoAStar_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Boss.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABoss_DoAStar_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoss, nullptr, "DoAStar", nullptr, nullptr, sizeof(Boss_eventDoAStar_Parms), Z_Construct_UFunction_ABoss_DoAStar_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoss_DoAStar_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABoss_DoAStar_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoss_DoAStar_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABoss_DoAStar()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABoss_DoAStar_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABoss_FindPlayer_Statics
	{
		struct Boss_eventFindPlayer_Parms
		{
			FVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ABoss_FindPlayer_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Boss_eventFindPlayer_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABoss_FindPlayer_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABoss_FindPlayer_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoss_FindPlayer_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Boss.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABoss_FindPlayer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoss, nullptr, "FindPlayer", nullptr, nullptr, sizeof(Boss_eventFindPlayer_Parms), Z_Construct_UFunction_ABoss_FindPlayer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoss_FindPlayer_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABoss_FindPlayer_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoss_FindPlayer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABoss_FindPlayer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABoss_FindPlayer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABoss_GetGoal_Statics
	{
		struct Boss_eventGetGoal_Parms
		{
			FVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ABoss_GetGoal_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Boss_eventGetGoal_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABoss_GetGoal_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABoss_GetGoal_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoss_GetGoal_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Boss.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABoss_GetGoal_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoss, nullptr, "GetGoal", nullptr, nullptr, sizeof(Boss_eventGetGoal_Parms), Z_Construct_UFunction_ABoss_GetGoal_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoss_GetGoal_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABoss_GetGoal_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoss_GetGoal_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABoss_GetGoal()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABoss_GetGoal_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABoss_GetPath_Statics
	{
		struct Boss_eventGetPath_Parms
		{
			FVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ABoss_GetPath_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Boss_eventGetPath_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABoss_GetPath_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABoss_GetPath_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoss_GetPath_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Boss.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABoss_GetPath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoss, nullptr, "GetPath", nullptr, nullptr, sizeof(Boss_eventGetPath_Parms), Z_Construct_UFunction_ABoss_GetPath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoss_GetPath_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABoss_GetPath_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoss_GetPath_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABoss_GetPath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABoss_GetPath_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABoss_GetToFace_Statics
	{
		struct Boss_eventGetToFace_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ABoss_GetToFace_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Boss_eventGetToFace_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ABoss_GetToFace_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(Boss_eventGetToFace_Parms), &Z_Construct_UFunction_ABoss_GetToFace_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABoss_GetToFace_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABoss_GetToFace_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoss_GetToFace_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Boss.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABoss_GetToFace_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoss, nullptr, "GetToFace", nullptr, nullptr, sizeof(Boss_eventGetToFace_Parms), Z_Construct_UFunction_ABoss_GetToFace_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoss_GetToFace_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABoss_GetToFace_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoss_GetToFace_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABoss_GetToFace()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABoss_GetToFace_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABoss_Lightning_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoss_Lightning_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Boss.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABoss_Lightning_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoss, nullptr, "Lightning", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABoss_Lightning_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoss_Lightning_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABoss_Lightning()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABoss_Lightning_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABoss_SetToFace_Statics
	{
		struct Boss_eventSetToFace_Parms
		{
			bool b;
		};
		static void NewProp_b_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_b;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ABoss_SetToFace_Statics::NewProp_b_SetBit(void* Obj)
	{
		((Boss_eventSetToFace_Parms*)Obj)->b = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ABoss_SetToFace_Statics::NewProp_b = { "b", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(Boss_eventSetToFace_Parms), &Z_Construct_UFunction_ABoss_SetToFace_Statics::NewProp_b_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABoss_SetToFace_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABoss_SetToFace_Statics::NewProp_b,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoss_SetToFace_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Boss.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABoss_SetToFace_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoss, nullptr, "SetToFace", nullptr, nullptr, sizeof(Boss_eventSetToFace_Parms), Z_Construct_UFunction_ABoss_SetToFace_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoss_SetToFace_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABoss_SetToFace_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoss_SetToFace_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABoss_SetToFace()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABoss_SetToFace_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABoss_Spawn_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABoss_Spawn_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Boss.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABoss_Spawn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoss, nullptr, "Spawn", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABoss_Spawn_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABoss_Spawn_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABoss_Spawn()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABoss_Spawn_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ABoss_NoRegister()
	{
		return ABoss::StaticClass();
	}
	struct Z_Construct_UClass_ABoss_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxHealth_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MaxHealth;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Health_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Health;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BossSkeletalMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BossSkeletalMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BossRoot_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BossRoot;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ToLightning_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_ToLightning;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ToSpawn_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_ToSpawn;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABoss_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_WireHunter,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ABoss_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ABoss_DetectKick, "DetectKick" }, // 849525677
		{ &Z_Construct_UFunction_ABoss_DoAStar, "DoAStar" }, // 2620057291
		{ &Z_Construct_UFunction_ABoss_FindPlayer, "FindPlayer" }, // 3511463183
		{ &Z_Construct_UFunction_ABoss_GetGoal, "GetGoal" }, // 1880045474
		{ &Z_Construct_UFunction_ABoss_GetPath, "GetPath" }, // 2772761924
		{ &Z_Construct_UFunction_ABoss_GetToFace, "GetToFace" }, // 2511376034
		{ &Z_Construct_UFunction_ABoss_Lightning, "Lightning" }, // 101482742
		{ &Z_Construct_UFunction_ABoss_SetToFace, "SetToFace" }, // 1928517047
		{ &Z_Construct_UFunction_ABoss_Spawn, "Spawn" }, // 1113780669
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoss_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Boss.h" },
		{ "ModuleRelativePath", "Boss.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoss_Statics::NewProp_MaxHealth_MetaData[] = {
		{ "Category", "Status" },
		{ "ModuleRelativePath", "Boss.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABoss_Statics::NewProp_MaxHealth = { "MaxHealth", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoss, MaxHealth), METADATA_PARAMS(Z_Construct_UClass_ABoss_Statics::NewProp_MaxHealth_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoss_Statics::NewProp_MaxHealth_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoss_Statics::NewProp_Health_MetaData[] = {
		{ "Category", "Status" },
		{ "Comment", "/*UPROPERTY(EditAnywhere)\n\x09\x09UShapeComponent* SphereCollision;*/" },
		{ "ModuleRelativePath", "Boss.h" },
		{ "ToolTip", "UPROPERTY(EditAnywhere)\n               UShapeComponent* SphereCollision;" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABoss_Statics::NewProp_Health = { "Health", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoss, Health), METADATA_PARAMS(Z_Construct_UClass_ABoss_Statics::NewProp_Health_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoss_Statics::NewProp_Health_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoss_Statics::NewProp_BossSkeletalMesh_MetaData[] = {
		{ "Category", "Boss" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Boss.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABoss_Statics::NewProp_BossSkeletalMesh = { "BossSkeletalMesh", nullptr, (EPropertyFlags)0x0020080000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoss, BossSkeletalMesh), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABoss_Statics::NewProp_BossSkeletalMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoss_Statics::NewProp_BossSkeletalMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoss_Statics::NewProp_BossRoot_MetaData[] = {
		{ "Category", "Boss" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Boss.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABoss_Statics::NewProp_BossRoot = { "BossRoot", nullptr, (EPropertyFlags)0x0020080000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoss, BossRoot), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABoss_Statics::NewProp_BossRoot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoss_Statics::NewProp_BossRoot_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoss_Statics::NewProp_ToLightning_MetaData[] = {
		{ "Category", "Boss" },
		{ "ModuleRelativePath", "Boss.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_ABoss_Statics::NewProp_ToLightning = { "ToLightning", nullptr, (EPropertyFlags)0x0024080000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoss, ToLightning), Z_Construct_UClass_ALightning_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ABoss_Statics::NewProp_ToLightning_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoss_Statics::NewProp_ToLightning_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoss_Statics::NewProp_ToSpawn_MetaData[] = {
		{ "Category", "Boss" },
		{ "ModuleRelativePath", "Boss.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_ABoss_Statics::NewProp_ToSpawn = { "ToSpawn", nullptr, (EPropertyFlags)0x0024080000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoss, ToSpawn), Z_Construct_UClass_AFireball_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ABoss_Statics::NewProp_ToSpawn_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoss_Statics::NewProp_ToSpawn_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABoss_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoss_Statics::NewProp_MaxHealth,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoss_Statics::NewProp_Health,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoss_Statics::NewProp_BossSkeletalMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoss_Statics::NewProp_BossRoot,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoss_Statics::NewProp_ToLightning,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoss_Statics::NewProp_ToSpawn,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABoss_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABoss>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABoss_Statics::ClassParams = {
		&ABoss::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ABoss_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ABoss_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ABoss_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABoss_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABoss()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABoss_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABoss, 2966761047);
	template<> WIREHUNTER_API UClass* StaticClass<ABoss>()
	{
		return ABoss::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABoss(Z_Construct_UClass_ABoss, &ABoss::StaticClass, TEXT("/Script/WireHunter"), TEXT("ABoss"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABoss);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
