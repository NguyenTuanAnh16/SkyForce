#pragma once
#include <SDL.h>
#include <vector>
#include "enemiesbullet.h" // Include đạn vào để hàm shoot() nhận diện được

// (Ví dụ bạn đang có enum này, nếu có thì giữ nguyên)
enum EnemyType { NORMAL_ENEMIES, BOSS_ENEMIES };

class Enemies {
public:
    float x, y;
    float startX;
    float width, height;
    float speed;
    float waveOffset;
    bool isAlive;
    EnemyType type;

    // Các hàm của quái
    Enemies(float startX, float startY, EnemyType type);
    void update(float deltaTime, float playerX, float playerY);
    void render(SDL_Renderer* renderer, SDL_Texture* texture);
    void shoot(std::vector<Bullet>& enemyBullets);
};
