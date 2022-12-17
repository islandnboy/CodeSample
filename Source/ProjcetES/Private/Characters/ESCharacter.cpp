// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/ESCharacter.h"
#include "Abilities/ESAbilitySystemComponent.h"
#include "Abilities/AttributeSets/ESAttributeSet.h"

// Sets default values
AESCharacter::AESCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

UAbilitySystemComponent* AESCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent.Get();
}

UESAttributeSet* AESCharacter::GetAttributeSet()
{
	return AttributeSet.Get();
}

void AESCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
}

void AESCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
}

void AESCharacter::HandleDmage(FHitResult HItResult, float DamageAmount, APawn* DamageInstigator, AActor* DamageCauser)
{
}

void AESCharacter::HandleDamageFeedback(FHitResult HitResult, float DamageAmount)
{
}

bool AESCharacter::GetAttributeValue_Implementation(FName AttributeName, float& fOut, bool bBase)
{
	if (AttributeSet.IsValid())
	{
		fOut = AttributeSet->GetAttributeValue(AttributeName, bBase);
		return true;
	}
	return false;
}

bool AESCharacter::SetAttributeValue_Implementation(FName AttributeName, float Value, bool bBase)
{
	if (AttributeSet.IsValid())
	{
		AttributeSet->SetAttributeValue(AttributeName, bBase);
		return true;
	}
	return false;
}

bool AESCharacter::AddGameplayTag_Implementation(FGameplayTag Tag)
{
	if (AbilitySystemComponent.IsValid())
	{
		AbilitySystemComponent->AddLooseGameplayTag(Tag);
		return true;
	}
	return false;
}

bool AESCharacter::RemoveGameplayTag_Implementation(FGameplayTag Tag)
{
	if (AbilitySystemComponent.IsValid())
	{
		AbilitySystemComponent->RemoveLooseGameplayTag(Tag);
		return true;
	}
	return false;
}

bool AESCharacter::HasGameplayTag_Implementation(FGameplayTag Tag)
{
	if (AbilitySystemComponent.IsValid())
	{
		return AbilitySystemComponent->HasMatchingGameplayTag(Tag);
	}
	return false;
}

bool AESCharacter::GetAgentSource_Implementation(AActor*& Actor)
{
	if (AbilitySystemComponent.IsValid())
	{
		Actor = AbilitySystemComponent->GetOwnerActor();
		return true;
	}
	return false;
}

bool AESCharacter::GetAgentAvatar_Implementation(AActor*& Actor)
{
	Actor = this;
	return true;
}

bool AESCharacter::PerformAgentEvent_Implementation(FName EventName, const FString& ArgString)
{

	return false;
}

// Called when the game starts or when spawned
void AESCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AESCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AESCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

