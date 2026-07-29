#ifndef _Starship_H
#define _Starship_H

#include <SDL.h>
#include <vector>
#include "Config.h"
#include "ResourceManager.h"

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
    SDL_FRect rectHpMax,rectHpNow;

    // vu khi
    std::vector<Offset> guns;
    float shootdelay;
    int gunType;

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
