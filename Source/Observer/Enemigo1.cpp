// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo1.h"
#include "VidasEnemigoObserver.h"
// Sets default values
AEnemigo1::AEnemigo1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	VidasEnemigo = 3;
}

// Called when the game starts or when spawned
void AEnemigo1::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green,
		FString::Printf(TEXT("El enemigo tiene %d vidas"), GetVidasEnemigo()));
}

void AEnemigo1::MallaColision()
{
	//EJEMPLO DE FUNCIONALIDAD (CORREGIR)
	/*if (AActor == ACharacter) {
		observer->EstablecerAccion("QuitarVida");
	}*/
}

// Called every frame
void AEnemigo1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetVidasEnemigo() == 0) {
		Destroyed();
	}

}

void AEnemigo1::EstablecerObserver(AVidasEnemigoObserver* _observer)
{
	observer = _observer;
	observer->Subscribirse(this);
}

void AEnemigo1::Actualizar(APublicador* _publicador)
{
	Actuar();
}

void AEnemigo1::Actuar()
{
	FString mensaje_recibido = observer->GetMensaje();
	if (mensaje_recibido.Equals("QuitarVida")) {
		SetVidasEnemigo(1);
	}
}

void AEnemigo1::SetVidasEnemigo(int32 _vidas)
{
	VidasEnemigo -= _vidas;
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Magenta,
		FString::Printf(TEXT("El enemigo tiene %d vidas"), GetVidasEnemigo()));
}

void AEnemigo1::Destroyed()
{
	Super::Destroyed();

	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red,
		FString::Printf(TEXT("El enemigo ya tiene vidas, fue destruido")));
	observer->Cancelar(this);
}

