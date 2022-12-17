// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/ESPlayerContentInfo.h"



UESHeroContentObject::UESHeroContentObject()
{
}
int32 UESHeroContentObject::GetID_Implementation()
{
	if(Thumbnail.IsValid())
	{
		return Thumbnail->GetIntegerField("ID");
	}
	return 0;
}

void UESHeroContentObject::SetID_Implementation(int32 ID)
{
	if (Thumbnail.IsValid())
	{
		Thumbnail->SetNumberField("ID", ID);
	}
}

FName UESHeroContentObject::GetName_Implementation()
{
	FName Name;
	if (Thumbnail.IsValid())
	{
		Name = FName( Thumbnail->GetStringField("Name"));
	}
	return Name;
}

void UESHeroContentObject::SetName_Implementation(const FName& Name)
{
	if (Thumbnail.IsValid())
	{
		Thumbnail->SetStringField("Name", Name.ToString());
	}
}

int32 UESHeroContentObject::GetLevel_Implementation()
{
	if (Featured.IsValid())
	{
		return Featured->GetIntegerField("Level");
	}
	return 0;
}

void UESHeroContentObject::SetLevel_Implementation(int32 Level)
{
	if (Featured.IsValid())
	{
		return Featured->SetNumberField("Level", Level);
	}
}

int32 UESHeroContentObject::GetGrade_Implementation()
{
	if (Featured.IsValid())
	{
		return Featured->GetIntegerField("Grade");
	}
	return 0;
}

void UESHeroContentObject::SetGrade_Implementation(int32 Grade)
{
	if (Featured.IsValid())
	{
		return Featured->SetNumberField("Grade", Grade);
	}
}

