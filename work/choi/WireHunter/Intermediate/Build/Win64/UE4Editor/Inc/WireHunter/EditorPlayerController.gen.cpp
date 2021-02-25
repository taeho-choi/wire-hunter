// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WireHunter/EditorPlayerController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEditorPlayerController() {}
// Cross Module References
	WIREHUNTER_API UClass* Z_Construct_UClass_AEditorPlayerController_NoRegister();
	WIREHUNTER_API UClass* Z_Construct_UClass_AEditorPlayerController();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	UPackage* Z_Construct_UPackage__Script_WireHunter();
// End Cross Module References
	void AEditorPlayerController::StaticRegisterNativesAEditorPlayerController()
	{
	}
	UClass* Z_Construct_UClass_AEditorPlayerController_NoRegister()
	{
		return AEditorPlayerController::StaticClass();
	}
	struct Z_Construct_UClass_AEditorPlayerController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEditorPlayerController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_WireHunter,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEditorPlayerController_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "EditorPlayerController.h" },
		{ "ModuleRelativePath", "EditorPlayerController.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEditorPlayerController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEditorPlayerController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEditorPlayerController_Statics::ClassParams = {
		&AEditorPlayerController::StaticClass,
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
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_AEditorPlayerController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEditorPlayerController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEditorPlayerController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEditorPlayerController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEditorPlayerController, 3333065077);
	template<> WIREHUNTER_API UClass* StaticClass<AEditorPlayerController>()
	{
		return AEditorPlayerController::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEditorPlayerController(Z_Construct_UClass_AEditorPlayerController, &AEditorPlayerController::StaticClass, TEXT("/Script/WireHunter"), TEXT("AEditorPlayerController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEditorPlayerController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
