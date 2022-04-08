// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Slate.h"

/**
 * 
 */
class TANKS_API MyCoreStyle
{
public:

	MyCoreStyle();
	~MyCoreStyle();

	static TSharedPtr<ISlateStyle> FindStyle();

	static void Initialize();

	static void Shutdown();

	static const ISlateStyle& Get();

private:

	static TSharedPtr<ISlateStyle> StylePtr;
};
