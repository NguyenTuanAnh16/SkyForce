#include "Game.h"
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
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );
    // cho phep lam mo
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    SDL_RenderSetLogicalSize(
    renderer,
    SCREEN_WIDTH,
    SCREEN_HEIGHT
    );

    // tai nguyen
    resource.Load(renderer);

    // hieu ung
    effect.Init(resource.effect);
    effectSystem.Init(&effect);

    // menu
    menu.Init(resource.menu);


    // nen
    background.Init(resource.background);

    // may bay
    starship.Init(resource.starship);

    // doi may bay
    selectShip.Init(resource.menu,&starship);

    player.ChangeStarship(selectShip,starship,effectSystem);

    // dan
    //weapon.Init(resource.weapon);
    weapon.Init(resource.weapon);
    weaponSystem.Init(100,&weapon);
    // dich
    enemy.Init(resource.enemy);
    enemysystem.Init(100,&enemy);


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
                 if(state == GameState::MENU)
                    menu.HandleEvent(event,state);
                 else if(state == GameState::SELECT_SHIP)
                 {
                      selectShip.HandleEvent(event,state);
                      if(state == GameState::PLAYING) player.ChangeStarship(selectShip,starship,effectSystem);
                 }
                 }
     Update();
     Render();
     capFPS();
     deltaTime =(SDL_GetTicks() - frameStart)/1000.0f;
    }

}

void Game::Render()
{
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderClear(renderer);

    if(state == GameState::MENU)
    {
        menu.Render(renderer);
    }
    else if(state == GameState::PLAYING)
    {
        background.Render(renderer);
        player.Render(renderer);
        weaponSystem.Render(renderer);
        enemysystem.Render(renderer);
        effectSystem.Render(renderer);
    }
    else if(state == GameState::SELECT_SHIP)
    {
        selectShip.Render(renderer);
    }

    SDL_RenderPresent(renderer);
}

void Game::Update()
{
    if(state == GameState::MENU)
    {
        menu.Update(deltaTime);
    }

    else if(state == GameState::PLAYING)
    {
        background.Update(deltaTime);

        player.Update(deltaTime, weaponSystem, effectSystem);

        weaponSystem.Update(deltaTime);

        spawnmanager.Update(deltaTime,40,5,enemysystem);

        enemysystem.Update(deltaTime,&weaponSystem);

        effectSystem.Update(deltaTime);

        collisionSystem.Update(player,enemysystem,weaponSystem,effectSystem);
    }

    else if(state == GameState::SELECT_SHIP)
    {
        selectShip.Update(deltaTime);
    }
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
