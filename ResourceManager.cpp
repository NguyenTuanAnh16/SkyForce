#include "ResourceManager.h"

void ResourceManager:: Load(SDL_Renderer* renderer){
// nen
backGround = IMG_LoadTexture(renderer,"ResourceManager/BackGround.jpg");
nibiru = IMG_LoadTexture(renderer,"ResourceManager/Nibiru.png");
asteroid = IMG_LoadTexture(renderer,"ResourceManager/Asteroid.png");

// tau vu tru
starshipone = IMG_LoadTexture(renderer,"ResourceManager/StarshipOne.png");
starshiptwo = IMG_LoadTexture(renderer,"ResourceManager/StarshipTwo.png");
starshipthree = IMG_LoadTexture(renderer,"ResourceManager/StarshipThree.png");

// dan
bulletOne = IMG_LoadTexture(renderer,"ResourceManager/BulletOne.png");
bulletTwo = IMG_LoadTexture(renderer,"ResourceManager/BulletTwo.png");

// dich
enemyOne = IMG_LoadTexture(renderer,"ResourceManager/EnemyOne.png");
enemyTwo = IMG_LoadTexture(renderer,"ResourceManager/EnemyTwo.png");
enemyThree = IMG_LoadTexture(renderer,"ResourceManager/EnemyThree.png");
}

void ResourceManager:: Free(){
SDL_DestroyTexture(backGround);
SDL_DestroyTexture(nibiru);
}
