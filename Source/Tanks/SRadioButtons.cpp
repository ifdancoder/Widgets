// Fill out your copyright notice in the Description page of Project Settings.


#include "SRadioButtons.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SRadioButtons::Construct(const FArguments& InArgs)
{
	OnRadioButtonChanged = InArgs._OnRadioButtonChanged;
	CheckBoxStyle = &InArgs._Style->CheckBoxStyle;
	TextStyle = &InArgs._Style->TextStyle;
	
	ChildSlot
	[
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		[
			CreateCheckbox(0, TEXT("Option 1"))
		]
		+ SVerticalBox::Slot()
		[
			CreateCheckbox(1, TEXT("Option 2"))
		]
		+ SVerticalBox::Slot()
		[
			CreateCheckbox(2, TEXT("Option 3"))
		]
	];
	
}

TSharedRef<SWidget> SRadioButtons::CreateCheckbox(int InIndex, FString InText)
{
	return SNew(SCheckBox)
		.IsChecked_Lambda([InIndex, this]() {return InIndex == CurrentIndex ? ECheckBoxState::Checked : ECheckBoxState::Unchecked; })
		.OnCheckStateChanged_Raw(this, &SRadioButtons::OnCheckboxStateChanged, InIndex)
		.Style(CheckBoxStyle)
		[
			SNew(STextBlock)
			.Text(FText::FromString(InText))
			.TextStyle(TextStyle)
		];
}

void SRadioButtons::OnCheckboxStateChanged(ECheckBoxState NewState, int InIndex)
{
	if (NewState == ECheckBoxState::Checked)
	{
		CurrentIndex = InIndex;
		OnRadioButtonChanged.ExecuteIfBound(CurrentIndex);
	}
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION