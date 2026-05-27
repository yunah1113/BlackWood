// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "W_CollectionHUD.generated.h"

UCLASS()
class BLACKWOOD_API UW_CollectionHUD : public UUserWidget
{
	GENERATED_BODY()

protected:
	// 초기화 함수 (여기서 코드로 UI 글자 상자들을 생성할 겁니다)
	virtual bool Initialize() override;

	// 실시간 새로고침 틱 함수
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

private:
	// 에디터에서 BindWidget 안 하고, 순수 코드로만 관리할 텍스트 상자 2개
	UPROPERTY()
	UTextBlock* CodelessRockText;

	UPROPERTY()
	UTextBlock* CodelessNoteText;
};