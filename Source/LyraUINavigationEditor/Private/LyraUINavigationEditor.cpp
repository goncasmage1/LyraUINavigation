// Fill out your copyright notice in the Description page of Project Settings.

#include "LyraUINavigationEditor.h"

#include "UI/Subsystem/LyraUIManagerSubsystem.h"
#include "ISettingsModule.h"
#include "ISettingsSection.h"
#include "Modules/ModuleManager.h"
#include "UI/LyraUIInputSettings.h"

#define LOCTEXT_NAMESPACE "FLyraUINavigationEditorModule"

void FLyraUINavigationEditorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	RegisterSettings();
}

void FLyraUINavigationEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	if (UObjectInitialized())
	{
		UnregisterSettings();
	}
}

void FLyraUINavigationEditorModule::RegisterSettings()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		ISettingsSectionPtr UIManagerSettingsSection = SettingsModule->RegisterSettings("Project", "Game", "LyraUIPolicy",
			LOCTEXT("LyraUINavigationSettingsName", "Lyra UI Policy"),
			LOCTEXT("LyraUINavigationSettingsDescription", "Configure the Lyra UI policy."),
			GetMutableDefault<ULyraUIManagerSubsystem>()
		);

		if (UIManagerSettingsSection.IsValid())
		{
			UIManagerSettingsSection->OnModified().BindRaw(this, &FLyraUINavigationEditorModule::HandleSettingsSaved);
		}

		ISettingsSectionPtr UIInputSettingsSection = SettingsModule->RegisterSettings("Project", "Game", "LyraUIInput",
			LOCTEXT("LyraUINavigationSettingsName", "Lyra UI Input"),
			LOCTEXT("LyraUINavigationSettingsDescription", "Configure the Lyra UI input settings."),
			GetMutableDefault<ULyraUIInputSettings>()
		);

		if (UIInputSettingsSection.IsValid())
		{
			UIInputSettingsSection->OnModified().BindRaw(this, &FLyraUINavigationEditorModule::HandleSettingsSaved);
		}
	}
}

void FLyraUINavigationEditorModule::UnregisterSettings()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "Game", "LyraUIPolicy");
		SettingsModule->UnregisterSettings("Project", "Game", "LyraUIInput");
	}
}

bool FLyraUINavigationEditorModule::HandleSettingsSaved()
{
	GetMutableDefault<ULyraUIManagerSubsystem>()->SaveConfig();
	GetMutableDefault<ULyraUIInputSettings>()->SaveConfig();

	return true;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FLyraUINavigationEditorModule, LyraUINavigationEditor)
