// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WireHunter/EditorDoll.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEditorDoll() {}
// Cross Module References
	WIREHUNTER_API UClass* Z_Construct_UClass_AEditorDoll_NoRegister();
	WIREHUNTER_API UClass* Z_Construct_UClass_AEditorDoll();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_WireHunter();
	ENGINE_API UClass* Z_Construct_UClass_UPoseableMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
// End Cross Module References
	void AEditorDoll::StaticRegisterNativesAEditorDoll()
	{
	}
	UClass* Z_Construct_UClass_AEditorDoll_NoRegister()
	{
		return AEditorDoll::StaticClass();
	}
	struct Z_Construct_UClass_AEditorDoll_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PM_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PM;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SK_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SK;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEditorDoll_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_WireHunter,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEditorDoll_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "EditorDoll.h" },
		{ "ModuleRelativePath", "EditorDoll.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEditorDoll_Statics::NewProp_PM_MetaData[] = {
		{ "Category", "EditorDoll" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "EditorDoll.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEditorDoll_Statics::NewProp_PM = { "PM", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEditorDoll, PM), Z_Construct_UClass_UPoseableMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEditorDoll_Statics::NewProp_PM_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEditorDoll_Statics::NewProp_PM_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEditorDoll_Statics::NewProp_SK_MetaData[] = {
		{ "Category", "EditorDoll" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "EditorDoll.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEditorDoll_Statics::NewProp_SK = { "SK", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AEditorDoll, SK), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AEditorDoll_Statics::NewProp_SK_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AEditorDoll_Statics::NewProp_SK_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEditorDoll_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEditorDoll_Statics::NewProp_PM,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEditorDoll_Statics::NewProp_SK,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEditorDoll_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEditorDoll>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEditorDoll_Statics::ClassParams = {
		&AEditorDoll::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AEditorDoll_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AEditorDoll_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AEditorDoll_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEditorDoll_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEditorDoll()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEditorDoll_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEditorDoll, 3638943373);
	template<> WIREHUNTER_API UClass* StaticClass<AEditorDoll>()
	{
		return AEditorDoll::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEditorDoll(Z_Construct_UClass_AEditorDoll, &AEditorDoll::StaticClass, TEXT("/Script/WireHunter"), TEXT("AEditorDoll"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEditorDoll);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
