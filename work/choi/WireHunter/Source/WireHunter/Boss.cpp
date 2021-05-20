// Fill out your copyright notice in the Description page of Project Settings.

#include "Boss.h"
#include "GameFramework/Actor.h"
#include "Math/UnrealMathUtility.h"
#include "Kismet/KismetMathLibrary.h"
#include "Obstacle.h"
#include "Runtime/Engine/Public/EngineUtils.h"


// Sets default values
ABoss::ABoss()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BossRoot = CreateDefaultSubobject<USceneComponent>(TEXT("FireballRoot"));
	RootComponent = BossRoot;


	BossSkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BossSkeletalMesh"));
	BossSkeletalMesh->SetupAttachment(BossRoot);
	BossSkeletalMesh->SetWorldScale3D(FVector(13.f, 13.f, 13.f));
	BossSkeletalMesh->SetWorldRotation(FRotator(0.f, -90.f, 0.f));

	static ConstructorHelpers::FObjectFinder<USkeletalMesh>SkeletalMeshAsset(TEXT("SkeletalMesh'/Game/ThirdPersonCPP/AI/Boss_Rig.Boss_Rig'"));
	static ConstructorHelpers::FObjectFinder<UMaterial>MaterialAsset(TEXT("Material'/Game/ThirdPersonCPP/GraphicResources/Boss/M_Boss.M_Boss'"));
	USkeletalMesh* Asset = SkeletalMeshAsset.Object;
	UMaterial* Material = MaterialAsset.Object;
	BossSkeletalMesh->SetSkeletalMesh(Asset);
	BossSkeletalMesh->SetMaterial(0, Material);

	SetHealth(100);
}

void ABoss::MakeMap()
{
	UWorld* world = GetWorld();

	TArray<FVector> buffer;

	for (const auto& e : TActorRange<AObstacle>(world)) {
		auto loc = e->GetActorLocation();
		buffer.Push(loc);
	}

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

void ABoss::FindPlayer()
{
	TargetLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
}

void ABoss::FacePlayer()
{
	TargetRotation = UKismetMathLibrary::FindLookAtRotation(this->GetActorLocation(), TargetLocation);
}

float ABoss::FindDistance(FVector a, FVector b)
{
	float x = a.X - b.X;
	float y = a.Y - b.Y;
	x = x * x;
	y = y * y;
	float c = x + y;
	float ret = sqrt(c);

	return ret;
}

TArray<FStructNode> ABoss::Regulate()
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

void ABoss::h(FStructNode next, FStructNode end)
{
	int x = abs(end.first - next.first);
	int y = abs(end.second - next.second);
	ScoreH[next.second][next.first] = (x + y) * 10;
}

void ABoss::g(FStructNode next, int plus)
{
	ScoreG[next.second][next.first] = plus;
}

void ABoss::f(FStructNode next)
{
	ScoreF[next.second][next.first] = ScoreG[next.second][next.first] + ScoreH[next.second][next.first];
}

FStructNode ABoss::FindTop()//가중치가 가장 작은 노드 반환
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

int ABoss::FindElement(float x, float y)
{
	for (int i = 0; i < Closed.Num(); ++i) {
		if (Closed[i].first == x && Closed[i].second == y) {
			return i;
		}
	}
	return -1;
}

void ABoss::AStar(char map[10][10], FStructNode start, FStructNode goal)
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
void ABoss::BeginPlay()
{
	Super::BeginPlay();

	Controller = Cast<ABossAIController>(GetController());

	//////////////////////////////////////////////////////////////////////

	MakeMap();

	Top = 17000.f;

	bFireballReady = false;

	bAStarReady = true;
	DoAStar();

	//GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &ABoss::Spawn, 2.f, true, 0.f);
}

void ABoss::DoAStar()
{
	if (bAStarReady) {
		PathIdx = 0;
		FindPlayer();
		auto ret = Regulate();

		Spawn();

		UE_LOG(LogTemp, Warning, TEXT("%d %d %d %d"), ret[0].first, ret[0].second, ret[1].first, ret[1].second);

		AStar(Map, ret[0], ret[1]);

		/*for (int i = 0; i < Path.Nusm(); ++i) {
			RealGoal = RealMap[Path[i].second][Path[i].first];
			UE_LOG(LogTemp, Warning, TEXT("RealGoal: %s"), *RealGoal.ToString());

		}*/
		bFireballReady = true;
	}
	bAStarReady = false;
}

void ABoss::SetRealGoal()
{
	if (Path.Num() - 1 > PathIdx) {
		PathIdx++;
	}
	RealGoal = RealMap[Path[PathIdx].second][Path[PathIdx].first];
	RealGoal.Z = TargetLocation.Z + 800.f;

	if (Path.Num() - 1 == PathIdx) {
		UE_LOG(LogTemp, Warning, TEXT("%s"), *this->GetActorLocation().ToString());

		bAStarReady = true;
	}

	bMoveReady = false;
}

// Called every frame+
void ABoss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FacePlayer();

	Delta += DeltaTime;
	if (Delta > 1.5f) {
		Delta = 0.f;
		bMoveReady = true;
	}

	if (bMoveReady) {
		SetRealGoal();
	}

	DoAStar();

	auto movement = FMath::VInterpTo(this->GetActorLocation(), RealGoal, GetWorld()->GetDeltaSeconds(), 1.5f);

	auto rot = FMath::RInterpTo(this->GetActorRotation(), TargetRotation, GetWorld()->GetDeltaSeconds(), 2.5f);

	this->SetActorLocationAndRotation(movement, rot);
}

// Called to bind functionality to input
void ABoss::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ABoss::Spawn()
{
	if (bFireballReady) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Spawned"));
		if (ToSpawn)
		{
			UWorld* world = GetWorld();
			if (world)
			{
				FActorSpawnParameters spawnParams;
				spawnParams.Owner = this;

				FRotator rot;
				FVector spawnLocation = GetActorLocation();

				world->SpawnActor<AFireball>(ToSpawn, spawnLocation, rot, spawnParams);
			}
		}
	}
	bFireballReady = false;
}