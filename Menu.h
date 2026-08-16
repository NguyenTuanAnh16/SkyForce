#ifndef _MENU_H
#define _MENU_H

#include <SDL.h>
#include "Config.h"
#include "ResourceManager.h"
#include "GameState.h"

// chon nut
struct Button
{
    SDL_Texture* texture = nullptr;
    SDL_FRect rect;

    bool hover = false;
    float scale = 1;

    void Update(float deltaTime, float mouseX, float mouseY);

    void Render(SDL_Renderer* renderer);
};

// menu dau
struct Menu
{
    SDL_Texture* backGround = nullptr;
    SDL_FRect rectBG;


    SDL_Texture* logo = nullptr;
    SDL_FRect rectLG;

    Button play;
    Button select;
    Button setting;
    Button exit;

    void Init(MenuRes& res);

    void Update(float deltatime);

    void HandleEvent(SDL_Event& e, GameState& state);

    void Render(SDL_Renderer* renderer);
};


#endif
