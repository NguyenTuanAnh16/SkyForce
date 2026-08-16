#include "ItemSystem.h"


void ItemSystem::Init(ItemDataBase* data)
{
      this->data = data;
      items.resize(100);
}

void ItemSystem::RandomDrop(float x, float y)
{
    int random = rand() % 100;

  //   70% không rơi
      if (random >= 30)
      return;

    random = rand() % 100;

    ItemType type;

    if (random < 40)
        type = ItemType::HP;
    else if (random < 70)
        type = ItemType::POWER;
    else
        type = ItemType::SHIELD;

    Spawn(x, y, type);
}


void ItemSystem::Spawn(float x, float y,ItemType type)
{
    for (auto& item : items)
    {
        if (!item.active)
        {
            item.active = true;
            item.data = data->Get(type);
            item.rect.x = x;
            item.rect.y = y;
            item.rect.w = item.data->width;
            item.rect.h = item.data->height;
            return;
        }
    }
}


void ItemSystem::ApplyItem(Player& player,Item& item, EffectSystem& effectSystem)
{
 if (item.data == &data->hp)
{
    timeHp = item.data->time;
    effectSystem.AddItem(EffectType::HP,player.starship->rect.w * 0.6);
}
else if (item.data == &data->power)
{
    timePower = item.data->time;
    player.starship->weaponType = WeaponType::PLAYER_TWO;
}
else if (item.data == &data->shield)
{
    timeShield = item.data->time;
    player.shieldActive = true;
    player.shieldValue = item.data->value;
    effectSystem.AddItem(EffectType::SHIELD,player.starship->rect.w * 1.2);
}

}


void ItemSystem::UpdateItem(float deltaTime, Player& player, EffectSystem& effectSystem)
{
    // HP
    if (timeHp > 0)
    {  timeHp -= deltaTime;
       player.starship->hpNow = player.starship->hpNow + data->hp.value * deltaTime;
       if(player.starship->hpNow > player.starship->hpMax)   player.starship->hpNow = player.starship->hpMax;
       if(timeHp < 0)  effectSystem.ClearItem(EffectType::HP);
    }

    // POWER
    if (timePower > 0)
    {
        timePower -= deltaTime;
        if (timePower <= 0)  player.starship->weaponType =  player.starship->defaultWeaponType;

    }

    // SHIELD
    if (timeShield > 0)
    {
        timeShield -= deltaTime;
        if (timeShield <= 0 || player.shieldValue <= 0) {player.shieldActive = false;  effectSystem.ClearItem(EffectType::SHIELD);}
    }
}



void ItemSystem::Update(float deltaTime)
{
    for (auto& item : items)
    {
        if (item.active)
        {
            item.rect.y = item.rect.y + item.data->speed * deltaTime;
            if(item.rect.y > 810) item.active = false;
        }
    }
}

void  ItemSystem::Reset()
{
     for (auto& item : items) item.active = false;
}


void ItemSystem::Render(SDL_Renderer* renderer)
{
    for (auto& item : items)
    {
        if(item.active)   SDL_RenderCopyF(renderer,item.data->texture,nullptr,&item.rect);
    }
}


