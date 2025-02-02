#include "WalkState.h"
#include "Kismet/GameplayStatics.h"

UWalkState::UWalkState()
{
	InitializeState(nullptr);
}

void UWalkState::Enter()
{
    UE_LOG(LogTemp, Log, TEXT("Entering Walk State"));

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

void UWalkState::Exit()
{
    UE_LOG(LogTemp, Log, TEXT("Exiting Walk State"));
    if (Sound2D)
    {
        Sound2D->Stop();
    }
}