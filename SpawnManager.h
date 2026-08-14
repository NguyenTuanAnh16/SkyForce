#ifndef _Spawnmanager_H
#define _Spawnmanager_H

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
    void Set(int type);
    void RandomSpawn();
    void Update(float deltaTime);
};


#endif
