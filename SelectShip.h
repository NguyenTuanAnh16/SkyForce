#ifndef SELECTSHIP_H
#define SELECTSHIP_H

#include <SDL.h>
#include "GameState.h"
#include "Menu.h"
#include "ResourceManager.h"
#include "Starship.h"
#include "Config.h"
#include "Music.h"

struct SelectShip
{
    SDL_Texture* backGround = nullptr;
    SDL_FRect rectBG;

    StarshipDataBase* data = nullptr;


    SDL_FRect rectBox;


    int selectedShip = 1;
    SDL_FRect rectShip;
    SDL_FRect rectName;

    SDL_Texture* shipInfo;
    SDL_FRect rectShipInfo;

    Button play;
    Button goBack;

    Button rightShip;
    Button leftShip;

    void Init(MenuRes& res,StarshipDataBase* starship);

    void Update(float deltaTime);

    void DrawBar(SDL_Renderer* renderer, int value, int maxValue, float x, float y);

    void HandleEvent(SDL_Event& e, GameState& state, Music& musicValue);

    void Render(SDL_Renderer* renderer);
};

#endif
