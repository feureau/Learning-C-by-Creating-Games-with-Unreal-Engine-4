// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelEnd_Actor.generated.h"

UCLASS()
class CPP_GAMETUT_API ALevelEnd_Actor : public AActor
{
	GENERATED_BODY()

		UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "Components", meta = (AllowprivateAccess = "true"))
		class UBillboardComponent* Root;

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		class UBoxComponent* CollisionBox;

public:
	// Sets default values for this actor's properties
	ALevelEnd_Actor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelEnd")
		FName LevelToGoTo;

private:
	UFUNCTION()
		void OnBoxOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
};
