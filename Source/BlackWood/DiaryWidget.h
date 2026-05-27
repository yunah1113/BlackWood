// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DiaryWidget.generated.h"

// 텍스트 출력을 위해 필요한 클래스 선언
class UTextBlock;

UCLASS()
class BLACKWOOD_API UDiaryWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	// [중요] 블루프린트에 있는 Txt_StoryContent라는 이름의 텍스트 블록과 자동으로 연결됩니다.
	UPROPERTY(meta = (BindWidget))
	UTextBlock* Txt_StoryContent;

	// 타이핑에 필요한 변수들
	FTimerHandle TypingTimerHandle; // 타이머 관리자
	FString FinalText;              // 이름이 합성된 최종 문장
	int32 CharIndex = 0;            // 현재 몇 번째 글자인지 저장

	// 한 글자씩 출력하는 핵심 함수
	void TypeNextChar();

public:
	// 블루프린트에서 호출할 시작 함수
	UFUNCTION(BlueprintCallable, Category = "Diary")
	void StartStory(const FString& RawText);
};
