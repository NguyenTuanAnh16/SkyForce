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
    two.value = 80.0f;    // Hồi HP
    two.duration = 0.0f;

    // 3. Item Khiên
    three.texture = res.shield;
    three.type = ITEM_SHIELD;
    three.speed = 150.0f;
    three.rect = { 0, 0, 55.0f, 45.0f };
    three.value = 350.0f;  // HP Khiên
    three.duration = 8.0f; // Tồn tại 8 giây
}
