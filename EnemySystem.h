#ifndef _EnemySystem_H
#define _EnemySystem_H

#include <SDL.h>
#include <vector>
#include "ResourceManager.h"
#include "Enemy.h"
#include "WeaponSystem.h"

struct EnemySystem
{
    EnemyDataBase* data = nullptr;

    std::vector<Enemy> enemys;
    std::vector<int> moveGroups;
    int idGround  = 0;
    void Init(int sum,EnemyDataBase* data);
    void Spawn(float x, float y,EnemyData* enemyData, int amount, int moveType);
    void Move (Enemy* enemy, float deltaTime);
    void Update(float deltatime,WeaponSystem* weaponSystem);
    void Reset();
    void Render(SDL_Renderer* renderer);
};

#endif

