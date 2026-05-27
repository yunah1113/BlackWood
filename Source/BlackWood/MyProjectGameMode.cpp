// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProjectGameMode.h"
#include "UW_NoteWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"

AMyProjectGameMode::AMyProjectGameMode() {}

void AMyProjectGameMode::BeginPlay()
{
    Super::BeginPlay();

    TArray<AActor*> AllActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), AllActors);

    for (AActor* Actor : AllActors)
    {
        if (Actor)
        {
            FString ActorName = Actor->GetClass()->GetName();

            if (ActorName.Contains(TEXT("BP_Rock")))
            {
                TotalRocks++;
            }
            else if (ActorName.Contains(TEXT("BP_Note")))
            {
                TotalNotes++;
            }
        }
    }

    UE_LOG(LogTemp, Warning, TEXT("C++ 카운트 완료 - 돌: %d개, 쪽지: %d개"), TotalRocks, TotalNotes);
}

void AMyProjectGameMode::AddRock()
{
    CurrentRocks++;
}

void AMyProjectGameMode::AddNote()
{
    CurrentNotes++;
}

FText AMyProjectGameMode::GetRockProgressText() const
{
    return FText::FromString(FString::Printf(TEXT("돌 수집 %d / %d"), CurrentRocks, TotalRocks));
}

FText AMyProjectGameMode::GetNoteProgressText() const
{
    return FText::FromString(FString::Printf(TEXT("쪽지 수집 %d / %d"), CurrentNotes, TotalNotes));
}

void AMyProjectGameMode::ShowNotePopup(int32 NoteID)
{
    APlayerController* PC = GetWorld()->GetFirstPlayerController();
    if (!PC) return;

    TSubclassOf<UUserWidget> WidgetClass = nullptr;

    if (NoteID == 1) WidgetClass = NoteWidgetClass_1;
    else if (NoteID == 2) WidgetClass = NoteWidgetClass_2;
    else if (NoteID == 3) WidgetClass = NoteWidgetClass_3;

    if (!WidgetClass)
    {
        UE_LOG(LogTemp, Error, TEXT("NoteID %d 에 해당하는 위젯 클래스가 없습니다!"), NoteID);
        return;
    }

    UUserWidget* CreatedWidget = CreateWidget<UUserWidget>(PC, WidgetClass);
    if (CreatedWidget)
    {
        CreatedWidget->AddToViewport(10);
        AddNote();
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("위젯 생성 실패!"));
    }
}

bool AMyProjectGameMode::IsAllCollected() const
{
    return CurrentRocks >= TotalRocks && CurrentNotes >= TotalNotes;
}
