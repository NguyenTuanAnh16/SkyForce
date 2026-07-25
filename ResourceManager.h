#ifndef _ResourceManager_H
#define _ResourceManager_H

#include <SDL.h>
#include <SDL_image.h>

// menu
struct MenuRes{

};

//  game
struct BackgroundRes
{
    SDL_Texture* backGround;
    SDL_Texture* nibiru;
    SDL_Texture* asteroid;
};

// tau vu tru
struct StarshipRes
{
    SDL_Texture* one;
    SDL_Texture* two;
    SDL_Texture* three;
};

// tai nguyen dich
struct EnemyRes
{
    SDL_Texture* one;
    SDL_Texture* two;
    SDL_Texture* three;
};


// tài nguyên đạn
struct WeaponRes
{
    SDL_Texture* playerOne;
    SDL_Texture* enemyOne;
};



struct ResourceManager {
  MenuRes menu;
  BackgroundRes background;
  StarshipRes starship;
  EnemyRes enemy;
  WeaponRes weapon;
  void Load(SDL_Renderer* renderer);
  void Free();
};

#endif
