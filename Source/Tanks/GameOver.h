// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Components/Button.h>
#include "GameOver.generated.h"

/**
 * 
 */
UCLASS()
class TANKS_API UGameOver : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
	class UButton* TryAgainButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
	class UButton* QuitGameButton;

	UFUNCTION()
	void OnTryAgainClicked();

	UFUNCTION()
	void OnQuitGameClicked();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level loading params")
	FName LoadLevelName;
};
