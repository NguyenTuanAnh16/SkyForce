#include "enemies.h"
#include <vector>
#include <cstdlib>
#include <iostream>
#include <SDL_image.h>
#include <algorithm>

class GameManager {
private:
    std::vector<Enemies> flock;
    std::vector<Bullet> enemyBullets;
    float shootTimer = 0.0f;

    SDL_Texture* enemiesTexture = nullptr;
    SDL_Texture* bulletTexture = nullptr;

public:
    void initLevel(SDL_Renderer* renderer) {
        enemiesTexture = IMG_LoadTexture(renderer, "D:/BTL ltnc/Gamebtl/bin/Debug/miniboss1.png");
        if (!enemiesTexture) {
            std::cout << "Loi load enemies: " << IMG_GetError() << std::endl;
}
        bulletTexture = IMG_LoadTexture(renderer, "D:/BTL ltnc/image/bulletblue1.png");
        if (!bulletTexture) {
            std::cout << "Loi load dan: " << IMG_GetError() << std::endl;
        }

        for (int row = 0; row < 4; ++row) {
            for (int col = 0; col < 10; ++col) {
                float px = 150.0f + col * 120.0f;
                float py = -300.0f + row * 80.0f;
                flock.push_back(Enemies(px, py, NORMAL_ENEMIES));
            }
        }
    }

    void updateGame(float deltaTime, float playerX, float playerY) {
        for (auto& enemies : flock) {
            enemies.update(deltaTime, playerX, playerY);
        }

        for (auto& b : enemyBullets) {
            if (b.active) {
                b.x += b.vx * deltaTime * 160.0f;
                b.y += b.vy * deltaTime * 160.0f;

                if (b.y > 900.0f) {
                    b.active = false;
                }
            }
        }

        enemyBullets.erase(std::remove_if(enemyBullets.begin(), enemyBullets.end(),
            [](const Bullet& b) { return !b.active; }), enemyBullets.end());

        shootTimer += deltaTime;
        if (shootTimer > 0.2f && !flock.empty()) {
            for(int i = 0; i < 3; i++) {
            int randomIndex = rand() % flock.size();
            if (flock[randomIndex].isAlive) {
                flock[randomIndex].shoot(enemyBullets);
            }
            }
            shootTimer = 0.0f;
        }
    }

    void renderGame(SDL_Renderer* renderer) {
        if (enemiesTexture == nullptr) {
            std::cout << "Loi: enemiesTexture dang la nullptr, khong thể ve quai!" << std::endl;
            return;
        }

        for (auto& enemies : flock) {
            enemies.render(renderer, enemiesTexture);
        }

        if (bulletTexture != nullptr) {
            for (auto& b : enemyBullets) {
                if (b.active) {
                    SDL_Rect bulletRect = { static_cast<int>(b.x), static_cast<int>(b.y), 20, 45 };
                    SDL_RenderCopy(renderer, bulletTexture, nullptr, &bulletRect);
                }
            }
        }
    }


    ~GameManager() {
        if (enemiesTexture) {
            SDL_DestroyTexture(enemiesTexture);
        }
        if (bulletTexture) SDL_DestroyTexture(bulletTexture);
    }
};
