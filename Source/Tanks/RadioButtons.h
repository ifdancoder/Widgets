// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "SRadioButtons.h"
#include "RadButWidgetStyle.h"
#include "RadioButtons.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRadioButtonChangedEvent, int, NewSelectedButton);

UCLASS()
class TANKS_API URadioButtons : public UWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintAssignable)
	FOnRadioButtonChangedEvent OnRadioButtonChanged;

	virtual void ReleaseSlateResources(bool bReleaseChildren) override;

	UPROPERTY(EditAnywhere, Category = Appearance, Meta=(Displayname=Style))
	FRadButStyle WidgetStyle;

protected:

	virtual TSharedRef<SWidget> RebuildWidget() override;

private:

	TSharedPtr<SRadioButtons> RadioButtons;

	void OnRadioButtonChangedFunc(int NewSelectedButton);
};
