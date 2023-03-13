// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Containers/Array.h"
#include "GameSettings/GameSettingAction.h"
#include "GameSettings/GameSettingValueScalarDynamic.h"
#include "UObject/UObjectGlobals.h"

#include "LyraSettingAction_SafeZoneEditor.generated.h"

class UGameSetting;
class UObject;


UCLASS()
class LYRAUINAVIGATION_API ULyraSettingValueScalarDynamic_SafeZoneValue : public UGameSettingValueScalarDynamic
{
	GENERATED_BODY()

public:
	virtual void ResetToDefault() override;
	virtual void RestoreToInitial() override;
};

UCLASS()
class LYRAUINAVIGATION_API ULyraSettingAction_SafeZoneEditor : public UGameSettingAction
{
	GENERATED_BODY()
	
public:
	ULyraSettingAction_SafeZoneEditor();
	virtual TArray<UGameSetting*> GetChildSettings() override;

private:
	UPROPERTY()
	TObjectPtr<ULyraSettingValueScalarDynamic_SafeZoneValue> SafeZoneValueSetting;
};