// Fill out your copyright notice in the Description page of Project Settings.


#include "Settings.h"
#include "TanksHUD.h"

void USettings::NativeConstruct()
{
	Super::NativeConstruct();

	if (GraphicalSettingsButton)
	{
		GraphicalSettingsButton->OnClicked.AddDynamic(this, &USettings::OnGraphicalSettingsClicked);
	}

	if (SoundSettingsButton)
	{
		SoundSettingsButton->OnClicked.AddDynamic(this, &USettings::SoundSettingsClicked);
	}

	if (SaveButton)
	{
		SaveButton->OnClicked.AddDynamic(this, &USettings::SaveClicked);
	}

	if (BackButton)
	{
		BackButton->OnClicked.AddDynamic(this, &USettings::BackClicked);
	}
}

void USettings::OnGraphicalSettingsClicked()
{
	Cast<ATanksHUD>(GetWorld()->GetFirstPlayerController()->GetHUD())->ShowWindow(EWidgetID::GraphicalSettings);
}

void USettings::SoundSettingsClicked()
{
	Cast<ATanksHUD>(GetWorld()->GetFirstPlayerController()->GetHUD())->ShowWindow(EWidgetID::SoundSettings);
}

void USettings::SaveClicked()
{

}

void USettings::BackClicked()
{
	Cast<ATanksHUD>(GetWorld()->GetFirstPlayerController()->GetHUD())->ShowWindow(EWidgetID::MainMenu);
}
