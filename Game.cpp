#include "Game.h"
#include <string>

void Game::Init(){
  // tao cua so
  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow( "Game Ban May Bay",
                            SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            SCREEN_WIDTH,
                            SCREEN_HEIGHT,
                            SDL_WINDOW_SHOWN);

    // Tạo renderer để vẽ
    renderer = SDL_CreateRenderer( window,
                                   -1,
                                   SDL_RENDERER_ACCELERATED
                                  );

    // cho phep lam mo
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    // tao kenh nhac
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);


    // tai nguyen
    resource.Load(renderer);

     // player
    starship.Init(resource.starship);
    player.Init(resource.player);


    // menu
    menu.Init(resource.menu);

    selectShip.Init(resource.menu,&starship);
    player.ChangeStarship(selectShip,starship,effectSystem);

    selectlevel.Init(resource.menu);
    setting.Init(resource.menu);
    gameOverlay.Init(resource.menu);

    // nen
    background.Init(resource.background);
    backGroundSystem.Init(&background);

     // dich
    enemy.Init(resource.enemy);
    enemysystem.Init(&enemy);
    spawnmanager.Init(&enemysystem);

    // dan
    weapon.Init(resource.weapon);
    weaponSystem.Init(&weapon);

    // hieu ung
    effect.Init(resource.effect);
    effectSystem.Init(&effect);

     // item;
    item.Init(resource.item);
    itemSystem.Init(&item);

    // nhac
    music.Init(resource.music);
    music.PlayMusic();


    deltaTime = 0.0f;
    resultTimer = 0.0f;
    waitingResult = false;

    running = true;
}

void Game::InitLevel()
{
  backGroundSystem.Set(selectlevel.level);
  player.Reset();
  enemysystem.Reset();
  spawnmanager.Set(selectlevel.level);
  weaponSystem.Reset();
  effectSystem.Reset();
  selectlevel.SetTargetScore();
}

void Game::Run()
{
    SDL_Event event;
    while (running){
           frameStart = SDL_GetTicks();
           while(SDL_PollEvent(&event)){
                 if(event.type == SDL_QUIT || state == GameState::EXIT)  running = false;
                 else if(state == GameState::MENU)
                        {  menu.HandleEvent(event,state);
                           if(state != GameState::MENU) music.PlayClick();
                        }
                 else if(state == GameState::SELECT_SHIP)
                        {
                            selectShip.HandleEvent(event,state,music);
                            if(state != GameState::SELECT_SHIP)
                              {  player.ChangeStarship(selectShip,starship,effectSystem);
                                  music.PlayClick();}
                        }
                 else if(state == GameState::SELECT_LEVEL)
                        {
                            selectlevel.HandleEvent(event,state);
                            if(state != GameState::SELECT_LEVEL) music.PlayClick();
                            if(state == GameState::PLAYING)
                                { InitLevel();
                                  player.ChangeStarship(selectShip,starship,effectSystem);}
                        }
                 else if(state == GameState::SETTING)
                    {
                        setting.HandleEvent(event,state, music);
                        if(state != GameState::SETTING) music.PlayClick();
                    }
                 else if(state == GameState::PLAYING)
                        {
                            player.HandleEvent(event,state);
                            if(state != GameState::PLAYING) music.PlayClick();
                        }
                 else if(state == GameState::PAUSE)
                        { gameOverlay.HandleEvent(event,state);
                          if(state != GameState::PAUSE) music.PlayClick();
                        }
                 else if(state == GameState::WIN)
                        {
                            gameOverlay.HandleEvent(event,state);
                            if(state != GameState::WIN) music.PlayClick();
                            if(state == GameState::PLAYING)
                              {   selectlevel.level ++; if(selectlevel.level++ >=3) selectlevel.level = 3;
                                  InitLevel();
                                  player.ChangeStarship(selectShip,starship,effectSystem);
                              }
                        }
                else if(state == GameState::LOST)
                {
                    gameOverlay.HandleEvent(event,state);
                    if(state != GameState::LOST) music.PlayClick();
                    if(state == GameState::PLAYING)
                      {  InitLevel();
                         player.ChangeStarship(selectShip,starship,effectSystem);
                      }
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
    else if(state == GameState::SELECT_SHIP)
        {
            selectShip.Render(renderer);
        }
    else if(state == GameState::SELECT_LEVEL)
        {
            selectlevel.Render(renderer);
        }

    else if(state == GameState::SETTING) setting.Render(renderer);
    else if(state == GameState::PLAYING)
        {
            backGroundSystem.Render(renderer);
            player.Render(renderer);
            weaponSystem.Render(renderer);
            enemysystem.Render(renderer);
            effectSystem.Render(renderer);
            itemSystem.Render(renderer);
        }
    else if(state == GameState::PAUSE || state == GameState::WIN || state == GameState::LOST)
        {
            backGroundSystem.Render(renderer);
            player.Render(renderer);
            weaponSystem.Render(renderer);
            enemysystem.Render(renderer);
            effectSystem.Render(renderer);
            itemSystem.Render(renderer);
            gameOverlay.Render(renderer,state);
        }
    SDL_RenderPresent(renderer);
}


void Game::Update()
{
    if(state == GameState::MENU)
        {
            menu.Update(deltaTime);
        }
    else if(state == GameState::SELECT_SHIP)
        {
            selectShip.Update(deltaTime);
        }
    else if(state == GameState::SELECT_LEVEL)
        {
            selectlevel.Update(deltaTime);
        }
    else if(state == GameState::SETTING) setting.Update(deltaTime);
    else if(state == GameState::PLAYING)
        {
            backGroundSystem.Update(deltaTime);
            player.Update(deltaTime, weaponSystem, effectSystem);
            spawnmanager.Update(deltaTime);
            enemysystem.Update(deltaTime,&weaponSystem);
            weaponSystem.Update(deltaTime);
            collisionSystem.Update(player,enemysystem,weaponSystem,effectSystem,itemSystem,music);
            effectSystem.Update(deltaTime);
            itemSystem.Update(deltaTime);
            itemSystem.UpdateItem(deltaTime,player,effectSystem);

     if((player.score >= selectlevel.targetScore || player.starship->hpNow <= 0) && !waitingResult)
        {
            waitingResult = true;
            resultTimer = 0.0f;
        }
    if(waitingResult)
        {
            resultTimer += deltaTime;
            if(resultTimer >= 1)
                {
                    if(player.starship->hpNow <= 0){state = GameState::LOST; music.PlayLost();}
                    else {state = GameState::WIN;  music.PlayWin();}
                    waitingResult = false;
                }
        }
        }
     else if(state == GameState::PAUSE || state == GameState::WIN || state == GameState::LOST)
        {
            gameOverlay.Update(deltaTime,state);
        }

}


void Game::capFPS()
{
    frameDelay = 1000/setting.fpsValue;
    frameTime = SDL_GetTicks() - frameStart;
    if (frameTime < frameDelay)
        {
            SDL_Delay(frameDelay - frameTime);
            frameTime = SDL_GetTicks() - frameStart;
        }
    if (frameTime > 0)
        {
            std::string title = "SkyForce - FPS: " + std::to_string(1000.0f / frameTime);
            SDL_SetWindowTitle(window, title.c_str());
        }
}


void Game::Clean()
{
  resource.Free();
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

