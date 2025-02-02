#pragma once

#include "CoreMinimal.h"
#include "CharacterState.h"
#include "RunState.generated.h"

class UAudioComponent;

UCLASS()
class STATEPATTERN_API URunState : public UCharacterState
{
	GENERATED_BODY()

public:
    URunState();

    void Enter() override;

    void Exit() override;

private:
    UAudioComponent* Sound2D;

};
