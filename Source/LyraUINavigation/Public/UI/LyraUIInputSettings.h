// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "UObject/Object.h"
#include "Containers/Array.h"
#include "UObject/SoftObjectPath.h"
#include "UObject/SoftObjectPtr.h"
#include "UObject/UObjectGlobals.h"
#include "InputMappingContext.h"
#include "UI/Data/LyraUIInputActions.h"
#include "LyraUIInputSettings.generated.h"

class UObject;
class USoundEffectSubmixPreset;
class USoundSubmix;

/**
 * 
 */
UCLASS(config = Game, defaultconfig, meta = (DisplayName = "Lyra UI Input Settings"))
class LYRAUINAVIGATION_API ULyraUIInputSettings : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(config, EditAnywhere, Category = "UI Input")
	TSoftObjectPtr<UInputMappingContext> EnhancedInputContext = TSoftObjectPtr<UInputMappingContext>(FSoftObjectPath("/LyraUINavigation/Input/IC_UINav.IC_UINav"));

	UPROPERTY(config, EditAnywhere, Category = "UI Input")
	TSoftObjectPtr<ULyraUIInputActions> EnhancedInputActions = TSoftObjectPtr<ULyraUIInputActions>(FSoftObjectPath("/LyraUINavigation/Input/LyraUIInputActions.LyraUIInputActions"));

};
