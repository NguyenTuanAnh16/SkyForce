#ifndef _Game_H
#define _Game_H

#include "ResourceManager.h"
#include "BackGround.h"
#include "Player.h"
#include "EnemySystem.h"
#include "WeaponSystem.h"
#include "Weapon.h"
#include "SpawnManager.h"
#include "CollisionSystem.h"

struct Game {
// cua so
SDL_Window* window;
SDL_Renderer* renderer;

// tai nguyen
ResourceManager resource;

// background
BackGround background;

// nguoi choi
Player player;
StarshipDataBase starship;

// dich
EnemySystem enemysystem;
EnemyDataBase enemy;

// random dich
SpawnManager spawnmanager;



// dan
WeaponSystem weaponSystem;
//WeaponDataBase weapon;

// va cham
CollisionSystem collisionSystem;

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
