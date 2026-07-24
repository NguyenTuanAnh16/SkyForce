#include "SpawnManager.h"
#include <cstdlib>

void SpawnManager::Update(float deltaTime,int spacing, int sum, EnemySystem& enemySystem)
{
    timer = timer + deltaTime;

    if(timer >= spawnTime)
    {
        int amount = 1 + rand() % sum;
        int x = rand() %(SCREEN_WIDTH
                         - amount*(int)enemySystem.data.Enemy(0).width
                         - (amount -1) * spacing);

        enemySystem.Spawn(x, -50,0, amount);

        timer = 0;
        spawnTime = 1.5 + rand() % 2;
    }
}
