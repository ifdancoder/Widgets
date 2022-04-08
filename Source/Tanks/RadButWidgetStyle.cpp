// Fill out your copyright notice in the Description page of Project Settings.


#include "RadButWidgetStyle.h"
#include "MyCoreStyle.h"

FRadButStyle::FRadButStyle()
{
    CheckBoxStyle = FCoreStyle::Get().GetWidgetStyle<FCheckBoxStyle>("RadioButton");
    TextStyle = FCoreStyle::Get().GetWidgetStyle<FTextBlockStyle>("NormalText");

    //*this = MyCoreStyle::Get().GetWidgetStyle<FMyStyle>("RadioButtonsStyle");
    //CheckBoxStyle = Default.CheckBoxStyle;
    //TextStyle = Default.TextStyle;
}

FRadButStyle::~FRadButStyle()
{
}

const FName FRadButStyle::TypeName(TEXT("FMyStyle"));

const FRadButStyle& FRadButStyle::GetDefault()
{
    static FRadButStyle Default;
    return Default;
}

void FRadButStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
    FSlateWidgetStyle::GetResources(OutBrushes);

    CheckBoxStyle.GetResources(OutBrushes);
    TextStyle.GetResources(OutBrushes);
}