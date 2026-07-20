#ifndef _Starship_H
#define _Starship_H

#include <SDL.h>
#include "Config.h"

struct Starship
{
    SDL_Texture* spTexture;
    float spX = 0,spY = 0;
    SDL_FRect spRect;
    const Uint8* key;

    void Init(SDL_Texture* starship);
    void Update(float deltaTime);
    void Render(SDL_Renderer* renderer);
};

#endif
