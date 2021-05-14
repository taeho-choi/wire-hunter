// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WireHunter/StrengthPotion.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStrengthPotion() {}
// Cross Module References
	WIREHUNTER_API UClass* Z_Construct_UClass_AStrengthPotion_NoRegister();
	WIREHUNTER_API UClass* Z_Construct_UClass_AStrengthPotion();
	WIREHUNTER_API UClass* Z_Construct_UClass_APickUp();
	UPackage* Z_Construct_UPackage__Script_WireHunter();
// End Cross Module References
	void AStrengthPotion::StaticRegisterNativesAStrengthPotion()
	{
	}
	UClass* Z_Construct_UClass_AStrengthPotion_NoRegister()
	{
		return AStrengthPotion::StaticClass();
	}
	struct Z_Construct_UClass_AStrengthPotion_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AStrengthPotion_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APickUp,
		(UObject* (*)())Z_Construct_UPackage__Script_WireHunter,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AStrengthPotion_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "StrengthPotion.h" },
		{ "ModuleRelativePath", "StrengthPotion.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AStrengthPotion_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AStrengthPotion>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AStrengthPotion_Statics::ClassParams = {
		&AStrengthPotion::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AStrengthPotion_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AStrengthPotion_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AStrengthPotion()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AStrengthPotion_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AStrengthPotion, 539518070);
	template<> WIREHUNTER_API UClass* StaticClass<AStrengthPotion>()
	{
		return AStrengthPotion::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AStrengthPotion(Z_Construct_UClass_AStrengthPotion, &AStrengthPotion::StaticClass, TEXT("/Script/WireHunter"), TEXT("AStrengthPotion"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AStrengthPotion);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
