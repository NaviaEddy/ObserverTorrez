// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ISubscriptor.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UISubscriptor : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class OBSERVER_API IISubscriptor
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void EstablecerObserver(class AVidasEnemigoObserver* _observer) = 0;
	virtual void Actualizar(class APublicador* _publicador) = 0;
};
