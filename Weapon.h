#ifndef _Weapon_H
#define _Weapon_H

#include<SDL.h>
#include "Config.h"
#include "ResourceManager.h"

struct WeaponData{

SDL_Texture* texture;
float width, height;
float speed;
float dame;
};

struct WeaponDataBase{
     WeaponData playerOne;
     WeaponData enemyOne;

     void Init(WeaponRes& res);
     WeaponData weapon(int type);

};

struct Weapon{
bool active = false;
SDL_FRect rect;
int type;
char owner;
};


#endif

