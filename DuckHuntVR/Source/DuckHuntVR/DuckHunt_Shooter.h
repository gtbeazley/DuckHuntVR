// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "DuckHunt_Shooter.generated.h"

class UCameraComponent;

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
	
	
};
