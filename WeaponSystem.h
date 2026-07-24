#ifndef _WeaponSystem_H
#define _WeaponSystem_H

#include <SDL.h>
#include <vector>
#include "Weapon.h"

struct WeaponSystem
{
    WeaponDataBase data;

    std::vector<Weapon> weapons;
    void Init(SDL_Texture* bulletOne,SDL_Texture* bulletTwo);
    void Shoot(float x, float y, int type);
    void Update(float dt);
    void Render(SDL_Renderer* renderer);
};

#endif


