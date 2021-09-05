// Fill out your copyright notice in the Description page of Project Settings.

#include "Dragon.h"
#include "BossAIController.h"
#include "WireHunterCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "Obstacle.h"
#include "Runtime/Engine/Public/EngineUtils.h"
#include "PaperSpriteComponent.h"
#include "Fireball.h"
#include "GameFramework/Actor.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraComponent.h"
#include "Kismet/KismetSystemLibrary.h"

#include "Net/UnrealNetwork.h"
#include "Engine/Engine.h"

#include "DrawDebugHelpers.h"

// Sets default values
ADragon::ADragon()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//need line to set default ai controller.
	AIControllerClass = ABossAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	bReplicates = true;

	NotPrecious = false;
	FirstBreathTrigger = false;
	SecondBreathTrigger = false;
	MeteorTrigger = false;

	ProjectileClass = AFireball::StaticClass();

	static ConstructorHelpers::FObjectFinder<UNiagaraSystem> BreathParticleAsset(TEXT("NiagaraSystem'/Game/ThirdPersonCPP/AI/WeaponPack/MuzzleFlashPack/Particles/NS_FlameThrower.NS_FlameThrower'"));
	UNiagaraSystem* NS_BreathParticleAsset = BreathParticleAsset.Object;
	BreathParticle = NS_BreathParticleAsset;

	static ConstructorHelpers::FObjectFinder<UNiagaraSystem> BloodParticleAsset(TEXT("NiagaraSystem'/Game/ThirdPersonCPP/AI/GunImpactParticles/Particles/Blood/NS_Blood_2.NS_Blood_2'"));
	UNiagaraSystem* NS_BloodParticleAsset = BloodParticleAsset.Object;
	BloodParticle = NS_BloodParticleAsset;
}

void ADragon::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ADragon, Health);

	DOREPLIFETIME(ADragon, FirstBreathTrigger);
	DOREPLIFETIME(ADragon, SecondBreathTrigger);
	DOREPLIFETIME(ADragon, MeteorTrigger);
}

void ADragon::MakeMap()
{
	UWorld* world = GetWorld();

	TArray<FVector> buffer;

	for (const auto& e : TActorRange<AObstacle>(world)) {
		auto loc = e->GetActorLocation();
		buffer.Push(loc);
	}

	Obstacles = buffer;

	buffer.Sort([](const FVector& A, const FVector& B) {
		return A.Y > B.Y;
		});

	TArray<TArray<FVector>> MapSortArr;
	TArray<FVector> mapSortArr;

	int idx = 0;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 5; ++j) {
			mapSortArr.Push(buffer[idx++]);
		}
		MapSortArr.Push(mapSortArr);
		mapSortArr.Empty();
	}

	for (int i = 0; i < 10; ++i) {
		MapSortArr[i].Sort([](const FVector& A, const FVector& B) {
			return A.X > B.X;
			});
	}

	float diff_x = abs(MapSortArr[0][0].X - MapSortArr[0][1].X) / 2;
	float diff_y = abs(MapSortArr[0][0].Y - MapSortArr[1][0].Y);

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			Map[i][j] = '*';
			if (i % 2 == 0 && j % 2 == 1) {//space
				RealMap[i][j] = RealMap[i][j - 1] - FVector(diff_x, 0.f, 0.f);
			}
			else if (i % 2 == 1 && j % 2 == 0) {
				RealMap[i][j] = RealMap[i - 1][j] - FVector(0.f, diff_y, 0.f);
			}
			////////////////////////////////////////////////////////////////////
			else {//wall
				Map[i][j] = '$';
				RealMap[i][j] = MapSortArr[i][j / 2];
			}
		}
	}
}

FVector ADragon::FindPlayer()
{
	Players.Empty();
	
	for (const auto& e : TActorRange<AWireHunterCharacter>(GetWorld())) {
		Players.Push(e->GetActorLocation());
	}

	TargetLocation = Players[0];//일단 서버

	//TargetLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	//TargetLocation = Players.Last();
	
	return TargetLocation;
}

void ADragon::FacePlayer()
{
	TargetRotation = UKismetMathLibrary::FindLookAtRotation(this->GetActorLocation(), TargetLocation);
}

float ADragon::FindDistance(FVector a, FVector b)
{
	float x = a.X - b.X;
	float y = a.Y - b.Y;
	x = x * x;
	y = y * y;
	float c = x + y;
	float ret = sqrt(c);

	return ret;
}

TArray<FStructNode> ADragon::Regulate()
{
	float min_g = 40000.f;
	int x_g = 10;
	int y_g = 10;

	float min_s = 40000.f;
	int x_s = 10;
	int y_s = 10;

	auto myLoc = this->GetActorLocation();

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {

			if ((i % 2 == 0 && j % 2 == 1) || i % 2 == 1 && j % 2 == 0) {//space

				auto d = FindDistance(RealMap[i][j], TargetLocation);

				if (d < min_g) {
					min_g = d;
					x_g = i;
					y_g = j;
				}

				d = FindDistance(RealMap[i][j], myLoc);

				if (d < min_s) {
					min_s = d;
					x_s = i;
					y_s = j;
				}

			}

			else {
				continue;
			}

		}
	}

	TArray<FStructNode> tmpArr;

	FStructNode tmpNode;

	tmpNode.first = y_s;
	tmpNode.second = x_s;

	tmpArr.Push(tmpNode);

	tmpNode.first = y_g;
	tmpNode.second = x_g;

	tmpArr.Push(tmpNode);

	return tmpArr;
}

void ADragon::h(FStructNode next, FStructNode end)
{
	int x = abs(end.first - next.first);
	int y = abs(end.second - next.second);
	ScoreH[next.second][next.first] = (x + y) * 10;
}

void ADragon::g(FStructNode next, int plus)
{
	ScoreG[next.second][next.first] = plus;
}

void ADragon::f(FStructNode next)
{
	ScoreF[next.second][next.first] = ScoreG[next.second][next.first] + ScoreH[next.second][next.first];
}

FStructNode ADragon::FindTop()//가중치가 가장 작은 노드 반환
{
	auto min = Min[0].weight;
	int idx = 0;
	for (int i = 1; i < Min.Num(); ++i) {
		if (Min[i].weight < min) {
			min = Min[i].weight;
			idx = i;
		}
	}

	return Min[idx].node;
}

int ADragon::FindElement(float x, float y)
{
	for (int i = 0; i < Closed.Num(); ++i) {
		if (Closed[i].first == x && Closed[i].second == y) {
			return i;
		}
	}
	return -1;
}

void ADragon::AStar(char map[10][10], FStructNode start, FStructNode goal)
{
	Min.Empty();
	Path.Empty();
	Closed.Empty();

	memset(ScoreF, 9999, sizeof(ScoreF));
	memset(ScoreG, 9999, sizeof(ScoreG));
	memset(ScoreH, 9999, sizeof(ScoreH));

	Path.Push(start);

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (map[i][j] == '$') {
				FStructNode obstacle;
				obstacle.first = j;
				obstacle.second = i;
				Closed.Push(obstacle);
			}
		}
	}

	FStructNode now = start;
	while (Path.Last().first != goal.first || Path.Last().second != goal.second) {
		int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
		int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

		for (int i = 0; i < 8; ++i) {
			int x = now.first + dx[i];
			int	y = now.second + dy[i];
			if (x < 0 || y < 0 || x > 9 || y > 9) {
				continue;
			}

			int idx = FindElement(x, y);//in Closed
			if (idx != -1) {
				continue;
			}

			FStructNode tmp;
			tmp.first = x;
			tmp.second = y;
			h(tmp, goal);
			if (dx[i] == 0 || dy[i] == 0) {
				g(tmp, 10);
			}
			else {
				g(tmp, 14);
			}

			f(tmp);

			FStructWeight pushed;
			pushed.weight = ScoreF[y][x];
			pushed.node = tmp;
			Min.Push(pushed);
		}
		now = FindTop();//at first, there is only start point in Min arr. 
		Closed.Push(now);
		Path.Push(now);

		Min.Empty(); // or new creation
	}

	for (int i = 0; i < Path.Num(); ++i) {
		UE_LOG(LogTemp, Warning, TEXT("%d >> x: %d / y: %d"), i + 1, Path[i].first, Path[i].second);
	}
	UE_LOG(LogTemp, Warning, TEXT("////////////////////////////////////////////////////////////"));

	if (Path.Num() == 1)
	{
		NotPrecious = true;
	}
	else 
	{
		NotPrecious = false;
		Path.RemoveAt(0);
	}
}

// Called when the game starts or when spawned
void ADragon::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;

	GetCharacterMovement()->SetMovementMode(MOVE_Flying);

	MakeMap();

	//FindPlayer();
}

TArray<FStructNode> ADragon::DoAStar()
{
	auto ret = Regulate();
	
	AStar(Map, ret[0], ret[1]);

	return Path;
}

FVector ADragon::GetGoal()
{
	FVector goal;
	goal = RealMap[Path[Path.Num() - 1].second][Path[Path.Num() - 1].first];
	goal.Z = TargetLocation.Z + 500.f;

	if (!NotPrecious)
	{
		return goal;
	}
	else
	{
		return GetActorLocation(); 
	}
}

FVector ADragon::GetPath()////////////////////////////////////////////////////
{
	FVector path;

	path = RealMap[Path[0].second][Path[0].first];
	path.Z = TargetLocation.Z + 500.f;

	//auto myLoc = GetActorLocation();
	//auto tmp = FMath::Sqrt(FVector::DistSquared(myLoc, path));
	//
	//if (tmp < 6000.f)
	//{
	//	path = RealMap[Path[1].second][Path[1].first];
	//	path.Z = TargetLocation.Z + 500.f;

	//	//Path.RemoveAt(0);
	//}

	Path.RemoveAt(0);

	UE_LOG(LogTemp, Warning, TEXT("%s"), *path.ToString());

	if (!NotPrecious)
	{
		return path;
	}
	else
	{
		return GetActorLocation();
	}
}

// Called every frame+
void ADragon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ADragon::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ADragon::Spawn_Implementation()
{
	int randIdx = rand() % 40 + 1;
	FVector targetLocation = Obstacles[randIdx] + FVector(0.f, 0.f, 15000.f);
	FVector spawnLocation = targetLocation + FVector(8000.f, 8000.f, 16000.f);

	FRotator spawnRotation = UKismetMathLibrary::FindLookAtRotation(spawnLocation, targetLocation);

	FActorSpawnParameters spawnParameters;
	spawnParameters.Instigator = GetInstigator();
	spawnParameters.Owner = this;

	AFireball* spwanedProjectile = GetWorld()->SpawnActor<AFireball>(spawnLocation, spawnRotation, spawnParameters);

	//FVector outVelocity = FVector::ZeroVector;   // 결과 Velocity
	//if (UGameplayStatics::SuggestProjectileVelocity_CustomArc(this, outVelocity, spawnLocation, TargetLocation, GetWorld()->GetGravityZ(), 0.5f))
	//{
	//	FPredictProjectilePathParams predictParams(20.0f, spawnLocation, outVelocity, 15.0f);   // 20: tracing 보여질 프로젝타일 크기, 15: 시물레이션되는 Max 시간(초)
	//	predictParams.DrawDebugTime = 0.f;     //디버그 라인 보여지는 시간 (초)
	//	predictParams.DrawDebugType = EDrawDebugTrace::Type::ForDuration;  // DrawDebugTime 을 지정하면 EDrawDebugTrace::Type::ForDuration 필요.
	//	predictParams.OverrideGravityZ = GetWorld()->GetGravityZ();
	//	FPredictProjectilePathResult result;
	//	UGameplayStatics::PredictProjectilePath(this, predictParams, result);
	//}
	//spwanedProjectile->ProjectileMovementComponent->AddForce(outVelocity); // objectToSend는 발사체
}

void ADragon::BreathMulti_Implementation()
{
	UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, BreathParticle, GetActorLocation() + GetActorForwardVector() * 2000 + FVector(0.f, 0.f, 250.f), GetActorRotation());
}

void ADragon::GenDeathParticleMulti_Implementation()
{
	UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, BloodParticle, GetActorLocation(), GetActorRotation(), FVector(100.f, 100.f, 100.f));
}

void ADragon::BreathTrace()
{
	TArray<FHitResult> hits;

	const float range = 3000.f;
	FVector startTrace = GetActorLocation() + GetActorForwardVector() * 2000 + FVector(0.f, 0.f, 200.f);
	FVector endTrace = (GetCapsuleComponent()->GetForwardVector() * range) + startTrace;

	FCollisionQueryParams queryParams = FCollisionQueryParams(SCENE_QUERY_STAT(BreathTrace), false, this);
	queryParams.AddIgnoredActor(this);
	TArray<AActor*> ActorsToIgnore;
	UKismetSystemLibrary::BoxTraceMulti(this, startTrace, endTrace, FVector(300.f, 300.f, 300.f), GetActorRotation(), TraceTypeQuery1, false, ActorsToIgnore, EDrawDebugTrace::ForOneFrame, hits, true);

	for (const auto& e : hits)
	{
		if (e.bBlockingHit)
		{
			if (e.Actor->IsA(AWireHunterCharacter::StaticClass()))
			{
				AWireHunterCharacter* TargetCharacter = Cast<AWireHunterCharacter>(e.Actor);
				TargetCharacter->SetHealth(TargetCharacter->GetHealth() - 5.f);
			}
		}
	}
}

bool ADragon::GetFirstBreathTrigger()
{
	return FirstBreathTrigger;
}

void ADragon::SetFirstBreathTrigger(bool b)
{
	FirstBreathTrigger = b;
}

bool ADragon::GetSecondBreathTrigger()
{
	return SecondBreathTrigger;
}

void ADragon::SetSecondBreathTrigger(bool b)
{
	SecondBreathTrigger = b;
}

bool ADragon::GetMeteorTrigger()
{
	return MeteorTrigger;
}

void ADragon::SetMeteorTrigger(bool b)
{
	MeteorTrigger = b;
}

void ADragon::SetHealth(float value)
{
	if (GetLocalRole() == ROLE_Authority)
	{
		Health = value;
		OnHealthUpdate();
	}
}

void ADragon::OnRep_Health()
{
	OnHealthUpdate();
}

void ADragon::OnHealthUpdate()
{
	//Client-specific functionality
	/*if (IsLocallyControlled())
	{
		FString healthMessage = FString::Printf(TEXT("You now have %f health remaining."), Health);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, healthMessage);

		if (Health <= 0)
		{
			Destroy();
		}
	}*/

	//Server-specific functionality
	if (Health <= 0)
	{
		if (HasAuthority())
		{
			Death();
		}
	}

	//Functions that occur on all machines. 
	/*
	   Any special functionality that should occur as a result of damage or death should be placed here.
	*/
}

void ADragon::Death()
{
	GenDeathParticleMulti();
	Destroy();
	FTimerHandle WaitHandle;
	float WaitTime = 4.f;
	GetWorld()->GetTimerManager().SetTimer(WaitHandle, FTimerDelegate::CreateLambda([&]()
		{
			UGameplayStatics::OpenLevel(this, "GameMenuLevel");
		}), WaitTime, false); //반복도 여기서 추가 변수를 선언해 설정가능
}