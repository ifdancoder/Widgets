// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthBar.h"
#include "Tanks.h"
#include <Blueprint/UserWidget.h>

void UHealthBar::SetHealth(float Percent)
{
	if (HealthBar)
	{
		HealthBar->SetPercent(Percent);
	}
}

void UHealthBar::SetAmmo(float Percent)
{
	if (AmmoBar)
	{
		AmmoBar->SetPercent(Percent);
	}
}
