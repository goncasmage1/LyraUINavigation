// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameSettings/GameSettingFilterState.h"
#include "Templates/SharedPointer.h"

class ULocalPlayer;


class LYRAUINAVIGATION_API FWhenPlayingAsPrimaryPlayer : public FGameSettingEditCondition
{
public:
	static TSharedRef<FWhenPlayingAsPrimaryPlayer> Get();

	virtual void GatherEditState(const ULocalPlayer* InLocalPlayer, FGameSettingEditableState& InOutEditState) const override;
};
