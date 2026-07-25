#ifndef _CollisionSystem_H
#define _CollisionSystem_H

#include <SDL.h>
#include "Player.h"
#include "EnemySystem.h"
#include "WeaponSystem.h"

struct CollisionSystem
{
    bool Check(const SDL_FRect& a,
                const SDL_FRect& b);

    void HandlePlayerEnemy(Player& player,
                           EnemySystem& enemySystem);


    void HandlePlayerWeapon(Player& player,
                            WeaponSystem& weaponSystem);


    void HandleEnemyWeapon(EnemySystem& enemySystem,
                           WeaponSystem& weaponSystem);

    void Update(Player& player,
                EnemySystem& enemySystem,
                WeaponSystem& weaponSystem);

};

#endif
