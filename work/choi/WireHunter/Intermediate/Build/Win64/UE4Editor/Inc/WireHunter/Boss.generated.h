// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FVector;
struct FStructNode;
#ifdef WIREHUNTER_Boss_generated_h
#error "Boss.generated.h already included, missing '#pragma once' in Boss.h"
#endif
#define WIREHUNTER_Boss_generated_h

#define WireHunter_Source_WireHunter_Boss_h_20_SPARSE_DATA
#define WireHunter_Source_WireHunter_Boss_h_20_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execDetectKick); \
	DECLARE_FUNCTION(execSetToFace); \
	DECLARE_FUNCTION(execGetToFace); \
	DECLARE_FUNCTION(execLightning); \
	DECLARE_FUNCTION(execGetPath); \
	DECLARE_FUNCTION(execDoAStar); \
	DECLARE_FUNCTION(execGetGoal); \
	DECLARE_FUNCTION(execFindPlayer); \
	DECLARE_FUNCTION(execSpawn);


#define WireHunter_Source_WireHunter_Boss_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execDetectKick); \
	DECLARE_FUNCTION(execSetToFace); \
	DECLARE_FUNCTION(execGetToFace); \
	DECLARE_FUNCTION(execLightning); \
	DECLARE_FUNCTION(execGetPath); \
	DECLARE_FUNCTION(execDoAStar); \
	DECLARE_FUNCTION(execGetGoal); \
	DECLARE_FUNCTION(execFindPlayer); \
	DECLARE_FUNCTION(execSpawn);


#define WireHunter_Source_WireHunter_Boss_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABoss(); \
	friend struct Z_Construct_UClass_ABoss_Statics; \
public: \
	DECLARE_CLASS(ABoss, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/WireHunter"), NO_API) \
	DECLARE_SERIALIZER(ABoss)


#define WireHunter_Source_WireHunter_Boss_h_20_INCLASS \
private: \
	static void StaticRegisterNativesABoss(); \
	friend struct Z_Construct_UClass_ABoss_Statics; \
public: \
	DECLARE_CLASS(ABoss, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/WireHunter"), NO_API) \
	DECLARE_SERIALIZER(ABoss)


#define WireHunter_Source_WireHunter_Boss_h_20_STANDARD_CONSTRUCTORS \
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


#define WireHunter_Source_WireHunter_Boss_h_20_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABoss(ABoss&&); \
	NO_API ABoss(const ABoss&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABoss); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABoss); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABoss)


#define WireHunter_Source_WireHunter_Boss_h_20_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__ToSpawn() { return STRUCT_OFFSET(ABoss, ToSpawn); } \
	FORCEINLINE static uint32 __PPO__ToLightning() { return STRUCT_OFFSET(ABoss, ToLightning); } \
	FORCEINLINE static uint32 __PPO__BossRoot() { return STRUCT_OFFSET(ABoss, BossRoot); } \
	FORCEINLINE static uint32 __PPO__BossSkeletalMesh() { return STRUCT_OFFSET(ABoss, BossSkeletalMesh); } \
	FORCEINLINE static uint32 __PPO__Health() { return STRUCT_OFFSET(ABoss, Health); } \
	FORCEINLINE static uint32 __PPO__MaxHealth() { return STRUCT_OFFSET(ABoss, MaxHealth); }


#define WireHunter_Source_WireHunter_Boss_h_17_PROLOG
#define WireHunter_Source_WireHunter_Boss_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	WireHunter_Source_WireHunter_Boss_h_20_PRIVATE_PROPERTY_OFFSET \
	WireHunter_Source_WireHunter_Boss_h_20_SPARSE_DATA \
	WireHunter_Source_WireHunter_Boss_h_20_RPC_WRAPPERS \
	WireHunter_Source_WireHunter_Boss_h_20_INCLASS \
	WireHunter_Source_WireHunter_Boss_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define WireHunter_Source_WireHunter_Boss_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	WireHunter_Source_WireHunter_Boss_h_20_PRIVATE_PROPERTY_OFFSET \
	WireHunter_Source_WireHunter_Boss_h_20_SPARSE_DATA \
	WireHunter_Source_WireHunter_Boss_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	WireHunter_Source_WireHunter_Boss_h_20_INCLASS_NO_PURE_DECLS \
	WireHunter_Source_WireHunter_Boss_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> WIREHUNTER_API UClass* StaticClass<class ABoss>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID WireHunter_Source_WireHunter_Boss_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
