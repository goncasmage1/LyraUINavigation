// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CommonActivatableWidget.h"
#include "Containers/Array.h"
#include "CoreTypes.h"
#include "GameSettings/GameSettingRegistry.h"
#include "GameSettings/GameSettingRegistryChangeTracker.h"
#include "Misc/AssertionMacros.h"
#include "UObject/NameTypes.h"
#include "UObject/UObjectGlobals.h"

#include "GameSettingScreen.generated.h"

class UGameSetting;
class UGameSettingCollection;
class UGameSettingPanel;
class UObject;
class UWidget;
struct FFrame;

enum class EGameSettingChangeReason : uint8;

/**
 * 
 */
UCLASS(Abstract, meta = (Category = "Settings", DisableNativeTick))
class LYRAUINAVIGATION_API UGameSettingScreen : public UCommonActivatableWidget
{
	GENERATED_BODY()
public:

protected:
	virtual void NativeOnInitialized() override;
	virtual void NativeOnActivated() override;
	virtual void NativeOnDeactivated() override;
	virtual UWidget* NativeGetDesiredFocusTarget() const override;

	UFUNCTION(BlueprintCallable, Category = "Game Setting Screen")
	void NavigateToSetting(FName SettingDevName);
	
	UFUNCTION(BlueprintCallable, Category = "Game Setting Screen")
	void NavigateToSettings(const TArray<FName>& SettingDevNames);

	UFUNCTION(BlueprintNativeEvent)
	void OnSettingsDirtyStateChanged(bool bSettingsDirty);
	virtual void OnSettingsDirtyStateChanged_Implementation(bool bSettingsDirty) { }

	UFUNCTION(BlueprintCallable, Category = "Game Setting Screen")
	bool AttemptToPopNavigation();

	UFUNCTION(BlueprintCallable, Category = "Game Setting Screen")
	UGameSettingCollection* GetSettingCollection(FName SettingDevName, bool& HasAnySettings); 

protected:
	virtual UGameSettingRegistry* CreateRegistry() PURE_VIRTUAL(, return nullptr;);

	template <typename GameSettingRegistryT = UGameSettingRegistry>
	GameSettingRegistryT* GetRegistry() const { return Cast<GameSettingRegistryT>(const_cast<UGameSettingScreen*>(this)->GetOrCreateRegistry()); }

	UFUNCTION(BlueprintCallable, Category = "Game Setting Screen")
	virtual void CancelChanges();

	UFUNCTION(BlueprintCallable, Category = "Game Setting Screen")
	virtual void ApplyChanges();

	UFUNCTION(BlueprintCallable, Category = "Game Setting Screen")
	bool HaveSettingsBeenChanged() const { return ChangeTracker.HaveSettingsBeenChanged(); }

	void ClearDirtyState();

	void HandleSettingChanged(UGameSetting* Setting, EGameSettingChangeReason Reason);

	FGameSettingRegistryChangeTracker ChangeTracker;

private:
	UGameSettingRegistry* GetOrCreateRegistry();

private:	// Bound Widgets
	UPROPERTY(BlueprintReadOnly, Category = "Game Setting Screen", meta = (BindWidget, BlueprintProtected = true, AllowPrivateAccess = true))
	TObjectPtr<UGameSettingPanel> Settings_Panel;

	UPROPERTY(Transient)
	mutable TObjectPtr<UGameSettingRegistry> Registry;
};
