// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bUseControllerRotationPitch = true;
	bUseControllerRotationYaw = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(Mesh);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	PawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("PawnMove"));
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMyPawn::MoveForwardBack(float Axis)
{
	AddMovementInput(GetActorForwardVector(), Axis, false);
}

void AMyPawn::MoveRightLeft(float Axis)
{
	AddMovementInput(GetActorRightVector(), Axis, false);
}

void AMyPawn::LookUpDown(float Axis)
{
	AddControllerPitchInput(Axis);
}

void AMyPawn::LookRightLeft(float Axis)
{
	AddControllerYawInput(Axis);
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    PlayerInputComponent->BindAxis("MoveForward", this, &AMyPawn::MoveForwardBack);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyPawn::MoveRightLeft);
	PlayerInputComponent->BindAxis("LookUpDown", this, &AMyPawn::LookUpDown);
	PlayerInputComponent->BindAxis("LookRightLeft", this, &AMyPawn::LookRightLeft);
}
