// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WireHunter/BossAIController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBossAIController() {}
// Cross Module References
	WIREHUNTER_API UClass* Z_Construct_UClass_ABossAIController_NoRegister();
	WIREHUNTER_API UClass* Z_Construct_UClass_ABossAIController();
	AIMODULE_API UClass* Z_Construct_UClass_AAIController();
	UPackage* Z_Construct_UPackage__Script_WireHunter();
// End Cross Module References
	void ABossAIController::StaticRegisterNativesABossAIController()
	{
	}
	UClass* Z_Construct_UClass_ABossAIController_NoRegister()
	{
		return ABossAIController::StaticClass();
	}
	struct Z_Construct_UClass_ABossAIController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABossAIController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AAIController,
		(UObject* (*)())Z_Construct_UPackage__Script_WireHunter,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABossAIController_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "BossAIController.h" },
		{ "ModuleRelativePath", "BossAIController.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABossAIController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABossAIController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABossAIController_Statics::ClassParams = {
		&ABossAIController::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_ABossAIController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABossAIController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABossAIController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABossAIController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABossAIController, 1129303831);
	template<> WIREHUNTER_API UClass* StaticClass<ABossAIController>()
	{
		return ABossAIController::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABossAIController(Z_Construct_UClass_ABossAIController, &ABossAIController::StaticClass, TEXT("/Script/WireHunter"), TEXT("ABossAIController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABossAIController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
