// Copyright (C) 2023 Gonçalo Marques - All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Framework/Application/NavigationConfig.h" // from Slate

class LYRAUINAVIGATION_API FLyraNavigationConfig : public FNavigationConfig
{
public:
	FLyraNavigationConfig();

	virtual EUINavigation GetNavigationDirectionFromAnalog(const FAnalogInputEvent& InAnalogEvent) override;

	virtual EUINavigationAction GetNavigationActionForKey(const FKey& InKey) const override;

	TMap<FKey, EUINavigationAction> KeyActionRules;
};