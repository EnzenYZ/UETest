// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "YZ_TestWeaponComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AYZ_TestCharacter;
#ifdef YZ_TEST_YZ_TestWeaponComponent_generated_h
#error "YZ_TestWeaponComponent.generated.h already included, missing '#pragma once' in YZ_TestWeaponComponent.h"
#endif
#define YZ_TEST_YZ_TestWeaponComponent_generated_h

#define FID_Unreal_Projects_YZ_Test_Source_YZ_Test_YZ_TestWeaponComponent_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execEndPlay); \
	DECLARE_FUNCTION(execFire); \
	DECLARE_FUNCTION(execAttachWeapon);


#define FID_Unreal_Projects_YZ_Test_Source_YZ_Test_YZ_TestWeaponComponent_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUYZ_TestWeaponComponent(); \
	friend struct Z_Construct_UClass_UYZ_TestWeaponComponent_Statics; \
public: \
	DECLARE_CLASS(UYZ_TestWeaponComponent, USkeletalMeshComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/YZ_Test"), NO_API) \
	DECLARE_SERIALIZER(UYZ_TestWeaponComponent)


#define FID_Unreal_Projects_YZ_Test_Source_YZ_Test_YZ_TestWeaponComponent_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UYZ_TestWeaponComponent(UYZ_TestWeaponComponent&&); \
	UYZ_TestWeaponComponent(const UYZ_TestWeaponComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UYZ_TestWeaponComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UYZ_TestWeaponComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UYZ_TestWeaponComponent) \
	NO_API virtual ~UYZ_TestWeaponComponent();


#define FID_Unreal_Projects_YZ_Test_Source_YZ_Test_YZ_TestWeaponComponent_h_11_PROLOG
#define FID_Unreal_Projects_YZ_Test_Source_YZ_Test_YZ_TestWeaponComponent_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Projects_YZ_Test_Source_YZ_Test_YZ_TestWeaponComponent_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Unreal_Projects_YZ_Test_Source_YZ_Test_YZ_TestWeaponComponent_h_14_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Projects_YZ_Test_Source_YZ_Test_YZ_TestWeaponComponent_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> YZ_TEST_API UClass* StaticClass<class UYZ_TestWeaponComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Projects_YZ_Test_Source_YZ_Test_YZ_TestWeaponComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
