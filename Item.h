#ifndef _Item_H
#define _Item_H

#include <SDL.h>
#include "ResourceManager.h"

enum ItemType {
    ITEM_CHANGE_BULLET = 1,
    ITEM_HEAL = 2,
    ITEM_SHIELD = 3
};

struct ItemData
{
    SDL_Texture* texture = nullptr;
    float speed = 150.0f;
    SDL_FRect rect;
    int type = 0;
    float value = 0.0f;
    float duration = 0.0f;
};

struct Item
{
    ItemData* data = nullptr;
    bool active = false;
    int type = 0;
    SDL_FRect rect;
};

struct ItemDataBase
{
    ItemData one;   // Item Đổi đạn
    ItemData two;   // Item Hồi máu
    ItemData three; // Item Khiên

    void Init(ItemRes& res);
};

#endif
