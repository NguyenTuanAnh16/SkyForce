#ifndef _Enemy_H
#define _Enemy_H

#include<SDL.h>
#include<vector>
#include "Weapon.h"

struct GunPointEnemy
{
    float x;
    float y;
};


struct EnemyData
{
    SDL_Texture* texture;

    float speed;
    int hp;
    int dame;
    float width,height;

    int moveType;
    int shootType;

    std::vector<GunPointEnemy> guns;
    float shootDelay;
};


struct Enemy{
// loai dich
int type;

// may bay dich
bool active = false;
SDL_FRect rect;

// dan
float shoottime = 0;
WeaponData* weapon;

};


struct EnemyDataBase
{
    EnemyData enemyOne;
    EnemyData enemyTwo;
    EnemyData enemyThree;
    void Init(SDL_Texture* enemyOne,
              SDL_Texture* enemyTwo,
              SDL_Texture* enemyThree);
    void Render(SDL_Renderer* renderer);
    EnemyData Enemy(int type);
};


#endif

