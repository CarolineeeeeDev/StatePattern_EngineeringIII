#include "IdleState.h"
#include "Kismet/GameplayStatics.h"

UIdleState::UIdleState()
{
    InitializeState(nullptr);
}

void UIdleState::Enter()
{
    UE_LOG(LogTemp, Log, TEXT("Entering Idle State"));

    if (GetCharacter())
    {
        GetCharacter()->GetMesh()->PlayAnimation(GetAnimation(), true);
    }
}

void UIdleState::Exit()
{
    UE_LOG(LogTemp, Log, TEXT("Exiting Idle State"));
}