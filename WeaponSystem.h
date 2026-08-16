#ifndef _WEAPONSYSTEM_H
#define _WEAPONSYSTEM_H

#include <SDL.h>
#include <vector>
#include "Weapon.h"

struct WeaponSystem
{
    WeaponDataBase* data;
    std::vector<Weapon> weapons;
    void Init(WeaponDataBase* data);
    void Shoot(float x, float y, WeaponType type, char owner);
    void Update(float dt);
    void Reset();
    void Render(SDL_Renderer* renderer);
};

#endif


