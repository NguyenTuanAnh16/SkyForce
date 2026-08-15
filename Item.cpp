#include "Item.h"

void ItemDataBase::Init(ItemRes& res)
{
// hp
     hp.texture = res.hp;
     hp.speed = 10;
     hp.time = 0;
     hp.value = 20;

// dan
     power.texture = res.power;
     power.speed = 10;
     power.time = 10;
     power.value = 3;

// khien
     shield.texture = res.shield;
     shield.speed = 10;
     shield.time = 10;
     shield.value = 20;
}
