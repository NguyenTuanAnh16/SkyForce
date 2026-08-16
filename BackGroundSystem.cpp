#include "BackGroundSystem.h"


void BackGroundSystem::Init(BackGroundDataBase* data)
{
       this->data = data;
    backGround.sceneryRectOne = {0,0,0,0};
    backGround.sceneryRectTwo = {0,0,0,0};
    backGround.planetRect = {0,0,0,0};
    backGround.meteorRect = {0,0,0,0};
}

void BackGroundSystem::Set(int level)
{

    if(level == 1) backGround.data = &data->one;
    else if(level == 2) backGround.data = &data->two;
    else  backGround.data = &data->three;


    backGround.sceneryRectOne = backGround.data->sceneryStart;
    backGround.sceneryRectTwo = backGround.data->sceneryStart;
    backGround.sceneryRectTwo.y = - backGround.sceneryRectOne.h;
    backGround.planetRect = backGround.data->planetStart;
    backGround.meteorRect = backGround.data->meteorStart;
    time = 0;

}


void BackGroundSystem::Update(float deltaTime)
{
    // cuon nen
    backGround.sceneryRectOne.y = backGround.sceneryRectOne.y + backGround.data->scenerySpeed * deltaTime;
    backGround.sceneryRectTwo.y = backGround.sceneryRectTwo.y + backGround.data->scenerySpeed * deltaTime;
    if(backGround.sceneryRectOne.y >= SCREEN_HEIGHT)  backGround.sceneryRectOne.y = backGround.sceneryRectTwo.y - backGround.sceneryRectOne.h;
    if(backGround.sceneryRectTwo.y >= SCREEN_HEIGHT)  backGround.sceneryRectTwo.y = backGround.sceneryRectOne.y - backGround.sceneryRectTwo.h;

    // cuon hanh tinh
    backGround.planetRect.y = backGround.planetRect.y + backGround.data->planetSpeed * deltaTime;
    if(backGround.planetRect.y >= SCREEN_HEIGHT)   backGround.planetRect.y = - backGround.planetRect.h;

    // bay thien thach
    time = time + deltaTime;
    backGround.meteorRect.x = backGround.meteorRect.x + backGround.data->meteorVelocityX * backGround.data->meteorSpeed * deltaTime;
    backGround.meteorRect.y = backGround.meteorRect.y + backGround.data->meteorVelocityY * backGround.data->meteorSpeed * deltaTime;
    if(time >= 3)
        {  backGround.meteorRect.x = rand() % SCREEN_WIDTH;
           backGround.meteorRect.y = 0;
           time = rand()%3;
           }
}

void BackGroundSystem::Render(SDL_Renderer* renderer)
{
   SDL_RenderCopyF(renderer,backGround.data->sceneryTex,nullptr,&backGround.sceneryRectOne);
   SDL_RenderCopyF(renderer,backGround.data->sceneryTex,nullptr,&backGround.sceneryRectTwo);

   SDL_RenderCopyF(renderer,backGround.data->planetTex,nullptr,&backGround.planetRect);

   SDL_RenderCopyExF(renderer,backGround.data->meteorTex,NULL,&backGround.meteorRect,backGround.data->meteorAngle,NULL,SDL_FLIP_NONE);
}

