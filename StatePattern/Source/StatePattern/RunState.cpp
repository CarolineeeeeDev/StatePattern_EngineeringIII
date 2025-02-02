#include "RunState.h"
#include "Kismet/GameplayStatics.h"

URunState::URunState()
{
	InitializeState(nullptr);
}

void URunState::Enter()
{
    UE_LOG(LogTemp, Log, TEXT("Entering Run State"));

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

void URunState::Exit()
{
    UE_LOG(LogTemp, Log, TEXT("Exiting Run State"));
    if (Sound2D)
    {
        Sound2D->Stop();
    }
}