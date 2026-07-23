#include "enemiesbullet.h"

Bullet::Bullet(float startX, float startY, float velX, float velY) {
    x = startX;
    y = startY;
    vx = velX;
    vy = velY;
    active = true;
}
