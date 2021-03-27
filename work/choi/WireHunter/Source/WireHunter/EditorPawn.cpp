// Fill out your copyright notice in the Description page of Project Settings.

#include "EditorPawn.h"

// Sets default values
AEditorPawn::AEditorPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UPoseableMeshComponent>(TEXT("MESH"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	RootComponent = Mesh;
	SpringArm->SetupAttachment(Mesh);
	Camera->SetupAttachment(SpringArm);

	Mesh->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -88.f), FRotator(0.f, -90.f, 0.f));
	SpringArm->TargetArmLength = 400.f;
	SpringArm->SetRelativeRotation(FRotator(-15.f, 0.f, 0.f));

	SetControlMode(0);
}

void AEditorPawn::SetControlMode(int32 ControlMode) {
	if (ControlMode == 0) {
		SpringArm->TargetArmLength = 450.f;
		SpringArm->SetRelativeRotation(FRotator::ZeroRotator);
		SpringArm->bUsePawnControlRotation = true;
		SpringArm->bInheritPitch = true;
		SpringArm->bInheritRoll = true;
		SpringArm->bInheritYaw = true;
		SpringArm->bDoCollisionTest = true;
		bUseControllerRotationYaw = false;
	}
}

// Called when the game starts or when spawned
void AEditorPawn::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AEditorPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Roll();
}

// Called to bind functionality to input
void AEditorPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AEditorPawn::LookUp);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AEditorPawn::Turn);

	PlayerInputComponent->BindAction(TEXT("Yaw"), IE_Pressed, this, &AEditorPawn::Yaw);
	PlayerInputComponent->BindAction(TEXT("Roll"), IE_Pressed, this, &AEditorPawn::Roll);
	PlayerInputComponent->BindAction(TEXT("Pitch"), IE_Pressed, this, &AEditorPawn::Pitch);
	PlayerInputComponent->BindAction(TEXT("DoBig"), IE_Pressed, this, &AEditorPawn::DoBig);
	PlayerInputComponent->BindAction(TEXT("DoSmall"), IE_Pressed, this, &AEditorPawn::DoSmall);
}

void AEditorPawn::LookUp(float newAxisValue) {
	AddControllerPitchInput(newAxisValue);
}

void AEditorPawn::Turn(float newAxisValue) {
	AddControllerYawInput(newAxisValue);
}

void AEditorPawn::Yaw() {//1
	auto Rot = Mesh->GetBoneRotationByName(FName("upperarm_l"), EBoneSpaces::ComponentSpace);
	auto NewRot = Rot.Add(0.f, 0.f, 1.f);
	Mesh->SetBoneRotationByName(FName("upperarm_l"), NewRot, EBoneSpaces::ComponentSpace);

	//UE_LOG(LogTemp, Warning, TEXT("YAW"));
}

void AEditorPawn::Roll() {//2
	auto Rot = Mesh->GetBoneRotationByName(FName("upperarm_l"), EBoneSpaces::ComponentSpace);
	auto NewRot = Rot.Add(0.05f, 0.f, 0.f);
	Mesh->SetBoneRotationByName(FName("upperarm_l"), NewRot, EBoneSpaces::ComponentSpace);

	UE_LOG(LogTemp, Warning, TEXT("**********%s*************"), *Rot.ToString());
}

void AEditorPawn::Pitch() {//3
	auto Rot = Mesh->GetBoneRotationByName(FName("upperarm_l"), EBoneSpaces::ComponentSpace);
	auto NewRot = Rot.Add(0.f, 1.f, 0.f);
	Mesh->SetBoneRotationByName(FName("upperarm_l"), NewRot, EBoneSpaces::ComponentSpace);

	//UE_LOG(LogTemp, Warning, TEXT("PITCH"));
}

void AEditorPawn::DoBig() {//4


}

void AEditorPawn::DoSmall() {//5

}