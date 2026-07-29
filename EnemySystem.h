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

    void Init(int sum,EnemyDataBase* data);
    void Spawn(float x, float y,int type, int amount);
    void Update(float deltatime,WeaponSystem* weaponSystem);
    void Render(SDL_Renderer* renderer);
};

#endif

