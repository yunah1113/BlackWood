// Fill out your copyright notice in the Description page of Project Settings.


#include "DiaryWidget.h"
#include "Components/TextBlock.h" // 텍스트 블록 기능을 쓰기 위해 필요
#include "TimerManager.h"         // 타이머 기능을 쓰기 위해 필요

void UDiaryWidget::StartStory(const FString& RawText) // PlayerName 파라미터 삭제
{
	FinalText = RawText; // 치환 없이 그대로 저장
	CharIndex = 0;
    
	if (Txt_StoryContent)
	{
		Txt_StoryContent->SetText(FText::GetEmpty());
	}

	GetWorld()->GetTimerManager().SetTimer(TypingTimerHandle, this, &UDiaryWidget::TypeNextChar, 0.05f, true);
}

void UDiaryWidget::TypeNextChar()
{
	if (CharIndex <= FinalText.Len())
	{
		// 앞에서부터 CharIndex만큼 글자를 잘라서 텍스트 블록에 표시
		FString CurrentString = FinalText.Left(CharIndex);
		Txt_StoryContent->SetText(FText::FromString(CurrentString));
        
		CharIndex++;
	}
	else
	{
		// 글자를 다 썼다면 타이머 종료
		GetWorld()->GetTimerManager().ClearTimer(TypingTimerHandle);
	}
}

