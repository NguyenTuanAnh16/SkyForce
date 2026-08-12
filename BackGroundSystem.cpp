#include "BackGroundSystem.h"
#include <iostream>

void BackGroundSystem::Init(BackGroundDataBase* data)
{
       this->data = data;
    backGround.sceneryRectOne = {0,0,0,0};
    backGround.sceneryRectTwo = {0,0,0,0};
    backGround.planetRect = {0,0,0,0};
    backGround.meteorRect = {0,0,0,0};
}

void BackGroundSystem::Set(int type)
{

    if(type == 1) backGround.data = &data->one;
    else if(type == 2) backGround.data = &data->two;
    else if(type == 3) backGround.data = &data->three;

    backGround.sceneryRectOne = backGround.data->sceneryStart;
    backGround.sceneryRectTwo = backGround.data->sceneryStart;
    backGround.sceneryRectTwo.y = - backGround.sceneryRectOne.h;
    backGround.planetRect = backGround.data->planetStart;
    backGround.meteorRect = backGround.data->meteorStart;

}


void BackGroundSystem::Update(float deltaTime)
{
    // cuon nen
    backGround.sceneryRectOne.y = backGround.sceneryRectOne.y + backGround.data->scenerySpeed * deltaTime;
    backGround.sceneryRectTwo.y = backGround.sceneryRectOne.y - backGround.sceneryRectOne.h;
    if(backGround.sceneryRectOne.y >= SCREEN_HEIGHT)
        {  backGround.sceneryRectOne.y = 0;
           backGround.sceneryRectTwo.y = - backGround.sceneryRectOne.h;
           }

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

