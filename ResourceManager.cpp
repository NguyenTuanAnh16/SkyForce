#include "ResourceManager.h"

void ResourceManager:: Load(SDL_Renderer* renderer){
// menu
menu.backGround = IMG_LoadTexture(renderer,"ResourceManager/Menu/BackGround.png");
menu.logo = IMG_LoadTexture(renderer,"ResourceManager/Menu/Logo.png");
menu.playGame = IMG_LoadTexture(renderer,"ResourceManager/Menu/Play.png");
menu.selectShip = IMG_LoadTexture(renderer,"ResourceManager/Menu/Select.png");
menu.settings = IMG_LoadTexture(renderer,"ResourceManager/Menu/Settings.png");
menu.exit = IMG_LoadTexture(renderer,"ResourceManager/Menu/Exit.png");
menu.goBack = IMG_LoadTexture(renderer,"ResourceManager/Menu/Return.png");
menu.right =  IMG_LoadTexture(renderer,"ResourceManager/Menu/Right.png");
menu.left = IMG_LoadTexture(renderer,"ResourceManager/Menu/Left.png");
menu.shipInfo = IMG_LoadTexture(renderer,"ResourceManager/Menu/Shipinfo.png");

// game
background.backGround = IMG_LoadTexture(renderer,"ResourceManager/BackGround/BackGround.jpg");
background.nibiru = IMG_LoadTexture(renderer,"ResourceManager/BackGround/Nibiru.png");
background.asteroid = IMG_LoadTexture(renderer,"ResourceManager/BackGround/Asteroid.png");

// tau vu tru
starship.one = IMG_LoadTexture(renderer,"ResourceManager/Starship/One.png");
starship.nameOne = IMG_LoadTexture(renderer,"ResourceManager/Starship/Nameone.png");
starship.two = IMG_LoadTexture(renderer,"ResourceManager/Starship/Two.png");
starship.nameTwo = IMG_LoadTexture(renderer,"ResourceManager/Starship/Nametwo.png");
starship.three = IMG_LoadTexture(renderer,"ResourceManager/Starship/Three.png");
starship.nameThree = IMG_LoadTexture(renderer,"ResourceManager/Starship/Namethree.png");

// dich
enemy.one = IMG_LoadTexture(renderer,"ResourceManager/Enemy/One.png");
enemy.two = IMG_LoadTexture(renderer,"ResourceManager/Enemy/Two.png");
enemy.three = IMG_LoadTexture(renderer,"ResourceManager/Enemy/Three.png");


// dan
weapon.playerOne = IMG_LoadTexture(renderer,"ResourceManager/Weapon/Player/One.png");
weapon.enemyOne = IMG_LoadTexture(renderer,"ResourceManager/Weapon/Enemy/One.png");

// hieuung
effect.one = IMG_LoadTexture(renderer,"ResourceManager/Effect/One.png");
effect.two = IMG_LoadTexture(renderer,"ResourceManager/Effect/Two.png");
effect.shipOne = IMG_LoadTexture(renderer,"ResourceManager/Effect/ShipOne.png");
}

void ResourceManager::Free()
{
    // menu


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
