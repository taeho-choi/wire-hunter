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
#ifdef WIREHUNTER_PickUp_generated_h
#error "PickUp.generated.h already included, missing '#pragma once' in PickUp.h"
#endif
#define WIREHUNTER_PickUp_generated_h

#define WireHunter_Source_WireHunter_PickUp_h_13_SPARSE_DATA
#define WireHunter_Source_WireHunter_PickUp_h_13_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnPlayerEnterPickupBox);


#define WireHunter_Source_WireHunter_PickUp_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnPlayerEnterPickupBox);


#define WireHunter_Source_WireHunter_PickUp_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPickUp(); \
	friend struct Z_Construct_UClass_APickUp_Statics; \
public: \
	DECLARE_CLASS(APickUp, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/WireHunter"), NO_API) \
	DECLARE_SERIALIZER(APickUp)


#define WireHunter_Source_WireHunter_PickUp_h_13_INCLASS \
private: \
	static void StaticRegisterNativesAPickUp(); \
	friend struct Z_Construct_UClass_APickUp_Statics; \
public: \
	DECLARE_CLASS(APickUp, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/WireHunter"), NO_API) \
	DECLARE_SERIALIZER(APickUp)


#define WireHunter_Source_WireHunter_PickUp_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APickUp(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APickUp) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APickUp); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APickUp); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APickUp(APickUp&&); \
	NO_API APickUp(const APickUp&); \
public:


#define WireHunter_Source_WireHunter_PickUp_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APickUp(APickUp&&); \
	NO_API APickUp(const APickUp&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APickUp); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APickUp); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APickUp)


#define WireHunter_Source_WireHunter_PickUp_h_13_PRIVATE_PROPERTY_OFFSET
#define WireHunter_Source_WireHunter_PickUp_h_10_PROLOG
#define WireHunter_Source_WireHunter_PickUp_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	WireHunter_Source_WireHunter_PickUp_h_13_PRIVATE_PROPERTY_OFFSET \
	WireHunter_Source_WireHunter_PickUp_h_13_SPARSE_DATA \
	WireHunter_Source_WireHunter_PickUp_h_13_RPC_WRAPPERS \
	WireHunter_Source_WireHunter_PickUp_h_13_INCLASS \
	WireHunter_Source_WireHunter_PickUp_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define WireHunter_Source_WireHunter_PickUp_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	WireHunter_Source_WireHunter_PickUp_h_13_PRIVATE_PROPERTY_OFFSET \
	WireHunter_Source_WireHunter_PickUp_h_13_SPARSE_DATA \
	WireHunter_Source_WireHunter_PickUp_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	WireHunter_Source_WireHunter_PickUp_h_13_INCLASS_NO_PURE_DECLS \
	WireHunter_Source_WireHunter_PickUp_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> WIREHUNTER_API UClass* StaticClass<class APickUp>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID WireHunter_Source_WireHunter_PickUp_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
