#include "SpawnManager.h"
#include <cstdlib>

void SpawnManager::Init(EnemySystem* enemySystem)
{
    this->enemySystem = enemySystem;
}


void SpawnManager::Set(int level)
{
    if (level == 1)
       {
           rateEnemy[0] = 80;
           rateEnemy[1] = 20;
           rateEnemy[2] = 0;
           amountMax = 4;
           spawnTime = 2;
       }
    else if (level == 2)
            {
                rateEnemy[0] = 60;
                rateEnemy[1] = 30;
                rateEnemy[2] = 10;
                amountMax = 5;
                spawnTime = 1.5f;
            }
    else if (level == 3)
            {
                rateEnemy[0] = 40;
                rateEnemy[1] = 40;
                rateEnemy[2] = 20;
                amountMax = 6;
                spawnTime = 1;
            }
}


void SpawnManager::RandomSpawn()
{
    // Chọn loại địch
    int random = rand() % 100;

    EnemyData* enemyData;

    if (random < rateEnemy[0])
        enemyData = &enemySystem->data->one;

    else if (random < rateEnemy[0] + rateEnemy[1])
        enemyData = &enemySystem->data->two;

    else
        enemyData = &enemySystem->data->three;


    // Số lượng
    int amount = 1 + rand() % amountMax;


    // random kiểu di chuyển cho cả nhóm
    int moveType;

    if (amount == 1)
        moveType = 0;
    else if (amount <= 3)
        moveType = rand() % 2;
    else
        moveType = rand() % 3;

// Vị trí
int x = rand() % ( SCREEN_WIDTH - amount * (int)enemyData->rect.w - (amount - 1) * 40);

    enemySystem->Spawn(
        x,
        -50,
        enemyData,
        amount,
        1
    );
}




void SpawnManager::Update(float deltaTime)
{
    timer += deltaTime;

    if (timer >= spawnTime)
    {
        RandomSpawn();
        timer = 0;
    }
}
