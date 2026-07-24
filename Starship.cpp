#include "Starship.h"

void StarshipDataBase::Init(SDL_Texture* starshipone,
                        SDL_Texture* starshiptwo,
                        SDL_Texture* starshipthree)
{
    this->starshipone.texture = starshipone;
    this->starshipone.speed = 1200;
    this->starshipone.hp = 100;
    this->starshipone.rect = {(SCREEN_WIDTH - 145) / 2, SCREEN_HEIGHT * 0.8 , 145, 115};
    this->starshipone.guns = {{(145-13) / 2, -25}};
    this->starshipone.dame = 10;
    this->starshipone.shootdelay = 0.4f;

    this->starshiptwo.texture = starshiptwo;
    this->starshiptwo.speed = 1000;
    this->starshiptwo.hp = 200;
    this->starshiptwo.rect = {(SCREEN_WIDTH - 161) / 2, SCREEN_HEIGHT * 0.8, 161, 127};
    this->starshiptwo.guns ={{53, -25},{97, -25}};
    this->starshiptwo.dame = 20;
    this->starshiptwo.shootdelay = 0.4f;

    this->starshipthree.texture = starshipthree;
    this->starshipthree.speed = 800;
    this->starshipthree.hp = 500;
    this->starshipthree.rect = {(SCREEN_WIDTH - 177) / 2, SCREEN_HEIGHT * 0.8, 177, 138};
    this->starshipthree.guns ={{50, -25 + 17},{83, -25},{115, -25 + 17}};
    this->starshipthree.dame = 50;
    this->starshipthree.shootdelay = 0.4f;
    this->starshipthree.gunType = 1;

}

void Starship::Update(float deltaTime)
{

}



void Starship::Render(SDL_Renderer* renderer)
{
    SDL_RenderCopyF(renderer,texture,nullptr,&rect);
}
