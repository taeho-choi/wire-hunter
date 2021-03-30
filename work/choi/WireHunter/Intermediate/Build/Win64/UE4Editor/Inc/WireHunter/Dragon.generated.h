// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef WIREHUNTER_Dragon_generated_h
#error "Dragon.generated.h already included, missing '#pragma once' in Dragon.h"
#endif
#define WIREHUNTER_Dragon_generated_h

#define WireHunter_Source_WireHunter_Dragon_h_12_SPARSE_DATA
#define WireHunter_Source_WireHunter_Dragon_h_12_RPC_WRAPPERS
#define WireHunter_Source_WireHunter_Dragon_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define WireHunter_Source_WireHunter_Dragon_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADragon(); \
	friend struct Z_Construct_UClass_ADragon_Statics; \
public: \
	DECLARE_CLASS(ADragon, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/WireHunter"), NO_API) \
	DECLARE_SERIALIZER(ADragon)


#define WireHunter_Source_WireHunter_Dragon_h_12_INCLASS \
private: \
	static void StaticRegisterNativesADragon(); \
	friend struct Z_Construct_UClass_ADragon_Statics; \
public: \
	DECLARE_CLASS(ADragon, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/WireHunter"), NO_API) \
	DECLARE_SERIALIZER(ADragon)


#define WireHunter_Source_WireHunter_Dragon_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ADragon(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ADragon) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADragon); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADragon); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADragon(ADragon&&); \
	NO_API ADragon(const ADragon&); \
public:


#define WireHunter_Source_WireHunter_Dragon_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ADragon(ADragon&&); \
	NO_API ADragon(const ADragon&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADragon); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADragon); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADragon)


#define WireHunter_Source_WireHunter_Dragon_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__MoveType() { return STRUCT_OFFSET(ADragon, MoveType); }


#define WireHunter_Source_WireHunter_Dragon_h_9_PROLOG
#define WireHunter_Source_WireHunter_Dragon_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	WireHunter_Source_WireHunter_Dragon_h_12_PRIVATE_PROPERTY_OFFSET \
	WireHunter_Source_WireHunter_Dragon_h_12_SPARSE_DATA \
	WireHunter_Source_WireHunter_Dragon_h_12_RPC_WRAPPERS \
	WireHunter_Source_WireHunter_Dragon_h_12_INCLASS \
	WireHunter_Source_WireHunter_Dragon_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define WireHunter_Source_WireHunter_Dragon_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	WireHunter_Source_WireHunter_Dragon_h_12_PRIVATE_PROPERTY_OFFSET \
	WireHunter_Source_WireHunter_Dragon_h_12_SPARSE_DATA \
	WireHunter_Source_WireHunter_Dragon_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	WireHunter_Source_WireHunter_Dragon_h_12_INCLASS_NO_PURE_DECLS \
	WireHunter_Source_WireHunter_Dragon_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> WIREHUNTER_API UClass* StaticClass<class ADragon>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID WireHunter_Source_WireHunter_Dragon_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
