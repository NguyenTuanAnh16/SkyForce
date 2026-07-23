#pragma once
#include <SDL.h>

struct Bullet {
    float x, y;
    float vx, vy;
    bool active;

    // Định nghĩa hàm khởi tạo (Constructor) cho đạn để dễ tái sử dụng
    Bullet(float startX, float startY, float velX, float velY);

    // (Sau này bạn có thể thêm hàm updateBullet() hoặc renderBullet() vào đây nếu muốn)
};
