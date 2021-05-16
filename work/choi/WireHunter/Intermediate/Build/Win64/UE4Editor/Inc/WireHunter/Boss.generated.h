// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef WIREHUNTER_Boss_generated_h
#error "Boss.generated.h already included, missing '#pragma once' in Boss.h"
#endif
#define WIREHUNTER_Boss_generated_h

#define WireHunter_Source_WireHunter_Boss_h_18_SPARSE_DATA
#define WireHunter_Source_WireHunter_Boss_h_18_RPC_WRAPPERS
#define WireHunter_Source_WireHunter_Boss_h_18_RPC_WRAPPERS_NO_PURE_DECLS
#define WireHunter_Source_WireHunter_Boss_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABoss(); \
	friend struct Z_Construct_UClass_ABoss_Statics; \
public: \
	DECLARE_CLASS(ABoss, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/WireHunter"), NO_API) \
	DECLARE_SERIALIZER(ABoss)


#define WireHunter_Source_WireHunter_Boss_h_18_INCLASS \
private: \
	static void StaticRegisterNativesABoss(); \
	friend struct Z_Construct_UClass_ABoss_Statics; \
public: \
	DECLARE_CLASS(ABoss, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/WireHunter"), NO_API) \
	DECLARE_SERIALIZER(ABoss)


#define WireHunter_Source_WireHunter_Boss_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABoss(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABoss) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABoss); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABoss); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABoss(ABoss&&); \
	NO_API ABoss(const ABoss&); \
public:


#define WireHunter_Source_WireHunter_Boss_h_18_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABoss(ABoss&&); \
	NO_API ABoss(const ABoss&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABoss); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABoss); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABoss)


#define WireHunter_Source_WireHunter_Boss_h_18_PRIVATE_PROPERTY_OFFSET
#define WireHunter_Source_WireHunter_Boss_h_15_PROLOG
#define WireHunter_Source_WireHunter_Boss_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	WireHunter_Source_WireHunter_Boss_h_18_PRIVATE_PROPERTY_OFFSET \
	WireHunter_Source_WireHunter_Boss_h_18_SPARSE_DATA \
	WireHunter_Source_WireHunter_Boss_h_18_RPC_WRAPPERS \
	WireHunter_Source_WireHunter_Boss_h_18_INCLASS \
	WireHunter_Source_WireHunter_Boss_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define WireHunter_Source_WireHunter_Boss_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	WireHunter_Source_WireHunter_Boss_h_18_PRIVATE_PROPERTY_OFFSET \
	WireHunter_Source_WireHunter_Boss_h_18_SPARSE_DATA \
	WireHunter_Source_WireHunter_Boss_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	WireHunter_Source_WireHunter_Boss_h_18_INCLASS_NO_PURE_DECLS \
	WireHunter_Source_WireHunter_Boss_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> WIREHUNTER_API UClass* StaticClass<class ABoss>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID WireHunter_Source_WireHunter_Boss_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
