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
    SDL_RENDERER_ACCELERATED// | SDL_RENDERER_PRESENTVSYNC0210
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
    backGroundSystem.Init(&background);

    // may bay
    starship.Init(resource.starship);

    // player
    player.Init(resource.player);

    // doi may bay
    selectShip.Init(resource.menu,&starship);

    player.ChangeStarship(selectShip,starship,effectSystem);

    // doi man
    selectlevel.Init(resource.menu);

    // pause
    pause.Init(resource.menu);

    // dan
    //weapon.Init(resource.weapon);
    weapon.Init(resource.weapon);
    weaponSystem.Init(100,&weapon);
    // dich
    enemy.Init(resource.enemy);
    enemysystem.Init(100,&enemy);
    spawnmanager.Init(&enemysystem);

}

void Game::InitLevel()
{
//  LevelData.
}

void Game::Run()
{
    SDL_Event event;
    while (running){
           frameStart = SDL_GetTicks();
           while(SDL_PollEvent(&event)){
                 if(event.type == SDL_QUIT || state == GameState::EXIT){
                    running = false;
                    }
                 if(state == GameState::MENU)
                    menu.HandleEvent(event,state);
                 else if(state == GameState::SELECT_SHIP)
                 {
                      selectShip.HandleEvent(event,state);
                      if(state == GameState::SELECT_LEVEL) player.ChangeStarship(selectShip,starship,effectSystem);
                 }
                 else if(state == GameState::SELECT_LEVEL)
                 {
                     selectlevel.HandleEvent(event,state);
                      if(state == GameState::PLAYING){
                            backGroundSystem.Set(selectlevel.level);
                            spawnmanager.Set(selectlevel.level);
                      }
                 }
                 else if(state == GameState::PLAYING)
                 {
                     player.HandleEvent(event,state);
                 }
                 else if(state == GameState::PAUSE)
                 {
                     pause.HandleEvent(event,state);
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
        backGroundSystem.Render(renderer);
        player.Render(renderer);
        weaponSystem.Render(renderer);
        enemysystem.Render(renderer);
        effectSystem.Render(renderer);
    }
    else if(state == GameState::SELECT_SHIP)
    {
        selectShip.Render(renderer);
    }
    else if(state == GameState::SELECT_LEVEL)
    {
        selectlevel.Render(renderer);
    }
    else if(state == GameState::PAUSE)
    {
        backGroundSystem.Render(renderer);
        player.Render(renderer);
        weaponSystem.Render(renderer);
        enemysystem.Render(renderer);
        effectSystem.Render(renderer);
        pause.Render(renderer);
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
        backGroundSystem.Update(deltaTime);

        player.Update(deltaTime, weaponSystem, effectSystem);

        weaponSystem.Update(deltaTime);

        spawnmanager.Update(deltaTime);

        enemysystem.Update(deltaTime,&weaponSystem);

        effectSystem.Update(deltaTime);

        collisionSystem.Update(player,enemysystem,weaponSystem,effectSystem);
    }

    else if(state == GameState::SELECT_SHIP)
    {
        selectShip.Update(deltaTime);
    }
    else if(state == GameState::SELECT_LEVEL)
    {
        selectlevel.Update(deltaTime);
    }
    else if(state == GameState::PAUSE)
    {
        pause.Update(deltaTime);
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
