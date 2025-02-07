// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "YZ_Test/YZ_TestGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeYZ_TestGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_YZ_Test();
YZ_TEST_API UClass* Z_Construct_UClass_AYZ_TestGameMode();
YZ_TEST_API UClass* Z_Construct_UClass_AYZ_TestGameMode_NoRegister();
// End Cross Module References

// Begin Class AYZ_TestGameMode
void AYZ_TestGameMode::StaticRegisterNativesAYZ_TestGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AYZ_TestGameMode);
UClass* Z_Construct_UClass_AYZ_TestGameMode_NoRegister()
{
	return AYZ_TestGameMode::StaticClass();
}
struct Z_Construct_UClass_AYZ_TestGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "YZ_TestGameMode.h" },
		{ "ModuleRelativePath", "YZ_TestGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AYZ_TestGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AYZ_TestGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_YZ_Test,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AYZ_TestGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AYZ_TestGameMode_Statics::ClassParams = {
	&AYZ_TestGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AYZ_TestGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AYZ_TestGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AYZ_TestGameMode()
{
	if (!Z_Registration_Info_UClass_AYZ_TestGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AYZ_TestGameMode.OuterSingleton, Z_Construct_UClass_AYZ_TestGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AYZ_TestGameMode.OuterSingleton;
}
template<> YZ_TEST_API UClass* StaticClass<AYZ_TestGameMode>()
{
	return AYZ_TestGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AYZ_TestGameMode);
AYZ_TestGameMode::~AYZ_TestGameMode() {}
// End Class AYZ_TestGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Unreal_Projects_YZ_Test_Source_YZ_Test_YZ_TestGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AYZ_TestGameMode, AYZ_TestGameMode::StaticClass, TEXT("AYZ_TestGameMode"), &Z_Registration_Info_UClass_AYZ_TestGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AYZ_TestGameMode), 2128649955U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_YZ_Test_Source_YZ_Test_YZ_TestGameMode_h_239815719(TEXT("/Script/YZ_Test"),
	Z_CompiledInDeferFile_FID_Unreal_Projects_YZ_Test_Source_YZ_Test_YZ_TestGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_YZ_Test_Source_YZ_Test_YZ_TestGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
