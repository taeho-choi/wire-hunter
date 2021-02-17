// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PRACTICE_Fountain_generated_h
#error "Fountain.generated.h already included, missing '#pragma once' in Fountain.h"
#endif
#define PRACTICE_Fountain_generated_h

#define practice_Source_practice_Fountain_h_13_SPARSE_DATA
#define practice_Source_practice_Fountain_h_13_RPC_WRAPPERS
#define practice_Source_practice_Fountain_h_13_RPC_WRAPPERS_NO_PURE_DECLS
#define practice_Source_practice_Fountain_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFountain(); \
	friend struct Z_Construct_UClass_AFountain_Statics; \
public: \
	DECLARE_CLASS(AFountain, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/practice"), NO_API) \
	DECLARE_SERIALIZER(AFountain)


#define practice_Source_practice_Fountain_h_13_INCLASS \
private: \
	static void StaticRegisterNativesAFountain(); \
	friend struct Z_Construct_UClass_AFountain_Statics; \
public: \
	DECLARE_CLASS(AFountain, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/practice"), NO_API) \
	DECLARE_SERIALIZER(AFountain)


#define practice_Source_practice_Fountain_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFountain(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFountain) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFountain); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFountain); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFountain(AFountain&&); \
	NO_API AFountain(const AFountain&); \
public:


#define practice_Source_practice_Fountain_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFountain(AFountain&&); \
	NO_API AFountain(const AFountain&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFountain); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFountain); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFountain)


#define practice_Source_practice_Fountain_h_13_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__RotateSpeed() { return STRUCT_OFFSET(AFountain, RotateSpeed); }


#define practice_Source_practice_Fountain_h_10_PROLOG
#define practice_Source_practice_Fountain_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	practice_Source_practice_Fountain_h_13_PRIVATE_PROPERTY_OFFSET \
	practice_Source_practice_Fountain_h_13_SPARSE_DATA \
	practice_Source_practice_Fountain_h_13_RPC_WRAPPERS \
	practice_Source_practice_Fountain_h_13_INCLASS \
	practice_Source_practice_Fountain_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define practice_Source_practice_Fountain_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	practice_Source_practice_Fountain_h_13_PRIVATE_PROPERTY_OFFSET \
	practice_Source_practice_Fountain_h_13_SPARSE_DATA \
	practice_Source_practice_Fountain_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	practice_Source_practice_Fountain_h_13_INCLASS_NO_PURE_DECLS \
	practice_Source_practice_Fountain_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PRACTICE_API UClass* StaticClass<class AFountain>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID practice_Source_practice_Fountain_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
