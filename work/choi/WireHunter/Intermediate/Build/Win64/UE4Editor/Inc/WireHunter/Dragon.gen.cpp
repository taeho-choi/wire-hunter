// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WireHunter/Dragon.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDragon() {}
// Cross Module References
	WIREHUNTER_API UClass* Z_Construct_UClass_ADragon_NoRegister();
	WIREHUNTER_API UClass* Z_Construct_UClass_ADragon();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_WireHunter();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
// End Cross Module References
	void ADragon::StaticRegisterNativesADragon()
	{
	}
	UClass* Z_Construct_UClass_ADragon_NoRegister()
	{
		return ADragon::StaticClass();
	}
	struct Z_Construct_UClass_ADragon_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DragonMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DragonMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DragonRoot_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DragonRoot;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MoveType_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_MoveType;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ADragon_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_WireHunter,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADragon_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Dragon.h" },
		{ "ModuleRelativePath", "Dragon.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADragon_Statics::NewProp_DragonMesh_MetaData[] = {
		{ "Category", "Dragon" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Dragon.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADragon_Statics::NewProp_DragonMesh = { "DragonMesh", nullptr, (EPropertyFlags)0x0010000000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ADragon, DragonMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ADragon_Statics::NewProp_DragonMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADragon_Statics::NewProp_DragonMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADragon_Statics::NewProp_DragonRoot_MetaData[] = {
		{ "Category", "Dragon" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Dragon.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADragon_Statics::NewProp_DragonRoot = { "DragonRoot", nullptr, (EPropertyFlags)0x0010000000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ADragon, DragonRoot), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ADragon_Statics::NewProp_DragonRoot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADragon_Statics::NewProp_DragonRoot_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADragon_Statics::NewProp_MoveType_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Dragon.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_ADragon_Statics::NewProp_MoveType = { "MoveType", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ADragon, MoveType), METADATA_PARAMS(Z_Construct_UClass_ADragon_Statics::NewProp_MoveType_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADragon_Statics::NewProp_MoveType_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ADragon_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADragon_Statics::NewProp_DragonMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADragon_Statics::NewProp_DragonRoot,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADragon_Statics::NewProp_MoveType,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ADragon_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADragon>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ADragon_Statics::ClassParams = {
		&ADragon::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ADragon_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ADragon_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ADragon_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ADragon_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ADragon()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ADragon_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ADragon, 3434548105);
	template<> WIREHUNTER_API UClass* StaticClass<ADragon>()
	{
		return ADragon::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ADragon(Z_Construct_UClass_ADragon, &ADragon::StaticClass, TEXT("/Script/WireHunter"), TEXT("ADragon"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADragon);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
