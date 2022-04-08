// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateWidgetStyle.h"
#include "Styling/SlateWidgetStyleContainerBase.h"

#include "MyWidgetStyle.generated.h"

/**
 * 
 */
USTRUCT()
struct TANKS_API FMyStyle : public FSlateWidgetStyle
{
	GENERATED_USTRUCT_BODY()

	FMyStyle();
	virtual ~FMyStyle();

	UPROPERTY(EditAnywhere, Category=Appereance)
	FCheckBoxStyle CheckBoxStyle;
	UPROPERTY(EditAnywhere, Category = Appereance)
	FTextBlockStyle TextStyle;

	// FSlateWidgetStyle
	virtual void GetResources(TArray<const FSlateBrush*>& OutBrushes) const override;
	static const FName TypeName;
	virtual const FName GetTypeName() const override { return TypeName; };
	static const FMyStyle& GetDefault();
};

/**
 */
UCLASS(hidecategories=Object, MinimalAPI)
class UMyWidgetStyle : public USlateWidgetStyleContainerBase
{
	GENERATED_BODY()

public:
	/** The actual data describing the widget appearance. */
	UPROPERTY(Category=Appearance, EditAnywhere, meta=(ShowOnlyInnerProperties))
	FMyStyle WidgetStyle;

	virtual const struct FSlateWidgetStyle* const GetStyle() const override
	{
		return static_cast< const struct FSlateWidgetStyle* >( &WidgetStyle );
	}
};
