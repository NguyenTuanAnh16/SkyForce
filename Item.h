#ifndef _ITEM_H
#define _ITEM_H

#include <SDL.h>
#include "ResourceManager.h"

enum class ItemType
{
    HP,
    POWER,
    SHIELD
};

struct ItemData
{
    SDL_Texture* texture = nullptr;
    float width, height;
    float speed = 0;
    int value = 0;
    float time = 0;
};

struct Item
{
    ItemData* data = nullptr;
    bool active = false;
    SDL_FRect rect;
};

struct ItemDataBase
{
    ItemData hp;
    ItemData power;
    ItemData shield;

    void Init(ItemRes& res);

    ItemData* Get(ItemType type);
};

#endif
