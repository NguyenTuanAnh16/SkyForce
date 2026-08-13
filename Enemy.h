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
    // anh
    SDL_Texture* texture = nullptr;

    // thong so dich
    float speed;
    float hpMax;
    SDL_FRect rect;

    // loai vu khi
    int weaponType;

    // diem tieu diet
    int score;

    std::vector<GunPointEnemy> guns;
    float shootDelay;
};


struct Enemy{
// loai dich
EnemyData* data = nullptr;

// nhom
int groupId = -1;

// may bay dich
bool active = false;
SDL_FRect rect;

// hp
float hpNow;
SDL_FRect rectHpMax;
SDL_FRect rectHp;

// dan
float shoottime = 0;


};


struct EnemyDataBase
{
    EnemyData one;
    EnemyData two;
    EnemyData three;
    void Init(EnemyRes& res);
};


#endif

