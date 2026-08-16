#ifndef _GAME_H
#define _GAME_H

#include "ResourceManager.h"
#include "GameState.h"

#include "Config.h"
#include "Music.h"

#include "Menu.h"
#include "SelectLevel.h"
#include "SelectShip.h"
#include "Setting.h"
#include "GameOverlay.h"

#include "BackGroundSystem.h"
#include "Player.h"
#include "EnemySystem.h"
#include "SpawnManager.h"
#include "WeaponSystem.h"
#include "CollisionSystem.h"
#include "EffectSystem.h"
#include "ItemSystem.h"


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
SelectLevel selectlevel;
SelectShip selectShip;
Setting setting;
GameOverlay gameOverlay;

// background
BackGroundDataBase background;
BackGroundSystem backGroundSystem;

// nguoi choi
Player player;
StarshipDataBase starship;


// dich
EnemyDataBase enemy;
EnemySystem enemysystem;
SpawnManager spawnmanager;



// dan
WeaponDataBase weapon;
WeaponSystem weaponSystem;


// va cham
CollisionSystem collisionSystem;

// hieu ung
EffectDataBase effect;
EffectSystem effectSystem;

// item
ItemDataBase item;
ItemSystem itemSystem;

// nhac
Music music;


// fps
Uint64 frameStart = 0;
Uint64 frameTime = 0;
int frameDelay;

// thoi gian
float deltaTime;
float resultTimer = 0.0f;
bool waitingResult = false;

// game
bool running = true;

void Init();
void InitLevel();

void Run();

void Update();
void Render();

void capFPS();

void Clean();
};

#endif // x
