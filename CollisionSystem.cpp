#include "CollisionSystem.h"
#include <iostream>

bool CollisionSystem::Check(const SDL_FRect& a,
                            const SDL_FRect& b)
{
    return SDL_HasIntersectionF(&a, &b);
}

void CollisionSystem::HandlePlayerEnemy(Player& player,
                                        EnemySystem& enemySystem)
{
    for(auto& enemy : enemySystem.enemys){
        if(enemy.active && Check(player.starship.rect,enemy.rect)){
                enemy.active = false;
                player.starship.hpNow = player.starship.hpNow - enemy.hpNow;
        }
    }
}

void CollisionSystem::HandlePlayerWeapon(Player& player,
                                        WeaponSystem& weaponSystem)
{
    for(auto& weapon : weaponSystem.weapons)
        {  if(weapon.owner != 'P' && weapon.active && Check(player.starship.rect,weapon.rect))
              {
                  weapon.active = false;
                  player.starship.hpNow = player.starship.hpNow - weaponSystem.data.weapon(weapon.type).dame;
              }
        }
}

void CollisionSystem::HandleEnemyWeapon(EnemySystem& enemySystem,
                                        WeaponSystem& weaponSystem)
{
    for(auto& enemy : enemySystem.enemys){
        for(auto& weapon : weaponSystem.weapons){
            if(weapon.owner != 'E' && enemy.active && weapon.active && Check(enemy.rect,weapon.rect) )
            {
                weapon.active = false;
                enemy.hpNow = enemy.hpNow - weaponSystem.data.weapon(weapon.type).dame;
                if(enemy.hpNow <= 0) enemy.active = false;
            }
        }
    }
}

void CollisionSystem::Update(Player& player,
                             EnemySystem& enemySystem,
                             WeaponSystem& weaponSystem)
{
    HandlePlayerEnemy(player,enemySystem);
    HandlePlayerWeapon(player,weaponSystem);
    HandleEnemyWeapon(enemySystem,weaponSystem);
}
