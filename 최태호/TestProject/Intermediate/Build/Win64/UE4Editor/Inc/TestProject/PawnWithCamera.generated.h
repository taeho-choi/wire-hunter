// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TESTPROJECT_PawnWithCamera_generated_h
#error "PawnWithCamera.generated.h already included, missing '#pragma once' in PawnWithCamera.h"
#endif
#define TESTPROJECT_PawnWithCamera_generated_h

#define TestProject_Source_TestProject_PawnWithCamera_h_12_SPARSE_DATA
#define TestProject_Source_TestProject_PawnWithCamera_h_12_RPC_WRAPPERS
#define TestProject_Source_TestProject_PawnWithCamera_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define TestProject_Source_TestProject_PawnWithCamera_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPawnWithCamera(); \
	friend struct Z_Construct_UClass_APawnWithCamera_Statics; \
public: \
	DECLARE_CLASS(APawnWithCamera, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TestProject"), NO_API) \
	DECLARE_SERIALIZER(APawnWithCamera)


#define TestProject_Source_TestProject_PawnWithCamera_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAPawnWithCamera(); \
	friend struct Z_Construct_UClass_APawnWithCamera_Statics; \
public: \
	DECLARE_CLASS(APawnWithCamera, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TestProject"), NO_API) \
	DECLARE_SERIALIZER(APawnWithCamera)


#define TestProject_Source_TestProject_PawnWithCamera_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APawnWithCamera(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APawnWithCamera) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APawnWithCamera); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APawnWithCamera); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APawnWithCamera(APawnWithCamera&&); \
	NO_API APawnWithCamera(const APawnWithCamera&); \
public:


#define TestProject_Source_TestProject_PawnWithCamera_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APawnWithCamera(APawnWithCamera&&); \
	NO_API APawnWithCamera(const APawnWithCamera&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APawnWithCamera); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APawnWithCamera); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APawnWithCamera)


#define TestProject_Source_TestProject_PawnWithCamera_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__OurCameraSpringArm() { return STRUCT_OFFSET(APawnWithCamera, OurCameraSpringArm); }


#define TestProject_Source_TestProject_PawnWithCamera_h_9_PROLOG
#define TestProject_Source_TestProject_PawnWithCamera_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TestProject_Source_TestProject_PawnWithCamera_h_12_PRIVATE_PROPERTY_OFFSET \
	TestProject_Source_TestProject_PawnWithCamera_h_12_SPARSE_DATA \
	TestProject_Source_TestProject_PawnWithCamera_h_12_RPC_WRAPPERS \
	TestProject_Source_TestProject_PawnWithCamera_h_12_INCLASS \
	TestProject_Source_TestProject_PawnWithCamera_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TestProject_Source_TestProject_PawnWithCamera_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TestProject_Source_TestProject_PawnWithCamera_h_12_PRIVATE_PROPERTY_OFFSET \
	TestProject_Source_TestProject_PawnWithCamera_h_12_SPARSE_DATA \
	TestProject_Source_TestProject_PawnWithCamera_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	TestProject_Source_TestProject_PawnWithCamera_h_12_INCLASS_NO_PURE_DECLS \
	TestProject_Source_TestProject_PawnWithCamera_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TESTPROJECT_API UClass* StaticClass<class APawnWithCamera>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TestProject_Source_TestProject_PawnWithCamera_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
