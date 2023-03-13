// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "AudioMixerBlueprintLibrary.h"
#include "CommonGame/CommonLocalPlayer.h"
#include "Containers/UnrealString.h"
#include "HAL/Platform.h"
#include "UObject/UObjectGlobals.h"
#include "UObject/WeakObjectPtrTemplates.h"

#include "LyraLocalPlayer.generated.h"

class APlayerController;
class UInputMappingContext;
class ULyraSettingsLocal;
class ULyraSettingsShared;
class UObject;
class UWorld;
struct FSwapAudioOutputResult;

/**
 * ULyraLocalPlayer
 */
UCLASS()
class LYRAUINAVIGATION_API ULyraLocalPlayer : public UCommonLocalPlayer
{
	GENERATED_BODY()

public:

	ULyraLocalPlayer();

	//~UObject interface
	virtual void PostInitProperties() override;
	//~End of UObject interface

public:
	UFUNCTION()
	ULyraSettingsLocal* GetLocalSettings() const;

	UFUNCTION()
	ULyraSettingsShared* GetSharedSettings() const;

protected:
	void OnAudioOutputDeviceChanged(const FString& InAudioOutputDeviceId);
	
	UFUNCTION()
	void OnCompletedAudioDeviceSwap(const FSwapAudioOutputResult& SwapResult);

private:
	UPROPERTY(Transient)
	mutable TObjectPtr<ULyraSettingsShared> SharedSettings;

	UPROPERTY(Transient)
	mutable TObjectPtr<const UInputMappingContext> InputMappingContext;

	UPROPERTY()
	TWeakObjectPtr<APlayerController> LastBoundPC;
};
