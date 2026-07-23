#include "enemiesshooting.h"

void Shooting::normalShoot(float x, float y, float width, float height, std::vector<Bullet>& enemyBullets) {
    float bulletX = x + width / 2.0f - 7.5f;
    float bulletY = y + height;

    enemyBullets.push_back(Bullet(bulletX, bulletY, 0.0f, 10.0f));
}
