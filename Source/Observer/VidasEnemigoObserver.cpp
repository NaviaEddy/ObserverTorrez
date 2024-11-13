// Fill out your copyright notice in the Description page of Project Settings.


#include "VidasEnemigoObserver.h"

// Sets default values
AVidasEnemigoObserver::AVidasEnemigoObserver()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mensaje = " ";
}

// Called when the game starts or when spawned
void AVidasEnemigoObserver::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVidasEnemigoObserver::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AVidasEnemigoObserver::EstablecerAccion(FString _mensaje)
{
	Mensaje = _mensaje;
	Notificar();
}


