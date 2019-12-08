// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Duck.generated.h"

UCLASS()
class DUCKHUNTVR_API ADuck : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADuck();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Static Mesh component
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* Mesh;

	// Is true when there is a TarLocFound, is false when haven't found one or has reached one
	bool TarLocFound;

	// Determines where the duck is to go next 
	FVector TarLoc;

	// The starting location th duck goes to when its shot
	FVector StartLoc;

	// the speed that the duck travels
	float m_speed = 0.1;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Sets the target location for the duck
	void SetTarLoc(FVector a_tarLoc);
	
	// Condition for changing the target location
	bool NeedsNewLoc();

	// Moves the duck towards its target
	void MoveToTarget();

	// Resets the ducks position to its starting position, called when shot
	void ResetPos();

};
