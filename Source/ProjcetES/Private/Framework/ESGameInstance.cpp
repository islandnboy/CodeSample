// Fill out your copyright notice in the Description page of Project Settings.


#include "Framework/ESGameInstance.h"
#include "Framework/ESLocalDataBase.h"

UESGameInstance::UESGameInstance()
{
	LocalDB = CreateDefaultSubobject<UESLocalDataBase>(TEXT("ESLocalDataBase"));
}

UESLocalDataBase* UESGameInstance::GetLocalDataBase()
{
	return LocalDB;
}
