// Fill out your copyright notice in the Description page of Project Settings.


#include "GraphicalSettings.h"
#include "TanksHUD.h"

void UGraphicalSettings::NativeConstruct()
{
	if (SaveButton)
	{
		SaveButton->OnClicked.AddDynamic(this, &UGraphicalSettings::SaveClicked);
	}

	if (BackButton)
	{
		BackButton->OnClicked.AddDynamic(this, &UGraphicalSettings::BackClicked);
	}
}

void UGraphicalSettings::SaveClicked()
{

}

void UGraphicalSettings::BackClicked()
{
	Cast<ATanksHUD>(GetWorld()->GetFirstPlayerController()->GetHUD())->ShowWindow(EWidgetID::Settings);
}