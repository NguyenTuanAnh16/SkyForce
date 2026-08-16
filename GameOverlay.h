#ifndef _GAMEOVERLAY_H
#define _GAMEOVERLAY_H

#include <SDL.h>
#include "Menu.h"
#include "Config.h"

struct GameOverlay
{
    SDL_Texture* boxTex = nullptr;
    SDL_FRect boxRect;

    SDL_FRect rectAll;
// pause
    SDL_Texture* pauseLogoTex = nullptr;
    SDL_FRect pauseLogoRect;

    Button continueBt;

// win
    SDL_Texture* winLogoTex = nullptr;
    SDL_FRect winLogoRect;

    Button nextLever;

// lost

    SDL_Texture* lostLogoTex = nullptr;
    SDL_FRect lostLogoRect;

    Button retry;

    Button goBack;
    Button exit;

    void Init(MenuRes& res);

    void Update(float deltaTime,GameState& state);

    void HandleEvent(SDL_Event& e, GameState& state);

    void Render(SDL_Renderer* renderer,GameState& state);
};

#endif

