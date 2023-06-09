// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "HAL/Platform.h"
#include "InputCoreTypes.h"
#include "Templates/SubclassOf.h"
#include "UObject/UObjectGlobals.h"
#include "GameSettings/Widgets/GameSettingListEntry.h"
#include "GameSettings/Widgets/Misc/KeyAlreadyBoundWarning.h"

#include "LyraSettingsListEntrySetting_KeyboardInput.generated.h"

class UGameSetting;
class UGameSettingPressAnyKey;
class ULyraButtonBase;
class ULyraSettingKeyboardInput;
class UObject;

//////////////////////////////////////////////////////////////////////////
// ULyraSettingsListEntrySetting_KeyboardInput
//////////////////////////////////////////////////////////////////////////

UCLASS(Abstract, Blueprintable, meta = (Category = "Settings", DisableNativeTick))
class LYRAUINAVIGATION_API ULyraSettingsListEntrySetting_KeyboardInput : public UGameSettingListEntry_Setting
{
	GENERATED_BODY()

public:
	virtual void SetSetting(UGameSetting* InSetting) override;

protected:
	virtual void NativeOnInitialized() override;
	virtual void NativeOnEntryReleased() override;
	virtual void OnSettingChanged() override;

	void HandlePrimaryKeyClicked();
	void HandleSecondaryKeyClicked();
	void HandleClearClicked();

	void HandlePrimaryKeySelected(FKey InKey, UGameSettingPressAnyKey* PressAnyKeyPanel);
	void HandleSecondaryKeySelected(FKey InKey, UGameSettingPressAnyKey* PressAnyKeyPanel);
	void HandlePrimaryDuplicateKeySelected(FKey InKey, UKeyAlreadyBoundWarning* DuplicateKeyPressAnyKeyPanel) const;
	void HandleSecondaryDuplicateKeySelected(FKey InKey, UKeyAlreadyBoundWarning* DuplicateKeyPressAnyKeyPanel) const;
	void ChangeBinding(int32 BindSlot, FKey InKey);
	void HandleKeySelectionCanceled(UGameSettingPressAnyKey* PressAnyKeyPanel);
	void HandleKeySelectionCanceled(UKeyAlreadyBoundWarning* PressAnyKeyPanel);

	void Refresh();

private:
	UPROPERTY(Transient)
	FKey OriginalKeyToBind = EKeys::Invalid;

protected:
	UPROPERTY()
	TObjectPtr<ULyraSettingKeyboardInput> KeyboardInputSetting;

	UPROPERTY(EditDefaultsOnly, Category = "Lyra Settings Keyboard Input")
	TSubclassOf<UGameSettingPressAnyKey> PressAnyKeyPanelClass;

	UPROPERTY(EditDefaultsOnly, Category = "Lyra Settings Keyboard Input")
	TSubclassOf<UKeyAlreadyBoundWarning> KeyAlreadyBoundWarningPanelClass;

private:	// Bound Widgets
	UPROPERTY(BlueprintReadOnly, Category = "Lyra Settings Keyboard Input", meta = (BindWidget, BlueprintProtected = true, AllowPrivateAccess = true))
	TObjectPtr<ULyraButtonBase> Button_PrimaryKey;

	UPROPERTY(BlueprintReadOnly, Category = "Lyra Settings Keyboard Input", meta = (BindWidget, BlueprintProtected = true, AllowPrivateAccess = true))
	TObjectPtr<ULyraButtonBase> Button_SecondaryKey;

	UPROPERTY(BlueprintReadOnly, Category = "Lyra Settings Keyboard Input", meta = (BindWidget, BlueprintProtected = true, AllowPrivateAccess = true))
	TObjectPtr<ULyraButtonBase> Button_Clear;
};
