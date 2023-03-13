// Fill out your copyright notice in the Description page of Project Settings.

#include "LyraUINavigationEditor.h"

#include "UI/Subsystem/LyraUIManagerSubsystem.h"
#include "ISettingsModule.h"
#include "ISettingsSection.h"
#include "Modules/ModuleManager.h"

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
		ISettingsSectionPtr SettingsSection = SettingsModule->RegisterSettings("Project", "Plugins", "LyraUINavigation",
			LOCTEXT("LyraUINavigationSettingsName", "Lyra UI Navigation"),
			LOCTEXT("LyraUINavigationSettingsDescription", "Configure the Lyra UI Navigation settings."),
			GetMutableDefault<ULyraUIManagerSubsystem>()
		);

		if (SettingsSection.IsValid())
		{
			SettingsSection->OnModified().BindRaw(this, &FLyraUINavigationEditorModule::HandleSettingsSaved);
		}
	}
}

void FLyraUINavigationEditorModule::UnregisterSettings()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "LyraUINavigation");
	}
}

bool FLyraUINavigationEditorModule::HandleSettingsSaved()
{
	GetMutableDefault<ULyraUIManagerSubsystem>()->SaveConfig();

	return true;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FLyraUINavigationEditorModule, LyraUINavigationEditor)
