// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class TANKS_API SMiniMap : public SLeafWidget
{
public:
	SLATE_BEGIN_ARGS(SMiniMap)
		: _PlayerImage()
	{}

	SLATE_ARGUMENT(UTexture2D*, PlayerImage)
	
	SLATE_ARGUMENT(TArray<FBox2D>, Obstacles)
	
	SLATE_ATTRIBUTE(FVector2D, PlayerPos)

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;

protected:

	virtual FVector2D ComputeDesiredSize(float LayoutScaleMultiplier) const override;

	UTexture2D* PlayerImage = nullptr;

	TArray<FBox2D> Obstacles;

	TAttribute<FVector2D> PlayerPos;

};
