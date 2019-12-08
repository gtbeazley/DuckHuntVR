// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DuckHuntVRGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class DUCKHUNTVR_API ADuckHuntVRGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

		ADuckHuntVRGameModeBase();

public:

	// Name of the main menu map
	FName MainMenuName = "MainMenu";

	// Name of the main game map
	FName MainGameName = "MainGameMap";

	// Name of the save game slot
	FString SaveGameSlot = "DuckHuntVRBG";
	
	/* handles the next map*/
	UFUNCTION(BlueprintCallable)
		void OpenNextMap(FName a_name);

	// Gets the Savegameslot name
	UFUNCTION(BlueprintCallable)
		FString GetSlotName();

	// Gets the main menu map name
	UFUNCTION(BlueprintCallable)
		FName GetMainMenuMapName();

	// Gets main game map name
	UFUNCTION(BlueprintCallable)
		FName GetMainGameMapName();
};
