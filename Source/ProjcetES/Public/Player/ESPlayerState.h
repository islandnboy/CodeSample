// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "Battle/ESBattleInterface.h"
#include "Battle/ESEquipableInterface.h"
#include "ESPlayerState.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBattleAgentPerformEventDelegate, FName, EventName, const FString&, Args);

UCLASS()
class PROJCETES_API AESPlayerState :
	public APlayerState,
	public IAbilitySystemInterface,
	public IESBattleAgent,
	public IESEquipmentOwner
{
	GENERATED_BODY()

public:
	AESPlayerState();


	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	class UESAttributeSet* GetAttributeSet() const;

	// IESBattleAgent 备泅何
	virtual bool GetAttributeValue_Implementation(FName AttributeName, float& fOut, bool bBase) override;
	virtual bool SetAttributeValue_Implementation(FName AttributeName, float Value, bool bBase) override;
	virtual bool AddGameplayTag_Implementation(FGameplayTag Tag) override;
	virtual bool RemoveGameplayTag_Implementation(FGameplayTag Tag) override;
	virtual bool HasGameplayTag_Implementation(FGameplayTag Tag) override;
	virtual bool GetAgentSource_Implementation(AActor*& Actor) override;
	virtual bool GetAgentAvatar_Implementation(AActor*& Actor) override;
	virtual bool PerformAgentEvent_Implementation(FName EventName, const FString& ArgString) override;

	// IESEquipmentOwner 备泅何
	virtual bool AddEquipItem_Implementation(const TScriptInterface<IESEquipableItem>& iItem)override;
	virtual bool RemoveEquipItem_Implementation(const TScriptInterface<IESEquipableItem>& iItem)override;
	virtual bool FindEquipItem_Implementation(FName EquipSlot, UObject*& Out)override;
	virtual bool GetAllEquipItems_Implementation(TArray<UObject*>& Out)override;


	UPROPERTY(BlueprintAssignable, Category = "ESPlayerState:IESBattleAgent")
	FBattleAgentPerformEventDelegate OnBattleAgentPerformEventDelegate;

private:

	UPROPERTY()
	class UESAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
	class UESAttributeSet* AttributeSet;

	UPROPERTY();
	TMap<FName, UObject*> EquipItmes;
};
