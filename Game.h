#ifndef _Game_H
#define _Game_H

#include "ResourceManager.h"
#include "BackGround.h"
#include "Starship.h"
#include "Bullet.h"
struct Game {
// cua so
SDL_Window* window;
SDL_Renderer* renderer;

// tai nguyen
ResourceManager resource;

// background
BackGround background;

// tau vu tru
Starship starship;

// dan
BulletPlayer bulletplayer;

// fps
Uint32 frameStart = 0;
Uint32 frameTime = 0;
int frameDelay;

// thoi gian
float deltaTime;

// check
bool running = true;

void Init();
void Run();
void Render();
void Update();
void capFPS();
void Clean();
};

#endif // _Game_H
