// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "MyWidgetStyle.h"
#include "RadButWidgetStyle.h"
//#include "RB.h"

/**
 * 
 */

DECLARE_DELEGATE_OneParam(FOnRadioButtonChanged, int)

class TANKS_API SRadioButtons : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SRadioButtons)
	{
	}

	SLATE_STYLE_ARGUMENT(FRadButStyle, Style);

	SLATE_EVENT(FOnRadioButtonChanged, OnRadioButtonChanged);
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	FOnRadioButtonChanged OnRadioButtonChanged;
private:
	TSharedRef<SWidget> CreateCheckbox(int InIndex, FString InText);

	void OnCheckboxStateChanged(ECheckBoxState NewState, int InIndex);

	int CurrentIndex = 0;

	const FCheckBoxStyle* CheckBoxStyle = nullptr;

	const FTextBlockStyle* TextStyle = nullptr;
};
