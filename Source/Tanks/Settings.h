// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Components/Button.h>
#include "Settings.generated.h"

/**
 * 
 */
UCLASS()
class TANKS_API USettings : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
	class UButton* GraphicalSettingsButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
	class UButton* SoundSettingsButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
	class UButton* SaveButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
	class UButton* BackButton;

	UFUNCTION()
	void OnGraphicalSettingsClicked();

	UFUNCTION()
	void SoundSettingsClicked();

	UFUNCTION()
	void SaveClicked();

	UFUNCTION()
	void BackClicked();
};
