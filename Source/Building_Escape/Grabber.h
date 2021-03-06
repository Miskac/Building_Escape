// Copyright Marko Miskov 2021

#pragma once


#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDING_ESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	float Reach = 100.f;
	
	UPROPERTY()
	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UPROPERTY()
	UInputComponent* InputComponent = nullptr;
	
	void Grab();
	void Release();
	void FindPhysicsHandle();
	void SetUpInputComponent();
	// returns the first actor within reach
	FHitResult GetFirstPhysicsBodyInReach() const;
	// returns line trace end
	FVector GetPlayersReach() const;
	// gets players position in the world
	FVector GetPlayersWorldPos() const;
};
