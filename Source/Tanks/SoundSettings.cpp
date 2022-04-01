// Fill out your copyright notice in the Description page of Project Settings.


#include "SoundSettings.h"
#include "TanksHUD.h"

void USoundSettings::NativeConstruct()
{
	if (SaveButton)
	{
		SaveButton->OnClicked.AddDynamic(this, &USoundSettings::SaveClicked);
	}

	if (BackButton)
	{
		BackButton->OnClicked.AddDynamic(this, &USoundSettings::BackClicked);
	}
}

void USoundSettings::SaveClicked()
{

}

void USoundSettings::BackClicked()
{
	Cast<ATanksHUD>(GetWorld()->GetFirstPlayerController()->GetHUD())->ShowWindow(EWidgetID::Settings);
}