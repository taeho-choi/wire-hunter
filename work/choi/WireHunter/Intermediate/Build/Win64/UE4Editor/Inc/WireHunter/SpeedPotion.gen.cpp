// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WireHunter/SpeedPotion.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSpeedPotion() {}
// Cross Module References
	WIREHUNTER_API UClass* Z_Construct_UClass_ASpeedPotion_NoRegister();
	WIREHUNTER_API UClass* Z_Construct_UClass_ASpeedPotion();
	WIREHUNTER_API UClass* Z_Construct_UClass_APickUp();
	UPackage* Z_Construct_UPackage__Script_WireHunter();
// End Cross Module References
	void ASpeedPotion::StaticRegisterNativesASpeedPotion()
	{
	}
	UClass* Z_Construct_UClass_ASpeedPotion_NoRegister()
	{
		return ASpeedPotion::StaticClass();
	}
	struct Z_Construct_UClass_ASpeedPotion_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASpeedPotion_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APickUp,
		(UObject* (*)())Z_Construct_UPackage__Script_WireHunter,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASpeedPotion_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SpeedPotion.h" },
		{ "ModuleRelativePath", "SpeedPotion.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASpeedPotion_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASpeedPotion>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASpeedPotion_Statics::ClassParams = {
		&ASpeedPotion::StaticClass,
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
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASpeedPotion_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASpeedPotion_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASpeedPotion()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ASpeedPotion_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASpeedPotion, 3885089713);
	template<> WIREHUNTER_API UClass* StaticClass<ASpeedPotion>()
	{
		return ASpeedPotion::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASpeedPotion(Z_Construct_UClass_ASpeedPotion, &ASpeedPotion::StaticClass, TEXT("/Script/WireHunter"), TEXT("ASpeedPotion"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASpeedPotion);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
