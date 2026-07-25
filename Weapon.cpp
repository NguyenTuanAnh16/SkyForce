#include "Weapon.h"

void WeaponDataBase::Init(WeaponRes& res){

    //  dan player
            this->playerOne.texture = res.playerOne;
            this->playerOne.speed = 1000;
            this->playerOne.width = 8;
            this->playerOne.height = 16;
            this->playerOne.dame = 60;

    // dan dich
            this->enemyOne.texture = res.enemyOne;
            this->enemyOne.speed = - 400;
            this->enemyOne.width = 6;
            this->enemyOne.height = 6;
            this->enemyOne.dame = 10;

}

WeaponData WeaponDataBase::weapon(int type){
    if(type == 1) return playerOne;
    if(type == 2) return enemyOne;
    return WeaponData();

}

