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
    // 현재 체력
    // + 회복
    // - 피해
    UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData Health;
    ATTRIBUTE_ACCESSORS(UESAttributeSet, Health)
    // 최대 체력 GameplayEffects 로 변경이 가능함
	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_MaxHealth)
    FGameplayAttributeData MaxHealth;
    ATTRIBUTE_ACCESSORS(UESAttributeSet, MaxHealth)
	// 헌재 마나
	UPROPERTY(BlueprintReadOnly, Category = "Mana", ReplicatedUsing = OnRep_Mana)
	FGameplayAttributeData Mana;
    ATTRIBUTE_ACCESSORS(UESAttributeSet, Mana)
    // 최대 마나 GameplayEffects 로 변경이 가능함
	UPROPERTY(BlueprintReadOnly, Category = "Mana", ReplicatedUsing = OnRep_MaxMana)
    FGameplayAttributeData MaxMana;
    ATTRIBUTE_ACCESSORS(UESAttributeSet, MaxMana)
    // 스태미나
    UPROPERTY(BlueprintReadOnly, Category = "Stamina", ReplicatedUsing = OnRep_Stamina)
	FGameplayAttributeData Stamina;
    ATTRIBUTE_ACCESSORS(UESAttributeSet, Stamina)
    // 최대 스태미나 GameplayEffects 로 변경이 가능함
	UPROPERTY(BlueprintReadOnly, Category = "Stamina", ReplicatedUsing = OnRep_MaxStamina)
    FGameplayAttributeData MaxStamina;
    ATTRIBUTE_ACCESSORS(UESAttributeSet, MaxStamina)

	// 공격력
	UPROPERTY(BlueprintReadOnly, Category = "Attack", ReplicatedUsing = OnRep_AttackPower)
	FGameplayAttributeData AttackPower;
    ATTRIBUTE_ACCESSORS(UESAttributeSet, AttackPower)
   
    // 치명타 확률
	UPROPERTY(BlueprintReadOnly, Category = "Critical", ReplicatedUsing = OnRep_CriticalRate)
	FGameplayAttributeData CriticalRate;
    ATTRIBUTE_ACCESSORS(UESAttributeSet, CriticalRate)
	// 치명타 대미지 계수
    UPROPERTY(BlueprintReadOnly, Category = "Critical", ReplicatedUsing = OnRep_CriticalDamage)
	FGameplayAttributeData CriticalDamage;
    ATTRIBUTE_ACCESSORS(UESAttributeSet, CriticalDamage)

     // 공격 속도
	UPROPERTY(BlueprintReadOnly, Category = "Speed", ReplicatedUsing = OnRep_AttackSpeedScale)
	FGameplayAttributeData AttackSpeedScale;
    ATTRIBUTE_ACCESSORS(UESAttributeSet, AttackSpeedScale)
    // 이동속도
	UPROPERTY(BlueprintReadOnly, Category = "Speed", ReplicatedUsing = OnRep_MoveSpeedScale)
	FGameplayAttributeData MoveSpeedScale;
    ATTRIBUTE_ACCESSORS(UESAttributeSet, MoveSpeedScale)

    // 대미지
    // 서버용 계산 메타데이터
    UPROPERTY(BlueprintReadOnly, Category = "Damage")
	FGameplayAttributeData Damage;
    ATTRIBUTE_ACCESSORS(UESAttributeSet, Damage)
public:
    UESAttributeSet();

    // AttributeSet Overrides
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    // 이름으로 탐색
    float GetAttributeValue(FName AttributeName, bool bBase = false);
    // 이름으로 변경
    void SetAttributeValue(FName AttributeName, float NewVal);
    // 이름으로 초기화
    void InitAttribute(FName AttributeName, float Value);

protected:
    // Max 변화량에 따른 속성조절
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
