// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Battle/ESBattleInterface.h"
#include "ESCharacter.generated.h"

UCLASS()
class PROJCETES_API AESCharacter : 
	public ACharacter, 
	public IAbilitySystemInterface,
	public IESBattleAgent

{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AESCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	class UESAttributeSet* GetAttributeSet();

	virtual void PossessedBy(AController* NewController) override;

	virtual void OnRep_PlayerState() override;


	virtual void HandleDmage(FHitResult HItResult, float DamageAmount, APawn* DamageInstigator, AActor* DamageCauser);

	virtual void HandleDamageFeedback(FHitResult HitResult, float DamageAmount);


	// IESBattleAgent ±¸ÇöºÎ
	virtual bool GetAttributeValue_Implementation(FName AttributeName, float& fOut, bool bBase) override;
	virtual bool SetAttributeValue_Implementation(FName AttributeName, float Value, bool bBase) override;
	virtual bool AddGameplayTag_Implementation(FGameplayTag Tag) override;
	virtual bool RemoveGameplayTag_Implementation(FGameplayTag Tag) override;
	virtual bool HasGameplayTag_Implementation(FGameplayTag Tag) override;
	virtual bool GetAgentSource_Implementation(AActor*& Actor) override;
	virtual bool GetAgentAvatar_Implementation(AActor*& Actor) override;
	virtual bool PerformAgentEvent_Implementation(FName EventName, const FString& ArgString)override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	TWeakObjectPtr<class UESAbilitySystemComponent> AbilitySystemComponent;;

	TWeakObjectPtr<class UESAttributeSet> AttributeSet;

};
