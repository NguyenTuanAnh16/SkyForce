#include "Item.h"

void ItemDataBase::Init(ItemRes& res)
{
// hp
     hp.texture = res.hp;
     hp.width = 35;
     hp.height = 39;
     hp.speed = 300;
     hp.time = 3;
     hp.value = 30;

// dan
     power.texture = res.power;
     power.width = 35;
     power.height = 37;
     power.speed = 300;
     power.time = 3;

// khien
     shield.texture = res.shield;
     shield.width = 35;
     shield.height = 39;
     shield.speed = 300;
     shield.time = 3;
     shield.value = 100;
}


ItemData* ItemDataBase::Get(ItemType type)
{
    if (type == ItemType::HP)
        return &hp;

    if (type == ItemType::POWER)
        return &power;

    if (type == ItemType::SHIELD)
        return &shield;

    return nullptr;
}
