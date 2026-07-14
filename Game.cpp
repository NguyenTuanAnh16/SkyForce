#include <iostream>
#include "Game.h"
using namespace std;



int main(int argc, char* argv[])
{
    // Khởi tạo SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "SDL init error: " << SDL_GetError();
        return -1;
    }

    // Tạo cửa sổ
     window = SDL_CreateWindow(
        "Game Ban May Bay",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH,
        HEIGHT,
        SDL_WINDOW_SHOWN
    );

    if (window == NULL)
    {
        cout << "Create window error: " << SDL_GetError();
        return -1;
    }

    // Tạo renderer để vẽ
    SDL_Renderer* renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED
    );

    bool running = true;
    SDL_Event event;

    while (running)
    {
        // Xử lý sự kiện
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }

        // Xóa màn hình
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);


        // Vẽ ở đây


        // Hiển thị
        SDL_RenderPresent(renderer);
    }


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
