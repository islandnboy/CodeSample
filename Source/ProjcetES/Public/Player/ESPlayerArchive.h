// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ESPlayerArchive.generated.h"

/**
 * 
 */
UCLASS()
class PROJCETES_API UESPlayerArchive : public UObject
{
	GENERATED_BODY()

public:
	UESPlayerArchive();

	UFUNCTION(BlueprintCallable)
	bool Init();

	UFUNCTION(BlueprintCallable)
	bool Find(int Index, class UObject* Out, bool ForceMake = false);


	UFUNCTION(BlueprintCallable)
	bool NewObject(class UObject* Out);

private:

	UPROPERTY()
	TArray<class UObject*> __RawData;

	TSharedPtr<FJsonObject> Thumbnail;

	TSharedPtr<FJsonObject> Featured;
	
};
