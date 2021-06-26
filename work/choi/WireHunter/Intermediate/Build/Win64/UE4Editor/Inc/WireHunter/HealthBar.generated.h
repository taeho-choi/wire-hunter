// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef WIREHUNTER_HealthBar_generated_h
#error "HealthBar.generated.h already included, missing '#pragma once' in HealthBar.h"
#endif
#define WIREHUNTER_HealthBar_generated_h

#define WireHunter_Source_WireHunter_HealthBar_h_13_SPARSE_DATA
#define WireHunter_Source_WireHunter_HealthBar_h_13_RPC_WRAPPERS
#define WireHunter_Source_WireHunter_HealthBar_h_13_RPC_WRAPPERS_NO_PURE_DECLS
#define WireHunter_Source_WireHunter_HealthBar_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUHealthBar(); \
	friend struct Z_Construct_UClass_UHealthBar_Statics; \
public: \
	DECLARE_CLASS(UHealthBar, UUserWidget, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/WireHunter"), NO_API) \
	DECLARE_SERIALIZER(UHealthBar)


#define WireHunter_Source_WireHunter_HealthBar_h_13_INCLASS \
private: \
	static void StaticRegisterNativesUHealthBar(); \
	friend struct Z_Construct_UClass_UHealthBar_Statics; \
public: \
	DECLARE_CLASS(UHealthBar, UUserWidget, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/WireHunter"), NO_API) \
	DECLARE_SERIALIZER(UHealthBar)


#define WireHunter_Source_WireHunter_HealthBar_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UHealthBar(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UHealthBar) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UHealthBar); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHealthBar); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UHealthBar(UHealthBar&&); \
	NO_API UHealthBar(const UHealthBar&); \
public:


#define WireHunter_Source_WireHunter_HealthBar_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UHealthBar(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UHealthBar(UHealthBar&&); \
	NO_API UHealthBar(const UHealthBar&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UHealthBar); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHealthBar); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UHealthBar)


#define WireHunter_Source_WireHunter_HealthBar_h_13_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__HealthBar() { return STRUCT_OFFSET(UHealthBar, HealthBar); } \
	FORCEINLINE static uint32 __PPO__CurrentHealthLabel() { return STRUCT_OFFSET(UHealthBar, CurrentHealthLabel); } \
	FORCEINLINE static uint32 __PPO__MaxHealthLabel() { return STRUCT_OFFSET(UHealthBar, MaxHealthLabel); }


#define WireHunter_Source_WireHunter_HealthBar_h_10_PROLOG
#define WireHunter_Source_WireHunter_HealthBar_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	WireHunter_Source_WireHunter_HealthBar_h_13_PRIVATE_PROPERTY_OFFSET \
	WireHunter_Source_WireHunter_HealthBar_h_13_SPARSE_DATA \
	WireHunter_Source_WireHunter_HealthBar_h_13_RPC_WRAPPERS \
	WireHunter_Source_WireHunter_HealthBar_h_13_INCLASS \
	WireHunter_Source_WireHunter_HealthBar_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define WireHunter_Source_WireHunter_HealthBar_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	WireHunter_Source_WireHunter_HealthBar_h_13_PRIVATE_PROPERTY_OFFSET \
	WireHunter_Source_WireHunter_HealthBar_h_13_SPARSE_DATA \
	WireHunter_Source_WireHunter_HealthBar_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	WireHunter_Source_WireHunter_HealthBar_h_13_INCLASS_NO_PURE_DECLS \
	WireHunter_Source_WireHunter_HealthBar_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> WIREHUNTER_API UClass* StaticClass<class UHealthBar>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID WireHunter_Source_WireHunter_HealthBar_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
