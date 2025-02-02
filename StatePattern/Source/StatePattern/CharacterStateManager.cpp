#include "CharacterStateManager.h"
#include "CharacterState.h"
#include "StatePatternCharacter.h"

ACharacterStateManager::ACharacterStateManager()
{
    CurrentState = nullptr;
    Character = nullptr;

    WalkSpeedThreshold = 300.0f;
    bIsAttackStateDelayed = false;
}

void ACharacterStateManager::InitializeStates(AStatePatternCharacter* InCharacter)
{
    Character = InCharacter;
    IdleState = NewObject<UIdleState>(this);
    IdleState->InitializeState(Character);
    IdleState->InitializeAsset(Character->IdleAnimation, nullptr);
    WalkState = NewObject<UWalkState>(this);
    WalkState->InitializeState(Character);
    WalkState->InitializeAsset(Character->WalkAnimation, Character->WalkSound);
    RunState = NewObject<URunState>(this);
    RunState->InitializeState(Character);
    RunState->InitializeAsset(Character->RunAnimation, Character->RunSound);
    CrawlState = NewObject<UCrawlState>(this);
    CrawlState->InitializeState(Character);
    CrawlState->InitializeAsset(Character->CrawlAnimation, Character->WalkSound);
    AttackState = NewObject<UAttackState>(this);
    AttackState->InitializeState(Character);
    AttackState->InitializeAsset(Character->AttackAnimation, Character->AttackSound);

    SetState(IdleState);
}

void ACharacterStateManager::BeginPlay()
{
    Super::BeginPlay();

}

void ACharacterStateManager::SetState(UCharacterState* NewState)
{
    if (!CurrentState) // state not set
    {
        CurrentState = NewState;
        if (CurrentState)
        {
            CurrentState->Enter();
        }
    }
    else
    {
        if (CurrentState != NewState)
        {
            CurrentState->Exit();
            CurrentState = NewState;
            if (CurrentState)
            {
                CurrentState->Enter();
            }
        }
    }
}

void ACharacterStateManager::UpdateState(float DeltaTime)
{
    if (!Character) return;
    if (CurrentState == CrawlState) return;

    FVector Velocity = Character->GetVelocity();
    float Speed = Velocity.Size();
   
    if (Speed > 0.0)
    {
        if (CurrentState == IdleState)
        {
            if (Speed > 0.0f)
            {
                if (Speed > WalkSpeedThreshold) SetState(RunState); // idle => run
                else SetState(WalkState);// idle => walk
            }
        }
        else if (CurrentState == WalkState)
        {
            if (Speed > WalkSpeedThreshold) SetState(RunState); // walk => run
        }
        else if (CurrentState == RunState)
        {
            if (Speed < WalkSpeedThreshold) SetState(WalkState); // run => walk
        }
    }
    else
    {
        if (CurrentState == WalkState || CurrentState == RunState) // walk / run => idle
        {
            SetState(IdleState);
        }
    }
    if (CurrentState == AttackState && bIsAttackStateDelayed == false)
    {
        bIsAttackStateDelayed = true;
        float AnimationDuration = AttackState->GetAnimation()->GetPlayLength();
        GetWorld()->GetTimerManager().SetTimer(AttackStateTimerHandle, this, &ACharacterStateManager::StopAttack, AnimationDuration, false);
    }
}

void ACharacterStateManager::Attack()
{
    if (CurrentState != CrawlState)
    {
        SetState(AttackState);
    }
}

void ACharacterStateManager::StopAttack()
{
    SetState(IdleState);
    bIsAttackStateDelayed = false;
}

void ACharacterStateManager::Crawl()
{
    if (CurrentState != AttackState && CurrentState != CrawlState)
    {
        SetState(CrawlState);
        return;
    }
    if (CurrentState == CrawlState)
    {
        SetState(IdleState);
        return;
    }
}
