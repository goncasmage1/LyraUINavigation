// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CommonRotator.h"
#include "HAL/Platform.h"
#include "UObject/UObjectGlobals.h"

#include "GameSettingRotator.generated.h"

class UObject;

/**
 * 
 */
UCLASS(Abstract, meta = (Category = "Settings", DisableNativeTick))
class LYRAUINAVIGATION_API UGameSettingRotator : public UCommonRotator
{
	GENERATED_BODY()

public:
	UGameSettingRotator(const FObjectInitializer& Initializer);

	void SetDefaultOption(int32 DefaultOptionIndex);

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = Events, meta = (DisplayName = "On Default Option Specified"))
	void BP_OnDefaultOptionSpecified(int32 DefaultOptionIndex);
};
