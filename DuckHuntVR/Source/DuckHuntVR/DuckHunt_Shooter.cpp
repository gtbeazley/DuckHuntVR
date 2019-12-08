// Fill out your copyright notice in the Description page of Project Settings.

#include "DuckHunt_Shooter.h"
#include "Components/InputComponent.h" 
#include "Camera/CameraComponent.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "DuckHunt_SaveGame.h"
#include "Duck.h"
#include "DuckHuntVRGameModeBase.h"

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
	
	m_curBullets = m_maxBullets;
}

// Called every frame
void ADuckHunt_Shooter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (shot)
	{
		bool l_loseBullet = true;
		TArray<FHitResult> l_outHits;
		FVector l_traceStartLoc = Camera->GetComponentLocation(), l_traceEndLoc = l_traceStartLoc + (Camera->GetForwardVector() * 3000);

		GetWorld()->LineTraceMultiByChannel(l_outHits, l_traceStartLoc, l_traceEndLoc, ECC_Visibility);

		for (auto result : l_outHits)
			if (Cast<ADuck>(result.Actor))
			{
				l_loseBullet = false;
				Cast<ADuck>(result.Actor)->ResetPos();
				m_curScore++;
			}

		if (l_loseBullet)
			m_curBullets--;

		shot = false;
	}

	if (m_curBullets <= 0)
		LoseGame();
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
	if(!shot)
		shot = true;
}

void ADuckHunt_Shooter::LookUp(float a_val)
{
	FRotator rotation = Camera->GetComponentRotation();
	if (rotation.Pitch - a_val >= -85 && rotation.Pitch - a_val <= 85)
	{
		rotation.Pitch -= a_val;
		Camera->SetWorldRotation(rotation);
	}
}

void ADuckHunt_Shooter::LookRight(float a_val)
{
	FRotator rotation = Camera->GetComponentRotation();
	rotation.Yaw += a_val;
	Camera->SetWorldRotation(rotation);
}

void ADuckHunt_Shooter::LoseGame()
{

	ADuckHuntVRGameModeBase* GMInstance = Cast<ADuckHuntVRGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	UDuckHunt_SaveGame* SGInstance;
	if (UGameplayStatics::DoesSaveGameExist(GMInstance->SaveGameSlot, 0))
		SGInstance = Cast<UDuckHunt_SaveGame>(UGameplayStatics::LoadGameFromSlot(GMInstance->SaveGameSlot, 0));
	else
		SGInstance = Cast<UDuckHunt_SaveGame>(UGameplayStatics::CreateSaveGameObject(UDuckHunt_SaveGame::StaticClass()));

	if (SGInstance && SGInstance->highScore < m_curScore)
	{
		SGInstance->highScore = m_curScore;
		UGameplayStatics::SaveGameToSlot(SGInstance, GMInstance->SaveGameSlot, 0);
		SaveGame(SGInstance, GMInstance);
	}
	GMInstance->OpenNextMap(GMInstance->MainMenuName);

}

void ADuckHunt_Shooter::SaveGame(UDuckHunt_SaveGame* a_sGInstance, ADuckHuntVRGameModeBase* a_gMInstance)
{ 
	//UGameplayStatics::SaveGameToSlot(a_sGInstance, a_gMInstance->SaveGameSlot, 0);
}

int32 ADuckHunt_Shooter::GetCurScore()
{
	return m_curScore;
}

int32 ADuckHunt_Shooter::GetMaxBullets()
{
	return m_maxBullets;
}

int32 ADuckHunt_Shooter::GetCurBullets()
{
	return m_curBullets;
}

