#ifndef _ItemSystem_H
#define _ItemSystem_H

#include <SDL.h>
#include <vector>
#include <cstdlib>

#include "Item.h"
#include "ResourceManager.h"
#include "Player.h"
#include "EffectSystem.h"

struct ItemSystem {
    ItemRes* res = nullptr;
    ItemDataBase* dataBase = nullptr;
    std::vector<Item> items;

    void Init(ItemRes* res, ItemDataBase* dataBase);
    void Spawn(float x, float y, int type);
    void TryDropItem(float x, float y);
    void ApplyItemToPlayer(Player& player, Item& item, EffectSystem& effectSystem);
    void Update(float dt);
    void Render(SDL_Renderer* renderer);
    void Reset();
};

#endif
