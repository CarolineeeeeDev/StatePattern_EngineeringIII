#include "AttackState.h"
#include "Kismet/GameplayStatics.h"

UAttackState::UAttackState()
{
	InitializeState(nullptr);
}

void UAttackState::Enter()
{
    UE_LOG(LogTemp, Log, TEXT("Entering Attack State"));

    if (GetCharacter())
    {
        GetCharacter()->GetMesh()->PlayAnimation(GetAnimation(), true);
        if (!Sound2D)
        {
            Sound2D = UGameplayStatics::SpawnSound2D(this, GetSound());
        }
        else
        {
            Sound2D->Play();
        }
    }
}

void UAttackState::Exit()
{
    UE_LOG(LogTemp, Log, TEXT("Exiting Attack State"));
    if (Sound2D)
    {
        Sound2D->Stop();
    }
}