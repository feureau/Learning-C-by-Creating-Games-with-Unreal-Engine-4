#pragma once

#include "CoreMinimal.h"
#include "Characters/Base_Character.h"
#include "GamePlayElements/InteractionInterface.h"
#include "Player_Character.generated.h"

/**
 *
 */
UCLASS()
class CPP_GAMETUT_API APlayer_Character : public ABase_Character, public IInteractionInterface
{
	GENERATED_BODY()

		UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* SpringArm;
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* Camera;
	/**This would be for our arms mesh**/
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		class USkeletalMeshComponent* FP_Mesh;
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		class USkeletalMeshComponent* GunMesh;

public:
	//Constructor
	APlayer_Character();

	UFUNCTION(BlueprintCallable, Category = "Character|Input") void PauseGame();

	UFUNCTION(BlueprintCallable, Category = "Character|Input") void UnPauseGame();

	UFUNCTION(BlueprintPure, Category = "Character|Gun|Ammo")
		int32 GetCurrentAmmo() const
	{
		return CurrentAmmo;
	}

	UFUNCTION(BlueprintPure, Category = "Character|Gun|Ammo")
		int32 GetMaxAmmo() const
	{
		return MaxAmmo;
	}

	UFUNCTION(BlueprintCallable, Category = "Character|Gun|Ammo")
		void SetCurrentAmmo(int NewAmmo)
	{
		CurrentAmmo = NewAmmo;
	}

	/** Base turn rate, in deg/sec. Other scaling may affect final turnrate.**/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Camera")
		float BaseTurnRate;

	//** Base Look up/down rate, in deg/sec. Other scaling may affect final rate.**/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Camera")
		float BaseLookUpRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Movement")
		float SprintSpeed;

protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	virtual void PossessedBy(AController* NewController) override;

	virtual void OnDeath_Implementation() override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	virtual void OnInteract_Implementation(AActor* Interactor)
		PURE_VIRTUAL(IInteractionInterface::OnInteract_Implementation, );

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Character|Input|Gun")
		void OnFire();
	virtual void OnFire_Implementation();

	//** Check if we have remaining ammo **/
	bool HasAmmo() const
	{
		return (CurrentAmmo > 0);
	}

	UFUNCTION(BluePrintNativeEvent, BlueprintCallable, Category = "Character|Input|Movement")
		void OnSprintStart();
	void OnSprintStart_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Character|Input|Movement")
		void OnSprintEnd();
	void OnSprintEnd_Implementation();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Character|Gun")
		class UParticleSystem* TrailEffect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Character|Gun")
		class UParticleSystem* HitEffect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Character|Gun")
		class UAnimMontage* FireAnimation;

	// The amount of damage that the gun shoots and applies to an actor.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Gun")
		float DamageAmount;

	//** Flag for when the player can shoot. **/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Gun")
		bool bCanShoot;

	UFUNCTION(BlueprintCallable, Category = "Character|Input|Movement")
		void MoveForward(float Scalar);

	UFUNCTION(BlueprintCallable, Category = "Character|Input|Movement")
		void MoveRight(float Scalar);

	UFUNCTION(BlueprintCallable, Category = "Character|Input|Camera")
		void LookUpAtRate(float Rate);

	UFUNCTION(BlueprintCallable, Category = "Character|Input|Camera")
		void TurnAtRate(float Rate);

	//** Flag for when the player can shoot unlimited amount of bullets **/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Gun|Ammo")
		bool bUnlimitedAmmo;

	int CurrentAmmo;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Character|Gun|Ammo")
		int MaxAmmo;

	/** Minimum view pitch, in degrees.**/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Camera")
		float CameraPitchMin;

	/**Maximum view pitch, in degrees.**/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Camera")
		float CameraPitchMax;

	// the range or distance needed for our interaction to actually register
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character")
		float InteractionDistance;

private:
	float PreviousWalkSpeed;

	void SpawnShootingParticles(FVector ParticleLocation);

	UFUNCTION()
		void Interact();

	UPROPERTY()	class AGenericHUD* HudReference;
};
