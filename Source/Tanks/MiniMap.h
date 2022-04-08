// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "MiniMap.generated.h"

class SMiniMap;

UCLASS()
class TANKS_API UMiniMap : public UWidget
{
	GENERATED_BODY()

public:

	virtual void ReleaseSlateResources(bool bReleaseChildren) override;

	UPROPERTY(EditAnywhere, Category = Appearance)
	UTexture2D* PlayerImage;

	UPROPERTY(EditAnywhere, Category = Appearance)
	TArray<FBox2D> Obstacles;

	UPROPERTY(EditAnywhere, Category = Appearance)
	float PlayerPosX = 0.5f;

	UPROPERTY()
	FGetFloat PlayerPosXDelegate;

	UPROPERTY(EditAnywhere, Category = Appearance)
	float PlayerPosY = 0.5f;

	UPROPERTY()
	FGetFloat PlayerPosYDelegate;
	
protected:

	virtual TSharedRef<SWidget> RebuildWidget() override;
	
private:

	TSharedPtr<SMiniMap> RadioButtons;

	FVector2D GetPlayerPos() const;
	
};
