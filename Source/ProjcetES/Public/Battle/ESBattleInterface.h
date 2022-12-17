// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ESBattleInterface.generated.h"
/**
 * 
 */

UINTERFACE(MinimalAPI, Blueprintable)
class UESBattleAgent : public UInterface
{
	GENERATED_BODY()
};

class PROJCETES_API IESBattleAgent
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ISFBattleActorInterface")
	bool GetAttributeValue(FName AttributeName, float& fOut, bool bBase = false);
	virtual bool GetAttributeValue_Implementation(FName AttributeName, float& fOut, bool bBase) { return false; }
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ISFBattleActorInterface")
	bool SetAttributeValue(FName AttributeName, float Value, bool bBase = false);
	virtual bool SetAttributeValue_Implementation(FName AttributeName, float Value, bool bBase) { return false; }

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ISFBattleActorInterface")
	bool AddGameplayTag(FGameplayTag Tag);
	virtual bool AddGameplayTag_Implementation(FGameplayTag Tag) { return false; }

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ISFBattleActorInterface")
	bool RemoveGameplayTag(FGameplayTag Tag);
	virtual bool RemoveGameplayTag_Implementation(FGameplayTag Tag) { return false; }

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ISFBattleActorInterface")
	bool HasGameplayTag(FGameplayTag Tag);
	virtual bool HasGameplayTag_Implementation(FGameplayTag Tag) { return false; }

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ISFBattleActorInterface")
	bool GetAgentSource(AActor*& Actor);
	virtual bool GetAgentSource_Implementation(AActor*& Actor) { return false; }

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ISFBattleActorInterface")
	bool GetAgentAvatar(AActor*& Actor);
	virtual bool GetAgentAvatar_Implementation(AActor*& Actor) { return false; }

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "ISFBattleActorInterface")
	bool PerformAgentEvent(FName EventName, const FString& ArgString);
	virtual bool PerformAgentEvent_Implementation(FName EventName, const FString& ArgString) { return false; }

};