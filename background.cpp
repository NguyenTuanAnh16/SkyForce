#include "background.h"
#include <SDL_image.h>
#include <iostream>

Background::Background(SDL_Renderer* renderer, const std::string& filePath, int screenWidth, int screenHeight, float speed) {
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    this->speed = speed;
    this->y1 = 0.0f;
    this->y2 = static_cast<float>(-screenHeight);

    texture = IMG_LoadTexture(renderer, filePath.c_str());
    if (!texture) {
            std::cout << "Loi load background: " << IMG_GetError() << std::endl;
}
}

Background::~Background() {
    if (texture) {
        SDL_DestroyTexture(texture);
    }
}

void Background::update(float deltaTime) {
    y1 += speed * deltaTime;
    y2 += speed * deltaTime;

    if (y1 >= screenHeight) {
        y1 = y2 - screenHeight;
    }
    if (y2 >= screenHeight) {
        y2 = y1 - screenHeight;
    }
}

void Background::render(SDL_Renderer* renderer) {
    if (!texture) return;

    SDL_Rect rect1 = { 0, static_cast<int>(y1), screenWidth, screenHeight };
    SDL_Rect rect2 = { 0, static_cast<int>(y2), screenWidth, screenHeight };

    SDL_RenderCopy(renderer, texture, nullptr, &rect1);
    SDL_RenderCopy(renderer, texture, nullptr, &rect2);
}
