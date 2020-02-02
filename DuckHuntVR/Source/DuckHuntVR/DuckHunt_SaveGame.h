// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "DuckHunt_SaveGame.generated.h"

/**
 * 
 */
UCLASS()
class DUCKHUNTVR_API UDuckHunt_SaveGame : public USaveGame
{
	GENERATED_BODY()
public:
	//Defaults constructor of the save game
	UDuckHunt_SaveGame();
	
	// Count of how many ducks were shot
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 highScore;

	// Accesses the Highscore variable
	//UFUNCTION(BlueprintCallable)
		int32 GetHighScore();
};
