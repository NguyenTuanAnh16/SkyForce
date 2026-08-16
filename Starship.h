#ifndef _STARSHIP_H
#define _STARSHIP_H

#include <SDL.h>
#include <vector>
#include "Config.h"
#include "ResourceManager.h"
#include "WeaponSystem.h"

struct Offset
{
    float x;
    float y;
};

struct Starship
{
    // Render
    SDL_Texture* texture = nullptr;
    SDL_FRect rect;
    SDL_Texture* nameTexture = nullptr;

    // va cham
    std::vector<SDL_FRect> hitboxes;

    // trang thai
    float speed;
    float hpMax,hpNow;

    // vu khi
    std::vector<Offset> guns;
    float shootdelay;
    WeaponType weaponType;        // loại đạn đang bắn
    WeaponType defaultWeaponType; // loại đạn gốc của máy bay

    // dong co
    std::vector<Offset> engines;
    float engineSize;
};

struct StarshipDataBase
{
    Starship one;
    Starship two;
    Starship three;
    void Init(StarshipRes& res);
};

#endif
