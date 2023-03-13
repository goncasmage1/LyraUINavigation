// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Components/ListView.h"
#include "GameSettingListEntry.h"

#include "GameSettingListView.generated.h"

class UGameSettingCollection;
class ULocalPlayer;
class UGameSettingVisualData;

/**
 * List of game settings.  Every entry widget needs to extend from GameSettingListEntryBase.
 */
UCLASS(meta = (EntryClass = GameSettingListEntryBase))
class LYRAUINAVIGATION_API UGameSettingListView : public UListView
{
	GENERATED_BODY()

public:
	UGameSettingListView(const FObjectInitializer& ObjectInitializer);

	void AddNameOverride(const FName& DevName, const FText& OverrideName);

#if WITH_EDITOR
	virtual void ValidateCompiledDefaults(IWidgetCompilerLog& InCompileLog) const override;
#endif

protected:
	virtual UUserWidget& OnGenerateEntryWidgetInternal(UObject* Item, TSubclassOf<UUserWidget> DesiredEntryClass, const TSharedRef<STableViewBase>& OwnerTable) override;
	virtual bool OnIsSelectableOrNavigableInternal(UObject* SelectedItem) override;

protected:
	UPROPERTY(EditAnywhere, Category = "Game Setting List View")
	TObjectPtr<UGameSettingVisualData> VisualData;

private:
	TMap<FName, FText> NameOverrides;
};