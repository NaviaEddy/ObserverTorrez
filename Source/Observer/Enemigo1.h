// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "ISubscriptor.h"
#include "IAccionEnemiga.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemigo1.generated.h"

UCLASS()
class OBSERVER_API AEnemigo1 : public AActor, public IISubscriptor, public IIAccionEnemiga
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemigo1();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Destroyed() override;


	int32 VidasEnemigo;
	class AVidasEnemigoObserver* observer;

	void MallaColision();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	void EstablecerObserver(class AVidasEnemigoObserver* _observer) override;
	void Actualizar(class APublicador* _publicador) override;
	void Actuar() override;
	void SetVidasEnemigo(int32 _vidas);
	FORCEINLINE int32 GetVidasEnemigo() { return VidasEnemigo; };
};
