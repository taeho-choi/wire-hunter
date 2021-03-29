// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WireHunter/WireHunterCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWireHunterCharacter() {}
// Cross Module References
	WIREHUNTER_API UClass* Z_Construct_UClass_AWireHunterCharacter_NoRegister();
	WIREHUNTER_API UClass* Z_Construct_UClass_AWireHunterCharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_WireHunter();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	WIREHUNTER_API UClass* Z_Construct_UClass_ABullet_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	ENGINE_API UClass* Z_Construct_UClass_UParticleSystem_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UWidgetComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
// End Cross Module References
	void AWireHunterCharacter::StaticRegisterNativesAWireHunterCharacter()
	{
	}
	UClass* Z_Construct_UClass_AWireHunterCharacter_NoRegister()
	{
		return AWireHunterCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AWireHunterCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ProjectileClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_ProjectileClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MuzzleOffset_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_MuzzleOffset;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LockLeftClimb_MetaData[];
#endif
		static void NewProp_LockLeftClimb_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_LockLeftClimb;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LockRightClimb_MetaData[];
#endif
		static void NewProp_LockRightClimb_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_LockRightClimb;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WallRightVector_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_WallRightVector;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WallUpVector_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_WallUpVector;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_isClimbing_MetaData[];
#endif
		static void NewProp_isClimbing_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isClimbing;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FloatingRot_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_FloatingRot;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FloatingPos_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_FloatingPos;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxHealth_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MaxHealth;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Health_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Health;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BaseLookUpRate_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BaseLookUpRate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BaseTurnRate_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BaseTurnRate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TimerBetweenShots_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_TimerBetweenShots;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ImpactParticle_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ImpactParticle;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HealthWidget_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HealthWidget;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FollowCamera_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FollowCamera;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AWireHunterCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_WireHunter,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "WireHunterCharacter.h" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_ProjectileClass_MetaData[] = {
		{ "Category", "Projectile" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_ProjectileClass = { "ProjectileClass", nullptr, (EPropertyFlags)0x0014000000010001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, ProjectileClass), Z_Construct_UClass_ABullet_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_ProjectileClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_ProjectileClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MuzzleOffset_MetaData[] = {
		{ "Category", "GamePlay" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MuzzleOffset = { "MuzzleOffset", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, MuzzleOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MuzzleOffset_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MuzzleOffset_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_LockLeftClimb_MetaData[] = {
		{ "Category", "Floating" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	void Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_LockLeftClimb_SetBit(void* Obj)
	{
		((AWireHunterCharacter*)Obj)->LockLeftClimb = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_LockLeftClimb = { "LockLeftClimb", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AWireHunterCharacter), &Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_LockLeftClimb_SetBit, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_LockLeftClimb_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_LockLeftClimb_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_LockRightClimb_MetaData[] = {
		{ "Category", "Floating" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	void Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_LockRightClimb_SetBit(void* Obj)
	{
		((AWireHunterCharacter*)Obj)->LockRightClimb = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_LockRightClimb = { "LockRightClimb", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AWireHunterCharacter), &Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_LockRightClimb_SetBit, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_LockRightClimb_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_LockRightClimb_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_WallRightVector_MetaData[] = {
		{ "Category", "Floating" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_WallRightVector = { "WallRightVector", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, WallRightVector), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_WallRightVector_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_WallRightVector_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_WallUpVector_MetaData[] = {
		{ "Category", "Floating" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_WallUpVector = { "WallUpVector", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, WallUpVector), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_WallUpVector_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_WallUpVector_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_isClimbing_MetaData[] = {
		{ "Category", "Floating" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	void Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_isClimbing_SetBit(void* Obj)
	{
		((AWireHunterCharacter*)Obj)->isClimbing = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_isClimbing = { "isClimbing", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AWireHunterCharacter), &Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_isClimbing_SetBit, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_isClimbing_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_isClimbing_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_FloatingRot_MetaData[] = {
		{ "Category", "Floating" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_FloatingRot = { "FloatingRot", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, FloatingRot), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_FloatingRot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_FloatingRot_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_FloatingPos_MetaData[] = {
		{ "Category", "Floating" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_FloatingPos = { "FloatingPos", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, FloatingPos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_FloatingPos_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_FloatingPos_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MaxHealth_MetaData[] = {
		{ "Category", "Status" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MaxHealth = { "MaxHealth", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, MaxHealth), METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MaxHealth_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MaxHealth_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_Health_MetaData[] = {
		{ "Category", "Status" },
		{ "Comment", "// Character's Status\n" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
		{ "ToolTip", "Character's Status" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_Health = { "Health", nullptr, (EPropertyFlags)0x0020080000010005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, Health), METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_Health_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_Health_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_BaseLookUpRate_MetaData[] = {
		{ "Category", "Camera" },
		{ "Comment", "/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
		{ "ToolTip", "Base look up/down rate, in deg/sec. Other scaling may affect final rate." },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_BaseLookUpRate = { "BaseLookUpRate", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, BaseLookUpRate), METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_BaseLookUpRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_BaseLookUpRate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_BaseTurnRate_MetaData[] = {
		{ "Category", "Camera" },
		{ "Comment", "/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
		{ "ToolTip", "Base turn rate, in deg/sec. Other scaling may affect final turn rate." },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_BaseTurnRate = { "BaseTurnRate", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, BaseTurnRate), METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_BaseTurnRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_BaseTurnRate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_TimerBetweenShots_MetaData[] = {
		{ "Category", "Gameplay" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_TimerBetweenShots = { "TimerBetweenShots", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, TimerBetweenShots), METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_TimerBetweenShots_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_TimerBetweenShots_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_ImpactParticle_MetaData[] = {
		{ "Category", "Gameplay" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_ImpactParticle = { "ImpactParticle", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, ImpactParticle), Z_Construct_UClass_UParticleSystem_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_ImpactParticle_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_ImpactParticle_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_HealthWidget_MetaData[] = {
		{ "Category", "WireHunterCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_HealthWidget = { "HealthWidget", nullptr, (EPropertyFlags)0x00400000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, HealthWidget), Z_Construct_UClass_UWidgetComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_HealthWidget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_HealthWidget_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_FollowCamera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/** Follow camera */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
		{ "ToolTip", "Follow camera" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_FollowCamera = { "FollowCamera", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, FollowCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_FollowCamera_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_FollowCamera_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/** Camera boom positioning the camera behind the character */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "WireHunterCharacter.h" },
		{ "ToolTip", "Camera boom positioning the camera behind the character" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWireHunterCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_CameraBoom_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_CameraBoom_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AWireHunterCharacter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_ProjectileClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MuzzleOffset,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_LockLeftClimb,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_LockRightClimb,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_WallRightVector,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_WallUpVector,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_isClimbing,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_FloatingRot,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_FloatingPos,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_MaxHealth,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_Health,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_BaseLookUpRate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_BaseTurnRate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_TimerBetweenShots,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_ImpactParticle,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_HealthWidget,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_FollowCamera,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWireHunterCharacter_Statics::NewProp_CameraBoom,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AWireHunterCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWireHunterCharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AWireHunterCharacter_Statics::ClassParams = {
		&AWireHunterCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AWireHunterCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::PropPointers),
		0,
		0x008000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AWireHunterCharacter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AWireHunterCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AWireHunterCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AWireHunterCharacter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AWireHunterCharacter, 2388792526);
	template<> WIREHUNTER_API UClass* StaticClass<AWireHunterCharacter>()
	{
		return AWireHunterCharacter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AWireHunterCharacter(Z_Construct_UClass_AWireHunterCharacter, &AWireHunterCharacter::StaticClass, TEXT("/Script/WireHunter"), TEXT("AWireHunterCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AWireHunterCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
