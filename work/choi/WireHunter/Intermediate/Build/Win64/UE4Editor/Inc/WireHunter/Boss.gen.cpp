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
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_WireHunter();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	WIREHUNTER_API UClass* Z_Construct_UClass_AFireball_NoRegister();
// End Cross Module References
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
			{ "Spawn", &ABoss::execSpawn },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
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
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ToSpawn_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_ToSpawn;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABoss_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_WireHunter,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ABoss_Statics::FuncInfo[] = {
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
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoss_Statics::NewProp_ToSpawn_MetaData[] = {
		{ "Category", "Boss" },
		{ "ModuleRelativePath", "Boss.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_ABoss_Statics::NewProp_ToSpawn = { "ToSpawn", nullptr, (EPropertyFlags)0x0024080000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABoss, ToSpawn), Z_Construct_UClass_AFireball_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ABoss_Statics::NewProp_ToSpawn_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABoss_Statics::NewProp_ToSpawn_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABoss_Statics::PropPointers[] = {
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
	IMPLEMENT_CLASS(ABoss, 3195543753);
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
