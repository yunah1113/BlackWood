// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BlackWoodCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

/**
 * A controllable top-down perspective character
 */
UCLASS(abstract)
class ABlackWoodCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> CameraBoom;

public:
	/** --- 추가된 플레이어 상태 정보 --- **/
    
	// 플레이어의 이름을 저장합니다. 기본값은 "주인공"입니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerStatus")
	FString PlayerName = TEXT("주인공");

	// 플레이어의 체력을 저장합니다. (세미콜론 추가 완료)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerStatus")
	float PlayerHP = 100.0f; 

	/** --- 기존 함수들 --- **/

	/** Constructor */
	ABlackWoodCharacter();

	/** Initialization */
	virtual void BeginPlay() override;

	/** Update */
	virtual void Tick(float DeltaSeconds) override;

	/** Returns the camera component **/
	UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent.Get(); }

	/** Returns the Camera Boom component **/
	USpringArmComponent* GetCameraBoom() const { return CameraBoom.Get(); }
};
