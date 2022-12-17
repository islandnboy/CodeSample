// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "ESAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

#define ATTRIBUTE_REPLICATER(ClassName, PropertyName)\
	UFUNCTION() \
    virtual void OnRep_##PropertyName(const FGameplayAttributeData& Old##PropertyName)\
    {\
		GAMEPLAYATTRIBUTE_REPNOTIFY(ClassName, PropertyName,  Old##PropertyName);\
	}
/**
 * 
 */
UCLASS()
class PROJCETES_API UESAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
    // ���� ü��
    // + ȸ��
    // - ����
    UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData Health;
    ATTRIBUTE_ACCESSORS(UESAttributeSet, Health)
    // �ִ� ü�� GameplayEffects �� ������ ������
	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_MaxHealth)
    FGameplayAttributeData MaxHealth;
    ATTRIBUTE_ACCESSORS(UESAttributeSet, MaxHealth)
	// ���� ����
	UPROPERTY(BlueprintReadOnly, Category = "Mana", ReplicatedUsing = OnRep_Mana)
	FGameplayAttributeData Mana;
    ATTRIBUTE_ACCESSORS(UESAttributeSet, Mana)
    // �ִ� ���� GameplayEffects �� ������ ������
	UPROPERTY(BlueprintReadOnly, Category = "Mana", ReplicatedUsing = OnRep_MaxMana)
    FGameplayAttributeData MaxMana;
    ATTRIBUTE_ACCESSORS(UESAttributeSet, MaxMana)
    // ���¹̳�
    UPROPERTY(BlueprintReadOnly, Category = "Stamina", ReplicatedUsing = OnRep_Stamina)
	FGameplayAttributeData Stamina;
    ATTRIBUTE_ACCESSORS(UESAttributeSet, Stamina)
    // �ִ� ���¹̳� GameplayEffects �� ������ ������
	UPROPERTY(BlueprintReadOnly, Category = "Stamina", ReplicatedUsing = OnRep_MaxStamina)
    FGameplayAttributeData MaxStamina;
    ATTRIBUTE_ACCESSORS(UESAttributeSet, MaxStamina)

	// ���ݷ�
	UPROPERTY(BlueprintReadOnly, Category = "Attack", ReplicatedUsing = OnRep_AttackPower)
	FGameplayAttributeData AttackPower;
    ATTRIBUTE_ACCESSORS(UESAttributeSet, AttackPower)
   
    // ġ��Ÿ Ȯ��
	UPROPERTY(BlueprintReadOnly, Category = "Critical", ReplicatedUsing = OnRep_CriticalRate)
	FGameplayAttributeData CriticalRate;
    ATTRIBUTE_ACCESSORS(UESAttributeSet, CriticalRate)
	// ġ��Ÿ ����� ���
    UPROPERTY(BlueprintReadOnly, Category = "Critical", ReplicatedUsing = OnRep_CriticalDamage)
	FGameplayAttributeData CriticalDamage;
    ATTRIBUTE_ACCESSORS(UESAttributeSet, CriticalDamage)

     // ���� �ӵ�
	UPROPERTY(BlueprintReadOnly, Category = "Speed", ReplicatedUsing = OnRep_AttackSpeedScale)
	FGameplayAttributeData AttackSpeedScale;
    ATTRIBUTE_ACCESSORS(UESAttributeSet, AttackSpeedScale)
    // �̵��ӵ�
	UPROPERTY(BlueprintReadOnly, Category = "Speed", ReplicatedUsing = OnRep_MoveSpeedScale)
	FGameplayAttributeData MoveSpeedScale;
    ATTRIBUTE_ACCESSORS(UESAttributeSet, MoveSpeedScale)

    // �����
    // ������ ��� ��Ÿ������
    UPROPERTY(BlueprintReadOnly, Category = "Damage")
	FGameplayAttributeData Damage;
    ATTRIBUTE_ACCESSORS(UESAttributeSet, Damage)
public:
    UESAttributeSet();

    // AttributeSet Overrides
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    // �̸����� Ž��
    float GetAttributeValue(FName AttributeName, bool bBase = false);
    // �̸����� ����
    void SetAttributeValue(FName AttributeName, float NewVal);
    // �̸����� �ʱ�ȭ
    void InitAttribute(FName AttributeName, float Value);

protected:
    // Max ��ȭ���� ���� �Ӽ�����
    void AdjustAttributeForMaxChange(FGameplayAttributeData& AffectedAttribute, const FGameplayAttributeData& MaxAttribute, float NewValue, const FGameplayAttribute& AffectedAttributeProperty);

    UFUNCTION() virtual void OnRep_Health(const FGameplayAttributeData& OldHealth) { GAMEPLAYATTRIBUTE_REPNOTIFY(UESAttributeSet, Health, OldHealth); }
    UFUNCTION() virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) { GAMEPLAYATTRIBUTE_REPNOTIFY(UESAttributeSet, MaxHealth, OldMaxHealth); }
    UFUNCTION() virtual void OnRep_Mana(const FGameplayAttributeData& OldMana) { GAMEPLAYATTRIBUTE_REPNOTIFY(UESAttributeSet, Mana, OldMana); }
	UFUNCTION() virtual void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) { GAMEPLAYATTRIBUTE_REPNOTIFY(UESAttributeSet, MaxMana, OldMaxMana); }
    UFUNCTION() virtual void OnRep_Stamina(const FGameplayAttributeData& OldStamina) { GAMEPLAYATTRIBUTE_REPNOTIFY(UESAttributeSet, Stamina, OldStamina); }
	UFUNCTION() virtual void OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) { GAMEPLAYATTRIBUTE_REPNOTIFY(UESAttributeSet, MaxStamina, OldMaxStamina); }

    UFUNCTION() virtual void OnRep_AttackPower(const FGameplayAttributeData& OldAttackPower) { GAMEPLAYATTRIBUTE_REPNOTIFY(UESAttributeSet, AttackPower, OldAttackPower); }
    UFUNCTION() virtual void OnRep_CriticalRate(const FGameplayAttributeData& OldCriticalRate) { GAMEPLAYATTRIBUTE_REPNOTIFY(UESAttributeSet, CriticalRate, OldCriticalRate); }
    UFUNCTION() virtual void OnRep_CriticalDamage(const FGameplayAttributeData& OldCriticalDamage) { GAMEPLAYATTRIBUTE_REPNOTIFY(UESAttributeSet, CriticalDamage, OldCriticalDamage); }
    UFUNCTION() virtual void OnRep_AttackSpeedScale(const FGameplayAttributeData& OldAttackSpeedScale) { GAMEPLAYATTRIBUTE_REPNOTIFY(UESAttributeSet, AttackSpeedScale, OldAttackSpeedScale); }
    UFUNCTION() virtual void OnRep_MoveSpeedScale(const FGameplayAttributeData& OldMoveSpeedScale) { GAMEPLAYATTRIBUTE_REPNOTIFY(UESAttributeSet, MoveSpeedScale, OldMoveSpeedScale); }

};
