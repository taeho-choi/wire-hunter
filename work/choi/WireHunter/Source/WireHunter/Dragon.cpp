// Fill out your copyright notice in the Description page of Project Settings.

#include "Dragon.h"
#include "BossAIController.h"
#include "WireHunterCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "Obstacle.h"
#include "Runtime/Engine/Public/EngineUtils.h"
#include "PaperSpriteComponent.h"

#include "Net/UnrealNetwork.h"

// Sets default values
ADragon::ADragon()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bReplicates = true;

	//need line to set default ai controller.
	AIControllerClass = ABossAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	ToFace = false;
}

void ADragon::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ADragon, Health);
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
	TargetLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();

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
}

// Called when the game starts or when spawned
void ADragon::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;

	/*MakeMap();

	FacePlayer();
	auto rot = FMath::RInterpTo(this->GetActorRotation(), TargetRotation, GetWorld()->GetDeltaSeconds(), 2.5f);
	this->SetActorRotation(rot);

	SetHealth(MaxHealth);*/

	GetCharacterMovement()->SetMovementMode(MOVE_Flying);
}

TArray<FStructNode> ADragon::DoAStar()
{
	FindPlayer();

	auto ret = Regulate();

	AStar(Map, ret[0], ret[1]);

	return Path;
}

FVector ADragon::GetGoal()
{
	FVector goal;
	goal = RealMap[Path[Path.Num() - 1].second][Path[Path.Num() - 1].first];
	goal.Z = TargetLocation.Z + 1000.f;

	return goal;
}

FVector ADragon::GetPath()////////////////////////////////////////////////////
{
	FVector path;
	path = RealMap[Path[0].second][Path[0].first];
	path.Z = TargetLocation.Z + 1000.f;

	Path.RemoveAt(0);

	UE_LOG(LogTemp, Warning, TEXT("%s"), *path.ToString());

	return path;
}

// Called every frame+
void ADragon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*if (ToFace) {
		FacePlayer();
		auto rot = FMath::RInterpTo(this->GetActorRotation(), TargetRotation, GetWorld()->GetDeltaSeconds(), 2.5f);
		this->SetActorRotation(rot);
	}

	if (Health < 0) {
		BossSkeletalMesh->SetSimulatePhysics(true);
		if (BossSkeletalMesh->GetComponentLocation().Z < -4000.f) {
			Destroy();
		}
	}*/

	auto tmp = GetActorLocation();

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, tmp.ToString());
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("----------------------------------------------------------"));
}

// Called to bind functionality to input
void ADragon::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ADragon::Spawn()
{
	if (ToSpawn) {
		UWorld* world = GetWorld();
		if (world) {
			FActorSpawnParameters spawnParams;
			spawnParams.Owner = this;

			FRotator rot;
			FVector spawnLocation = this->GetActorLocation();

			world->SpawnActor<AFireball>(ToSpawn, spawnLocation, rot, spawnParams);
		}
	}
}

void ADragon::Lightning()
{
	if (ToLightning) {
		UWorld* world = GetWorld();
		if (world) {
			FActorSpawnParameters spawnParams;
			spawnParams.Owner = this;

			FRotator rot;
			int randIdx = rand() % 50;
			FVector spawnLocation = Obstacles[randIdx] + FVector(0.f, 0.f, 25000.f);

			world->SpawnActor<ALightning>(ToLightning, spawnLocation, rot, spawnParams);
		}
	}
}

void ADragon::DetectKick()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Kick!"));
	FHitResult hit;

	const float range = 2000.f;
	FVector startTrace = BossRoot->GetComponentLocation() - FVector(0.f, 0.f, 400.f);
	FVector endTrace = (BossRoot->GetForwardVector() * range) + startTrace;

	FCollisionQueryParams queryParams = FCollisionQueryParams(SCENE_QUERY_STAT(KickTrace), false, this);
	queryParams.AddIgnoredActor(this);
	GetWorld()->LineTraceSingleByChannel(hit, startTrace, endTrace, ECC_Visibility, queryParams);
	//DrawDebugLine(GetWorld(), hit.TraceStart, hit.TraceEnd, FColor::Red, false, 100.f, 0, 1.f);

	if (hit.bBlockingHit)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Kick!"));
		if (hit.Actor->IsA(AWireHunterCharacter::StaticClass()))
		{
			AWireHunterCharacter* TargetCharacter = Cast<AWireHunterCharacter>(hit.Actor);
			TargetCharacter->SetHealth(TargetCharacter->GetHealth() - 1.f);
			TargetCharacter->BreakHook();
			TargetCharacter->SetisClimbing(false);
			TargetCharacter->Knockback((TargetRotation.Vector() + FVector(0.f, 0.f, 0.5f)) * 10000000);
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Kick!"));
		}
	}
}