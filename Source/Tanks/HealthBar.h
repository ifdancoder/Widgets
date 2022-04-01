// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
//#include "BasicClass.h"
#include <Components/ProgressBar.h>
#include "HealthComponent.h"
#include "HealthBar.generated.h"

/**
 *
 */
UCLASS()
class TANKS_API UHealthBar : public UUserWidget
{
    GENERATED_BODY()

public:
    UHealthComponent* Health;
    void SetHealth(float Percent);

    void SetAmmo(float Percent);

protected:
    UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
    class UProgressBar* HealthBar;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
	class UProgressBar* AmmoBar;
};