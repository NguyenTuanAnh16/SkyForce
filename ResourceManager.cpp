#include "ResourceManager.h"

void ResourceManager:: Load(SDL_Renderer* renderer){
// nen
backGround = IMG_LoadTexture(renderer,"ResourceManager/BackGround.jpg");
nibiru = IMG_LoadTexture(renderer,"ResourceManager/Nibiru.png");
asteroid = IMG_LoadTexture(renderer,"ResourceManager/Asteroid.png");

// tau vu tru
starship = IMG_LoadTexture(renderer,"ResourceManager/Starship.png");

// dan
bulletplayer = IMG_LoadTexture(renderer,"ResourceManager/BulletPlayer.png");
}

void ResourceManager:: Free(){
SDL_DestroyTexture(backGround);
SDL_DestroyTexture(nibiru);
}
