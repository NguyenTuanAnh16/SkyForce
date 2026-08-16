#ifndef _ITEMSYSTEM_H
#define _ITEMSYSTEM_H

#include "Item.h"
#include <vector>
#include "Player.h"
#include "EffectSystem.h"

struct ItemSystem
{
    ItemDataBase* data = nullptr;
    std::vector<Item> items;

    float timeHp;
    float timePower;
    float timeShield;

    void Init(ItemDataBase* data);


    void RandomDrop(float x, float y);

    void Spawn(float x, float y, ItemType type);

    void ApplyItem(Player& player,Item& item, EffectSystem& effectSystem);

    void UpdateItem(float deltaTime, Player& player, EffectSystem& effectSystem);

    void Update(float deltaTime);
    void Reset();
    void Render(SDL_Renderer* renderer);

};
#endif
