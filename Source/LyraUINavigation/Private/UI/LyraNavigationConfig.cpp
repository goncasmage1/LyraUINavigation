// Copyright (C) 2023 Gonçalo Marques - All Rights Reserved

#include "UI/LyraNavigationConfig.h"
#include "UI/LyraUIInputSettings.h"
#include "InputMappingContext.h"

FLyraNavigationConfig::FLyraNavigationConfig()
{
	KeyEventRules.Reset();
	bTabNavigation = false;
	bKeyNavigation = true;
	bAnalogNavigation = false;

	const ULyraUIInputSettings* const LyraUIInputSettings = GetDefault<ULyraUIInputSettings>();
	const ULyraUIInputActions* const InputActions = LyraUIInputSettings->EnhancedInputActions.LoadSynchronous();
	const UInputMappingContext* const InputContext = LyraUIInputSettings->EnhancedInputContext.LoadSynchronous();
	if (InputActions == nullptr || InputContext == nullptr)
	{
		return;
	}

	for (const FEnhancedActionKeyMapping& Mapping : InputContext->GetMappings())
	{
		if (Mapping.Action == InputActions->IA_MenuUp)
		{
			KeyEventRules.Emplace(Mapping.Key, EUINavigation::Up);
		}
		else if (Mapping.Action == InputActions->IA_MenuDown)
		{
			KeyEventRules.Emplace(Mapping.Key, EUINavigation::Down);
		}
		else if (Mapping.Action == InputActions->IA_MenuLeft)
		{
			KeyEventRules.Emplace(Mapping.Key, EUINavigation::Left);
		}
		else if (Mapping.Action == InputActions->IA_MenuRight)
		{
			KeyEventRules.Emplace(Mapping.Key, EUINavigation::Right);
		}
		else if (Mapping.Action == InputActions->IA_MenuNext)
		{
			KeyEventRules.Emplace(Mapping.Key, EUINavigation::Next);
		}
		else if (Mapping.Action == InputActions->IA_MenuPrevious)
		{
			KeyEventRules.Emplace(Mapping.Key, EUINavigation::Previous);
		}
		else if (Mapping.Action == InputActions->IA_MenuSelect)
		{
			KeyActionRules.Emplace(Mapping.Key, EUINavigationAction::Accept);
		}
		else if (Mapping.Action == InputActions->IA_MenuReturn)
		{
			KeyActionRules.Emplace(Mapping.Key, EUINavigationAction::Back);
		}
	}
}

EUINavigation FLyraNavigationConfig::GetNavigationDirectionFromAnalog(const FAnalogInputEvent& InAnalogEvent)
{
	// Disable analog direction as thumbsticks can be assigned to action key mapping.
  	// However, feel free to put axis mappings to analog input yourself.
	return EUINavigation::Invalid;
}

EUINavigationAction FLyraNavigationConfig::GetNavigationActionForKey(const FKey& InKey) const
{
	const EUINavigationAction* NavAction = KeyActionRules.Find(InKey);
	return NavAction == nullptr ? EUINavigationAction::Invalid : *NavAction;
}