#include "Weapon.h"

void WeaponDataBase::Init(WeaponRes& res){

    //  dan player
            playerOne.texture = res.playerOne;
            playerOne.speed = 1000;
            playerOne.width = 8;
            playerOne.height = 16;
            playerOne.dame = 60;

    // dan upgrade
            playerTwo.texture = (res.playerTwo != nullptr) ? res.playerTwo : res.playerOne;
            playerTwo.speed = 1200;
            playerTwo.width = 14;
            playerTwo.height = 28;
            playerTwo.dame = 120;
    // dan dich
            enemyOne.texture = res.enemyOne;
            enemyOne.speed = - 600;
            enemyOne.width = 6;
            enemyOne.height = 6;
            enemyOne.dame = 10;

}

WeaponData WeaponDataBase::weapon(int type){
    if(type == 1) return playerOne;
    if(type == 2) return enemyOne;
    if(type == 3) return playerTwo;
    return WeaponData();
}

