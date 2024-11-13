// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ObserverGameMode.generated.h"

UCLASS(minimalapi)
class AObserverGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AObserverGameMode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	class AVidasEnemigoObserver* observer;
	class AEnemigo1* enemigo1;
};



