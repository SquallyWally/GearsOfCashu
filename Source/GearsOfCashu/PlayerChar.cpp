// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerChar.h"

// Sets default values
APlayerChar::APlayerChar()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerChar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayerChar::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APlayerChar::LookUp);	
	PlayerInputComponent->BindAxis(TEXT("MoveLR"), this, &APlayerChar::MoveLR);
	PlayerInputComponent->BindAxis(TEXT("LookLR"), this, &APlayerChar::LookLR);
	PlayerInputComponent->BindAxis(TEXT("LookUpRate"), this, &APlayerChar::LookUpRate);
	PlayerInputComponent->BindAxis(TEXT("LookLRrate"), this, &APlayerChar::LookLRrate);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed,this , &ACharacter::Jump);

}

void APlayerChar::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);

}
void APlayerChar::MoveLR(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);

}
void APlayerChar::LookLR(float AxisValue)
{
	AddControllerYawInput(AxisValue);

}

void APlayerChar::LookUp(float AxisValue)
{
	AddControllerPitchInput(AxisValue);

}

//To make the movement not FPS bound
void APlayerChar::LookUpRate(float AxisValue)
{
	AddControllerPitchInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());

}

void APlayerChar::LookLRrate(float AxisValue)
{
	AddControllerYawInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());

}