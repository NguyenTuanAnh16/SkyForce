#ifndef _CollisionSystem_H
#define _CollisionSystem_H

#include <SDL.h>
#include "Player.h"
#include "EnemySystem.h"
#include "WeaponSystem.h"
#include "EffectSystem.h"
#include "Music.h"

struct CollisionSystem
{
    bool Check(const SDL_FRect& a,
               const SDL_FRect& b);

    void HandlePlayerEnemy(Player& player,
                           EnemySystem& enemySystem,
                           EffectSystem& effectSystem,
                           Music& music);

    void HandlePlayerWeapon(Player& player,
                            WeaponSystem& weaponSystem,
                            EffectSystem& effectSystem,
                            Music& music);

    void HandleEnemyWeapon(Player& player,
                           EnemySystem& enemySystem,
                           WeaponSystem& weaponSystem,
                           EffectSystem& effectSystem,
                           Music& music);

    void Update(Player& player,
                EnemySystem& enemySystem,
                WeaponSystem& weaponSystem,
                EffectSystem& effectSystem,
                Music& music);
};

#endif
