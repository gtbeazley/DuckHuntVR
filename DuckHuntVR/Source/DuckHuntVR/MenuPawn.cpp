// Fill out your copyright notice in the Description page of Project Settings.

#include "MenuPawn.h"
#include "Components/InputComponent.h" 
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine/World.h"
#include "QuitButton.h"
#include "Button3D.h"
#include "DuckHuntVRGameModeBase.h"
#include "DrawDebugHelpers.h"

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

	if (startbutton && startbutton->isHighlighted)
		startbutton->isHighlighted = false;
	if (quitbutton && quitbutton->isHighlighted)
		quitbutton->isHighlighted = false;

	TArray<FHitResult> l_outHits;
	FVector l_traceStartLoc = Camera->GetComponentLocation(), l_traceEndLoc = l_traceStartLoc + (Camera->GetForwardVector() * 3000);

	GetWorld()->LineTraceMultiByChannel(l_outHits, l_traceStartLoc, l_traceEndLoc, ECC_Visibility);
	DrawDebugLine(GetWorld(), l_traceStartLoc, l_traceEndLoc, FColor(0, 255, 0), true, 1, 1, 1);

	for (auto hitResult : l_outHits)
	{
		if (shot)
		{
			if (Cast<AQuitButton>(hitResult.Actor))
			{
				UKismetSystemLibrary::QuitGame(this, GetWorld()->GetFirstPlayerController(), EQuitPreference::Quit);
			}
			if (Cast<AButton3D>(hitResult.Actor))
			{
				Cast<ADuckHuntVRGameModeBase>(UGameplayStatics::GetGameMode(this))->OpenNextMap("MainGameMap");
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT(hitResult.Component->ComponentTags[0]));
			//if (hitResult.Component->ComponentHasTag(FName("Button"))) {
				if (Cast<AQuitButton>(hitResult.Actor))
				{
					quitbutton = Cast<AQuitButton>(hitResult.Actor);
						quitbutton->isHighlighted = true;
				}
				if (Cast<AButton3D>(hitResult.Actor))
				{
					startbutton = Cast<AButton3D>(hitResult.Actor);
						startbutton->isHighlighted = true;
				}
			//}
		}

	}
	shot = false;
	l_outHits.Empty();
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
	if (rotation.Pitch - a_val >= -85 && rotation.Pitch - a_val <= 85)
	{
		rotation.Pitch -= a_val;
		Camera->SetWorldRotation(rotation);
	}
}

void AMenuPawn::LookRight(float a_val)
{
	FRotator rotation = Camera->GetComponentRotation();
	rotation.Yaw += a_val;
	Camera->SetWorldRotation(rotation);
}

