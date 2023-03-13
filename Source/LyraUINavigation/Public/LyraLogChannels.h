// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Containers/UnrealString.h"
#include "Logging/LogMacros.h"

class UObject;

DECLARE_LOG_CATEGORY_EXTERN(LogLyra, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(LogLyraExperience, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(LogLyraAbilitySystem, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(LogLyraTeams, Log, All);

FString GetClientServerContextString(UObject* ContextObject = nullptr);
