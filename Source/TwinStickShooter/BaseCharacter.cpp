#include "BaseCharacter.h"

ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ABaseCharacter::CalculateHealth(float Delta) 
{
	Health -= Delta;
	CalculateDead();
}

void ABaseCharacter::CalculateDead() 
{
	IsDead = Health <= 0;
}

#if WITH_EDITOR
void ABaseCharacter::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) 
{
	IsDead = false;
	Health = 100;
	Super::PostEditChangeProperty(PropertyChangedEvent);
	CalculateDead();
}
#endif