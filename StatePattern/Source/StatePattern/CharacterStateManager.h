// CharacterStateManager.h
#pragma once

#include "CoreMinimal.h"

#include "IdleState.h"
#include "WalkState.h"
#include "RunState.h"
#include "CrawlState.h"
#include "AttackState.h"

#include "CharacterStateManager.generated.h"

class AStatePatternCharacter;

UCLASS()
class STATEPATTERN_API ACharacterStateManager : public AActor
{
    GENERATED_BODY()

public:
    ACharacterStateManager();

    UCharacterState* GetCurrentState() const { return CurrentState; }

    void SetState(UCharacterState* NewState);

    void InitializeStates(AStatePatternCharacter* InCharacter);

    void UpdateState(float DeltaTime);
    void Attack();
    void StopAttack();
    void Crawl();

    UAttackState* GetAttackState() { return AttackState; }

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY()
    UCharacterState* CurrentState;
    UPROPERTY()
    UIdleState* IdleState;
    UPROPERTY()
    UWalkState* WalkState;
    UPROPERTY()
    URunState* RunState;
    UPROPERTY()
    UCrawlState* CrawlState;
    UPROPERTY()
    UAttackState* AttackState;
    UPROPERTY()
    AStatePatternCharacter* Character;

    float WalkSpeedThreshold;

    FTimerHandle AttackStateTimerHandle;
    bool bIsAttackStateDelayed;
};
