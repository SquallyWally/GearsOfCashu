// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerChar.generated.h"

UCLASS()
class GEARSOFCASHU_API APlayerChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerChar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
private:
	void MoveForward(float AxisValue);
	void LookUp(float AxisValue);
	void MoveLR(float AxisValue);
	void LookLR(float AxisValue);
	void LookUpRate(float AxisValue);
	void LookLRrate(float AxisValue);
	
	UPROPERTY(EditAnywhere)
	float RotationRate = 10;


};
