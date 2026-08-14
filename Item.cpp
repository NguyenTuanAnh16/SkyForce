#include "Item.h"

void ItemDataBase::Init(ItemRes& res) {

    // Item 1: ChangeBullet
    changeBullet.texture = res.changeBullet;
    changeBullet.width = 55.0f;
    changeBullet.height = 65.0f;
    changeBullet.speed = 150.0f;

    // Item 2: Heal
    heal.texture = res.heal;
    heal.width = 55.0f;
    heal.height = 65.0f;
    heal.speed = 150.0f;
    heal.value = 50.0f;

    // Item 3: Shield
    shield.texture = res.shield;
    shield.width = 55.0f;
    shield.height = 65.0f;
    shield.speed = 150.0f;
}

ItemData ItemDataBase::Get(int type) {
    if (type == ITEM_CHANGE_BULLET) return changeBullet;
    if (type == ITEM_HEAL) return heal;
    if (type == ITEM_SHIELD) return shield;
    return ItemData();
}

void Item::Update(float dt) {
    if (!active) return;
    rect.y += speed * dt;
    if (rect.y > 850.0f) {
        active = false; // Tự hủy khi rơi khỏi màn hình
    }
}

void Item::Render(SDL_Renderer* renderer) {
    if (!active) return;

    // Nếu có file ảnh -> Chỉ vẽ ảnh
    if (texture != nullptr) {
        SDL_RenderCopyF(renderer, texture, nullptr, &rect);
    }
    // Dự phòng ô màu nếu thiếu file ảnh
    else {
        if (type == ITEM_CHANGE_BULLET)
            SDL_SetRenderDrawColor(renderer, 255, 215, 0, 255); // Vàng
        else if (type == ITEM_HEAL)
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);     // Đỏ
        else if (type == ITEM_SHIELD)
            SDL_SetRenderDrawColor(renderer, 0, 191, 255, 255); // Xanh dương

        SDL_RenderFillRectF(renderer, &rect);
    }
}

void ItemSystem::Init(int maxItems, ItemDataBase* db) {
    this->dataBase = db;
    items.resize(maxItems);
}

void ItemSystem::Spawn(float x, float y, int type) {
    for (auto& item : items) {
        if (!item.active) {
            ItemData data = dataBase->Get(type);
            item.active = true;
            item.type = type;
            item.rect = { x, y, data.width, data.height };
            item.speed = data.speed;
            item.texture = data.texture;
            return;
        }
    }
}

void ItemSystem::Update(float dt) {
    for (auto& item : items) {
        if (item.active) {
            item.Update(dt);
        }
    }
}

void ItemSystem::Render(SDL_Renderer* renderer) {
    for (auto& item : items) {
        if (item.active) {
            item.Render(renderer);
        }
    }
}

void ItemSystem::Reset() {
    for (auto& item : items) {
        item.active = false;
    }
}
