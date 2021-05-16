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
				RealMap[i][j] = MapSortArr[i][j/2];
			}
		}
	}

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			UE_LOG(LogTemp, Warning, TEXT("%s"), *RealMap[i][j].ToString());
		}
		UE_LOG(LogTemp, Warning, TEXT("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"));
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

void ABoss::h(FStructNode next, FStructNode end)
{
	int x = abs(end.first - next.first);
	int y = abs(end.second - next.second);
	ScoreH[next.second][next.first] = (x + y) * 10;
}

void ABoss::g(FStructNode next, int plus)
{
	ScoreG[next.second][next.first] =  plus;
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

	FStructWeight a;
	a.node = start;
	a.weight = 0;
	Min.Push(a);//or Emplace()
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

	while (Path.Last().first != goal.first || Path.Last().second != goal.second) {
		FStructNode now = FindTop();//at first, there is only start point in Min arr. 
		Closed.Push(now);
		Path.Push(now);

		Min.Empty(); // or new creation

		int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1};
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
			h(goal, tmp);
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
	}

	for (int i = 2; i < Path.Num(); ++i) {
		//print path from index2
	}
}

// Called when the game starts or when spawned
void ABoss::BeginPlay()
{
	Super::BeginPlay();

	Controller = Cast<ABossAIController>(GetController());

	//////////////////////////////////////////////////////////////////////

	MakeMap();
}

// Called every frame
void ABoss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FindPlayer();
	FacePlayer();

	auto movement = FMath::VInterpTo(this->GetActorLocation(), TargetLocation, GetWorld()->GetDeltaSeconds(), 0.5f);
	auto rot = FMath::RInterpTo(this->GetActorRotation(), TargetRotation, GetWorld()->GetDeltaSeconds(), 2.5f);

	this->SetActorLocationAndRotation(movement, rot);


}

// Called to bind functionality to input
void ABoss::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}