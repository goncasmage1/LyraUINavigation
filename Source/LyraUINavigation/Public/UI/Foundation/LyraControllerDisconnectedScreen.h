// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CommonActivatableWidget.h"
#include "UObject/UObjectGlobals.h"

#include "LyraControllerDisconnectedScreen.generated.h"

class UHorizontalBox;
class UObject;

UCLASS(Abstract, BlueprintType, Blueprintable)
class LYRAUINAVIGATION_API ULyraControllerDisconnectedScreen : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	void NativeOnActivated() override;

private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UHorizontalBox> HBox_SwitchUser;
};