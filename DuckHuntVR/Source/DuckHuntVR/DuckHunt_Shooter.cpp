// Fill out your copyright notice in the Description page of Project Settings.

#include "DuckHunt_Shooter.h"
#include "Components/InputComponent.h" 
#include "Camera/CameraComponent.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"  

// Sets default values
ADuckHunt_Shooter::ADuckHunt_Shooter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
}

// Called when the game starts or when spawned
void ADuckHunt_Shooter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADuckHunt_Shooter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TArray<FHitResult> l_outHits;
	FVector l_traceStartLoc = Camera->GetComponentLocation(), l_traceEndLoc = l_traceStartLoc + (Camera->GetForwardVector() * 3000);

	GetWorld()->LineTraceMultiByChannel(l_outHits, l_traceStartLoc, l_traceEndLoc, ECC_Visibility);
 

}

// Called to bind functionality to input
void ADuckHunt_Shooter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("LookRight", this, &ADuckHunt_Shooter::LookRight);
	PlayerInputComponent->BindAxis("LookUp", this, &ADuckHunt_Shooter::LookUp);

	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &ADuckHunt_Shooter::Interact);

}

void ADuckHunt_Shooter::Interact()
{
}

void ADuckHunt_Shooter::LookUp(float a_val)
{
	FRotator rotation = Camera->GetComponentRotation();
	rotation.Pitch -= a_val;
	Camera->SetWorldRotation(rotation);
}

void ADuckHunt_Shooter::LookRight(float a_val)
{
	FRotator rotation = Camera->GetComponentRotation();
	rotation.Yaw += a_val;
	Camera->SetWorldRotation(rotation);
}

