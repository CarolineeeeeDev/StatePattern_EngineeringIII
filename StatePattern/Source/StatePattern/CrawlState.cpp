#include "CrawlState.h"
#include "Kismet/GameplayStatics.h"

UCrawlState::UCrawlState()
{
	InitializeState(nullptr);
}

void UCrawlState::Enter()
{
    UE_LOG(LogTemp, Log, TEXT("Entering Crawl State"));

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

void UCrawlState::Exit()
{
    UE_LOG(LogTemp, Log, TEXT("Exiting Crawl State"));
    if (Sound2D)
    {
        Sound2D->Stop();
    }
}