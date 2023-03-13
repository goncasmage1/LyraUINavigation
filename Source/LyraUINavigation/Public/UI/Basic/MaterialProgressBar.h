// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CommonUserWidget.h"

#include "MaterialProgressBar.generated.h"

class UImage;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UWidgetAnimation;

UCLASS(Abstract, meta = (DisableNativeTick))
class LYRAUINAVIGATION_API UMaterialProgressBar : public UCommonUserWidget
{
	GENERATED_BODY()

protected:

	virtual void SynchronizeProperties() override;

#if WITH_EDITOR
	virtual void OnWidgetRebuilt() override;
#endif

	virtual void OnAnimationFinished_Implementation(const UWidgetAnimation* Animation) override;

public:

	UFUNCTION(BlueprintCallable, Category = "Material Progress Bar")
	void SetProgress(float Progress);

	UFUNCTION(BlueprintCallable, Category = "Material Progress Bar")
	void SetStartProgress(float StartProgress);

	UFUNCTION(BlueprintCallable, Category = "Material Progress Bar")
	void SetColorA(FLinearColor ColorA);

	UFUNCTION(BlueprintCallable, Category = "Material Progress Bar")
	void SetColorB(FLinearColor ColorB);

	UFUNCTION(BlueprintCallable, Category = "Material Progress Bar")
	void SetColorBackground(FLinearColor ColorBackground);

	UFUNCTION(BlueprintCallable, Category = "Material Progress Bar")
	void AnimateProgressFromStart(float Start, float End, float AnimSpeed = 1.0f);

	UFUNCTION(BlueprintCallable, Category = "Material Progress Bar")
	void AnimateProgressFromCurrent(float End, float AnimSpeed = 1.0f);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFillAnimationFinished);

	UPROPERTY(BlueprintAssignable)
	FOnFillAnimationFinished OnFillAnimationFinished;

private:

	void SetProgress_Internal(float Progress);
	void SetStartProgress_Internal(float StartProgress);
	void SetColorA_Internal(FLinearColor ColorA);
	void SetColorB_Internal(FLinearColor ColorB);
	void SetColorBackground_Internal(FLinearColor ColorBackground);

	UMaterialInstanceDynamic* GetBarDynamicMaterial() const;

	UPROPERTY(EditAnywhere, Category = "Material Progress Bar", meta = (InlineEditConditionToggle = "CachedColorA"))
	bool bOverrideDefaultColorA = false;

	UPROPERTY(EditAnywhere, Category = "Material Progress Bar", meta = (DisplayName = "Color A", EditCondition = "bOverrideDefaultColorA"))
	FLinearColor CachedColorA;

	UPROPERTY(EditAnywhere, Category = "Material Progress Bar", meta = (InlineEditConditionToggle = "CachedColorB"))
	bool bOverrideDefaultColorB = false;

	UPROPERTY(EditAnywhere, Category = "Material Progress Bar", meta = (DisplayName = "Color B", EditCondition = "bOverrideDefaultColorB"))
	FLinearColor CachedColorB;

	UPROPERTY(EditAnywhere, Category = "Material Progress Bar", meta = (InlineEditConditionToggle = "CachedColorBackground"))
	bool bOverrideDefaultColorBackground;

	UPROPERTY(EditAnywhere, Category = "Material Progress Bar", meta = (DisplayName = "Color Background", EditCondition = "bOverrideDefaultColorBackground"))
	FLinearColor CachedColorBackground;

	UPROPERTY(EditAnywhere, Category = "Material Progress Bar", meta = (InlineEditConditionToggle = "Segments"))
	bool bOverrideDefaultSegments = false;

	UPROPERTY(EditAnywhere, Category = "Material Progress Bar", meta = (EditCondition = "bOverrideDefaultSegments"))
	int32 Segments;

	UPROPERTY(EditAnywhere, Category = "Material Progress Bar", meta = (InlineEditConditionToggle = "SegmentEdge"))
	bool bOverrideDefaultSegmentEdge = false;

	UPROPERTY(EditAnywhere, Category = "Material Progress Bar", meta = (EditCondition = "bOverrideDefaultSegmentEdge"))
	float SegmentEdge;

	UPROPERTY(EditAnywhere, Category = "Material Progress Bar", meta = (InlineEditConditionToggle = "FillEdgeSoftness"))
	bool bOverrideDefaultFillEdgeSoftness;

	UPROPERTY(EditAnywhere, Category = "Material Progress Bar", meta = (EditCondition = "bOverrideDefaultFillEdgeSoftness"))
	float FillEdgeSoftness;

	UPROPERTY(EditAnywhere, Category = "Material Progress Bar", meta = (InlineEditConditionToggle = "GlowEdge"))
	bool bOverrideDefaultGlowEdge = false;

	UPROPERTY(EditAnywhere, Category = "Material Progress Bar", meta = (EditCondition = "bOverrideDefaultGlowEdge"))
	float GlowEdge;

	UPROPERTY(EditAnywhere, Category = "Material Progress Bar", meta = (InlineEditConditionToggle = "GlowSoftness"))
	bool bOverrideDefaultGlowSoftness = false;

	UPROPERTY(EditAnywhere, Category = "Material Progress Bar", meta = (EditCondition = "bOverrideDefaultGlowSoftness"))
	float GlowSoftness;

	UPROPERTY(EditAnywhere, Category = "Material Progress Bar", meta = (InlineEditConditionToggle = "OutlineScale"))
	bool bOverrideDefaultOutlineScale = false;

	UPROPERTY(EditAnywhere, Category = "Material Progress Bar", meta = (EditCondition = "bOverrideDefaultOutlineScale"))
	float OutlineScale;

	UPROPERTY(EditAnywhere, Category = "Material Progress Bar")
	bool bUseStroke = true;

	UPROPERTY(EditDefaultsOnly, Category = "Material Progress Bar")
	TObjectPtr<UMaterialInterface> StrokeMaterial;

	UPROPERTY(EditDefaultsOnly, Category = "Material Progress Bar")
	TObjectPtr<UMaterialInterface> NoStrokeMaterial;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category = "Material Progress Bar", meta = (DisplayName = "Design Time Progress"))
	float DesignTime_Progress = 1.0f;
#endif

	UPROPERTY(BlueprintReadOnly, Category = "Material Progress Bar", meta = (BindWidget, AllowPrivateAccess))
	TObjectPtr<UImage> Image_Bar;

	UPROPERTY(BlueprintReadOnly, Category = "Material Progress Bar", Transient, meta = (BindWidgetAnim, AllowPrivateAccess))
	TObjectPtr<UWidgetAnimation> BoundAnim_FillBar;

	UPROPERTY(Transient)
	mutable TObjectPtr<UMaterialInstanceDynamic> CachedMID;

	float CachedProgress = -1.0f;
	float CachedStartProgress = -1.0f;
};