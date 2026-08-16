#ifndef _WEAPON_H
#define _WEAPON_H

#include<SDL.h>
#include "Config.h"
#include "ResourceManager.h"


enum class WeaponType
{
    PLAYER_ONE,
    PLAYER_TWO,
    ENEMY_ONE
};


struct WeaponData{

SDL_Texture* texture;
float width, height;
float speed;
float dame;
};


struct Weapon{
WeaponData* data = nullptr;
bool active = false;
SDL_FRect rect;
char owner;
};


struct WeaponDataBase{
     WeaponData playerOne;
     WeaponData playerTwo;
     WeaponData enemyOne;

     void Init(WeaponRes& res);
     WeaponData* Get(WeaponType type);


};




#endif

