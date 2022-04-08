// Fill out your copyright notice in the Description page of Project Settings.


#include "RadioButtons.h"
#include "SRadioButtons.h"

void URadioButtons::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);

	RadioButtons.Reset();
}

TSharedRef<SWidget> URadioButtons::RebuildWidget()
{
	RadioButtons = SNew(SRadioButtons)
		.OnRadioButtonChanged_UObject(this, &ThisClass::OnRadioButtonChangedFunc)
		.Style(&WidgetStyle);

	return RadioButtons.ToSharedRef();
}

void URadioButtons::OnRadioButtonChangedFunc(int NewSelectedButton)
{
	OnRadioButtonChanged.Broadcast(NewSelectedButton);
}
