// Copyright Epic Games, Inc. All Rights Reserved.

#include "JamProjectGameMode.h"
#include "JamProjectHUD.h"
#include "JamProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AJamProjectGameMode::AJamProjectGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AJamProjectHUD::StaticClass();
}
