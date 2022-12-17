// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ESPlayerContentInfo.generated.h"

/**
 * 
 */

UINTERFACE(MinimalAPI)
class UESContentThumbnail : public UInterface
{
	GENERATED_BODY()
};

class PROJCETES_API IESContentThumbnail
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	int32 GetID();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetID(int32 ID);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	FName GetName();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetName(const FName& Name);

};

UINTERFACE(MinimalAPI)
class UESHeroFeatured : public UInterface
{
	GENERATED_BODY()
};

class PROJCETES_API IESHeroFeatured
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	int32 GetLevel();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetLevel(int32 Level);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	int32 GetGrade();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetGrade(int32 Grade);
};


UCLASS()
class PROJCETES_API UESHeroContentObject : public UObject, public IESContentThumbnail, public IESHeroFeatured
{
	GENERATED_BODY()

public:
	UESHeroContentObject();

	virtual int32 GetID_Implementation() override;

	virtual void SetID_Implementation(int32 ID) override;

	virtual FName GetName_Implementation() override;

	virtual void SetName_Implementation(const FName& Name) override;

	virtual int32 GetLevel_Implementation() override;

	virtual void SetLevel_Implementation(int32 Level) override;

	virtual int32 GetGrade_Implementation() override;

	virtual void SetGrade_Implementation(int32 Grade) override;

private:
	TSharedPtr<FJsonObject> Thumbnail;

	TSharedPtr<FJsonObject> Featured;
};
