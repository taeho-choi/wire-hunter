// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WireHunter/NodeStructure.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNodeStructure() {}
// Cross Module References
	WIREHUNTER_API UScriptStruct* Z_Construct_UScriptStruct_FStructNode();
	UPackage* Z_Construct_UPackage__Script_WireHunter();
	WIREHUNTER_API UClass* Z_Construct_UClass_ANodeStructure_NoRegister();
	WIREHUNTER_API UClass* Z_Construct_UClass_ANodeStructure();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
// End Cross Module References
class UScriptStruct* FStructNode::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern WIREHUNTER_API uint32 Get_Z_Construct_UScriptStruct_FStructNode_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FStructNode, Z_Construct_UPackage__Script_WireHunter(), TEXT("StructNode"), sizeof(FStructNode), Get_Z_Construct_UScriptStruct_FStructNode_Hash());
	}
	return Singleton;
}
template<> WIREHUNTER_API UScriptStruct* StaticStruct<FStructNode>()
{
	return FStructNode::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FStructNode(FStructNode::StaticStruct, TEXT("/Script/WireHunter"), TEXT("StructNode"), false, nullptr, nullptr);
static struct FScriptStruct_WireHunter_StaticRegisterNativesFStructNode
{
	FScriptStruct_WireHunter_StaticRegisterNativesFStructNode()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("StructNode")),new UScriptStruct::TCppStructOps<FStructNode>);
	}
} ScriptStruct_WireHunter_StaticRegisterNativesFStructNode;
	struct Z_Construct_UScriptStruct_FStructNode_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_second_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_second;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_first_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_first;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStructNode_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "NodeStructure.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FStructNode_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FStructNode>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStructNode_Statics::NewProp_second_MetaData[] = {
		{ "Category", "StructNode" },
		{ "ModuleRelativePath", "NodeStructure.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FStructNode_Statics::NewProp_second = { "second", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FStructNode, second), METADATA_PARAMS(Z_Construct_UScriptStruct_FStructNode_Statics::NewProp_second_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStructNode_Statics::NewProp_second_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStructNode_Statics::NewProp_first_MetaData[] = {
		{ "Category", "StructNode" },
		{ "ModuleRelativePath", "NodeStructure.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FStructNode_Statics::NewProp_first = { "first", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FStructNode, first), METADATA_PARAMS(Z_Construct_UScriptStruct_FStructNode_Statics::NewProp_first_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStructNode_Statics::NewProp_first_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FStructNode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStructNode_Statics::NewProp_second,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStructNode_Statics::NewProp_first,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FStructNode_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_WireHunter,
		nullptr,
		&NewStructOps,
		"StructNode",
		sizeof(FStructNode),
		alignof(FStructNode),
		Z_Construct_UScriptStruct_FStructNode_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStructNode_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000011),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FStructNode_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStructNode_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FStructNode()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FStructNode_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_WireHunter();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("StructNode"), sizeof(FStructNode), Get_Z_Construct_UScriptStruct_FStructNode_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FStructNode_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FStructNode_Hash() { return 3777977036U; }
	void ANodeStructure::StaticRegisterNativesANodeStructure()
	{
	}
	UClass* Z_Construct_UClass_ANodeStructure_NoRegister()
	{
		return ANodeStructure::StaticClass();
	}
	struct Z_Construct_UClass_ANodeStructure_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ANodeStructure_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_WireHunter,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANodeStructure_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "NodeStructure.h" },
		{ "ModuleRelativePath", "NodeStructure.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ANodeStructure_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANodeStructure>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ANodeStructure_Statics::ClassParams = {
		&ANodeStructure::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ANodeStructure_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ANodeStructure_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ANodeStructure()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ANodeStructure_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ANodeStructure, 1523935726);
	template<> WIREHUNTER_API UClass* StaticClass<ANodeStructure>()
	{
		return ANodeStructure::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ANodeStructure(Z_Construct_UClass_ANodeStructure, &ANodeStructure::StaticClass, TEXT("/Script/WireHunter"), TEXT("ANodeStructure"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANodeStructure);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
