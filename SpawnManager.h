#ifndef _Spawnmanager_H
#define _Spawnmanager_H

#include "EnemySystem.h"
#include "Config.h"

struct SpawnManager
{
    float timer = 0;
    float spawnTime = 1;


    void Update(float deltaTime, int spacing, int sum, EnemySystem& enemySystem);
};


#endif
