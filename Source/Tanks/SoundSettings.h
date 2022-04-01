// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Components/Button.h>
#include <Components/Slider.h>
#include "SoundSettings.generated.h"

/**
 * 
 */
UCLASS()
class TANKS_API USoundSettings : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
	class UButton* SaveButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
	class UButton* BackButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
	class USlider* Slider;

	UFUNCTION()
	void SaveClicked();

	UFUNCTION()
	void BackClicked();
};
