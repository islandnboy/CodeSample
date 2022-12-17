// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/ESGameplayAbility.h"
#include "AbilitysystemComponent.h"
#include "AbilitySystemGlobals.h"
#include "Player/ESPlayerState.h"

UESGameplayAbility::UESGameplayAbility()
{
}

void UESGameplayAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (bRecieveBattleAgentPerformEvent)
	{
		AESPlayerState* Owner = Cast<AESPlayerState>(GetOwningActorFromActorInfo());
		if (Owner)
		{
			Owner->OnBattleAgentPerformEventDelegate.AddDynamic(this, &UESGameplayAbility::OnRecieveBattleAgentEvent);
			bPerfomBattleAgentEventRegisterd = true;
		}
	}

	if (ActorInfo->AbilitySystemComponent.IsValid())
	{
		RecieveGameplayEventDelegateHandle = ActorInfo->AbilitySystemComponent->AddGameplayEventTagContainerDelegate(RecieveGameplayEventTags, FGameplayEventTagMulticastDelegate::FDelegate::CreateUObject(this, &UESGameplayAbility::RecieveGamplayEvent));

	}

}

void UESGameplayAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility( Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	if (bPerfomBattleAgentEventRegisterd)
	{
		AESPlayerState* Owner = Cast<AESPlayerState>(GetOwningActorFromActorInfo());
		if (Owner)
		{
			Owner->OnBattleAgentPerformEventDelegate.RemoveDynamic(this, &UESGameplayAbility::OnRecieveBattleAgentEvent);
			bPerfomBattleAgentEventRegisterd = false;
		}
	}
	if (ActorInfo->AbilitySystemComponent.IsValid() && RecieveGameplayEventDelegateHandle.IsValid())
	{
		ActorInfo->AbilitySystemComponent->RemoveGameplayEventTagContainerDelegate(RecieveGameplayEventTags, RecieveGameplayEventDelegateHandle);

	}
}
void UESGameplayAbility::RecieveGamplayEvent(FGameplayTag EventTag, const FGameplayEventData* Payload)
{
	OnRecieveGamplayEvent(EventTag, *Payload);
}