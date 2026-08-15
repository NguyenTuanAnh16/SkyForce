#ifndef _ItemSystem_H
#define _ItemSystem_H

#include <SDL.h>
#include <vector>
#include <cstdlib>

#include "Item.h"
#include "Player.h"
#include "EffectSystem.h"

struct ItemSystem {
    ItemDataBase* data = nullptr;
    std::vector<Item> items;

    void Init(int capacity, ItemDataBase* data);
    void Spawn(float x, float y, ItemData* itemData);
    void TryDropItem(float x, float y);
    void ApplyItemToPlayer(Player& player, Item& item, EffectSystem& effectSystem);
    void Update(float dt);
    void Render(SDL_Renderer* renderer);
    void Reset();
};

#endif
