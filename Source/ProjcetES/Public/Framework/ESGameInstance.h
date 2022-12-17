// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ESGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJCETES_API UESGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UESGameInstance();

	UFUNCTION(BlueprintCallable)
	class UESLocalDataBase* GetLocalDataBase();

private:

	UPROPERTY()
	class UESLocalDataBase* LocalDB;

	
};
