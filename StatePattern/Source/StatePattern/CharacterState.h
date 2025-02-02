#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "StatePatternCharacter.h"
#include "CharacterState.generated.h"

UCLASS(Blueprintable)
class STATEPATTERN_API UCharacterState : public UObject
{
	GENERATED_BODY()

public:
	virtual void Enter() {}

	virtual void Exit() {}

	virtual void Update(float DeltaTime) {}

	UAnimMontage* GetAnimation() { return Animation; }
	USoundBase* GetSound() { return Sound;  }
	void InitializeAsset(UAnimMontage* NewAnimation, USoundBase* NewSound) { Animation = NewAnimation; Sound = NewSound; }

	AStatePatternCharacter* GetCharacter() { return Character;  }
	void InitializeState(AStatePatternCharacter* NewCharacter) { Character = NewCharacter; }

private:
	UPROPERTY()
	UAnimMontage* Animation;
	UPROPERTY()
	USoundBase* Sound;
	UPROPERTY()
	AStatePatternCharacter* Character;
};
