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
menu.levelOne = IMG_LoadTexture(renderer,"ResourceManager/Menu/LevelOne.png");
menu.levelTwo = IMG_LoadTexture(renderer,"ResourceManager/Menu/LevelTwo.png");
menu.levelThree = IMG_LoadTexture(renderer,"ResourceManager/Menu/LevelThree.png");
menu.box = IMG_LoadTexture(renderer,"ResourceManager/Menu/Box.png");
menu.pauseLogo = IMG_LoadTexture(renderer,"ResourceManager/Menu/PauseLogo.png");
menu.continues = IMG_LoadTexture(renderer,"ResourceManager/Menu/Continue.png");
menu.nextLever = IMG_LoadTexture(renderer,"ResourceManager/Menu/NextLever.png");
menu.winLogo = IMG_LoadTexture(renderer,"ResourceManager/Menu/WinLogo.png");
menu.lostLogo = IMG_LoadTexture(renderer,"ResourceManager/Menu/LostLogo.png");
menu.retry = IMG_LoadTexture(renderer,"ResourceManager/Menu/Retry.png");
menu.musicOn = IMG_LoadTexture(renderer,"ResourceManager/Menu/MusicOn.png");
menu.musicOff = IMG_LoadTexture(renderer,"ResourceManager/Menu/MusicOff.png");
menu.soundOn = IMG_LoadTexture(renderer,"ResourceManager/Menu/SoundOn.png");
menu.soundOff = IMG_LoadTexture(renderer,"ResourceManager/Menu/SoundOff.png");
menu.FpsMax = IMG_LoadTexture(renderer,"ResourceManager/Menu/FpsMax.png");
menu.FpsMin = IMG_LoadTexture(renderer,"ResourceManager/Menu/FpsMin.png");

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
weapon.playerTwo = IMG_LoadTexture(renderer, "ResourceManager/Weapon/Player/Two.png");
weapon.enemyOne = IMG_LoadTexture(renderer,"ResourceManager/Weapon/Enemy/One.png");

// hieuung
effect.one = IMG_LoadTexture(renderer,"ResourceManager/Effect/One.png");
effect.two = IMG_LoadTexture(renderer,"ResourceManager/Effect/Two.png");
effect.shipOne = IMG_LoadTexture(renderer,"ResourceManager/Effect/ShipOne.png");
//hieu ung item
effect.txtHeal = IMG_LoadTexture(renderer, "ResourceManager/Effect/HealthUp.png");
effect.txtShield = IMG_LoadTexture(renderer, "ResourceManager/Effect/ShieldUp.png");
effect.txtChangeBullet = IMG_LoadTexture(renderer, "ResourceManager/Effect/ChangeBulletType.png");
effect.shieldAura = IMG_LoadTexture(renderer, "ResourceManager/Effect/ShieldAura.png");

music.music = Mix_LoadMUS("ResourceManager/Music/Music.mp3");
music.burst = Mix_LoadWAV("ResourceManager/Music/Burst.wav");
music.win = Mix_LoadWAV("ResourceManager/Music/Win.wav");
music.lost = Mix_LoadWAV("ResourceManager/Music/Lost.wav");
music.click = Mix_LoadWAV("ResourceManager/Music/Click.wav");
music.item = Mix_LoadWAV("ResourceManager/Music/Item.mp3");

//item
item.changeBullet = IMG_LoadTexture(renderer, "ResourceManager/Item/ChangeBullet.png");
item.heal = IMG_LoadTexture(renderer, "ResourceManager/Item/Heal.png");
item.shield = IMG_LoadTexture(renderer, "ResourceManager/Item/Shield.png");

}

void ResourceManager::Free()
{
    // menu


    // background
    SDL_DestroyTexture(background.sceneryOne);
    SDL_DestroyTexture(background.sceneryTwo);
    SDL_DestroyTexture(background.sceneryTwo);

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
    SDL_DestroyTexture(weapon.playerTwo);
    SDL_DestroyTexture(weapon.enemyOne);

    // item
    SDL_DestroyTexture(item.changeBullet);
    SDL_DestroyTexture(item.heal);
    SDL_DestroyTexture(item.shield);

    //efect hieu ung
    SDL_DestroyTexture(effect.txtHeal);
    SDL_DestroyTexture(effect.txtShield);
    SDL_DestroyTexture(effect.txtChangeBullet);
    SDL_DestroyTexture(effect.shieldAura);

    // menu (sau thêm ảnh thì thêm ở đây)
}
