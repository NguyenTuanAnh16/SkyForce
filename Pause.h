#ifndef _PAUSE_H
#define _PAUSE_H

#include <SDL.h>
#include "Menu.h"
#include "Config.h"

struct Pause
{
    SDL_Texture* pauseLogoTex = nullptr;
    SDL_FRect pauseLogoRect;

    SDL_Texture* boxTex = nullptr;
    SDL_FRect boxRect;

    Button settings;
    Button goBack;

    void Init(MenuRes& res);

    void Update(float deltaTime);

    void HandleEvent(SDL_Event& e, GameState& state);

    void Render(SDL_Renderer* renderer);
};

#endif

