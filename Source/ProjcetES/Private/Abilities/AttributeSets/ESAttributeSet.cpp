// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/AttributeSets/ESAttributeSet.h"

UESAttributeSet::UESAttributeSet()
{
}

void UESAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
}

void UESAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

void UESAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

float UESAttributeSet::GetAttributeValue(FName AttributeName, bool bBase)
{

	for (TFieldIterator<FProperty> Iter(GetClass(), EFieldIteratorFlags::IncludeSuper); Iter; ++Iter)
	{
		FProperty* Property = *Iter;

		if (Property->GetName().Equals(AttributeName.ToString()) == false)
			continue;

		if (FGameplayAttribute::IsGameplayAttributeDataProperty(Property) == false)
			continue;

		FStructProperty* StructProperty = CastField<FStructProperty>(Property);
		check(StructProperty);
		const FGameplayAttributeData* DataPtr = StructProperty->ContainerPtrToValuePtr<FGameplayAttributeData>(this);
		check(DataPtr);
		if (bBase)
			return DataPtr->GetBaseValue();
		else
			return DataPtr->GetCurrentValue();
	}

	return 0.0f;
}

void UESAttributeSet::SetAttributeValue(FName AttributeName, float NewVal)
{
	FProperty* FoundProp = FindFieldChecked<FProperty>(GetClass(), AttributeName);
	if (FoundProp == nullptr)
		return;
	FGameplayAttribute FoundAttribute(FoundProp);
	if (FoundAttribute.IsValid())
	{
		UAbilitySystemComponent* ASC = GetOwningAbilitySystemComponent();
		if (ensure(ASC))
		{
			ASC->SetNumericAttributeBase(FoundAttribute, NewVal);
		}
	}
}

void UESAttributeSet::AdjustAttributeForMaxChange(FGameplayAttributeData& AffectedAttribute, const FGameplayAttributeData& MaxAttribute, float NewValue, const FGameplayAttribute& AffectedAttributeProperty)
{
	UAbilitySystemComponent* ASC = GetOwningAbilitySystemComponent();
	const float CurrentMaxValue = MaxAttribute.GetCurrentValue();
	if (!FMath::IsNearlyEqual(CurrentMaxValue, NewValue) && ASC)
	{
		const float CurrentValue = AffectedAttribute.GetCurrentValue();
		float NewDelta = (CurrentMaxValue > 0.f) ? (CurrentValue * NewValue / CurrentMaxValue) - CurrentValue : NewValue;
		ASC->ApplyModToAttributeUnsafe(AffectedAttributeProperty, EGameplayModOp::Additive, NewDelta);
	}
}

void UESAttributeSet::InitAttribute(FName AttributeName, float Value)
{
	FProperty* FoundProp = FindFieldChecked<FProperty>(GetClass(), AttributeName);
	if (FoundProp == nullptr)
		return;

	if (FGameplayAttribute::IsGameplayAttributeDataProperty(FoundProp))
	{
		FStructProperty* StructProperty = CastField<FStructProperty>(FoundProp);
		check(StructProperty);
		FGameplayAttributeData* DataPtr = StructProperty->ContainerPtrToValuePtr<FGameplayAttributeData>(this);
		check(DataPtr);
		DataPtr->SetBaseValue(Value);
		DataPtr->SetCurrentValue(Value);
	}
}