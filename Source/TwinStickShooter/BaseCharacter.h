// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS(Blueprintable)
class TWINSTICKSHOOTER_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

// Health property
// isDead property
// Calculate death function
// Calculate health function
// Editor-centric code for changing properties

public:
	ABaseCharacter();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Base Character")
	float Health = 100;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Base Character")
	bool IsDead = false;

	UFUNCTION(BlueprintCallable, Category="Base Character")
	virtual float CalculateHealth(float Delta);

	virtual void CalculateDead();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

protected:
	virtual void BeginPlay() override;

};