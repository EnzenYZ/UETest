// Copyright Epic Games, Inc. All Rights Reserved.

#include "YZ_TestGameMode.h"
#include "YZ_TestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AYZ_TestGameMode::AYZ_TestGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
