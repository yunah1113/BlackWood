// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetTree.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/Border.h"
#include "Components/VerticalBox.h"
#include "Components/VerticalBoxSlot.h"
#include "UW_NoteWidget.generated.h"

UCLASS()
class BLACKWOOD_API UUW_NoteWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Note")
	void InitNote(int32 NoteID);

	UFUNCTION(BlueprintCallable, Category = "Note")
	void AdvanceNote();

protected:
	virtual void NativeConstruct() override;
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;

private:
	UPROPERTY()
	UCanvasPanel* RootCanvas = nullptr;

	UPROPERTY()
	UBorder* BackgroundBorder = nullptr;

	UPROPERTY()
	UTextBlock* PreviewText = nullptr;

	UPROPERTY()
	UTextBlock* FullText = nullptr;

	UPROPERTY()
	UTextBlock* HintText = nullptr;

	bool bShowingFull = false;
	int32 CurrentNoteID = 0;

	FString GetPreviewText(int32 NoteID);
	FString GetFullText(int32 NoteID);

	void ShowPreview();
	void ShowFull();
	void CloseNote();
};