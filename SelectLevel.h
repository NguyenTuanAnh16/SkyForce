#ifndef _SELECTLEVEL_H
#define _SELECTLEVEL_H

#include <SDL.h>
#include "Menu.h"
#include "Config.h"


struct SelectLevel
{
    SDL_Texture* backGround = nullptr;
    SDL_FRect rectBG;

    SDL_Texture* logo = nullptr;
    SDL_FRect rectLG;

    Button levelOne;
    Button levelTwo;
    Button levelThree;
    Button goBack;

    int level = 1;
    int targetScore = 0;

    void Init(MenuRes& res);

    void Update(float deltaTime);

    void SetTargetScore();

    void HandleEvent(SDL_Event& e, GameState& state);

    void Render(SDL_Renderer* renderer);
};

#endif


