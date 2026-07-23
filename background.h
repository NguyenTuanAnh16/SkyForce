#pragma once
#include <SDL.h>
#include <string>

class Background {
private:
    SDL_Texture* texture;
    float y1, y2;
    float speed;
    int screenWidth;
    int screenHeight;

public:
    Background(SDL_Renderer* renderer, const std::string& filePath, int screenWidth, int screenHeight, float speed);
    ~Background();

    void update(float deltaTime);
    void render(SDL_Renderer* renderer);
};
