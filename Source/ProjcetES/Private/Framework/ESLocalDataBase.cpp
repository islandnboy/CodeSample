// Fill out your copyright notice in the Description page of Project Settings.


#include "Framework/ESLocalDataBase.h"
#include "JsonObjectConverter.h"
#include "JsonObjectWrapper.h"


UESLocalDataBase::UESLocalDataBase()
{
	JsonString;
}

bool UESLocalDataBase::Init()
{
	if(LoadData() == false)
	{
		RootObject = MakeShareable(new FJsonObject());
		Thumbnail = MakeShareable(new FJsonObject());
		Featured = MakeShareable(new FJsonObject());
		RootObject->SetObjectField(TEXT("Thumbnail"), Thumbnail);
		RootObject->SetObjectField(TEXT("Featured"), Featured);
	}
	return true;
}

bool UESLocalDataBase::LoadData()
{
	/*
	TSharedPtr<TJsonReader<TCHAR> > Reader = TJsonReaderFactory<TCHAR>(JsonString);
	if(Reader.IsValid())
	{
		RootObject = MakeShareable(new FJsonObject());
		if(FJsonSerializer::Deserialize(Reader, RootObject))
		{
			Thumbnail = RootObject->GetField<FJsonValue>(TEXT("Thumbnail"));
			Featured = RootObject->GetField<FJsonValue>(TEXT("Featured"));
		}

	}
	*/
	return false;
}

bool UESLocalDataBase::SaveData(const FString& SavePath)
{
	TSharedRef<TJsonWriter<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>> JsonWriter = TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>::Create(&JsonString, 0);

	if(FJsonSerializer::Serialize(RootObject.ToSharedRef(), JsonWriter, true))
	{
		return FFileHelper::SaveStringToFile(*JsonString, *SavePath);;
	}
	
	return false;
}

bool UESLocalDataBase::FindTumbnail(FString Category, FString FindKey, FString FindValue, TSharedPtr<FJsonObject>& Out)
{
	if(Thumbnail.IsValid())
	{
		TArray< TSharedPtr<FJsonValue> > CategoryArr = Thumbnail->GetArrayField(Category);
		return FindObject(CategoryArr, FindKey, FindValue, Out);
	}
	return false;
}

bool UESLocalDataBase::FindFeatured(FString Category, FString FindKey, FString FindValue, TSharedPtr<FJsonObject>& Out)
{
	if (Featured.IsValid())
	{
		TArray< TSharedPtr<FJsonValue> > CategoryArr = Featured->GetArrayField(Category);
		return FindObject(CategoryArr, FindKey, FindValue, Out);

	}
	return false;
}

bool UESLocalDataBase::FindObject(const TArray< TSharedPtr<FJsonValue> >& SourceArr, const FString& FindKey, const FString& FindValue, TSharedPtr<FJsonObject>& Out)
{
	TArray< TSharedPtr<FJsonValue> > Arr = SourceArr;
	for (int32 i = 0; i < Arr.Num(); i++)
	{
		TSharedPtr<FJsonValue> JsonValue = Arr[i];
		TSharedPtr<FJsonObject> JsonValueObject = JsonValue->AsObject();

		if (JsonValueObject->GetStringField(FindKey).Equals(FindValue))
		{
			Out = JsonValueObject;
			return true;
		}

	}
	return false;
}

bool UESLocalDataBase::InsertTumbnail(FString Category, FString InsertKey, TSharedPtr<FJsonObject>& InsertObject)
{
	if (Thumbnail.IsValid())
	{
		TArray< TSharedPtr<FJsonValue> > CategoryArr = Thumbnail->GetArrayField(Category);
		return InsertUnique(CategoryArr, InsertKey, InsertObject);
	}
	return false;
}

bool UESLocalDataBase::InsertFeatured(FString Category, FString InsertKey,  TSharedPtr<FJsonObject>& InsertObject)
{
	if (Featured.IsValid())
	{
		TArray< TSharedPtr<FJsonValue> > CategoryArr = Featured->GetArrayField(Category);
		return InsertUnique(CategoryArr, InsertKey, InsertObject);
	}
	return false;
}


bool UESLocalDataBase::InsertUnique(TArray<TSharedPtr<FJsonValue>>& SourceArr, FString InsertKey, TSharedPtr<FJsonObject>& InsertObject)
{
	TArray< TSharedPtr<FJsonValue> > JsonArr = SourceArr;
	for (int32 i = 0; i < JsonArr.Num(); i++)
	{
		TSharedPtr<FJsonValue> JsonValue = JsonArr[i];
		TSharedPtr<FJsonObject> JsonValueObject = JsonValue->AsObject();

		if (JsonValueObject->GetStringField(InsertKey) == InsertObject->GetStringField(InsertKey))
		{
			return false;
		}

	}

	TSharedRef< FJsonValueObject > JsonValue = MakeShareable(new FJsonValueObject(InsertObject));
	JsonArr.Add(JsonValue);

	return true;
}
