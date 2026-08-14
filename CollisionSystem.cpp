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
        if(enemy.active){
            for(auto& hit : player.starship->hitboxes){
                SDL_FRect box = {player.starship->rect.x + hit.x,
                                 player.starship->rect.y + hit.y,
                                 hit.w, hit.h};
                if(Check(box, enemy.rect) && player.starship->hpNow > 0 ){
                    enemy.active = false;
                    effectSystem.AddBlast(enemy.rect.x + enemy.rect.w / 2,
                                         enemy.rect.y + enemy.rect.h / 2,
                                         1, enemy.rect.w * 1.2);
                    music.PlayBrust();

                    player.takeDamage(enemy.hpNow);

                    if(player.starship->hpNow <= 0)
                    {
                        effectSystem.AddBlast(player.starship->rect.x + player.starship->rect.w / 2,
                                     player.starship->rect.y + player.starship->rect.h / 2,
                                     1, player.starship->rect.w * 1.2);
                        effectSystem.ClearEngine();
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
        if(weapon.owner != 'P' && weapon.active){
            for(auto& hit : player.starship->hitboxes){
                SDL_FRect box = {player.starship->rect.x + hit.x,
                                 player.starship->rect.y + hit.y,
                                 hit.w, hit.h};
                if(Check(box, weapon.rect) && player.starship->hpNow > 0){
                    weapon.active = false;
                    effectSystem.AddBlast(weapon.rect.x + weapon.rect.w / 2,
                                     weapon.rect.y + weapon.rect.h, 2, 15);
                    float dame = weaponSystem.data->weapon(weapon.type).dame;
                    player.takeDamage(dame);

                    if(player.starship->hpNow <= 0)
                    {
                        effectSystem.AddBlast(player.starship->rect.x + player.starship->rect.w / 2,
                                     player.starship->rect.y + player.starship->rect.h / 2,
                                     1, player.starship->rect.w * 1.2);
                        effectSystem.ClearEngine();
                        music.PlayBrust();
                    }
                    break;
                }
            }
        }
    }
}

void CollisionSystem::HandleEnemyWeapon(EnemySystem& enemySystem,
                                        WeaponSystem& weaponSystem,
                                        EffectSystem& effectSystem,
                                        ItemSystem& itemSystem,
                                        Music& music)
{
    for(auto& enemy : enemySystem.enemys){
        if(enemy.active){
            for(auto& weapon : weaponSystem.weapons){
                if(weapon.owner != 'E' && weapon.active && Check(enemy.rect, weapon.rect))
                {
                    effectSystem.AddBlast(weapon.rect.x + weapon.rect.w / 2, weapon.rect.y, 2, 6);
                    weapon.active = false;

                    enemy.hpNow = enemy.hpNow - weaponSystem.data->weapon(weapon.type).dame;
                    if(enemy.hpNow <= 0){
                        enemy.active = false;
                        effectSystem.AddBlast(enemy.rect.x + enemy.rect.w / 2,
                                              enemy.rect.y + enemy.rect.h / 2, 1, enemy.rect.w);
                        music.PlayBrust();

                        itemSystem.TryDropItem(enemy.rect.x, enemy.rect.y);
                    }
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
    for (auto& item : itemSystem.items) {
        if (item.active) {
            for (auto& hit : player.starship->hitboxes) {
                SDL_FRect box = { player.starship->rect.x + hit.x,
                                  player.starship->rect.y + hit.y,
                                  hit.w, hit.h };

                if (Check(box, item.rect)) {
                    itemSystem.ApplyItemToPlayer(player, item, effectSystem);
                    music.PlayItem();
                    break;
                }
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
    HandleEnemyWeapon(enemySystem, weaponSystem, effectSystem, itemSystem, music);
    HandlePlayerItem(player, itemSystem, effectSystem, music);
}
