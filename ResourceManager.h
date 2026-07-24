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
SDL_Texture* starshipone;
SDL_Texture* starshiptwo;
SDL_Texture* starshipthree;

// dan
SDL_Texture* bulletOne;
SDL_Texture* bulletTwo;

// dich
SDL_Texture* enemyOne;
SDL_Texture* enemyTwo;
SDL_Texture* enemyThree;

void Load(SDL_Renderer* renderer);
void Free();
};

#endif
