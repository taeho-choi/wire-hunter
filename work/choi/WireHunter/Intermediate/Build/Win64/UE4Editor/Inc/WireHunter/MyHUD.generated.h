// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef WIREHUNTER_MyHUD_generated_h
#error "MyHUD.generated.h already included, missing '#pragma once' in MyHUD.h"
#endif
#define WIREHUNTER_MyHUD_generated_h

#define WireHunter_Source_WireHunter_MyHUD_h_15_SPARSE_DATA
#define WireHunter_Source_WireHunter_MyHUD_h_15_RPC_WRAPPERS
#define WireHunter_Source_WireHunter_MyHUD_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define WireHunter_Source_WireHunter_MyHUD_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyHUD(); \
	friend struct Z_Construct_UClass_AMyHUD_Statics; \
public: \
	DECLARE_CLASS(AMyHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/WireHunter"), NO_API) \
	DECLARE_SERIALIZER(AMyHUD)


#define WireHunter_Source_WireHunter_MyHUD_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAMyHUD(); \
	friend struct Z_Construct_UClass_AMyHUD_Statics; \
public: \
	DECLARE_CLASS(AMyHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/WireHunter"), NO_API) \
	DECLARE_SERIALIZER(AMyHUD)


#define WireHunter_Source_WireHunter_MyHUD_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMyHUD(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMyHUD) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyHUD); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyHUD); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyHUD(AMyHUD&&); \
	NO_API AMyHUD(const AMyHUD&); \
public:


#define WireHunter_Source_WireHunter_MyHUD_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMyHUD(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyHUD(AMyHUD&&); \
	NO_API AMyHUD(const AMyHUD&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyHUD); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyHUD); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMyHUD)


#define WireHunter_Source_WireHunter_MyHUD_h_15_PRIVATE_PROPERTY_OFFSET
#define WireHunter_Source_WireHunter_MyHUD_h_12_PROLOG
#define WireHunter_Source_WireHunter_MyHUD_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	WireHunter_Source_WireHunter_MyHUD_h_15_PRIVATE_PROPERTY_OFFSET \
	WireHunter_Source_WireHunter_MyHUD_h_15_SPARSE_DATA \
	WireHunter_Source_WireHunter_MyHUD_h_15_RPC_WRAPPERS \
	WireHunter_Source_WireHunter_MyHUD_h_15_INCLASS \
	WireHunter_Source_WireHunter_MyHUD_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define WireHunter_Source_WireHunter_MyHUD_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	WireHunter_Source_WireHunter_MyHUD_h_15_PRIVATE_PROPERTY_OFFSET \
	WireHunter_Source_WireHunter_MyHUD_h_15_SPARSE_DATA \
	WireHunter_Source_WireHunter_MyHUD_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	WireHunter_Source_WireHunter_MyHUD_h_15_INCLASS_NO_PURE_DECLS \
	WireHunter_Source_WireHunter_MyHUD_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> WIREHUNTER_API UClass* StaticClass<class AMyHUD>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID WireHunter_Source_WireHunter_MyHUD_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
