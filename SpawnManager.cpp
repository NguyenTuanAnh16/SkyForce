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

           rateAmount[0] = 40; // 1 địch
           rateAmount[1] = 30; // 2 địch
           rateAmount[2] = 20; // 3 địch
           rateAmount[3] = 10; // 4 địch

           amountMax = 4;
           spawnTime = 2.5f;

       }
    else if (level == 2)
            {
                rateEnemy[0] = 60;
                rateEnemy[1] = 30;
                rateEnemy[2] = 10;

                rateAmount[0] = 30;
                rateAmount[1] = 30;
                rateAmount[2] = 20;
                rateAmount[3] = 15;
                rateAmount[4] = 5;

                amountMax = 5;
                spawnTime = 2;
            }
    else if (level == 3)
            {
                rateEnemy[0] = 40;
                rateEnemy[1] = 40;
                rateEnemy[2] = 20;

                rateAmount[0] = 28;
                rateAmount[1] = 25;
                rateAmount[2] = 22;
                rateAmount[3] = 15;
                rateAmount[4] = 5;
                rateAmount[5] = 5;

                amountMax = 6;
                spawnTime = 2;
            }
}


void SpawnManager::RandomSpawn()
{
    // Chọn loại địch
    int random = rand() % 100;

    EnemyType type;

    if (random < rateEnemy[0])
    type = EnemyType::ONE;

    else if (random < rateEnemy[0] + rateEnemy[1])
    type = EnemyType::TWO;

    else
    type = EnemyType::THREE;


    // Số lượng
    // Số lượng
    int randomAmount = rand() % 100;
    int amount = 1;
    int total = 0;
    for(int i = 0; i < amountMax; i++)
        {
            total += rateAmount[i];
            if(randomAmount < total)
                {
                    amount = i + 1;
                    break;
                }
}


    // random kiểu di chuyển cho cả nhóm
    int moveType;

    if (amount == 1)
        moveType = 0;
    else if (amount <= 3)
        moveType = 1 + rand() % 3;
    else if (amount <=4)
         moveType = 1 + rand() % 4;
    else moveType = 5;

// Vị trí
int x = rand() % ( SCREEN_WIDTH - amount * (int)enemySystem->data->Get(type)->rect.w - (amount - 1) * 40 - 10);

if(amount >= 4)  x =  100+ rand() % ( SCREEN_WIDTH - amount * (int)enemySystem->data->Get(type)->rect.w - (amount - 1) * 40 - 200);

if(amount >= 5)  x =  200+ rand() % ( SCREEN_WIDTH - amount * (int)enemySystem->data->Get(type)->rect.w - (amount - 1) * 40 - 400);

// render dich
    enemySystem->Spawn(
        x,
        -50,
        type,
        amount,
        moveType
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
