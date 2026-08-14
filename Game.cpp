#include "Game.h"
#include <string>
#include <ctime>

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

    // cho phep lam mo
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    SDL_RenderSetLogicalSize(
        renderer,
        SCREEN_WIDTH,
        SCREEN_HEIGHT
    );

    // tao kenh nhac
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

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

    // setting
    setting.Init(resource.menu);

    // pause
    pause.Init(resource.menu);

    // dan
    weapon.Init(resource.weapon);
    weaponSystem.Init(100,&weapon);

    // dich
    enemy.Init(resource.enemy);
    enemysystem.Init(100,&enemy);
    spawnmanager.Init(&enemysystem);

    // item 
    itemDataBase.Init(resource.item);
    itemSystem.Init(&resource.item, &itemDataBase);

    // nhac
    music.Init(resource.music);
    music.PlayMusic();

    srand(time(NULL));
}

void Game::InitLevel()
{
    backGroundSystem.Set(selectlevel.level);
    spawnmanager.Set(selectlevel.level);
    enemysystem.Reset();
    effectSystem.Reset();
    weaponSystem.Reset();
    player.Reset();
    itemSystem.Reset();
    selectlevel.SetTargetScore();
}

void Game::Run()
{
    SDL_Event event;
    while (running){
        frameStart = SDL_GetTicks();
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT || state == GameState::EXIT)
                running = false;
            else if(state == GameState::MENU)
            {
                menu.HandleEvent(event,state);
                if(state != GameState::MENU) music.PlayClick();
            }
            else if(state == GameState::SELECT_SHIP)
            {
                selectShip.HandleEvent(event,state,music);
                if(state != GameState::SELECT_SHIP)
                {
                    player.ChangeStarship(selectShip,starship,effectSystem);
                    music.PlayClick();
                }
            }
            else if(state == GameState::SELECT_LEVEL)
            {
                selectlevel.HandleEvent(event,state);
                if(state != GameState::SELECT_LEVEL) music.PlayClick();
                if(state == GameState::PLAYING)
                {
                    InitLevel();
                    player.ChangeStarship(selectShip,starship,effectSystem);
                }
            }
            else if(state == GameState::PLAYING)
            {
                player.HandleEvent(event,state);
                if(state != GameState::PLAYING) music.PlayClick();
            }
            else if(state == GameState::PAUSE)
            {
                pause.HandleEvent(event,state);
                if(state != GameState::PAUSE) music.PlayClick();
            }
            else if(state == GameState::WIN)
            {
                pause.HandleEvent(event,state);
                if(state != GameState::WIN) music.PlayClick();
                if(state == GameState::PLAYING)
                {
                    selectlevel.level ++; if(selectlevel.level >= 3) selectlevel.level = 3;
                    InitLevel();
                    player.ChangeStarship(selectShip,starship,effectSystem);
                }
            }
            else if(state == GameState::LOST)
            {
                pause.HandleEvent(event,state);
                if(state != GameState::LOST) music.PlayClick();
                if(state == GameState::PLAYING)
                {
                    InitLevel();
                    player.ChangeStarship(selectShip,starship,effectSystem);
                }
            }
            else if(state == GameState::SETTING)
            {
                setting.HandleEvent(event,state, music);
                if(state != GameState::SETTING) music.PlayClick();
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
        itemSystem.Render(renderer);
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
    else if(state == GameState::PAUSE || state == GameState::WIN || state == GameState::LOST)
    {
        backGroundSystem.Render(renderer);
        itemSystem.Render(renderer);
        player.Render(renderer);
        weaponSystem.Render(renderer);
        enemysystem.Render(renderer);
        effectSystem.Render(renderer);
        pause.Render(renderer,state);
    }
    else if(state == GameState::SETTING)
    {
        setting.Render(renderer);
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
        itemSystem.Update(deltaTime);
        effectSystem.Update(deltaTime);


        collisionSystem.Update(player, enemysystem, weaponSystem, effectSystem, itemSystem, music);

        if (player.starship != nullptr) {
            effectSystem.FollowNotif(*player.starship);
            effectSystem.FollowShield(*player.starship, player.hasShield);

        }

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
                if(player.starship->hpNow <= 0){
                    state = GameState::LOST;
                    music.PlayLost();
                }
                else {
                    state = GameState::WIN;
                    music.PlayWin();
                }
                waitingResult = false;
            }
        }
    }
    else if(state == GameState::SELECT_SHIP)
    {
        selectShip.Update(deltaTime);
    }
    else if(state == GameState::SELECT_LEVEL)
    {
        selectlevel.Update(deltaTime);
    }
    else if(state == GameState::PAUSE || state == GameState::WIN || state == GameState::LOST)
    {
        pause.Update(deltaTime,state);
    }
    else if(state == GameState::SETTING)
    {
        setting.Update(deltaTime);
    }
}

void Game::capFPS()
{
    frameDelay = 1000/setting.fpsValue;
    frameTime = SDL_GetTicks() - frameStart;

    if (frameTime < static_cast<Uint64>(frameDelay)){
        SDL_Delay(static_cast<Uint32>(frameDelay - frameTime));
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
