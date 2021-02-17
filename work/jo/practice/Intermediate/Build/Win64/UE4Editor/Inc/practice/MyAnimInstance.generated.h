// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PRACTICE_MyAnimInstance_generated_h
#error "MyAnimInstance.generated.h already included, missing '#pragma once' in MyAnimInstance.h"
#endif
#define PRACTICE_MyAnimInstance_generated_h

#define practice_Source_practice_MyAnimInstance_h_15_SPARSE_DATA
#define practice_Source_practice_MyAnimInstance_h_15_RPC_WRAPPERS
#define practice_Source_practice_MyAnimInstance_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define practice_Source_practice_MyAnimInstance_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMyAnimInstance(); \
	friend struct Z_Construct_UClass_UMyAnimInstance_Statics; \
public: \
	DECLARE_CLASS(UMyAnimInstance, UAnimInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/practice"), NO_API) \
	DECLARE_SERIALIZER(UMyAnimInstance)


#define practice_Source_practice_MyAnimInstance_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUMyAnimInstance(); \
	friend struct Z_Construct_UClass_UMyAnimInstance_Statics; \
public: \
	DECLARE_CLASS(UMyAnimInstance, UAnimInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/practice"), NO_API) \
	DECLARE_SERIALIZER(UMyAnimInstance)


#define practice_Source_practice_MyAnimInstance_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMyAnimInstance(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMyAnimInstance) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMyAnimInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMyAnimInstance); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMyAnimInstance(UMyAnimInstance&&); \
	NO_API UMyAnimInstance(const UMyAnimInstance&); \
public:


#define practice_Source_practice_MyAnimInstance_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMyAnimInstance(UMyAnimInstance&&); \
	NO_API UMyAnimInstance(const UMyAnimInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMyAnimInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMyAnimInstance); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UMyAnimInstance)


#define practice_Source_practice_MyAnimInstance_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CurrentPawnSpeed() { return STRUCT_OFFSET(UMyAnimInstance, CurrentPawnSpeed); } \
	FORCEINLINE static uint32 __PPO__IsInAir() { return STRUCT_OFFSET(UMyAnimInstance, IsInAir); }


#define practice_Source_practice_MyAnimInstance_h_12_PROLOG
#define practice_Source_practice_MyAnimInstance_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	practice_Source_practice_MyAnimInstance_h_15_PRIVATE_PROPERTY_OFFSET \
	practice_Source_practice_MyAnimInstance_h_15_SPARSE_DATA \
	practice_Source_practice_MyAnimInstance_h_15_RPC_WRAPPERS \
	practice_Source_practice_MyAnimInstance_h_15_INCLASS \
	practice_Source_practice_MyAnimInstance_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define practice_Source_practice_MyAnimInstance_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	practice_Source_practice_MyAnimInstance_h_15_PRIVATE_PROPERTY_OFFSET \
	practice_Source_practice_MyAnimInstance_h_15_SPARSE_DATA \
	practice_Source_practice_MyAnimInstance_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	practice_Source_practice_MyAnimInstance_h_15_INCLASS_NO_PURE_DECLS \
	practice_Source_practice_MyAnimInstance_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PRACTICE_API UClass* StaticClass<class UMyAnimInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID practice_Source_practice_MyAnimInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
