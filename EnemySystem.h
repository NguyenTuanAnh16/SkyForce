#ifndef _EnemySystem_H
#define _EnemySystem_H

#include <SDL.h>
#include <vector>
#include "Enemy.h"
#include "WeaponSystem.h"

struct EnemySystem
{
    EnemyDataBase data;

    std::vector<Enemy> enemys;

    void Init(SDL_Texture* enemyOne,
              SDL_Texture* enemyTwo,
              SDL_Texture* enemyThree);
    void Spawn(float x, float y,int type, int amount);
    void Update(float deltatime,WeaponSystem* weaponSystem);
    void Render(SDL_Renderer* renderer);
};

#endif

