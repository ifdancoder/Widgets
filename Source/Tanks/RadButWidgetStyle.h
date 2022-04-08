// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateWidgetStyle.h"
#include "Styling/SlateWidgetStyleContainerBase.h"

#include "RadButWidgetStyle.generated.h"

/**
 *
 */
USTRUCT()
struct TANKS_API FRadButStyle : public FSlateWidgetStyle
{
    GENERATED_USTRUCT_BODY()

    FRadButStyle();
    virtual ~FRadButStyle();

    UPROPERTY(EditAnywhere, Category = Appereance)
    FCheckBoxStyle CheckBoxStyle;

    UPROPERTY(EditAnywhere, Category = Appereance)
    FTextBlockStyle TextStyle;

    // FSlateWidgetStyle
    virtual void GetResources(TArray<const FSlateBrush*>& OutBrushes) const override;
    static const FName TypeName;
    virtual const FName GetTypeName() const override { return TypeName; };
    static const FRadButStyle& GetDefault();
};

/**
 */
UCLASS(hidecategories = Object, MinimalAPI)
class URadButWidgetStyle : public USlateWidgetStyleContainerBase
{
    GENERATED_BODY()

public:
    /** The actual data describing the widget appearance. */
    UPROPERTY(Category = Appearance, EditAnywhere, meta = (ShowOnlyInnerProperties))
        FRadButStyle WidgetStyle;

    virtual const struct FSlateWidgetStyle* const GetStyle() const override
    {
        return static_cast<const struct FSlateWidgetStyle*>(&WidgetStyle);
    }
};