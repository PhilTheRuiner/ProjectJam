// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

UCLASS()
class JAMPROJECT_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mesh")
	class UStaticMeshComponent* Mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera")
	class UCameraComponent* Camera;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera")
	class USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Move")
	class UFloatingPawnMovement* PawnMovement;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Move")
	float MoveSpeed = 250.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Move")
	float RotateSpeed = 100.f;
	
    void MoveForwardBack (float Axis);
	void MoveRightLeft (float Axis);
	void LookUpDown (float Axis);
	void LookRightLeft (float Axis);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
