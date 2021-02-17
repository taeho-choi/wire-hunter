// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "practice/practiceGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodepracticeGameMode() {}
// Cross Module References
	PRACTICE_API UClass* Z_Construct_UClass_ApracticeGameMode_NoRegister();
	PRACTICE_API UClass* Z_Construct_UClass_ApracticeGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_practice();
// End Cross Module References
	void ApracticeGameMode::StaticRegisterNativesApracticeGameMode()
	{
	}
	UClass* Z_Construct_UClass_ApracticeGameMode_NoRegister()
	{
		return ApracticeGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ApracticeGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ApracticeGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_practice,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ApracticeGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "practiceGameMode.h" },
		{ "ModuleRelativePath", "practiceGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ApracticeGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ApracticeGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ApracticeGameMode_Statics::ClassParams = {
		&ApracticeGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_ApracticeGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ApracticeGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ApracticeGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ApracticeGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ApracticeGameMode, 1594553574);
	template<> PRACTICE_API UClass* StaticClass<ApracticeGameMode>()
	{
		return ApracticeGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ApracticeGameMode(Z_Construct_UClass_ApracticeGameMode, &ApracticeGameMode::StaticClass, TEXT("/Script/practice"), TEXT("ApracticeGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ApracticeGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
