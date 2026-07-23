#include <iostream>
#include "Game.h"
#include "background.h"
#include "enemies.h"
#include "level.cpp"
#include <SDL_image.h>

using namespace std;

int main(int argc, char* argv[])
{
    // Khởi tạo SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "SDL init error: " << SDL_GetError() << endl;
        return -1;
    }

    // Khởi tạo SDL_image
    if (!(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) & (IMG_INIT_JPG | IMG_INIT_PNG))) {
        cout << "IMG_Init error: " << IMG_GetError() << endl;
        SDL_Quit();
        return -1;
    }

    int winWidth = 1600;
    int winHeight = 800;

    SDL_Window* window = SDL_CreateWindow(
        "Game Ban May Bay",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        winWidth, winHeight,
        SDL_WINDOW_SHOWN
    );

    if (window == NULL)
    {
        cout << "Create window error: " << SDL_GetError() << endl;
        IMG_Quit();
        SDL_Quit();
        return -1;
    }

    // Tạo renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if (renderer == NULL) {
        cout << "Create renderer error: " << SDL_GetError() << endl;
        SDL_DestroyWindow(window);
        IMG_Quit();
        SDL_Quit();
        return -1;
    }

    bool running = true;
    SDL_Event event;

    Background spaceBg(renderer, "D:/BTL ltnc/Gamebtl/bin/Debug/background.jpg", 1600, 800, 50.0f);

    GameManager enemyManager;
    enemyManager.initLevel(renderer);

    Uint32 lastTime = SDL_GetTicks();

    while (running)
    {
        Uint32 currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }

        spaceBg.update(deltaTime);
        enemyManager.updateGame(deltaTime, 400.0f, 700.0f);

        SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
        SDL_RenderClear(renderer);
        spaceBg.render(renderer);
        enemyManager.renderGame(renderer);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}
