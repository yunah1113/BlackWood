// Fill out your copyright notice in the Description page of Project Settings.


#include "W_CollectionHUD.h"
#include "MyProjectGameMode.h" // 내 게임모드의 기능을 쓰기 위해 불러옵니다.
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Blueprint/WidgetTree.h"

bool UW_CollectionHUD::Initialize()
{
	if (!Super::Initialize()) return false;

	// 1. 태초의 도화지(Canvas Panel)를 코드로 생성합니다.
	UCanvasPanel* RootCanvas = NewObject<UCanvasPanel>(this);
	if (!RootCanvas) return false;
	WidgetTree->RootWidget = RootCanvas; // 이 위젯의 바탕화면으로 지정

	// 2. 돌 수집 텍스트 상자 생성 및 세팅
	CodelessRockText = NewObject<UTextBlock>(this);
	if (CodelessRockText)
	{
		RootCanvas->AddChild(CodelessRockText);
		// 화면 좌측 상단에 배치 (X: 50, Y: 50 위치)
		if (UCanvasPanelSlot* TextSlot = Cast<UCanvasPanelSlot>(CodelessRockText->Slot))
		{
			TextSlot->SetPosition(FVector2D(50.0f, 50.0f));
			TextSlot->SetSize(FVector2D(400.0f, 50.0f));
		}
		// 글씨 크기 설정 (기본 24pt)
		CodelessRockText->Font.Size = 24;
	}

	// 3. 쪽지 수집 텍스트 상자 생성 및 세팅
	CodelessNoteText = NewObject<UTextBlock>(this);
	if (CodelessNoteText)
	{
		RootCanvas->AddChild(CodelessNoteText);
		// 돌 수집 글자 바로 밑에 배치 (X: 50, Y: 100 위치)
		if (UCanvasPanelSlot* TextSlot = Cast<UCanvasPanelSlot>(CodelessNoteText->Slot))
		{
			TextSlot->SetPosition(FVector2D(50.0f, 100.0f));
			TextSlot->SetSize(FVector2D(400.0f, 50.0f));
		}
		CodelessNoteText->Font.Size = 24;
	}

	return true;
}

void UW_CollectionHUD::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	// 실시간으로 게임모드에서 값을 받아와 글자를 업데이트합니다.
	if (AMyProjectGameMode* GM = Cast<AMyProjectGameMode>(GetWorld()->GetAuthGameMode()))
	{
		if (CodelessRockText)
		{
			CodelessRockText->SetText(GM->GetRockProgressText());
		}
		if (CodelessNoteText)
		{
			CodelessNoteText->SetText(GM->GetNoteProgressText());
		}
	}
}
