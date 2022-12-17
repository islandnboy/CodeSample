// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ESLocalDataBase.generated.h"

/**
 * 
 */
UCLASS()
class PROJCETES_API UESLocalDataBase : public UObject
{
	GENERATED_BODY()

public:
	UESLocalDataBase();

	UFUNCTION(BlueprintCallable)
	bool Init();

	UFUNCTION(BlueprintCallable)
	bool LoadData();

	UFUNCTION(BlueprintCallable)
	bool SaveData(const FString& SavePath);


	bool FindTumbnail(FString Category, FString FindKey, FString FindValue, TSharedPtr<FJsonObject>& Out);

	bool FindFeatured(FString Category, FString FindKey, FString FindValue, TSharedPtr<FJsonObject>& Out);

	bool FindObject(const TArray< TSharedPtr<FJsonValue> >& SourceArr, const FString& FindKey, const FString& FindValue, TSharedPtr<FJsonObject>& Out);


	bool InsertTumbnail(FString Category, FString InsertKey, TSharedPtr<FJsonObject>& InsertObject);

	bool InsertFeatured(FString Category, FString InsertKey, TSharedPtr<FJsonObject>& InsertObject);

	bool InsertUnique(TArray< TSharedPtr<FJsonValue> >& SourceArr, FString InsertKey, TSharedPtr<FJsonObject>& InsertObject);

private:

	FString JsonString;

	TSharedPtr<FJsonObject> RootObject;

	TSharedPtr<FJsonObject> Thumbnail;

	TSharedPtr<FJsonObject> Featured;

};

