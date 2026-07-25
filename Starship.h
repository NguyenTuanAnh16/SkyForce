#ifndef _Starship_H
#define _Starship_H

#include <SDL.h>
#include <vector>
#include "Config.h"
#include "ResourceManager.h"

struct GunPoint
{
    float x;
    float y;
};

struct Starship
{
    SDL_Texture* texture;
    SDL_FRect rect;


    float speed;
    float hpMax,hpNow;
    SDL_FRect rectHpMax,rectHpNow;

    std::vector<GunPoint> guns;
    float shootdelay;
    int gunType;

    void Update(float deltaTime);
    void Render(SDL_Renderer* renderer);
};

struct StarshipDataBase
{
    Starship one;
    Starship two;
    Starship three;
    void Init(StarshipRes& res);
};

#endif
