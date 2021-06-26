// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WireHunter/WeightStructure.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWeightStructure() {}
// Cross Module References
	WIREHUNTER_API UScriptStruct* Z_Construct_UScriptStruct_FStructWeight();
	UPackage* Z_Construct_UPackage__Script_WireHunter();
	WIREHUNTER_API UScriptStruct* Z_Construct_UScriptStruct_FStructNode();
	WIREHUNTER_API UClass* Z_Construct_UClass_AWeightStructure_NoRegister();
	WIREHUNTER_API UClass* Z_Construct_UClass_AWeightStructure();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
// End Cross Module References
class UScriptStruct* FStructWeight::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern WIREHUNTER_API uint32 Get_Z_Construct_UScriptStruct_FStructWeight_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FStructWeight, Z_Construct_UPackage__Script_WireHunter(), TEXT("StructWeight"), sizeof(FStructWeight), Get_Z_Construct_UScriptStruct_FStructWeight_Hash());
	}
	return Singleton;
}
template<> WIREHUNTER_API UScriptStruct* StaticStruct<FStructWeight>()
{
	return FStructWeight::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FStructWeight(FStructWeight::StaticStruct, TEXT("/Script/WireHunter"), TEXT("StructWeight"), false, nullptr, nullptr);
static struct FScriptStruct_WireHunter_StaticRegisterNativesFStructWeight
{
	FScriptStruct_WireHunter_StaticRegisterNativesFStructWeight()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("StructWeight")),new UScriptStruct::TCppStructOps<FStructWeight>);
	}
} ScriptStruct_WireHunter_StaticRegisterNativesFStructWeight;
	struct Z_Construct_UScriptStruct_FStructWeight_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_node_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_node;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_weight_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_weight;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStructWeight_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "WeightStructure.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FStructWeight_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FStructWeight>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStructWeight_Statics::NewProp_node_MetaData[] = {
		{ "Category", "StructWeight" },
		{ "ModuleRelativePath", "WeightStructure.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FStructWeight_Statics::NewProp_node = { "node", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FStructWeight, node), Z_Construct_UScriptStruct_FStructNode, METADATA_PARAMS(Z_Construct_UScriptStruct_FStructWeight_Statics::NewProp_node_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStructWeight_Statics::NewProp_node_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStructWeight_Statics::NewProp_weight_MetaData[] = {
		{ "Category", "StructWeight" },
		{ "ModuleRelativePath", "WeightStructure.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FStructWeight_Statics::NewProp_weight = { "weight", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FStructWeight, weight), METADATA_PARAMS(Z_Construct_UScriptStruct_FStructWeight_Statics::NewProp_weight_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStructWeight_Statics::NewProp_weight_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FStructWeight_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStructWeight_Statics::NewProp_node,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStructWeight_Statics::NewProp_weight,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FStructWeight_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_WireHunter,
		nullptr,
		&NewStructOps,
		"StructWeight",
		sizeof(FStructWeight),
		alignof(FStructWeight),
		Z_Construct_UScriptStruct_FStructWeight_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStructWeight_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000011),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FStructWeight_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStructWeight_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FStructWeight()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FStructWeight_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_WireHunter();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("StructWeight"), sizeof(FStructWeight), Get_Z_Construct_UScriptStruct_FStructWeight_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FStructWeight_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FStructWeight_Hash() { return 314678093U; }
	void AWeightStructure::StaticRegisterNativesAWeightStructure()
	{
	}
	UClass* Z_Construct_UClass_AWeightStructure_NoRegister()
	{
		return AWeightStructure::StaticClass();
	}
	struct Z_Construct_UClass_AWeightStructure_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AWeightStructure_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_WireHunter,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWeightStructure_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "WeightStructure.h" },
		{ "ModuleRelativePath", "WeightStructure.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AWeightStructure_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWeightStructure>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AWeightStructure_Statics::ClassParams = {
		&AWeightStructure::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AWeightStructure_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AWeightStructure_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AWeightStructure()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AWeightStructure_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AWeightStructure, 2765656833);
	template<> WIREHUNTER_API UClass* StaticClass<AWeightStructure>()
	{
		return AWeightStructure::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AWeightStructure(Z_Construct_UClass_AWeightStructure, &AWeightStructure::StaticClass, TEXT("/Script/WireHunter"), TEXT("AWeightStructure"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AWeightStructure);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
