#ifndef _Player_H
#define _Player_H

#include <SDL.h>
#include "Starship.h"
#include "WeaponSystem.h"

struct Player
{
    const Uint8* key;

    Starship starship;

    float shoottime = 0;

    void ChangeStarship(Starship ship);

    void Update(float deltaTime,WeaponSystem* weaponSystem);

    void Render(SDL_Renderer* renderer);
};

#endif
