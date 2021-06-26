// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef WIREHUNTER_Fireball_generated_h
#error "Fireball.generated.h already included, missing '#pragma once' in Fireball.h"
#endif
#define WIREHUNTER_Fireball_generated_h

#define WireHunter_Source_WireHunter_Fireball_h_12_SPARSE_DATA
#define WireHunter_Source_WireHunter_Fireball_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit);


#define WireHunter_Source_WireHunter_Fireball_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit);


#define WireHunter_Source_WireHunter_Fireball_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFireball(); \
	friend struct Z_Construct_UClass_AFireball_Statics; \
public: \
	DECLARE_CLASS(AFireball, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/WireHunter"), NO_API) \
	DECLARE_SERIALIZER(AFireball)


#define WireHunter_Source_WireHunter_Fireball_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAFireball(); \
	friend struct Z_Construct_UClass_AFireball_Statics; \
public: \
	DECLARE_CLASS(AFireball, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/WireHunter"), NO_API) \
	DECLARE_SERIALIZER(AFireball)


#define WireHunter_Source_WireHunter_Fireball_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFireball(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFireball) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFireball); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFireball); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFireball(AFireball&&); \
	NO_API AFireball(const AFireball&); \
public:


#define WireHunter_Source_WireHunter_Fireball_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFireball(AFireball&&); \
	NO_API AFireball(const AFireball&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFireball); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFireball); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFireball)


#define WireHunter_Source_WireHunter_Fireball_h_12_PRIVATE_PROPERTY_OFFSET
#define WireHunter_Source_WireHunter_Fireball_h_9_PROLOG
#define WireHunter_Source_WireHunter_Fireball_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	WireHunter_Source_WireHunter_Fireball_h_12_PRIVATE_PROPERTY_OFFSET \
	WireHunter_Source_WireHunter_Fireball_h_12_SPARSE_DATA \
	WireHunter_Source_WireHunter_Fireball_h_12_RPC_WRAPPERS \
	WireHunter_Source_WireHunter_Fireball_h_12_INCLASS \
	WireHunter_Source_WireHunter_Fireball_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define WireHunter_Source_WireHunter_Fireball_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	WireHunter_Source_WireHunter_Fireball_h_12_PRIVATE_PROPERTY_OFFSET \
	WireHunter_Source_WireHunter_Fireball_h_12_SPARSE_DATA \
	WireHunter_Source_WireHunter_Fireball_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	WireHunter_Source_WireHunter_Fireball_h_12_INCLASS_NO_PURE_DECLS \
	WireHunter_Source_WireHunter_Fireball_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> WIREHUNTER_API UClass* StaticClass<class AFireball>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID WireHunter_Source_WireHunter_Fireball_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
