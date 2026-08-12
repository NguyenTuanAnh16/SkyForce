#include "CollisionSystem.h"


bool CollisionSystem::Check(const SDL_FRect& a,
                            const SDL_FRect& b)
{
    return SDL_HasIntersectionF(&a, &b);
}

void CollisionSystem::HandlePlayerEnemy(Player& player,
                                        EnemySystem& enemySystem,
                                        EffectSystem& effectSystem)
{
    for(auto& enemy : enemySystem.enemys){
        if(enemy.active){
                for(auto& hit : player.starship->hitboxes){
                     SDL_FRect box = {player.starship->rect.x + hit.x,
                                      player.starship->rect.y + hit.y,
                                      hit.w, hit.h};
                    if(Check(box,enemy.rect)){
                        enemy.active = false;
                        player.starship->hpNow = player.starship->hpNow - enemy.hpNow;
                        effectSystem.AddBlast(enemy.rect.x + enemy.rect.w / 2,
                                         enemy.rect.y + enemy.rect.h / 2,
                                         1, enemy.rect.w * 1.2);
                        player.score = player.score + enemy.data->score;
                        break;
                        }
                  }
           }
       }
 }

void CollisionSystem::HandlePlayerWeapon(Player& player,
                                        WeaponSystem& weaponSystem,
                                        EffectSystem& effectSystem)
{
    for(auto& weapon : weaponSystem.weapons){
            if(weapon.owner != 'P' && weapon.active){
              for(auto& hit : player.starship->hitboxes){
                     SDL_FRect box = {player.starship->rect.x + hit.x,
                                      player.starship->rect.y + hit.y,
                                      hit.w, hit.h};
                    if(Check(box, weapon.rect)){
                        weapon.active = false;
                        player.starship->hpNow = player.starship->hpNow - weaponSystem.data->weapon(weapon.type).dame;
                        effectSystem.AddBlast(weapon.rect.x + weapon.rect.w / 2,
                                         weapon.rect.y + weapon.rect.h, 2,15);
                        break;
                        }
                  }
              }
        }
}

void CollisionSystem::HandleEnemyWeapon(Player& player,
                                        EnemySystem& enemySystem,
                                        WeaponSystem& weaponSystem,
                                        EffectSystem& effectSystem)
{
    for(auto& enemy : enemySystem.enemys){
        for(auto& weapon : weaponSystem.weapons){
            if(weapon.owner != 'E' && enemy.active && weapon.active && Check(enemy.rect,weapon.rect) )
            {
                effectSystem.AddBlast(weapon.rect.x + weapon.rect.w / 2,
                                 weapon.rect.y ,2,6);
                weapon.active = false;

                enemy.hpNow = enemy.hpNow - weaponSystem.data->weapon(weapon.type).dame;
                if(enemy.hpNow <= 0){
                        enemy.active = false;
                   effectSystem.AddBlast(enemy.rect.x + enemy.rect.w / 2,
                                    enemy.rect.y + enemy.rect.h / 2,1,enemy.rect.w);
                   player.score = player.score + enemy.data->score;

                }
            }
        }
    }
}

void CollisionSystem::Update(Player& player,
                             EnemySystem& enemySystem,
                             WeaponSystem& weaponSystem,
                             EffectSystem& effectSystem)
{
    HandlePlayerEnemy(player,enemySystem,effectSystem);
    HandlePlayerWeapon(player,weaponSystem,effectSystem);
    HandleEnemyWeapon(player,enemySystem,weaponSystem,effectSystem);
}
