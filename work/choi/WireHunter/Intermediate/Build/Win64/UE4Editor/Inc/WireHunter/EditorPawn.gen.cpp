// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WireHunter/EditorPawn.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEditorPawn() {}
// Cross Module References
	WIREHUNTER_API UClass* Z_Construct_UClass_AEditorPawn_NoRegister();
	WIREHUNTER_API UClass* Z_Construct_UClass_AEditorPawn();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_WireHunter();
// End Cross Module References
	void AEditorPawn::StaticRegisterNativesAEditorPawn()
	{
	}
	UClass* Z_Construct_UClass_AEditorPawn_NoRegister()
	{
		return AEditorPawn::StaticClass();
	}
	struct Z_Construct_UClass_AEditorPawn_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEditorPawn_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_WireHunter,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEditorPawn_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "EditorPawn.h" },
		{ "ModuleRelativePath", "EditorPawn.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEditorPawn_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEditorPawn>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEditorPawn_Statics::ClassParams = {
		&AEditorPawn::StaticClass,
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
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AEditorPawn_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEditorPawn_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEditorPawn()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEditorPawn_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEditorPawn, 984760939);
	template<> WIREHUNTER_API UClass* StaticClass<AEditorPawn>()
	{
		return AEditorPawn::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEditorPawn(Z_Construct_UClass_AEditorPawn, &AEditorPawn::StaticClass, TEXT("/Script/WireHunter"), TEXT("AEditorPawn"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEditorPawn);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
