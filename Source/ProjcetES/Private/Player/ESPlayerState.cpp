// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ESPlayerState.h"
#include "Abilities/ESAbilitySystemComponent.h"
#include "Abilities/AttributeSets/ESAttributeSet.h"

AESPlayerState::AESPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UESAbilitySystemComponent>("AbilitySystemComp");
	AttributeSet = CreateDefaultSubobject<UESAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* AESPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UESAttributeSet* AESPlayerState::GetAttributeSet() const
{
	return AttributeSet;
}

bool AESPlayerState::GetAttributeValue_Implementation(FName AttributeName, float& fOut, bool bBase)
{
	fOut = AttributeSet->GetAttributeValue(AttributeName, bBase);
	return true;
}

bool AESPlayerState::SetAttributeValue_Implementation(FName AttributeName, float Value, bool bBase)
{
	AttributeSet->SetAttributeValue(AttributeName, Value);
	return true;

}

bool AESPlayerState::AddGameplayTag_Implementation(FGameplayTag Tag)
{
	AbilitySystemComponent->AddLooseGameplayTag(Tag);
	return true;
}

bool AESPlayerState::RemoveGameplayTag_Implementation(FGameplayTag Tag)
{
	AbilitySystemComponent->RemoveLooseGameplayTag(Tag);
	return true;
}

bool AESPlayerState::HasGameplayTag_Implementation(FGameplayTag Tag)
{
	return AbilitySystemComponent->HasMatchingGameplayTag(Tag);
}

bool AESPlayerState::GetAgentSource_Implementation(AActor*& Actor)
{
	Actor = this;
	return true;
}

bool AESPlayerState::GetAgentAvatar_Implementation(AActor*& Actor)
{
	Actor = GetPawn();
	return true;
}

bool AESPlayerState::PerformAgentEvent_Implementation(FName EventName, const FString& ArgString)
{
	OnBattleAgentPerformEventDelegate.Broadcast(EventName, ArgString);
	return false;
}

bool AESPlayerState::AddEquipItem_Implementation(const TScriptInterface<IESEquipableItem>& iItem)
{
	UObject* Obj = iItem.GetObject();
	if (Obj == nullptr)
		return false;
	FName SlotName;
	if (IESEquipableItem::Execute_GetEquipSlot(Obj, SlotName))
	{
		EquipItmes.Add(SlotName, Obj);
		return true;
	}

	return false;
}

bool AESPlayerState::RemoveEquipItem_Implementation(const TScriptInterface<IESEquipableItem>& iItem)
{
	UObject* Obj = iItem.GetObject();
	if (Obj == nullptr)
		return false;
	FName SlotName;
	if (IESEquipableItem::Execute_GetEquipSlot(Obj, SlotName))
	{
		EquipItmes.Remove(SlotName);
		return true;
	}
	return false;
}

bool AESPlayerState::FindEquipItem_Implementation(FName EquipSlot, UObject*& Out)
{
	if (EquipItmes.Contains(EquipSlot))
	{
		Out = EquipItmes[EquipSlot];
		return true;
	}
	return false;
}

bool AESPlayerState::GetAllEquipItems_Implementation(TArray<UObject*>& Out)
{
	if (EquipItmes.IsEmpty() == false)
	{
		for (auto Iter : EquipItmes)
		{
			Out.Add(Iter.Value);
		}
	}
	return false;
}

