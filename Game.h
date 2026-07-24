#ifndef _Game_H
#define _Game_H

#include "ResourceManager.h"
#include "BackGround.h"
#include "Starship.h"
#include "WeaponSystem.h"
#include "EnemySystem.h"
#include "SpawnManager.h"
#include "Player.h"

struct Game {
// cua so
SDL_Window* window;
SDL_Renderer* renderer;

// tai nguyen
ResourceManager resource;

// background
BackGround background;

// tau vu tru
StarshipDataBase starshipdata;

// dich
EnemySystem enemysystem;


// random dich
SpawnManager spawnmanager;

// nguoi choi
Player player;

// dan
WeaponSystem weaponSystem;

// fps
Uint32 frameStart = 0;
Uint32 frameTime = 0;
int frameDelay;

// thoi gian
float deltaTime;
float shootTimer = 0;
float shootDelay = 0.15f;

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
