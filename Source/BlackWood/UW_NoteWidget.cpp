#include "UW_NoteWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/WidgetTree.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/Border.h"
#include "Components/TextBlock.h"
#include "Components/CanvasPanel.h"

void UUW_NoteWidget::NativeConstruct()
{
    Super::NativeConstruct();

    
}

FString UUW_NoteWidget::GetPreviewText(int32 NoteID)
{
    switch (NoteID)
    {
    case 1: return TEXT("조각 1 루이스가 마니에게: \"마니, 당신을 위한 선물을 준비했소….\"");
    case 2: return TEXT("조각 2 루이스가 마니에게: \"마니 당신이라면 궁금한 걸 못 참을테니 미리 말하겠소….\"");
    case 3: return TEXT("조각 3 마니가 루이스에게: \"루이스, 미안해요. 빨리 말하려 했지만……\"");
    default: return TEXT("");
    }
}

FString UUW_NoteWidget::GetFullText(int32 NoteID)
{
    switch (NoteID)
    {
    case 1: return TEXT("루이스가 마니에게\n\n마니, 당신을 위한 선물을 준비했소. 이걸 광산 깊은 곳에 숨기느라 고생했지만 당신이 기뻐한다면 더할나위 없을거요. 여태 시장이던 나 때문에 마니 당신과 자주 만나지 못하고 숨어서 봐야 하는 것에 큰 죄책감을 느꼈지… 이제는 당신이 그런 수고를 하지 않도록 하겠소. 나의 진심을 알아주게.");
    case 2: return TEXT("루이스가 마니에게\n\n마니 당신이라면 궁금한 걸 못 참을테니 미리 말하겠소. 나는 시장을 그만두려 하오. 일도 많고 탈도 많은 탓에 나도 요즘 회의감을 느끼기 시작했어. 알아보니 주점 사장 거스가 시장 일에 관심을 가졌다는군. 거스에게 시장을 물려주고 나는 은퇴하기로 했네. 마니 당신과 더 행복하려 해. 축제 전날, 광산 맨 아래층으로 와주겠나?");
    case 3: return TEXT("마니가 루이스에게\n\n루이스, 미안해요. 빨리 말하려 했지만 그런 날은 오지 않았어. 나 사실 하비와 만나요. 당신이 시장을 은퇴한다는 쪽지를 보고 더 확실해졌어요. 나는 예전에 말했듯 직업이 확실한 사람이 좋아요. 하비는 의사이고 친절해요. 다툼이 잦은 당신과는 다르죠. 하비에게 애꿎은 시비는 걸지 말아요. 옛 정을 생각해서 축제 전날 광산으로 갈게요.");
    default: return TEXT("");
    }
}

void UUW_NoteWidget::InitNote(int32 NoteID)
{
    CurrentNoteID = NoteID;
    bShowingFull = false;
    ShowPreview();
    
    SetKeyboardFocus(); // 입력 모드 전환 후에 키보드 포커스 지정
}

void UUW_NoteWidget::ShowPreview()
{
    if (PreviewText)
    {
        PreviewText->SetText(FText::FromString(GetPreviewText(CurrentNoteID)));
        PreviewText->SetVisibility(ESlateVisibility::Visible);
    }
    if (FullText)
        FullText->SetVisibility(ESlateVisibility::Collapsed);
    if (HintText)
    {
        HintText->SetText(FText::FromString(TEXT("[ 클릭 또는 Enter — 전체 내용 보기 ]")));
        HintText->SetVisibility(ESlateVisibility::Visible);
    }
    if (BackgroundBorder)
        BackgroundBorder->SetVisibility(ESlateVisibility::Visible);
}

void UUW_NoteWidget::ShowFull()
{
    if (PreviewText)
        PreviewText->SetVisibility(ESlateVisibility::Collapsed);
    if (FullText)
    {
        FullText->SetText(FText::FromString(GetFullText(CurrentNoteID)));
        FullText->SetVisibility(ESlateVisibility::Visible);
    }
    if (HintText)
    {
        HintText->SetText(FText::FromString(TEXT("[ 클릭 또는 Enter — 닫기 ]")));
        HintText->SetVisibility(ESlateVisibility::Visible);
    }
}

void UUW_NoteWidget::CloseNote()
{
    RemoveFromParent();
}

void UUW_NoteWidget::AdvanceNote()
{
    if (!bShowingFull)
    {
        bShowingFull = true;
        ShowFull();
    }
    else
    {
        CloseNote();
    }
}

FReply UUW_NoteWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
    AdvanceNote();
    return FReply::Handled();
}

FReply UUW_NoteWidget::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
    if (InKeyEvent.GetKey() == EKeys::Enter || InKeyEvent.GetKey() == EKeys::SpaceBar)
    {
        AdvanceNote();
        return FReply::Handled();
    }
    return Super::NativeOnKeyDown(InGeometry, InKeyEvent);
}