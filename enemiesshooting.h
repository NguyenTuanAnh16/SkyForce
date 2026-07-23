#pragma once
#include <vector>
#include "enemiesbullet.h"

class Shooting {
public:
    // Hàm xử lý bắn đạn thường (rơi thẳng xuống)
    static void normalShoot(float x, float y, float width, float height, std::vector<Bullet>& enemyBullets);

    // (Tương lai) Bạn có thể thêm hàm cho Boss bắn chùm 3 tia ở đây
    // static void bossSpreadShoot(float x, float y, float width, float height, std::vector<Bullet>& enemyBullets);
};
