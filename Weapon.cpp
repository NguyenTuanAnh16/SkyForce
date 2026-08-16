#include "Weapon.h"

void WeaponDataBase::Init(WeaponRes& res){

    //  dan player
            playerOne.texture = res.playerOne;
            playerOne.speed = 1000;
            playerOne.width = 8;
            playerOne.height = 16;
            playerOne.dame = 20;



            playerTwo.texture = res.playerOne;
            playerTwo.speed = 1000;
            playerTwo.width = 15;
            playerTwo.height = 30;
            playerTwo.dame = 40;


    // dan dich
            enemyOne.texture = res.enemyOne;
            enemyOne.speed = - 800;
            enemyOne.width = 6;
            enemyOne.height = 6;
            enemyOne.dame = 5 ;

}

WeaponData* WeaponDataBase::Get(WeaponType type)
{
    if (type == WeaponType::PLAYER_ONE)
        return &playerOne;
    else if(type == WeaponType::PLAYER_TWO)
        return &playerTwo;
    else if (type == WeaponType::ENEMY_ONE)
        return &enemyOne;

    return nullptr;
}

