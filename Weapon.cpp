#include "Weapon.h"

void WeaponDataBase::Init(WeaponRes& res){

    //  dan player
            playerOne.texture = res.playerOne;
            playerOne.speed = 1000;
            playerOne.width = 8;
            playerOne.height = 16;
            playerOne.dame = 30;

    // dan dich
            enemyOne.texture = res.enemyOne;
            enemyOne.speed = - 600;
            enemyOne.width = 6;
            enemyOne.height = 6;
            enemyOne.dame = 5 ;

}

WeaponData WeaponDataBase::weapon(int type){
    if(type == 1) return playerOne;
    if(type == 2) return enemyOne;
    return WeaponData();

}

