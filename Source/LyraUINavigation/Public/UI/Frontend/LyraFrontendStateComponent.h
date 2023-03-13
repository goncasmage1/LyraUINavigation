// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Components/ActorComponent.h"
//#include "ControlFlowNode.h"
#include "Engine/EngineTypes.h"
#include "HAL/Platform.h"
//#include "LoadingProcessInterface.h"
#include "Templates/SharedPointer.h"
#include "UObject/SoftObjectPtr.h"
#include "UObject/UObjectGlobals.h"

#include "LyraFrontendStateComponent.generated.h"

class FControlFlow;
class FString;
class FText;
class UObject;
struct FFrame;

enum class ECommonUserOnlineContext : uint8;
enum class ECommonUserPrivilege : uint8;
class UCommonActivatableWidget;
class UCommonUserInfo;
class ULyraExperienceDefinition;

UCLASS(Abstract)
class LYRAUINAVIGATION_API ULyraFrontendStateComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	ULyraFrontendStateComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	/*void FlowStep_TryShowMainScreen(FControlFlowNodeRef SubFlow);*/

	FDelegateHandle OnJoinSessionCompleteEventHandle;
};
