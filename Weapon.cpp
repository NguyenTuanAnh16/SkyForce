#include "Weapon.h"

void WeaponDataBase::Init(SDL_Texture* bulletOne, SDL_Texture* bulletTwo){

    //  dan player
            this->bulletOne.texture = bulletOne;
            this->bulletOne.speed = 1000;
            this->bulletOne.width = 8;
            this->bulletOne.height = 16;

    // dan dich
            this->bulletTwo.texture = bulletTwo;
            this->bulletTwo.speed = - 400;
            this->bulletTwo.width = 6;
            this->bulletTwo.height = 6;

}

WeaponData WeaponDataBase::weapon(int type){
    if(type == 1) return bulletOne;
    if(type == 2) return bulletTwo;
    return WeaponData();

}

