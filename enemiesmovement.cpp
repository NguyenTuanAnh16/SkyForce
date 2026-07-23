#include "enemiesmovement.h"
#include <cmath>

void Movement::updateNormalEnemy(float& x, float& y, float startX, float& waveOffset, float speed, float deltaTime, float screenHeight) {
    waveOffset += speed * deltaTime;
    x = startX + sin(waveOffset) * 80.0f;
    y += (speed * 30.0f) * deltaTime;
    if (y > screenHeight + 50.0f) {
        y = -50.0f;
    }
}

void Movement::updateBossEnemy(float& x, float playerX, float speed) {
    if (x < playerX) {
        x += speed * 1.5f;
    } else if (x > playerX) {
        x -= speed * 1.5f;
    }
}
