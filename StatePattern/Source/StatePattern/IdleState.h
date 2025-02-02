#pragma once

#include "CoreMinimal.h"
#include "CharacterState.h"
#include "IdleState.generated.h"

class AStatePatternCharacter;
UCLASS()
class STATEPATTERN_API UIdleState : public UCharacterState
{
	GENERATED_BODY()

public:
    UIdleState();

    void Enter() override;
    
    void Exit() override;

};
