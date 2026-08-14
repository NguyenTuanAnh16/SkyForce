#include "Item.h"

void ItemDataBase::Init(ItemRes& res)
{
    // 1. Item Đổi đạn
    one.texture = res.changeBullet;
    one.type = ITEM_CHANGE_BULLET;
    one.speed = 150.0f;
    one.rect = { 0, 0, 55.0f, 45.0f };
    one.value = 3.0f;     // Bắn loại đạn số 3
    one.duration = 5.0f;  // Tác dụng 5 giây

    // 2. Item Hồi máu
    two.texture = res.heal;
    two.type = ITEM_HEAL;
    two.speed = 150.0f;
    two.rect = { 0, 0, 55.0f, 50.0f };
    two.value = 80.0f;    // Hồi 50 HP
    two.duration = 0.0f;

    // 3. Item Khiên
    three.texture = res.shield;
    three.type = ITEM_SHIELD;
    three.speed = 150.0f;
    three.rect = { 0, 0, 55.0f, 45.0f };
    three.value = 350.0f;  // Khiên có 350 HP
    three.duration = 8.0f; // Tồn tại 8 giây
}

ItemData* ItemDataBase::GetItemData(int type)
{
    if (type == ITEM_CHANGE_BULLET) return &one;
    if (type == ITEM_HEAL)          return &two;
    if (type == ITEM_SHIELD)        return &three;
    return nullptr;
}
