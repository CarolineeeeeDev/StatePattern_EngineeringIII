// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterState.h"
#include "WalkState.generated.h"

class UAudioComponent;

UCLASS()
class STATEPATTERN_API UWalkState : public UCharacterState
{
	GENERATED_BODY()

public:
    UWalkState();

    void Enter() override;

    void Exit() override;

private:
    UAudioComponent* Sound2D;
};
