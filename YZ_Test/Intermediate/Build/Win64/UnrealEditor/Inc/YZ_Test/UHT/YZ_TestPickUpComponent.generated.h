// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "YZ_TestPickUpComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class AYZ_TestCharacter;
class UPrimitiveComponent;
struct FHitResult;
#ifdef YZ_TEST_YZ_TestPickUpComponent_generated_h
#error "YZ_TestPickUpComponent.generated.h already included, missing '#pragma once' in YZ_TestPickUpComponent.h"
#endif
#define YZ_TEST_YZ_TestPickUpComponent_generated_h

#define FID_Unreal_Projects_YZ_Test_Source_YZ_Test_YZ_TestPickUpComponent_h_12_DELEGATE \
YZ_TEST_API void FOnPickUp_DelegateWrapper(const FMulticastScriptDelegate& OnPickUp, AYZ_TestCharacter* PickUpCharacter);


#define FID_Unreal_Projects_YZ_Test_Source_YZ_Test_YZ_TestPickUpComponent_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnSphereBeginOverlap);


#define FID_Unreal_Projects_YZ_Test_Source_YZ_Test_YZ_TestPickUpComponent_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUYZ_TestPickUpComponent(); \
	friend struct Z_Construct_UClass_UYZ_TestPickUpComponent_Statics; \
public: \
	DECLARE_CLASS(UYZ_TestPickUpComponent, USphereComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/YZ_Test"), NO_API) \
	DECLARE_SERIALIZER(UYZ_TestPickUpComponent)


#define FID_Unreal_Projects_YZ_Test_Source_YZ_Test_YZ_TestPickUpComponent_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UYZ_TestPickUpComponent(UYZ_TestPickUpComponent&&); \
	UYZ_TestPickUpComponent(const UYZ_TestPickUpComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UYZ_TestPickUpComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UYZ_TestPickUpComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UYZ_TestPickUpComponent) \
	NO_API virtual ~UYZ_TestPickUpComponent();


#define FID_Unreal_Projects_YZ_Test_Source_YZ_Test_YZ_TestPickUpComponent_h_14_PROLOG
#define FID_Unreal_Projects_YZ_Test_Source_YZ_Test_YZ_TestPickUpComponent_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Projects_YZ_Test_Source_YZ_Test_YZ_TestPickUpComponent_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Unreal_Projects_YZ_Test_Source_YZ_Test_YZ_TestPickUpComponent_h_17_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Projects_YZ_Test_Source_YZ_Test_YZ_TestPickUpComponent_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> YZ_TEST_API UClass* StaticClass<class UYZ_TestPickUpComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Projects_YZ_Test_Source_YZ_Test_YZ_TestPickUpComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
