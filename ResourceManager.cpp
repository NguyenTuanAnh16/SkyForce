#include "ResourceManager.h"

void ResourceManager:: Load(SDL_Renderer* renderer){

// game
background.backGround = IMG_LoadTexture(renderer,"ResourceManager/BackGround/BackGround.jpg");
background.nibiru = IMG_LoadTexture(renderer,"ResourceManager/BackGround/Nibiru.png");
background.asteroid = IMG_LoadTexture(renderer,"ResourceManager/BackGround/Asteroid.png");

// tau vu tru
starship.one = IMG_LoadTexture(renderer,"ResourceManager/Starship/One.png");
starship.two = IMG_LoadTexture(renderer,"ResourceManager/Starship/Two.png");
starship.three = IMG_LoadTexture(renderer,"ResourceManager/Starship/Three.png");

// dich
enemy.one = IMG_LoadTexture(renderer,"ResourceManager/Enemy/One.png");
enemy.two = IMG_LoadTexture(renderer,"ResourceManager/Enemy/Two.png");
enemy.three = IMG_LoadTexture(renderer,"ResourceManager/Enemy/Three.png");


// dan
weapon.playerOne = IMG_LoadTexture(renderer,"ResourceManager/Weapon/Player/One.png");
weapon.enemyOne = IMG_LoadTexture(renderer,"ResourceManager/Weapon/Enemy/One.png");

}

void ResourceManager::Free()
{
    // background
    SDL_DestroyTexture(background.backGround);
    SDL_DestroyTexture(background.nibiru);
    SDL_DestroyTexture(background.asteroid);


    // starship
    SDL_DestroyTexture(starship.one);
    SDL_DestroyTexture(starship.two);
    SDL_DestroyTexture(starship.three);


    // enemy
    SDL_DestroyTexture(enemy.one);
    SDL_DestroyTexture(enemy.two);
    SDL_DestroyTexture(enemy.three);


    // weapon
    SDL_DestroyTexture(weapon.playerOne);
    SDL_DestroyTexture(weapon.enemyOne);


    // menu (sau thêm ảnh thì thêm ở đây)
}
