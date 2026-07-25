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
    float hpMax;
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

// hp
float hpNow;
SDL_FRect rectHpMax;
SDL_FRect rectHp;

// dan
float shoottime = 0;
WeaponData* weapon;

};


struct EnemyDataBase
{
    EnemyData one;
    EnemyData two;
    EnemyData three;
    void Init(EnemyRes& res);
    EnemyData Enemy(int type);
};


#endif

