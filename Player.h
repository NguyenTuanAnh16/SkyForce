#ifndef _Player_H
#define _Player_H

#include <SDL.h>
#include "ResourceManager.h"
#include "Starship.h"
#include "WeaponSystem.h"
#include "SelectShip.h"
#include "EffectSystem.h"
#include "Menu.h"

struct Player
{
    // input
    const Uint8* key = nullptr;

    // may bay
    Starship* starship = nullptr;
    float shoottime = 0;

    // diem
    SDL_Texture* scoreTex = nullptr;
    SDL_Texture* numberTex = nullptr;
    SDL_FRect scoreRect;
    SDL_FRect numberRect;
    int score = 0;


    // hp
    SDL_Texture* hpTex = nullptr;
    SDL_FRect hpRect;
    SDL_FRect hpMaxRect;
    SDL_FRect hpNowRect;

    // dung game
    Button pause;



    void Init(PlayerRes& player);

    void ChangeStarship(SelectShip& ship,StarshipDataBase& data, EffectSystem& effectSystem);

    void HandleEvent(SDL_Event& e, GameState& state);

    void Update(float deltaTime,WeaponSystem& weaponSystem, EffectSystem& effectSystem);

    void Reset();

    void RenderScore(SDL_Renderer* renderer);

    void Render(SDL_Renderer* renderer);
};

#endif
