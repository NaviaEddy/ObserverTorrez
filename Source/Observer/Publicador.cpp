// Fill out your copyright notice in the Description page of Project Settings.


#include "Publicador.h"
#include "ISubscriptor.h"

// Sets default values
APublicador::APublicador()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ArrayEnemigos = TArray<AActor*>();
}

// Called when the game starts or when spawned
void APublicador::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APublicador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APublicador::Subscribirse(AActor* _subs)
{
	ArrayEnemigos.Add(_subs);
}

void APublicador::Cancelar(AActor* _subs)
{
	ArrayEnemigos.Remove(_subs);
}

void APublicador::Notificar()
{
    for (AActor* Actor : ArrayEnemigos)
    {
        IISubscriptor* Sus = Cast<IISubscriptor>(Actor);

        if (Sus)
        {
            Sus->Actualizar(this);
        }
    }
}

