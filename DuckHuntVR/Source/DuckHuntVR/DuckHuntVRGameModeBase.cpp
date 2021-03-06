// Fill out your copyright notice in the Description page of Project Settings.

#include "DuckHuntVRGameModeBase.h"
#include "MenuPawn.h"
#include "DuckHunt_Shooter.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"


ADuckHuntVRGameModeBase::ADuckHuntVRGameModeBase()
{ 
	DefaultPawnClass = AMenuPawn::StaticClass();
	
}

void ADuckHuntVRGameModeBase::OpenNextMap(FName a_name)
{
	if(a_name == MainMenuName)
		DefaultPawnClass = AMenuPawn::StaticClass();
	else
		DefaultPawnClass = ADuckHunt_Shooter::StaticClass();

	UGameplayStatics::OpenLevel(this, a_name);
}

FString ADuckHuntVRGameModeBase::GetSlotName()
{
	return SaveGameSlot;
}

FName ADuckHuntVRGameModeBase::GetMainMenuMapName()
{
	return MainMenuName;
}

FName ADuckHuntVRGameModeBase::GetMainGameMapName()
{
	return MainGameName;
}
