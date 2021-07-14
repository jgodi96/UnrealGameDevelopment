// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "PawnTurret.h"
#include "PawnTank.h"

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

    GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle,this,&APawnTurret::CheckFireCondition,FireRate,true);

    PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this,0));
    
    TEST();
	
}


// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    

}
void APawnTurret::CheckFireCondition() 
{
    // If Player == null || is Dead THEN BAIL!|
    if(!PlayerPawn){
        return;
    }


    //IF Player is in range then fire!
    if(ReturnDistanceToPlayer() <= FireRange){
        //fire
        UE_LOG(LogTemp,Warning,TEXT("Fired condition success"))
    }

   
}

float APawnTurret::ReturnDistanceToPlayer() 
{
    if(!PlayerPawn){
        0.0f;
    }

    float Distance = FVector::Dist(PlayerPawn->GetActorLocation(),GetActorLocation());
    return Distance;



}
