#ifndef ITEM_H
#define ITEM_H

#include <SDL.h>
#include "ResourceManager.h"

struct ItemData
{
    SDL_Texture* texture = nullptr;
    float speed;
    SDL_FRect rect;
    int value;
    float time;
};

struct Item
{
    ItemData* data = nullptr;
    SDL_FRect rect;
};

struct ItemDataBase
{
    ItemData hp;
    ItemData power;
    ItemData shield;

    void Init(ItemRes& res);
};

#endif
