#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "QuestDataTypes.generated.h"

USTRUCT(BlueprintType)
struct FQuestObjective
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestObjective")
	FText ObjectiveName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestObjective")
	FText ObjectiveDescription;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestObjective")
	FString ObjectiveID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestObjective")
	int32 Quantity = 0;
	
};

USTRUCT(BlueprintType)
struct FQuestList : public FTableRowBase
{

	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestData")
	FText QuestName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestData")
	FText QuestDescription;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestData")
	TArray<FQuestObjective> QuestObjective;
	
};


