// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "YZ_TestProjectile.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef YZ_TEST_YZ_TestProjectile_generated_h
#error "YZ_TestProjectile.generated.h already included, missing '#pragma once' in YZ_TestProjectile.h"
#endif
#define YZ_TEST_YZ_TestProjectile_generated_h

#define FID_Unreal_Projects_YZ_Test_Source_YZ_Test_YZ_TestProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnHit);


#define FID_Unreal_Projects_YZ_Test_Source_YZ_Test_YZ_TestProjectile_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAYZ_TestProjectile(); \
	friend struct Z_Construct_UClass_AYZ_TestProjectile_Statics; \
public: \
	DECLARE_CLASS(AYZ_TestProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/YZ_Test"), NO_API) \
	DECLARE_SERIALIZER(AYZ_TestProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_Unreal_Projects_YZ_Test_Source_YZ_Test_YZ_TestProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AYZ_TestProjectile(AYZ_TestProjectile&&); \
	AYZ_TestProjectile(const AYZ_TestProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AYZ_TestProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AYZ_TestProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AYZ_TestProjectile) \
	NO_API virtual ~AYZ_TestProjectile();


#define FID_Unreal_Projects_YZ_Test_Source_YZ_Test_YZ_TestProjectile_h_12_PROLOG
#define FID_Unreal_Projects_YZ_Test_Source_YZ_Test_YZ_TestProjectile_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Projects_YZ_Test_Source_YZ_Test_YZ_TestProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Unreal_Projects_YZ_Test_Source_YZ_Test_YZ_TestProjectile_h_15_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Projects_YZ_Test_Source_YZ_Test_YZ_TestProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> YZ_TEST_API UClass* StaticClass<class AYZ_TestProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Projects_YZ_Test_Source_YZ_Test_YZ_TestProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
