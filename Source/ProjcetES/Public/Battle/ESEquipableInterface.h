// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ESEquipableInterface.generated.h"
/**
 * 
 */
UINTERFACE(MinimalAPI, Blueprintable)
class UESEquipableItem : public UInterface
{
	GENERATED_BODY()
};

class PROJCETES_API IESEquipableItem
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "IESEquipableItem")
	bool Equip();
	virtual bool Equip_Implementation() { return false; }

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "IESEquipableItem")
	bool UnEquip();
	virtual bool UnEquip_Implementation() { return false; }

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "IESEquipableItem")
	bool GetEquipSlot(FName& SlotName);
	virtual bool GetEquipSlot_Implementation(FName& SlotName) { return false; }

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "IESEquipableItem")
	bool GetOwner(AActor*& Owner);
	virtual bool GetOwner_Implementation(AActor*& Owner) { return false; }

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "IESEquipableItem")
	bool SetOwner(AActor* Owner);
	virtual bool SetOwner_Implementation(AActor* Owner) { return false; }

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "IESEquipableItem")
	bool GetEquippedActor(AActor*& OutActor);
	virtual bool GetEquippedActor_Implementation(AActor*& OutActor) { return false; }
};

UINTERFACE(MinimalAPI, Blueprintable)
class UESEquipmentOwner : public UInterface
{
	GENERATED_BODY()
};


class PROJCETES_API IESEquipmentOwner
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "IESEquipableItem")
	bool AddEquipItem(const TScriptInterface<IESEquipableItem>& iItem);
	virtual bool AddEquipItem_Implementation(const TScriptInterface<IESEquipableItem>& iItem) { return false; }

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "IESEquipableItem")
	bool RemoveEquipItem(const TScriptInterface<IESEquipableItem>& iItem);
	virtual bool RemoveEquipItem_Implementation(const TScriptInterface<IESEquipableItem>& iItem) { return false; }

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "IESEquipableItem")
	bool FindEquipItem(FName EquipSlot, UObject*& Out);
	virtual bool FindEquipItem_Implementation(FName EquipSlot, UObject*& Out) { return false; }

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "IESEquipableItem")
	bool GetAllEquipItems(TArray<UObject*>& Out);
	virtual bool GetAllEquipItems_Implementation(TArray<UObject*>& Out) { return false; }
};
