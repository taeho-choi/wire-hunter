// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WireHunter/WireHunterGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWireHunterGameMode() {}
// Cross Module References
	WIREHUNTER_API UClass* Z_Construct_UClass_AWireHunterGameMode_NoRegister();
	WIREHUNTER_API UClass* Z_Construct_UClass_AWireHunterGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_WireHunter();
// End Cross Module References
	void AWireHunterGameMode::StaticRegisterNativesAWireHunterGameMode()
	{
	}
	UClass* Z_Construct_UClass_AWireHunterGameMode_NoRegister()
	{
		return AWireHunterGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AWireHunterGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AWireHunterGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_WireHunter,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "WireHunterGameMode.h" },
		{ "ModuleRelativePath", "WireHunterGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AWireHunterGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWireHunterGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AWireHunterGameMode_Statics::ClassParams = {
		&AWireHunterGameMode::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AWireHunterGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AWireHunterGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AWireHunterGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AWireHunterGameMode, 3282398843);
	template<> WIREHUNTER_API UClass* StaticClass<AWireHunterGameMode>()
	{
		return AWireHunterGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AWireHunterGameMode(Z_Construct_UClass_AWireHunterGameMode, &AWireHunterGameMode::StaticClass, TEXT("/Script/WireHunter"), TEXT("AWireHunterGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AWireHunterGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
