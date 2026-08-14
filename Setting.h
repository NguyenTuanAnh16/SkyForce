#ifndef _SETTING_H
#define _SETTING_H

#include <SDL.h>
#include "Menu.h"
#include "Music.h"

struct Setting
{
    SDL_Texture* backGround = nullptr;
    SDL_FRect rectBG;

    SDL_Texture* logo = nullptr;
    SDL_FRect rectLG;

    SDL_Texture* fpsMaxTex = nullptr;
    SDL_Texture* fpsMinTex = nullptr;
    Button fps;
    int fpsValue;

    SDL_Texture* musicOnTex = nullptr;
    SDL_Texture* musicOffTex = nullptr;
    Button music;

    SDL_Texture* soundOnTex = nullptr;
    SDL_Texture* soundOffTex = nullptr;
    Button sound;

    Button goBack;

    void Init(MenuRes& res);

    void Update(float deltaTime);

    void HandleEvent(SDL_Event& e, GameState& state, Music& musicValue);

    void Render(SDL_Renderer* renderer);
};

#endif
