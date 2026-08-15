#include "ItemSystem.h"

void ItemSystem::Init(int capacity, ItemDataBase* data)
{
    this->data = data;
    items.resize(capacity);
}

void ItemSystem::Spawn(float x, float y, ItemData* itemData)
{
    if (!itemData) return;

    for (auto& item : items) {
        if (!item.active) {
            item.active = true;
            item.type = itemData->type;
            item.data = itemData;
            item.rect = { x, y, itemData->rect.w, itemData->rect.h };
            return;
        }
    }
}

void ItemSystem::TryDropItem(float x, float y)
{
    if (!data) return;

    if (rand() % 100 < 60) {
        int roll = rand() % 100;
        ItemData* dropData = nullptr;

        if (roll < 50)
            dropData = &data->one;
        else if (roll < 80)
            dropData = &data->two;
        else
            dropData = &data->three;

        Spawn(x, y, dropData);
    }
}

void ItemSystem::ApplyItemToPlayer(Player& player, Item& item, EffectSystem& effectSystem)
{
    if (!item.data) return;

    float headX = player.starship->rect.x + player.starship->rect.w / 2.0f;
    float headY = player.starship->rect.y;

    if (item.type == ITEM_CHANGE_BULLET) {
        player.changeWeaponType((int)item.data->value, item.data->duration);
        effectSystem.AddItemNotif(headX, headY, 6, 1.5f);
    }
    else if (item.type == ITEM_HEAL) {
        player.heal(item.data->value);
        effectSystem.AddItemNotif(headX, headY, 4, 1.5f);
    }
    else if (item.type == ITEM_SHIELD) {
        player.activateShield(item.data->duration, item.data->value);
        effectSystem.AddItemNotif(headX, headY, 5, 1.5f);
    }

    item.active = false;
}

void ItemSystem::Update(float dt)
{
    for (auto& item : items) {
        if (item.active && item.data) {
            item.rect.y += item.data->speed * dt;
            if (item.rect.y > 800) {
                item.active = false;
            }
        }
    }
}

void ItemSystem::Render(SDL_Renderer* renderer)
{
    for (auto& item : items) {
        if (item.active && item.data && item.data->texture) {
            SDL_RenderCopyF(renderer, item.data->texture, nullptr, &item.rect);
        }
    }
}

void ItemSystem::Reset()
{
    for (auto& item : items) {
        item.active = false;
    }
}
