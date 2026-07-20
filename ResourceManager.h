#ifndef _ResourceManager_H
#define _ResourceManager_H

#include <SDL.h>
#include <SDL_image.h>

struct ResourceManager {
// nen
SDL_Texture* backGround;
SDL_Texture* nibiru;
SDL_Texture* asteroid;

// tau vu tru
SDL_Texture* starship;

// dan
SDL_Texture* bulletplayer;

void Load(SDL_Renderer* renderer);
void Free();
};

#endif
