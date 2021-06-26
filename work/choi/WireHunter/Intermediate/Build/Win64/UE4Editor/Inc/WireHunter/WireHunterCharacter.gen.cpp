// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WireHunter/WireHunterCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWireHunterCharacter() {}
// Cross Module References
	WIREHUNTER_API UClass* Z_Construct_UClass_AWireHunterCharacter_NoRegister();
	WIREHUNTER_API UClass* Z_Construct_UClass_AWireHunterCharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_WireHunter();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AController_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FDamageEvent();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	WIREHUNTER_API UClass* Z_Construct_UClass_ABullet_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	ENGINE_API UClass* Z_Construct_UClass_UParticleSystem_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperSpriteComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneCaptureComponent2D_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UPointLightComponent_NoRegister();
	CABLECOMPONENT_API UClass* Z_Construct_UClass_UCableComponent_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UWidgetComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AWireHunterCharacter::execOnRep_CurrentHealth)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnRep_CurrentHealth();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AWireHunterCharacter::execTakeDamage)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_DamageTaken);
		P_GET_STRUCT_REF(FDamageEvent,Z_Param_Out_DamageEvent);
		P_GET_OBJECT(AController,Z_Param_EventInstigator);
		P_GET_OBJECT(AActor,Z_Param_DamageCauser);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->TakeDamage(Z_Param_DamageTaken,Z_Param_Out_DamageEvent,Z_Param_EventInstigator,Z_Param_DamageCauser);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AWireHunterCharacter::execGetMaxHealth)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetMaxHealth();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AWireHunterCharacter::execSetHealth)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_healthValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetHealth(Z_Param_healthValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AWireHunterCharacter::execGetHealth)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetHealth();
		P_NATIVE_END;
	}
	void AWireHunterCharacter::StaticRegisterNativesAWireHunterCharacter()
	{
		UClass* Class = AWireHunterCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetHealth", &AWireHunterCharacter::execGetHealth },
			{ "GetMaxHealth", &AWireHunterCharacter::execGetMaxHealth },
			{ "OnRep_CurrentHealth", &AWireHunterCharacter::execOnRep_CurrentHealth },
			{ "SetHealth", &AWireHunterCharacter::execSetHealth },
			{ "TakeDamage", &AWireHunterCharacter::execTakeDamage },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AWireHunterCharacter_GetHealth_Statics
	{
		struct WireHunterCharacter_eventGetHealth_Parms
		{
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AWireHunterCharacter_GetHealth_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(WireHunterCharacter_eventGetHealth_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AWireHunterCharacter_GetHealth_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWireHunterCharacter_GetHealth_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AWireHunterCharacter_GetHealth_Statics::Function_MetaDataParams[] = {
		{ "Category", "Health" },
		{ "Comment", "// Character's Status\n" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
		{ "ToolTip", "Character's Status" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AWireHunterCharacter_GetHealth_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AWireHunterCharacter, nullptr, "GetHealth", nullptr, nullptr, sizeof(WireHunterCharacter_eventGetHealth_Parms), Z_Construct_UFunction_AWireHunterCharacter_GetHealth_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AWireHunterCharacter_GetHealth_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AWireHunterCharacter_GetHealth_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AWireHunterCharacter_GetHealth_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AWireHunterCharacter_GetHealth()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AWireHunterCharacter_GetHealth_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AWireHunterCharacter_GetMaxHealth_Statics
	{
		struct WireHunterCharacter_eventGetMaxHealth_Parms
		{
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AWireHunterCharacter_GetMaxHealth_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(WireHunterCharacter_eventGetMaxHealth_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AWireHunterCharacter_GetMaxHealth_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWireHunterCharacter_GetMaxHealth_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AWireHunterCharacter_GetMaxHealth_Statics::Function_MetaDataParams[] = {
		{ "Category", "Health" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AWireHunterCharacter_GetMaxHealth_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AWireHunterCharacter, nullptr, "GetMaxHealth", nullptr, nullptr, sizeof(WireHunterCharacter_eventGetMaxHealth_Parms), Z_Construct_UFunction_AWireHunterCharacter_GetMaxHealth_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AWireHunterCharacter_GetMaxHealth_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AWireHunterCharacter_GetMaxHealth_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AWireHunterCharacter_GetMaxHealth_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AWireHunterCharacter_GetMaxHealth()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AWireHunterCharacter_GetMaxHealth_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AWireHunterCharacter_OnRep_CurrentHealth_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AWireHunterCharacter_OnRep_CurrentHealth_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//R\n" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
		{ "ToolTip", "R" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AWireHunterCharacter_OnRep_CurrentHealth_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AWireHunterCharacter, nullptr, "OnRep_CurrentHealth", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AWireHunterCharacter_OnRep_CurrentHealth_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AWireHunterCharacter_OnRep_CurrentHealth_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AWireHunterCharacter_OnRep_CurrentHealth()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AWireHunterCharacter_OnRep_CurrentHealth_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AWireHunterCharacter_SetHealth_Statics
	{
		struct WireHunterCharacter_eventSetHealth_Parms
		{
			float healthValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_healthValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AWireHunterCharacter_SetHealth_Statics::NewProp_healthValue = { "healthValue", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(WireHunterCharacter_eventSetHealth_Parms, healthValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AWireHunterCharacter_SetHealth_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWireHunterCharacter_SetHealth_Statics::NewProp_healthValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AWireHunterCharacter_SetHealth_Statics::Function_MetaDataParams[] = {
		{ "Category", "Health" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AWireHunterCharacter_SetHealth_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AWireHunterCharacter, nullptr, "SetHealth", nullptr, nullptr, sizeof(WireHunterCharacter_eventSetHealth_Parms), Z_Construct_UFunction_AWireHunterCharacter_SetHealth_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AWireHunterCharacter_SetHealth_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AWireHunterCharacter_SetHealth_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AWireHunterCharacter_SetHealth_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AWireHunterCharacter_SetHealth()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AWireHunterCharacter_SetHealth_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AWireHunterCharacter_TakeDamage_Statics
	{
		struct WireHunterCharacter_eventTakeDamage_Parms
		{
			float DamageTaken;
			FDamageEvent DamageEvent;
			AController* EventInstigator;
			AActor* DamageCauser;
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DamageCauser;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_EventInstigator;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DamageEvent_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_DamageEvent;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DamageTaken;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AWireHunterCharacter_TakeDamage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(WireHunterCharacter_eventTakeDamage_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AWireHunterCharacter_TakeDamage_Statics::NewProp_DamageCauser = { "DamageCauser", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(WireHunterCharacter_eventTakeDamage_Parms, DamageCauser), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AWireHunterCharacter_TakeDamage_Statics::NewProp_EventInstigator = { "EventInstigator", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(WireHunterCharacter_eventTakeDamage_Parms, EventInstigator), Z_Construct_UClass_AController_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AWireHunterCharacter_TakeDamage_Statics::NewProp_DamageEvent_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AWireHunterCharacter_TakeDamage_Statics::NewProp_DamageEvent = { "DamageEvent", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(WireHunterCharacter_eventTakeDamage_Parms, DamageEvent), Z_Construct_UScriptStruct_FDamageEvent, METADATA_PARAMS(Z_Construct_UFunction_AWireHunterCharacter_TakeDamage_Statics::NewProp_DamageEvent_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AWireHunterCharacter_TakeDamage_Statics::NewProp_DamageEvent_MetaData)) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AWireHunterCharacter_TakeDamage_Statics::NewProp_DamageTaken = { "DamageTaken", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(WireHunterCharacter_eventTakeDamage_Parms, DamageTaken), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AWireHunterCharacter_TakeDamage_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWireHunterCharacter_TakeDamage_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWireHunterCharacter_TakeDamage_Statics::NewProp_DamageCauser,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWireHunterCharacter_TakeDamage_Statics::NewProp_EventInstigator,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWireHunterCharacter_TakeDamage_Statics::NewProp_DamageEvent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWireHunterCharacter_TakeDamage_Statics::NewProp_DamageTaken,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AWireHunterCharacter_TakeDamage_Statics::Function_MetaDataParams[] = {
		{ "Category", "Health" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AWireHunterCharacter_TakeDamage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AWireHunterCharacter, nullptr, "TakeDamage", nullptr, nullptr, sizeof(WireHunterCharacter_eventTakeDamage_Parms), Z_Construct_UFunction_AWireHunterCharacter_TakeDamage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AWireHunterCharacter_TakeDamage_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AWireHunterCharacter_TakeDamage_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AWireHunterCharacter_TakeDamage_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AWireHunterCharacter_TakeDamage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AWireHunterCharacter_TakeDamage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AWireHunterCharacter_NoRegister()
	{
		return AWireHunterCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AWireHunterCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_cppHooked_MetaData[];
#endif
		static void NewProp_cppHooked_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_cppHooked;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ProjectileClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_ProjectileClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MuzzleOffset_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_MuzzleOffset;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Hooked_MetaData[];
#endif
		static void NewProp_Hooked_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Hooked;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LockLeftClimb_MetaData[];
#endif
		static void NewProp_LockLeftClimb_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_LockLeftClimb;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LockRightClimb_MetaData[];
#endif
		static void NewProp_LockRightClimb_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_LockRightClimb;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WallRightVector_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_WallRightVector;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WallUpVector_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_WallUpVector;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_isBulletEmpty_MetaData[];
#endif
		static void NewProp_isBulletEmpty_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isBulletEmpty;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_isWithdrawing_MetaData[];
#endif
		static void NewProp_isWithdrawing_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isWithdrawing;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_isLedgeClimbing_MetaData[];
#endif
		static void NewProp_isLedgeClimbing_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isLedgeClimbing;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_isClimbing_MetaData[];
#endif
		static void NewProp_isClimbing_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isClimbing;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FloatingRot_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_FloatingRot;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FloatingPos_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_FloatingPos;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MoveRightValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_MoveRightValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MoveForwardValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_MoveForwardValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Bullets_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Bullets;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxBullets_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_MaxBullets;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxHealth_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MaxHealth;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Health_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Health;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BaseLookUpRate_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BaseLookUpRate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BaseTurnRate_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BaseTurnRate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TimerBetweenShots_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_TimerBetweenShots;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MuzzleParticle_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MuzzleParticle;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ImpactParticle_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ImpactParticle;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Gun_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Gun;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PlayerPointer_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PlayerPointer;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MinimapCapture_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MinimapCapture;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReloadAnim_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReloadAnim;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LedgeClimb_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_LedgeClimb;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WirePointLight_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WirePointLight;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_cppWire_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_cppWire;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HealthWidget_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HealthWidget;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FollowCamera_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FollowCamera;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SpringArm_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SpringArm;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AWireHunterCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_WireHunter,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AWireHunterCharacter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AWireHunterCharacter_GetHealth, "GetHealth" }, // 2435732261
		{ &Z_Construct_UFunction_AWireHunterCharacter_GetMaxHealth, "GetMaxHealth" }, // 4157313112
		{ &Z_Construct_UFunction_AWireHunterCharacter_OnRep_CurrentHealth, "OnRep_CurrentHealth" }, // 2036157899
		{ &Z_Construct_UFunction_AWireHunterCharacter_SetHealth, "SetHealth" }, // 4529590
		{ &Z_Construct_UFunction_AWireHunterCharacter_TakeDamage, "TakeDamage" }, // 1469552393
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "WireHunterCharacter.h" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_cppHooked_MetaData[] = {
		{ "Category", "WireSystem" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	void Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_cppHooked_SetBit(void* Obj)
	{
		((AWireHunterCharacter*)Obj)->cppHooked = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_cppHooked = { "cppHooked", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AWireHunterCharacter), &Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_cppHooked_SetBit, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_cppHooked_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_cppHooked_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_ProjectileClass_MetaData[] = {
		{ "Category", "Projectile" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_ProjectileClass = { "ProjectileClass", nullptr, (EPropertyFlags)0x0014000000010001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, ProjectileClass), Z_Construct_UClass_ABullet_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_ProjectileClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_ProjectileClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MuzzleOffset_MetaData[] = {
		{ "Category", "GamePlay" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MuzzleOffset = { "MuzzleOffset", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, MuzzleOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MuzzleOffset_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MuzzleOffset_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_Hooked_MetaData[] = {
		{ "Category", "Floating" },
		{ "Comment", "// WireSystem\n" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
		{ "ToolTip", "WireSystem" },
	};
#endif
	void Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_Hooked_SetBit(void* Obj)
	{
		((AWireHunterCharacter*)Obj)->Hooked = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_Hooked = { "Hooked", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AWireHunterCharacter), &Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_Hooked_SetBit, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_Hooked_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_Hooked_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_LockLeftClimb_MetaData[] = {
		{ "Category", "Floating" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	void Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_LockLeftClimb_SetBit(void* Obj)
	{
		((AWireHunterCharacter*)Obj)->LockLeftClimb = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_LockLeftClimb = { "LockLeftClimb", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AWireHunterCharacter), &Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_LockLeftClimb_SetBit, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_LockLeftClimb_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_LockLeftClimb_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_LockRightClimb_MetaData[] = {
		{ "Category", "Floating" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	void Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_LockRightClimb_SetBit(void* Obj)
	{
		((AWireHunterCharacter*)Obj)->LockRightClimb = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_LockRightClimb = { "LockRightClimb", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AWireHunterCharacter), &Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_LockRightClimb_SetBit, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_LockRightClimb_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_LockRightClimb_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_WallRightVector_MetaData[] = {
		{ "Category", "Floating" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_WallRightVector = { "WallRightVector", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, WallRightVector), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_WallRightVector_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_WallRightVector_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_WallUpVector_MetaData[] = {
		{ "Category", "Floating" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_WallUpVector = { "WallUpVector", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, WallUpVector), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_WallUpVector_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_WallUpVector_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_isBulletEmpty_MetaData[] = {
		{ "Category", "Floating" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	void Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_isBulletEmpty_SetBit(void* Obj)
	{
		((AWireHunterCharacter*)Obj)->isBulletEmpty = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_isBulletEmpty = { "isBulletEmpty", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AWireHunterCharacter), &Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_isBulletEmpty_SetBit, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_isBulletEmpty_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_isBulletEmpty_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_isWithdrawing_MetaData[] = {
		{ "Category", "Floating" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	void Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_isWithdrawing_SetBit(void* Obj)
	{
		((AWireHunterCharacter*)Obj)->isWithdrawing = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_isWithdrawing = { "isWithdrawing", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AWireHunterCharacter), &Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_isWithdrawing_SetBit, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_isWithdrawing_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_isWithdrawing_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_isLedgeClimbing_MetaData[] = {
		{ "Category", "Floating" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	void Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_isLedgeClimbing_SetBit(void* Obj)
	{
		((AWireHunterCharacter*)Obj)->isLedgeClimbing = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_isLedgeClimbing = { "isLedgeClimbing", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AWireHunterCharacter), &Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_isLedgeClimbing_SetBit, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_isLedgeClimbing_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_isLedgeClimbing_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_isClimbing_MetaData[] = {
		{ "Category", "Floating" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	void Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_isClimbing_SetBit(void* Obj)
	{
		((AWireHunterCharacter*)Obj)->isClimbing = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_isClimbing = { "isClimbing", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AWireHunterCharacter), &Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_isClimbing_SetBit, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_isClimbing_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_isClimbing_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_FloatingRot_MetaData[] = {
		{ "Category", "Floating" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_FloatingRot = { "FloatingRot", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, FloatingRot), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_FloatingRot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_FloatingRot_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_FloatingPos_MetaData[] = {
		{ "Category", "Floating" },
		{ "Comment", "// Floating\n" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
		{ "ToolTip", "Floating" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_FloatingPos = { "FloatingPos", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, FloatingPos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_FloatingPos_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_FloatingPos_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MoveRightValue_MetaData[] = {
		{ "Category", "Status" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MoveRightValue = { "MoveRightValue", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, MoveRightValue), METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MoveRightValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MoveRightValue_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MoveForwardValue_MetaData[] = {
		{ "Category", "Status" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MoveForwardValue = { "MoveForwardValue", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, MoveForwardValue), METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MoveForwardValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MoveForwardValue_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_Bullets_MetaData[] = {
		{ "Category", "Status" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_Bullets = { "Bullets", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, Bullets), METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_Bullets_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_Bullets_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MaxBullets_MetaData[] = {
		{ "Category", "Status" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MaxBullets = { "MaxBullets", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, MaxBullets), METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MaxBullets_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MaxBullets_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MaxHealth_MetaData[] = {
		{ "Category", "Status" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MaxHealth = { "MaxHealth", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, MaxHealth), METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MaxHealth_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MaxHealth_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_Health_MetaData[] = {
		{ "Category", "Status" },
		{ "Comment", "// Character's Status\n" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
		{ "ToolTip", "Character's Status" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_Health = { "Health", "OnRep_CurrentHealth", (EPropertyFlags)0x0020080100010025, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, Health), METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_Health_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_Health_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_BaseLookUpRate_MetaData[] = {
		{ "Category", "Camera" },
		{ "Comment", "/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
		{ "ToolTip", "Base look up/down rate, in deg/sec. Other scaling may affect final rate." },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_BaseLookUpRate = { "BaseLookUpRate", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, BaseLookUpRate), METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_BaseLookUpRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_BaseLookUpRate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_BaseTurnRate_MetaData[] = {
		{ "Category", "Camera" },
		{ "Comment", "/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
		{ "ToolTip", "Base turn rate, in deg/sec. Other scaling may affect final turn rate." },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_BaseTurnRate = { "BaseTurnRate", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, BaseTurnRate), METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_BaseTurnRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_BaseTurnRate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_TimerBetweenShots_MetaData[] = {
		{ "Category", "Gameplay" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_TimerBetweenShots = { "TimerBetweenShots", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, TimerBetweenShots), METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_TimerBetweenShots_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_TimerBetweenShots_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MuzzleParticle_MetaData[] = {
		{ "Category", "Gameplay" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MuzzleParticle = { "MuzzleParticle", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, MuzzleParticle), Z_Construct_UClass_UParticleSystem_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MuzzleParticle_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MuzzleParticle_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_ImpactParticle_MetaData[] = {
		{ "Category", "Gameplay" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_ImpactParticle = { "ImpactParticle", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, ImpactParticle), Z_Construct_UClass_UParticleSystem_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_ImpactParticle_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_ImpactParticle_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_Gun_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Gun" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_Gun = { "Gun", nullptr, (EPropertyFlags)0x004000000008000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, Gun), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_Gun_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_Gun_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_PlayerPointer_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Minimap" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_PlayerPointer = { "PlayerPointer", nullptr, (EPropertyFlags)0x004000000008000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, PlayerPointer), Z_Construct_UClass_UPaperSpriteComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_PlayerPointer_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_PlayerPointer_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MinimapCapture_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Minimap" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MinimapCapture = { "MinimapCapture", nullptr, (EPropertyFlags)0x004000000008000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, MinimapCapture), Z_Construct_UClass_USceneCaptureComponent2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MinimapCapture_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MinimapCapture_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_ReloadAnim_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "animation" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_ReloadAnim = { "ReloadAnim", nullptr, (EPropertyFlags)0x0040000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, ReloadAnim), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_ReloadAnim_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_ReloadAnim_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_LedgeClimb_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "animation" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_LedgeClimb = { "LedgeClimb", nullptr, (EPropertyFlags)0x0040000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, LedgeClimb), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_LedgeClimb_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_LedgeClimb_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_WirePointLight_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "cable" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_WirePointLight = { "WirePointLight", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, WirePointLight), Z_Construct_UClass_UPointLightComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_WirePointLight_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_WirePointLight_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_cppWire_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "cable" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_cppWire = { "cppWire", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, cppWire), Z_Construct_UClass_UCableComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_cppWire_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_cppWire_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_HealthWidget_MetaData[] = {
		{ "Category", "WireHunterCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_HealthWidget = { "HealthWidget", nullptr, (EPropertyFlags)0x00400000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, HealthWidget), Z_Construct_UClass_UWidgetComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_HealthWidget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_HealthWidget_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_FollowCamera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/** Follow camera */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
		{ "ToolTip", "Follow camera" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_FollowCamera = { "FollowCamera", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, FollowCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_FollowCamera_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_FollowCamera_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_SpringArm_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_SpringArm = { "SpringArm", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, SpringArm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_SpringArm_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_SpringArm_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/** Camera boom positioning the camera behind the character */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
		{ "ToolTip", "Camera boom positioning the camera behind the character" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_CameraBoom_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_CameraBoom_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AWireHunterCharacter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_cppHooked,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_ProjectileClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MuzzleOffset,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_Hooked,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_LockLeftClimb,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_LockRightClimb,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_WallRightVector,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_WallUpVector,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_isBulletEmpty,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_isWithdrawing,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_isLedgeClimbing,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_isClimbing,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_FloatingRot,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_FloatingPos,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MoveRightValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MoveForwardValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_Bullets,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MaxBullets,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MaxHealth,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_Health,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_BaseLookUpRate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_BaseTurnRate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_TimerBetweenShots,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MuzzleParticle,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_ImpactParticle,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_Gun,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_PlayerPointer,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MinimapCapture,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_ReloadAnim,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_LedgeClimb,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_WirePointLight,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_cppWire,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_HealthWidget,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_FollowCamera,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_SpringArm,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_CameraBoom,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AWireHunterCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWireHunterCharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AWireHunterCharacter_Statics::ClassParams = {
		&AWireHunterCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AWireHunterCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::PropPointers),
		0,
		0x008000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AWireHunterCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AWireHunterCharacter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AWireHunterCharacter, 734139687);
	template<> WIREHUNTER_API UClass* StaticClass<AWireHunterCharacter>()
	{
		return AWireHunterCharacter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AWireHunterCharacter(Z_Construct_UClass_AWireHunterCharacter, &AWireHunterCharacter::StaticClass, TEXT("/Script/WireHunter"), TEXT("AWireHunterCharacter"), false, nullptr, nullptr, nullptr);

	void AWireHunterCharacter::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
	{
		static const FName Name_Health(TEXT("Health"));

		const bool bIsValid = true
			&& Name_Health == ClassReps[(int32)ENetFields_Private::Health].Property->GetFName();

		checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in AWireHunterCharacter"));
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AWireHunterCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
