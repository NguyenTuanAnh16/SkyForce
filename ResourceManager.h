#ifndef _RESOURCEMANAGER_H
#define _RESOURCEMANAGER_H


#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

// menu
struct MenuRes
{
   // chung
   SDL_Texture* backGround = nullptr;
   SDL_Texture* logo = nullptr;
   SDL_Texture* goBack = nullptr;
   SDL_Texture* exit = nullptr;
   SDL_Texture* box = nullptr;

   // menu
   SDL_Texture* playGame = nullptr;
   SDL_Texture* selectShip = nullptr;
   SDL_Texture* settings = nullptr;

   // doi may bay
   SDL_Texture* right = nullptr;
   SDL_Texture* left = nullptr;
   SDL_Texture* shipInfo = nullptr;

   // doi level
   SDL_Texture* levelOne = nullptr;
   SDL_Texture* levelTwo = nullptr;
   SDL_Texture* levelThree = nullptr;

   // setting
   SDL_Texture* FpsMax = nullptr;
   SDL_Texture* FpsMin = nullptr;
   SDL_Texture* musicOn = nullptr;
   SDL_Texture* musicOff = nullptr;
   SDL_Texture* soundOn = nullptr;
   SDL_Texture* soundOff = nullptr;

   // pause
   SDL_Texture* pauseLogo = nullptr;
   SDL_Texture* continues = nullptr;

   // win
   SDL_Texture* nextLevel = nullptr;
   SDL_Texture* winLogo = nullptr;

   // lost
   SDL_Texture* lostLogo = nullptr;
   SDL_Texture* retry = nullptr;
};

struct PlayerRes
{
    SDL_Texture* score = nullptr;
    SDL_Texture* hp = nullptr;
    SDL_Texture* number = nullptr;
    SDL_Texture* pause  = nullptr;
};
//  game
struct BackgroundRes
{
    SDL_Texture* sceneryOne = nullptr;
    SDL_Texture* sceneryTwo = nullptr;
    SDL_Texture* sceneryThree = nullptr;
    SDL_Texture* nibiru = nullptr;
    SDL_Texture* asteroid = nullptr;
};

// tau vu tru
struct StarshipRes
{
    SDL_Texture* one = nullptr;
    SDL_Texture* nameOne = nullptr;
    SDL_Texture* two = nullptr;
    SDL_Texture* nameTwo = nullptr;
    SDL_Texture* three = nullptr;
    SDL_Texture* nameThree = nullptr;
};

// tai nguyen dich
struct EnemyRes
{
    SDL_Texture* one = nullptr;
    SDL_Texture* two = nullptr;
    SDL_Texture* three = nullptr;
};


// tài nguyên đạn
struct WeaponRes
{
    SDL_Texture* playerOne = nullptr;
    SDL_Texture* enemyOne = nullptr;
};

struct EffectRes
{
    SDL_Texture* one = nullptr;
    SDL_Texture* two = nullptr;
    SDL_Texture* shipOne = nullptr;
    SDL_Texture* shield  = nullptr;
    SDL_Texture* hp = nullptr;
};

struct MusicRes
{
    Mix_Music* music = nullptr;
    Mix_Chunk* burst = nullptr;
    Mix_Chunk* win = nullptr;
    Mix_Chunk* lost = nullptr;
    Mix_Chunk* click = nullptr;
};

struct ItemRes
{
    SDL_Texture* hp = nullptr;
    SDL_Texture* power = nullptr;
    SDL_Texture* shield = nullptr;
};
struct ResourceManager {
  MenuRes menu;
  PlayerRes player;
  BackgroundRes background;
  StarshipRes starship;
  EnemyRes enemy;
  WeaponRes weapon;
  EffectRes effect;
  MusicRes music;
  ItemRes item;
  void Load(SDL_Renderer* renderer);
  void Free();
};

#endif
