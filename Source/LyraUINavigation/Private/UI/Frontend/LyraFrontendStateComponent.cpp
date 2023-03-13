// Copyright Epic Games, Inc. All Rights Reserved.

#include "UI/Frontend/LyraFrontendStateComponent.h"

#include "CommonActivatableWidget.h"
#include "CommonGame/CommonGameInstance.h"
#include "Containers/Array.h"
#include "Containers/UnrealString.h"
#include "Delegates/Delegate.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/GameStateBase.h"
#include "Internationalization/Text.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/AssertionMacros.h"
#include "Misc/Optional.h"
#include "NativeGameplayTags.h"
#include "CommonGame/PrimaryGameLayout.h"
#include "Templates/Casts.h"
#include "UObject/NameTypes.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(LyraFrontendStateComponent)

namespace FrontendTags
{
	UE_DEFINE_GAMEPLAY_TAG_STATIC(TAG_PLATFORM_TRAIT_SINGLEONLINEUSER, "Platform.Trait.SingleOnlineUser");
	UE_DEFINE_GAMEPLAY_TAG_STATIC(TAG_UI_LAYER_MENU, "UI.Layer.Menu");
}

ULyraFrontendStateComponent::ULyraFrontendStateComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

//void ULyraFrontendStateComponent::FlowStep_TryShowMainScreen(FControlFlowNodeRef SubFlow)
//{
//	if (UPrimaryGameLayout* RootLayout = UPrimaryGameLayout::GetPrimaryGameLayoutForPrimaryPlayer(this))
//	{
//		constexpr bool bSuspendInputUntilComplete = true;
//		RootLayout->PushWidgetToLayerStackAsync<UCommonActivatableWidget>(FrontendTags::TAG_UI_LAYER_MENU, bSuspendInputUntilComplete, MainScreenClass,
//			[this, SubFlow](EAsyncWidgetLayerState State, UCommonActivatableWidget* Screen) {
//			switch (State)
//			{
//			case EAsyncWidgetLayerState::AfterPush:
//				bShouldShowLoadingScreen = false;
//				SubFlow->ContinueFlow();
//				return;
//			case EAsyncWidgetLayerState::Canceled:
//				bShouldShowLoadingScreen = false;
//				SubFlow->ContinueFlow();
//				return;
//			}
//		});
//	}
//}

