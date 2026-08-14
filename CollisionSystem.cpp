#include "CollisionSystem.h"


bool CollisionSystem::Check(const SDL_FRect& a, const SDL_FRect& b)
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

void CollisionSystem::HandleEnemyWeapon(EnemySystem& enemySystem,
                                        WeaponSystem& weaponSystem,
                                        EffectSystem& effectSystem,
                                        ItemSystem& itemSystem)
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

                        // Tỉ lệ 60% rớt item khi tiêu diệt quái
                        if (rand() % 100 < 60) {
                            int roll = rand() % 100;
                            int itemType = ITEM_CHANGE_BULLET;

                            if (roll < 50)
                                itemType = ITEM_CHANGE_BULLET;
                            else if (roll < 80)
                                itemType = ITEM_HEAL;
                            else
                                itemType = ITEM_SHIELD;

                            itemSystem.Spawn(enemy.rect.x, enemy.rect.y, itemType);
                        }
                    }
                }
            }
        }
    }
}

void CollisionSystem::HandlePlayerItem(Player& player, ItemSystem& itemSystem, EffectSystem& effectSystem)
{
    for (auto& item : itemSystem.items) {
        if (item.active) {
            for (auto& hit : player.starship->hitboxes) {
                SDL_FRect box = { player.starship->rect.x + hit.x,
                                  player.starship->rect.y + hit.y,
                                  hit.w, hit.h };

                if (Check(box, item.rect)) {

                    if (item.type == ITEM_CHANGE_BULLET) {
                        player.changeWeaponType(3, 5.0f);
                        effectSystem.AddItemNotif(player.starship->rect.x + player.starship->rect.w / 2, player.starship->rect.y, 6, 1.5f);
                    }
                    else if (item.type == ITEM_HEAL) {
                        player.heal(50.0f);
                        effectSystem.AddItemNotif(player.starship->rect.x + player.starship->rect.w / 2, player.starship->rect.y, 4, 1.5f);
                    }
                    else if (item.type == ITEM_SHIELD) {
                        player.activateShield(8.0f, 350.0f);
                        effectSystem.AddItemNotif(player.starship->rect.x + player.starship->rect.w / 2, player.starship->rect.y, 5, 1.5f);
                    }

                    item.active = false;
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
                             ItemSystem& itemSystem)
{
    HandlePlayerEnemy(player, enemySystem, effectSystem);
    HandlePlayerWeapon(player, weaponSystem, effectSystem);
    HandleEnemyWeapon(enemySystem, weaponSystem, effectSystem, itemSystem);
    HandlePlayerItem(player, itemSystem, effectSystem);
}
