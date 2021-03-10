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
	ENGINE_API UClass* Z_Construct_UClass_UPhysicsHandleComponent_NoRegister();
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
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PhysicsHandle_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PhysicsHandle;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEditorPlayerController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_WireHunter,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEditorPlayerController_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n *\n */" },
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "EditorPlayerController.h" },
		{ "ModuleRelativePath", "EditorPlayerController.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEditorPlayerController_Statics::NewProp_PhysicsHandle_MetaData[] = {
		{ "Category", "EditorPlayerController" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "EditorPlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEditorPlayerController_Statics::NewProp_PhysicsHandle = { "PhysicsHandle", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEditorPlayerController, PhysicsHandle), Z_Construct_UClass_UPhysicsHandleComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEditorPlayerController_Statics::NewProp_PhysicsHandle_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEditorPlayerController_Statics::NewProp_PhysicsHandle_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEditorPlayerController_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEditorPlayerController_Statics::NewProp_PhysicsHandle,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEditorPlayerController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEditorPlayerController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEditorPlayerController_Statics::ClassParams = {
		&AEditorPlayerController::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AEditorPlayerController_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AEditorPlayerController_Statics::PropPointers),
		0,
		0x008002A4u,
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
	IMPLEMENT_CLASS(AEditorPlayerController, 1041294391);
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
