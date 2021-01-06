// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TestProject/PawnWithCamera.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePawnWithCamera() {}
// Cross Module References
	TESTPROJECT_API UClass* Z_Construct_UClass_APawnWithCamera_NoRegister();
	TESTPROJECT_API UClass* Z_Construct_UClass_APawnWithCamera();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_TestProject();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
// End Cross Module References
	void APawnWithCamera::StaticRegisterNativesAPawnWithCamera()
	{
	}
	UClass* Z_Construct_UClass_APawnWithCamera_NoRegister()
	{
		return APawnWithCamera::StaticClass();
	}
	struct Z_Construct_UClass_APawnWithCamera_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OurCameraSpringArm_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OurCameraSpringArm;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APawnWithCamera_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_TestProject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APawnWithCamera_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "PawnWithCamera.h" },
		{ "ModuleRelativePath", "PawnWithCamera.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APawnWithCamera_Statics::NewProp_OurCameraSpringArm_MetaData[] = {
		{ "Category", "PawnWithCamera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "PawnWithCamera.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APawnWithCamera_Statics::NewProp_OurCameraSpringArm = { "OurCameraSpringArm", nullptr, (EPropertyFlags)0x0020080000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APawnWithCamera, OurCameraSpringArm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_APawnWithCamera_Statics::NewProp_OurCameraSpringArm_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APawnWithCamera_Statics::NewProp_OurCameraSpringArm_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APawnWithCamera_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APawnWithCamera_Statics::NewProp_OurCameraSpringArm,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APawnWithCamera_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APawnWithCamera>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APawnWithCamera_Statics::ClassParams = {
		&APawnWithCamera::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_APawnWithCamera_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_APawnWithCamera_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_APawnWithCamera_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APawnWithCamera_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APawnWithCamera()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APawnWithCamera_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APawnWithCamera, 3289882353);
	template<> TESTPROJECT_API UClass* StaticClass<APawnWithCamera>()
	{
		return APawnWithCamera::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APawnWithCamera(Z_Construct_UClass_APawnWithCamera, &APawnWithCamera::StaticClass, TEXT("/Script/TestProject"), TEXT("APawnWithCamera"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APawnWithCamera);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
