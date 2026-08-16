#include "ResourceManager.h"
#include <iostream>
void ResourceManager:: Load(SDL_Renderer* renderer){
// menu
// chung
menu.backGround = IMG_LoadTexture(renderer,"ResourceManager/Menu/BackGround.png");
menu.logo = IMG_LoadTexture(renderer,"ResourceManager/Menu/Logo.png");
menu.goBack = IMG_LoadTexture(renderer,"ResourceManager/Menu/Return.png");
menu.exit = IMG_LoadTexture(renderer,"ResourceManager/Menu/Exit.png");
menu.box = IMG_LoadTexture(renderer,"ResourceManager/Menu/Box.png");
// menu
menu.playGame = IMG_LoadTexture(renderer,"ResourceManager/Menu/Play.png");
menu.selectShip = IMG_LoadTexture(renderer,"ResourceManager/Menu/Select.png");
menu.settings = IMG_LoadTexture(renderer,"ResourceManager/Menu/Settings.png");
// doi may bay
menu.right =  IMG_LoadTexture(renderer,"ResourceManager/Menu/Right.png");
menu.left = IMG_LoadTexture(renderer,"ResourceManager/Menu/Left.png");
menu.shipInfo = IMG_LoadTexture(renderer,"ResourceManager/Menu/Shipinfo.png");
// doi lever
menu.levelOne = IMG_LoadTexture(renderer,"ResourceManager/Menu/LevelOne.png");
menu.levelTwo = IMG_LoadTexture(renderer,"ResourceManager/Menu/LevelTwo.png");
menu.levelThree = IMG_LoadTexture(renderer,"ResourceManager/Menu/LevelThree.png");
//setting
menu.FpsMax = IMG_LoadTexture(renderer,"ResourceManager/Menu/FpsMax.png");
menu.FpsMin = IMG_LoadTexture(renderer,"ResourceManager/Menu/FpsMin.png");
menu.musicOn = IMG_LoadTexture(renderer,"ResourceManager/Menu/MusicOn.png");
menu.musicOff = IMG_LoadTexture(renderer,"ResourceManager/Menu/MusicOff.png");
menu.soundOn = IMG_LoadTexture(renderer,"ResourceManager/Menu/SoundOn.png");
menu.soundOff = IMG_LoadTexture(renderer,"ResourceManager/Menu/SoundOff.png");
// pause
menu.pauseLogo = IMG_LoadTexture(renderer,"ResourceManager/Menu/PauseLogo.png");
menu.continues = IMG_LoadTexture(renderer,"ResourceManager/Menu/Continue.png");
// win
menu.nextLevel = IMG_LoadTexture(renderer,"ResourceManager/Menu/NextLever.png");
menu.winLogo = IMG_LoadTexture(renderer,"ResourceManager/Menu/WinLogo.png");
// lost
menu.lostLogo = IMG_LoadTexture(renderer,"ResourceManager/Menu/LostLogo.png");
menu.retry = IMG_LoadTexture(renderer,"ResourceManager/Menu/Retry.png");

// player
player.score = IMG_LoadTexture(renderer,"ResourceManager/Player/Score.png");
player.hp = IMG_LoadTexture(renderer,"ResourceManager/Player/Hp.png");
player.number = IMG_LoadTexture(renderer,"ResourceManager/Player/Number.png");
player.pause = IMG_LoadTexture(renderer,"ResourceManager/Player/Pause.png");

// game
background.sceneryOne = IMG_LoadTexture(renderer,"ResourceManager/BackGround/BGOne.png");
background.sceneryTwo = IMG_LoadTexture(renderer,"ResourceManager/BackGround/BGTwo.png");
background.sceneryThree = IMG_LoadTexture(renderer,"ResourceManager/BackGround/BGThree.png");

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
effect.shield = IMG_LoadTexture(renderer,"ResourceManager/Effect/Shield.png");
effect.hp = IMG_LoadTexture(renderer,"ResourceManager/Effect/Hp.png");


// nhac
music.music = Mix_LoadMUS("ResourceManager/Music/Music.mp3");
music.burst = Mix_LoadWAV("ResourceManager/Music/Burst.wav");
music.win = Mix_LoadWAV("ResourceManager/Music/Win.wav");
music.lost = Mix_LoadWAV("ResourceManager/Music/Lost.wav");
music.click = Mix_LoadWAV("ResourceManager/Music/Click.wav");

//item
item.hp = IMG_LoadTexture(renderer,"ResourceManager/Item/Hp.png");
item.power = IMG_LoadTexture(renderer,"ResourceManager/Item/Power.png");
item.shield = IMG_LoadTexture(renderer,"ResourceManager/Item/Shield.png");

}

void ResourceManager::Free()
{
    // menu
    // chung
    SDL_DestroyTexture(menu.backGround);
    SDL_DestroyTexture(menu.logo);
    SDL_DestroyTexture(menu.goBack);
    SDL_DestroyTexture(menu.exit);
    SDL_DestroyTexture(menu.box);

    // menu
    SDL_DestroyTexture(menu.playGame);
    SDL_DestroyTexture(menu.selectShip);
    SDL_DestroyTexture(menu.settings);

    // doi may bay
    SDL_DestroyTexture(menu.right);
    SDL_DestroyTexture(menu.left);
    SDL_DestroyTexture(menu.shipInfo);

    // doi level
    SDL_DestroyTexture(menu.levelOne);
    SDL_DestroyTexture(menu.levelTwo);
    SDL_DestroyTexture(menu.levelThree);

    // setting
    SDL_DestroyTexture(menu.FpsMax);
    SDL_DestroyTexture(menu.FpsMin);
    SDL_DestroyTexture(menu.musicOn);
    SDL_DestroyTexture(menu.musicOff);
    SDL_DestroyTexture(menu.soundOn);
    SDL_DestroyTexture(menu.soundOff);

    // pause
    SDL_DestroyTexture(menu.pauseLogo);
    SDL_DestroyTexture(menu.continues);

    // win
    SDL_DestroyTexture(menu.nextLevel);
    SDL_DestroyTexture(menu.winLogo);

    // lost
    SDL_DestroyTexture(menu.lostLogo);
    SDL_DestroyTexture(menu.retry);


    // player
    SDL_DestroyTexture(player.score);
    SDL_DestroyTexture(player.hp);
    SDL_DestroyTexture(player.number);
    SDL_DestroyTexture(player.pause);


    // game
    SDL_DestroyTexture(background.sceneryOne);
    SDL_DestroyTexture(background.sceneryTwo);
    SDL_DestroyTexture(background.sceneryThree);
    SDL_DestroyTexture(background.nibiru);
    SDL_DestroyTexture(background.asteroid);


    // tau vu tru
    SDL_DestroyTexture(starship.one);
    SDL_DestroyTexture(starship.nameOne);
    SDL_DestroyTexture(starship.two);
    SDL_DestroyTexture(starship.nameTwo);
    SDL_DestroyTexture(starship.three);
    SDL_DestroyTexture(starship.nameThree);


    // dich
    SDL_DestroyTexture(enemy.one);
    SDL_DestroyTexture(enemy.two);
    SDL_DestroyTexture(enemy.three);


    // dan
    SDL_DestroyTexture(weapon.playerOne);
    SDL_DestroyTexture(weapon.enemyOne);


    // hieu ung
    SDL_DestroyTexture(effect.one);
    SDL_DestroyTexture(effect.two);
    SDL_DestroyTexture(effect.shipOne);
    SDL_DestroyTexture(effect.shield);
    SDL_DestroyTexture(effect.hp);


    // nhac
    Mix_FreeMusic(music.music);
    Mix_FreeChunk(music.burst);
    Mix_FreeChunk(music.win);
    Mix_FreeChunk(music.lost);
    Mix_FreeChunk(music.click);


    // item
    SDL_DestroyTexture(item.hp);
    SDL_DestroyTexture(item.power);
    SDL_DestroyTexture(item.shield);
}
