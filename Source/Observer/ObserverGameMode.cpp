// Copyright Epic Games, Inc. All Rights Reserved.

#include "ObserverGameMode.h"
#include "ObserverCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "VidasEnemigoObserver.h"
#include "Enemigo1.h"

AObserverGameMode::AObserverGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AObserverGameMode::BeginPlay()
{
	Super::BeginPlay();

	observer = GetWorld()->SpawnActor<AVidasEnemigoObserver>(AVidasEnemigoObserver::StaticClass());
	enemigo1 = GetWorld()->SpawnActor<AEnemigo1>(AEnemigo1::StaticClass());

	enemigo1->EstablecerObserver(observer);
	observer->EstablecerAccion("QuitarVida");
	observer->EstablecerAccion("QuitarVida");
	observer->EstablecerAccion("QuitarVida");

}
