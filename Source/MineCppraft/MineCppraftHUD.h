// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MineCppraftHUD.generated.h"

UCLASS()
class AMineCppraftHUD : public AHUD
{
	GENERATED_BODY()

public:
	AMineCppraftHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

