#ifndef _COLLISIONSYSTEM_H
#define _COLLISIONSYSTEM_H

#include <SDL.h>
#include "Player.h"
#include "EnemySystem.h"
#include "WeaponSystem.h"
#include "EffectSystem.h"
#include "ItemSystem.h"
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
                           ItemSystem& itemSystem,
                           Music& music);

    void HandlePlayerItem(Player& Player,
                          ItemSystem& itemSystem,
                          EffectSystem& effectSystem,
                          Music& music);

    void Update(Player& player,
                EnemySystem& enemySystem,
                WeaponSystem& weaponSystem,
                EffectSystem& effectSystem,
                ItemSystem& itemSystem,
                Music& music);
};

#endif
