#pragma once

#include "CoreMinimal.h"
#include "CharacterState.h"
#include "AttackState.generated.h"


UCLASS()
class STATEPATTERN_API UAttackState : public UCharacterState
{
	GENERATED_BODY()

public:
    UAttackState();

    void Enter() override;

    void Exit() override;

private:
    UAudioComponent* Sound2D;
};
