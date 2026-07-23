#include "enemies.h"
#include "enemiesmovement.h"
#include "enemiesshooting.h"

Enemies::Enemies(float startX, float startY, EnemyType type) {
    this->x = startX;
    this->y = startY;
    this->startX = startX;
    this->type = type;
    this->width = 40.0f;
    this->height = 40.0f;

    // Tốc độ di chuyển cơ bản
    this->speed = 2.0f;
    this->waveOffset = 0.0f;
    this->isAlive = true;
}

void Enemies::update(float deltaTime, float playerX, float playerY) {
    if (!isAlive) return;

    if (type == NORMAL_ENEMIES) {
        Movement::updateNormalEnemy(x, y, startX, waveOffset, speed, deltaTime, 900.0f);
    }
    else if (type == BOSS_ENEMIES) {
        Movement::updateBossEnemy(x, playerX, speed);
    }
}

void Enemies::render(SDL_Renderer* renderer, SDL_Texture* texture) {
    if (!isAlive) return;

    SDL_Rect destRect = {
        static_cast<int>(x),
        static_cast<int>(y),
        static_cast<int>(width),
        static_cast<int>(height)
    };

    SDL_RenderCopy(renderer, texture, nullptr, &destRect);
}

void Enemies::shoot(std::vector<Bullet>& enemyBullets) {
    if (!isAlive) return;

    if (type == NORMAL_ENEMIES) {
        Shooting::normalShoot(x, y, width, height, enemyBullets);
    }
    else if (type == BOSS_ENEMIES) {
        // Để dành chỗ này cho hàm bắn đạn chùm/tia laze,... của Boss sau này
    }
}
