#include "Game.h"
#include "Config.h"
#include <string>
void Game::Init(){
  // tao cua so
  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow(
        "Game Ban May Bay",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
    );
    // Tạo renderer để vẽ
    renderer = SDL_CreateRenderer(
    window,
    -1,
    SDL_RENDERER_ACCELERATED
    );

    SDL_RenderSetLogicalSize(
    renderer,
    SCREEN_WIDTH,
    SCREEN_HEIGHT
    );

    // tai nguyen
    resource.Load(renderer);

    // nen
    background.Init(resource.backGround, resource.nibiru, resource.asteroid);
    // may bay
    starship.Init(resource.starship);
    // dan
    bulletplayer.Init(resource.bulletplayer);
}


void Game::Run()
{
    SDL_Event event;
    while (running){
           frameStart = SDL_GetTicks();
           while(SDL_PollEvent(&event)){
                 if(event.type == SDL_QUIT){
                    running = false;
                    }
                 }
     Update();
     Render();
     capFPS();
     deltaTime =(SDL_GetTicks() - frameStart)/1000.0f;
    }

}


void Game::Render(){
SDL_RenderClear(renderer);
background.Render(renderer);
starship.Render(renderer);
bulletplayer.Render(renderer);
SDL_RenderPresent(renderer);

}


void Game::Update(){
 background.Update(deltaTime);
 starship.Update(deltaTime);
 bulletplayer.Update(deltaTime);
}

void Game::capFPS()
{
    frameDelay = 1000/FPS;
    frameTime = SDL_GetTicks() - frameStart;
    if (frameTime < frameDelay){
            SDL_Delay(frameDelay - frameTime);
            frameTime = SDL_GetTicks() - frameStart;
            }
    if (frameTime > 0)
    {std::string title = "SkyForce - FPS: " + std::to_string(1000.0f / frameTime);
    SDL_SetWindowTitle(window, title.c_str());}
}

void Game::Clean()
{
  resource.Free();
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
