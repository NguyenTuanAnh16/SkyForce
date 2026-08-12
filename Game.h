#ifndef _Game_H
#define _Game_H

#include "ResourceManager.h"
#include "GameState.h"
#include "Menu.h"
#include "SelectLevel.h"
#include "SelectShip.h"
#include "Pause.h"
#include "BackGroundSystem.h"
#include "Player.h"
#include "EnemySystem.h"
#include "SpawnManager.h"
#include "WeaponSystem.h"
#include "Weapon.h"
#include "CollisionSystem.h"
#include "EffectSystem.h"


struct Game {
// cua so
SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

// tai nguyen
ResourceManager resource;

// trang thai
GameState state = GameState::MENU;

// menu
Menu menu;

// doi man
SelectLevel selectlevel;

// doi may bay
SelectShip selectShip;

// pause
Pause pause;

// background
BackGroundDataBase background;
BackGroundSystem backGroundSystem;
// nguoi choi
Player player;
StarshipDataBase starship;


// dich
EnemySystem enemysystem;
EnemyDataBase enemy;

// random dich
SpawnManager spawnmanager;



// dan
WeaponDataBase weapon;
WeaponSystem weaponSystem;
//WeaponDataBase weapon;

// va cham
CollisionSystem collisionSystem;

// hieu ung
EffectSystem effectSystem;
EffectDataBase effect;

// fps
Uint64 frameStart = 0;
Uint64 frameTime = 0;
int frameDelay;

// thoi gian
float deltaTime;
float shootTimer = 0;
float shootDelay = 0.15f;

// check
bool running = true;

void Init();
void InitLevel();
void Run();
void Render();
void Update();
void capFPS();
void Clean();
};

#endif // _Game_H
