
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyProjectGameMode.generated.h"

class UUW_NoteWidget;

UCLASS()
class BLACKWOOD_API AMyProjectGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    AMyProjectGameMode();

    virtual void BeginPlay() override;

    UFUNCTION(BlueprintCallable, Category = "Collection")
    void AddRock();

    UFUNCTION(BlueprintCallable, Category = "Collection")
    void AddNote();

    UFUNCTION(BlueprintCallable, Category = "Note")
    void ShowNotePopup(int32 NoteID);

    UFUNCTION(BlueprintPure, Category = "Collection")
    FText GetRockProgressText() const;

    UFUNCTION(BlueprintPure, Category = "Collection")
    FText GetNoteProgressText() const;
    
    UFUNCTION(BlueprintPure, Category = "Collection")
    bool IsAllCollected() const;

private:
    int32 TotalRocks = 0;
    int32 CurrentRocks = 0;

    int32 TotalNotes = 0;
    int32 CurrentNotes = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Note", meta = (AllowPrivateAccess = "true"))
    TSubclassOf<UUserWidget> NoteWidgetClass_1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Note", meta = (AllowPrivateAccess = "true"))
    TSubclassOf<UUserWidget> NoteWidgetClass_2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Note", meta = (AllowPrivateAccess = "true"))
    TSubclassOf<UUserWidget> NoteWidgetClass_3;
};