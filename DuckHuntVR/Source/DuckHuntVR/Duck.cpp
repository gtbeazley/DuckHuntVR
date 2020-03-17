// Fill out your copyright notice in the Description page of Project Settings.

#include "Duck.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h"
#include "Kismet/KismetMathLibrary.h"
#include <time.h>
#include "ConstructorHelpers.h"

// Sets default values
ADuck::ADuck()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	static ConstructorHelpers::FObjectFinder<UStaticMesh> meshObject(TEXT("StaticMesh'/Game/Assets/Sphere_Asset.Sphere_Asset'"));
	Mesh->SetStaticMesh(meshObject.Object);
	
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> matObject(TEXT("Material'/Game/Materials/Red.Red'"));
	Mesh->SetMaterial(0, matObject.Object);
	srand(time(NULL));
	Mesh->SetSimulatePhysics(true);
	Mesh->SetEnableGravity(false);
}

// Called when the game starts or when spawned
void ADuck::BeginPlay()
{
	Super::BeginPlay();
	
	StartLoc = GetActorLocation();
}

// Called every frame
void ADuck::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveToTarget();
}

void ADuck::SetTarLoc(FVector a_tarLoc)
{
	TarLoc = a_tarLoc;
	TarLocFound = true;
}

bool ADuck::NeedsNewLoc()
{
	if (!TarLocFound || (TarLoc - GetActorLocation()).Size() <= 10)
	{
		TarLocFound = false;
		return true;
	}
	return false;
}

void ADuck::MoveToTarget()
{
	if (TarLocFound)
	{
		FVector l_dir = TarLoc - GetActorLocation();
		float l_dis = l_dir.Size();
		l_dir.Normalize();
		Mesh->AddForce(l_dir * l_dis * m_speed);
	}
}

void ADuck::ResetPos()
{
	SetActorLocation({(float)(rand() %1000),(float)(rand() % 1000),(float)(rand() % 1000) });
}

