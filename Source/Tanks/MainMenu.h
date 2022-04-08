// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "TanksHUD.h"
#include <Components/NativeWidgetHost.h>
#include "RadioButtons.h"
#include <Components/Image.h>
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class TANKS_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativePreConstruct() override;

	virtual void NativeConstruct() override;

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
	class UImage* Frog;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
	class URadioButtons* RadioButtons;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	class UButton* NewGameButton;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	class UButton* MultiplayerButton;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	class UButton* OptionsButton;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	class UButton* QuitButton;

	UPROPERTY(meta=(BindWidgetAnim), Transient)
	class UWidgetAnimation* InvisAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level loading params")
	FName LoadLevelName;

	UFUNCTION()
	void OnNewGameClicked();

	UFUNCTION()
	void OnQuitClicked();

	UFUNCTION()
	void OnSettingsClicked();

	UFUNCTION()
	void End();

	FTimerHandle TimerHandle;

	UPROPERTY(BlueprintReadWrite)
	ATanksHUD* HUD;
};
