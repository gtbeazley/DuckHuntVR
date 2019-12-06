// Fill out your copyright notice in the Description page of Project Settings.

#include "MenuPawn.h"
#include "Components/InputComponent.h" 
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "ConstructorHelpers.h"
#include "Engine/World.h"
#include "QuitButton.h"
#include "Button3D.h"
#include "DuckHuntVRGameModeBase.h"

// Sets default values
AMenuPawn::AMenuPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");

}

// Called when the game starts or when spawned
void AMenuPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMenuPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FHitResult outHit;
	FVector l_traceStartLoc = Camera->GetComponentLocation(), l_traceEndLoc = l_traceStartLoc + (Camera->GetForwardVector() * 3000);

	TArray<AActor*> l_actors;

	GetWorld()->LineTraceSingleByChannel(outHit, l_traceStartLoc, l_traceEndLoc, ECC_Visibility);
 
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AQuitButton::StaticClass(), l_actors);
	if (Cast<AQuitButton>(outHit.Actor))
	{
		Cast<AQuitButton>(outHit.Actor)->Highlighted = true;
		if (shot)
			UKismetSystemLibrary::QuitGame(this, GetWorld()->GetFirstPlayerController(), EQuitPreference::Quit);
	}
	else
		if(l_actors.IsValidIndex(0) && l_actors[0] != nullptr &&  Cast<AQuitButton>(l_actors[0])) Cast<AQuitButton>(l_actors[0])->Highlighted = false;
	 
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AButton3D::StaticClass(), l_actors);
	 if (Cast<AButton3D>(outHit.Actor))
	{
		Cast<AButton3D>(outHit.Actor)->Highlighted = true;

		if (shot)
			Cast<ADuckHuntVRGameModeBase>(UGameplayStatics::GetGameMode(this))->OpenNextMap("MainGameMap");
	}
	else
		 if (l_actors.IsValidIndex(0) &&  l_actors[0] != nullptr &&  Cast<AButton3D>(l_actors[0])) Cast<AButton3D>(l_actors[0])->Highlighted = false;
	  
	shot = false;
}

// Called to bind functionality to input
void AMenuPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("LookRight", this, &AMenuPawn::LookRight);
	PlayerInputComponent->BindAxis("LookUp", this, &AMenuPawn::LookUp);

	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &AMenuPawn::Interact);
}

void AMenuPawn::Interact()
{
	if (!shot)
		shot = true;
}

void AMenuPawn::LookUp(float a_val)
{
	FRotator rotation = Camera->GetComponentRotation();
	rotation.Pitch -= a_val;
	Camera->SetWorldRotation(rotation);
}

void AMenuPawn::LookRight(float a_val)
{
	FRotator rotation = Camera->GetComponentRotation();
	rotation.Yaw += a_val;
	Camera->SetWorldRotation(rotation);
}

