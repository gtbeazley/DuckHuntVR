// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "DuckHunt_Shooter.generated.h"

class UCameraComponent;
class UDuckHunt_SaveGame;
class ADuckHuntVRGameModeBase;

UCLASS()
class DUCKHUNTVR_API ADuckHunt_Shooter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ADuckHunt_Shooter();

	/* Camera Component for the main game actor */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
		UCameraComponent* Camera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// determines if the player has shot
	bool shot = false;

	// The number of bullets the player is allowed to own
	int32 m_maxBullets = 3;
	
	// The number of bullets the player currently owns
	int32 m_curBullets;

	// The current scor the player has acquired
	int32 m_curScore = 0;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/* The Function called when the interact button is pressed */
	UFUNCTION()
	void Interact();

		/**Rotates Camera on Yaw Axis
		* @param a_val is the value that the rotation value changes by
		*/
	UFUNCTION()
		void LookUp(float a_val);

	/**Rotates Camera on Pitch Axis
	* @param a_val is the value that the rotation value changes by
	*/
	UFUNCTION()
		void LookRight(float a_val);
	
	/* The functionality for losing the game, returning to main menu and comparing and setting highscores */
	UFUNCTION(BlueprintCallable)
		void LoseGame();

	/* Saves the current score to the game slot */
	UFUNCTION(BlueprintCallable)
		void SaveGame(UDuckHunt_SaveGame * a_sGInstance, ADuckHuntVRGameModeBase* a_gMInstance);

	// Accesses the current score
	UFUNCTION(BlueprintCallable)
	int32 GetCurScore();

	// Accesses the maximum number of bullets that the player is allowed to own
	UFUNCTION(BlueprintCallable)
	int32 GetMaxBullets();

	// Accesses the current number of bullets that the player owns
	UFUNCTION(BlueprintCallable)
	int32 GetCurBullets();
	
};
