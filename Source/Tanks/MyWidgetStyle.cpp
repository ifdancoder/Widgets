// Fill out your copyright notice in the Description page of Project Settings.


#include "MyWidgetStyle.h"
#include "MyCoreStyle.h"

FMyStyle::FMyStyle()
{
	//CheckBoxStyle = FCoreStyle::Get().GetWidgetStyle<FCheckBoxStyle>("RadioButton");
	//TextStyle = FCoreStyle::Get().GetWidgetStyle<FTextBlockStyle>("NormalText");

	//*this = MyCoreStyle::Get().GetWidgetStyle<FMyStyle>("RadioButtonsStyle");
	//CheckBoxStyle = Default.CheckBoxStyle;
	//TextStyle = Default.TextStyle;
}

FMyStyle::~FMyStyle()
{
}

const FName FMyStyle::TypeName(TEXT("FMyStyle"));

const FMyStyle& FMyStyle::GetDefault()
{
	static FMyStyle Default;
	return Default;
}

void FMyStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
	FSlateWidgetStyle::GetResources(OutBrushes);

	CheckBoxStyle.GetResources(OutBrushes);
	TextStyle.GetResources(OutBrushes);
}

