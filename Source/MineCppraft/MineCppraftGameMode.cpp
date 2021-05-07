// Copyright Epic Games, Inc. All Rights Reserved.

#include "MineCppraftGameMode.h"
#include "MineCppraftHUD.h"
#include "MineCppraftCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMineCppraftGameMode::AMineCppraftGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AMineCppraftHUD::StaticClass();
}
