#include "ItemSystem.h"

void ItemSystem::Init(ItemRes* res, ItemDataBase* dataBase)
{
    this->res = res;
    this->dataBase = dataBase;
    items.resize(20);
}

void ItemSystem::Spawn(float x, float y, int type)
{
    if (!dataBase) return;
    ItemData* itemData = dataBase->GetItemData(type);
    if (!itemData) return;

    for (auto& item : items) {
        if (!item.active) {
            item.active = true;
            item.type = type;
            item.data = itemData;
            item.rect = { x, y, itemData->rect.w, itemData->rect.h };
            return;
        }
    }
}

void ItemSystem::TryDropItem(float x, float y)
{
    if (rand() % 100 < 60) {
        int roll = rand() % 100;
        int itemType = ITEM_CHANGE_BULLET;

        if (roll < 50)
            itemType = ITEM_CHANGE_BULLET;
        else if (roll < 80)
            itemType = ITEM_HEAL;
        else
            itemType = ITEM_SHIELD;

        Spawn(x, y, itemType);
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
            item.rect.y = item.rect.y + item.data->speed * dt;
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
