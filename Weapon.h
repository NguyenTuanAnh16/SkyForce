#ifndef _Weapon_H
#define _Weapon_H

#include<SDL.h>
#include "Config.h"

struct WeaponData{

SDL_Texture* texture;
float width, height;
float speed;
float dame;
};

struct WeaponDataBase{
     WeaponData bulletOne;
     WeaponData bulletTwo;

     void Init(SDL_Texture* bulletOne,SDL_Texture* bulletTwo);
     WeaponData weapon(int type);

};

struct Weapon{
bool active = false;
SDL_FRect rect;
int type;
};


#endif

