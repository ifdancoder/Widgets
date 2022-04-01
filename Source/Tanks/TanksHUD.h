// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include <Blueprint/UserWidget.h>
#include "TanksHUD.generated.h"

/**
 * 
 */

UENUM()
enum class EWidgetID : uint8
{
	None,
	MainMenu,
	Settings,
	GraphicalSettings,
	GameOver,
	SoundSettings,
};

UCLASS()
class TANKS_API ATanksHUD : public AHUD
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	UUserWidget* ShowWindow(const EWidgetID WidgetId, const int ZOrder=0);

	UFUNCTION(BlueprintCallable)
	void HideWidget();

	UFUNCTION(BlueprintPure)
	UUserWidget* GetCurrentWidget() const;

	virtual void BeginPlay() override;

protected:
	UUserWidget* CreateWidgetByClass(const TSubclassOf<UUserWidget> WidgetClass, const int ZOrder=0);

	UPROPERTY(EditAnywhere)
	TMap<EWidgetID, TSubclassOf<UUserWidget>> WidgetClasses;
	
	UPROPERTY()
	UUserWidget* CurrentWidget;
};
