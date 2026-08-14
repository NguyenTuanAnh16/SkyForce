#ifndef _Item_H
#define _Item_H

#include <SDL.h>
#include <vector>
#include "ResourceManager.h"

// Định nghĩa các loại Item trong game
enum ItemType {
    ITEM_CHANGE_BULLET = 1, // Đổi sang đạn nâng cấp Type 3
    ITEM_HEAL = 2,          // Hồi máu (Mở rộng)
    ITEM_SHIELD = 3         // Tạo khiên bảo vệ (Mở rộng)
};

struct ItemData {
    SDL_Texture* texture = nullptr;
    float width = 55.0f;
    float height = 55.0f;
    float speed = 150.0f;
    float value = 50.0f;
};

struct ItemDataBase {
    ItemData changeBullet;
    ItemData heal;
    ItemData shield;

    void Init(ItemRes& res);
    ItemData Get(int type);
};

struct Item {
    bool active = false;
    SDL_FRect rect;
    int type = 0;
    float speed = 150.0f;
    SDL_Texture* texture = nullptr;

    void Update(float dt);
    void Render(SDL_Renderer* renderer);
};

struct ItemSystem {
    ItemDataBase* dataBase = nullptr;
    std::vector<Item> items;

    void Init(int maxItems, ItemDataBase* db);
    void Spawn(float x, float y, int type);
    void Update(float dt);
    void Render(SDL_Renderer* renderer);
    void Reset();
};

#endif
