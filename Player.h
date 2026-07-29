#ifndef _Player_H
#define _Player_H

#include <SDL.h>
#include "Starship.h"
#include "WeaponSystem.h"
#include "SelectShip.h"
#include "EffectSystem.h"

struct Player
{
    const Uint8* key = nullptr;

    Starship* starship = nullptr;

    float shoottime = 0;

    void ChangeStarship(SelectShip& ship,StarshipDataBase& data, EffectSystem& effectSystem);

    void Update(float deltaTime,WeaponSystem& weaponSystem, EffectSystem& effectSystem);

    void Render(SDL_Renderer* renderer);
};

#endif
