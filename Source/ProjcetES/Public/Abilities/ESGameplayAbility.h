// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "ESGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class PROJCETES_API UESGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
public:
	UESGameplayAbility();

	/** Actually activate ability, do not call this directly */
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	/** Native function, called if an ability ends normally or abnormally. If bReplicate is set to true, try to replicate the ending to the client/server */
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;

	UFUNCTION(BlueprintImplementableEvent, Category = "ESGameplayAbility")
	void OnRecieveBattleAgentEvent(FName Event, const FString& ArgString);

	UFUNCTION(BlueprintImplementableEvent, Category = "ESGameplayAbility")
	void OnRecieveGamplayEvent(FGameplayTag EventTag, FGameplayEventData Payload);

	void RecieveGamplayEvent(FGameplayTag EventTag, const FGameplayEventData* Payload);
protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ESGameplayAbility")
	FGameplayTagContainer RecieveGameplayEventTags;

	FDelegateHandle RecieveGameplayEventDelegateHandle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ESGameplayAbility")
	bool bRecieveBattleAgentPerformEvent = false;

	UPROPERTY(Transient)
	bool bPerfomBattleAgentEventRegisterd = false;

	
};
