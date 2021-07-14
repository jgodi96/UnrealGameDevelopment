// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnBase.h"
#include "Components/CapsuleComponent.h"

// Sets default values
APawnBase::APawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(RootComponent);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);





}

void APawnBase::RotateTurretFunction(FVector LookAtTarget) 
{
	//Update Turret Mesh rotation to face towards the lookattarget passed in from child classes..
	//TurretMes->SetWorldRotation()...
}

void APawnBase::Fire() 
{
	//GetProjectileSpawnPioint Location && Rotation -> Spawn Projectile class at location firing towards Rotation.
}

void APawnBase::HandleDestruction() 
{
	//PlayDeath effects

	//do child overrides.
	//PawnTuirret
	//PawnnTank
}



