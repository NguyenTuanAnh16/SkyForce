#ifndef _SPAWNMANAGER_H
#define _SPAWNMANAGER_H
#include "EnemySystem.h"
#include "Config.h"

struct SpawnManager
{
    EnemySystem* enemySystem;

    float timer = 0;
    float spawnTime = 1;

    int rateEnemy[3];
    int rateAmount[6];
    int amountMax;
    int moveType;

    void Init(EnemySystem* enemySystem);
    void Set(int level);
    void RandomSpawn();
    void Update(float deltaTime);
};


#endif
