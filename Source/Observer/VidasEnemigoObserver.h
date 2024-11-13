// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Publicador.h"
#include "VidasEnemigoObserver.generated.h"

UCLASS()
class OBSERVER_API AVidasEnemigoObserver : public APublicador
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVidasEnemigoObserver();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	FString Mensaje;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void EstablecerAccion(FString _mensaje);
	FORCEINLINE FString GetMensaje() { return Mensaje; };
};
