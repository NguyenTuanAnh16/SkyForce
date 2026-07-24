#ifndef _Starship_H
#define _Starship_H

#include <SDL.h>
#include "Config.h"
#include <vector>

struct GunPoint
{
    float x;
    float y;
};

struct Starship
{
    SDL_Texture* texture;

    float speed;
    int hp;
    SDL_FRect rect;

    std::vector<GunPoint> guns;
    float shootdelay;
    int dame;
    int gunType;

    void Update(float deltaTime);
    void Render(SDL_Renderer* renderer);
};

struct StarshipDataBase
{
    Starship starshipone;
    Starship starshiptwo;
    Starship starshipthree;
    void Init(SDL_Texture* starshipone,
               SDL_Texture* starshiptwo,
               SDL_Texture* starshipthree);
};

#endif
