#include "CollisionSystem.h"


bool CollisionSystem::Check(const SDL_FRect& a,
                            const SDL_FRect& b)
{
    return SDL_HasIntersectionF(&a, &b);
}

void CollisionSystem::HandlePlayerEnemy(Player& player,
                                        EnemySystem& enemySystem,
                                        EffectSystem& effectSystem,
                                        Music& music)
{
    for(auto& enemy : enemySystem.enemys){
        if(enemy.active && Check(player.starship->rect,enemy.rect))
           {
                for(auto& hit : player.starship->hitboxes){
                     SDL_FRect box = {player.starship->rect.x + hit.x,
                                      player.starship->rect.y + hit.y,
                                      hit.w, hit.h};
                    if(Check(box,enemy.rect) && player.starship->hpNow > 0 ){
                        enemy.active = false;
                        effectSystem.AddBlast(enemy.rect.x + enemy.rect.w / 2,
                                         enemy.rect.y + enemy.rect.h / 2,
                                         EffectType::ONE,
                                         enemy.rect.w * 1.2);
                        music.PlayBrust();
                        player.shieldValue = player.shieldValue - enemy.hpNow;
                        if(!player.shieldActive) player.starship->hpNow = player.starship->hpNow - enemy.hpNow;
                        if(player.starship->hpNow <= 0)
                           {
                            effectSystem.AddBlast(player.starship->rect.x + player.starship->rect.w / 2,
                                         player.starship->rect.y + player.starship->rect.h / 2,
                                         EffectType::ONE,
                                         player.starship->rect.w * 1.2);
                             effectSystem.ClearEngine();
                             effectSystem.ClearItem(EffectType::SHIELD);
                             effectSystem.ClearItem(EffectType::HP);
                             music.PlayBrust();
                           }
                        player.score = player.score + enemy.data->score;
                        break;
                        }
                  }
           }
       }
 }

void CollisionSystem::HandlePlayerWeapon(Player& player,
                                        WeaponSystem& weaponSystem,
                                        EffectSystem& effectSystem,
                                        Music& music)
{
    for(auto& weapon : weaponSystem.weapons){
            if(weapon.owner != 'P' && weapon.active && Check(player.starship->rect,weapon.rect))
            {
              for(auto& hit : player.starship->hitboxes){
                     SDL_FRect box = {player.starship->rect.x + hit.x,
                                      player.starship->rect.y + hit.y,
                                      hit.w, hit.h};
                    if(Check(box, weapon.rect) && player.starship->hpNow > 0){
                        weapon.active = false;
                        effectSystem.AddBlast(weapon.rect.x + weapon.rect.w / 2,
                                         weapon.rect.y + weapon.rect.h,
                                         EffectType::TWO,
                                         15);
                       player.shieldValue = player.shieldValue - weapon.data->dame;
                       if(!player.shieldActive) player.starship->hpNow = player.starship->hpNow - weapon.data->dame;
                       if(player.starship->hpNow <= 0)
                           {
                            effectSystem.AddBlast(player.starship->rect.x + player.starship->rect.w / 2,
                                         player.starship->rect.y + player.starship->rect.h / 2,
                                         EffectType::ONE,
                                         player.starship->rect.w * 1.2);
                             effectSystem.ClearEngine();
                             effectSystem.ClearItem(EffectType::HP);
                             effectSystem.ClearItem(EffectType::SHIELD);
                             music.PlayBrust();
                           }
                        break;
                        }
                  }
              }
        }
}

void CollisionSystem::HandleEnemyWeapon(Player& player,
                                        EnemySystem& enemySystem,
                                        WeaponSystem& weaponSystem,
                                        EffectSystem& effectSystem,
                                        ItemSystem& itemSystem,
                                        Music& music)
{
    for(auto& enemy : enemySystem.enemys){
        for(auto& weapon : weaponSystem.weapons){
            if(weapon.owner != 'E' && enemy.active && weapon.active && Check(enemy.rect,weapon.rect) )
            {
                // hieu ung no
                effectSystem.AddBlast(weapon.rect.x + weapon.rect.w / 2,
                                 weapon.rect.y ,
                                 EffectType::TWO,
                                 6);
                // xoa dan
                weapon.active = false;

                // tru hp
                enemy.hpNow = enemy.hpNow - weapon.data->dame;
                if(enemy.hpNow <= 0){
                        enemy.active = false;
                   effectSystem.AddBlast(enemy.rect.x + enemy.rect.w / 2,
                                    enemy.rect.y + enemy.rect.h / 2,
                                    EffectType::ONE,
                                    enemy.rect.w);
                   music.PlayBrust();
                   player.score = player.score + enemy.data->score;
                   itemSystem.RandomDrop(enemy.rect.x + enemy.rect.w / 2,
                                         enemy.rect.y + enemy.rect.h / 2);
                }
            }
        }
    }
}


void CollisionSystem::HandlePlayerItem(Player& player,
                                       ItemSystem& itemSystem,
                                       EffectSystem& effectSystem,
                                       Music& music)

{
    for(auto& item : itemSystem.items)
    {
        if(item.active && Check(player.starship->rect,item.rect))
        {
                for(auto& hit : player.starship->hitboxes){
                     SDL_FRect box = {player.starship->rect.x + hit.x,
                                      player.starship->rect.y + hit.y,
                                      hit.w, hit.h};
                    if(Check(box, item.rect))
                        {item.active = false;
                         itemSystem.ApplyItem(player,item,effectSystem);
                         music.PlayClick();}
                    }
                    }
                    }
}

void CollisionSystem::Update(Player& player,
                             EnemySystem& enemySystem,
                             WeaponSystem& weaponSystem,
                             EffectSystem& effectSystem,
                             ItemSystem& itemSystem,
                             Music& music)
{
    HandlePlayerEnemy(player, enemySystem, effectSystem, music);
    HandlePlayerWeapon(player, weaponSystem, effectSystem, music);
    HandleEnemyWeapon(player, enemySystem, weaponSystem, effectSystem, itemSystem, music);
    HandlePlayerItem(player, itemSystem, effectSystem, music);
}
