// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MenuPawn.generated.h"


class UCameraComponent;
class AQuitButton;
class AButton3D;

UCLASS()
class DUCKHUNTVR_API AMenuPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMenuPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//camera component reference
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
		UCameraComponent* Camera;
	// quitbutton pointer used to change its colour for highlighting 
	AQuitButton* quitbutton = nullptr;
	//startbutton poiont used for chaing its colour for highlighting
	AButton3D* startbutton = nullptr;

	//if the menu player has shot
	bool shot = false;
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
