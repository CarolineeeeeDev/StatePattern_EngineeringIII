#pragma once

#include "CoreMinimal.h"
#include "CharacterState.h"
#include "CrawlState.generated.h"


UCLASS()
class STATEPATTERN_API UCrawlState : public UCharacterState
{
	GENERATED_BODY()

public:
    UCrawlState();

    void Enter() override;

    void Exit() override;

private:
    UAudioComponent* Sound2D;
};
