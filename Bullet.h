#ifndef _Bullet_H
#define _Bullet_H

#include<SDL.h>
#include "Config.h"

struct BulletPlayer
{
SDL_Texture* btTexture;
float btX,btY;
SDL_FRect btRect;
void Init(SDL_Texture* bulletplayer);
void Update(float deltaTime);
void Render(SDL_Renderer* renderer);
};

#endif
