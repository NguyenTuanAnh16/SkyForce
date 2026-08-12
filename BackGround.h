#ifndef _BackGround_H
#define _BackGround_H

#include <SDL.h>
#include "Config.h"
#include "ResourceManager.h"

struct BackGroundData
{
    SDL_Texture* sceneryTex = nullptr;
    SDL_FRect sceneryStart;
    float scenerySpeed = 0;

    SDL_Texture* planetTex = nullptr;
    SDL_FRect planetStart;
    float planetSpeed = 0;

    SDL_Texture* meteorTex = nullptr;
    SDL_FRect meteorStart;
    float meteorSpeed = 0;
    float meteorVelocityX = 0;
    float meteorVelocityY = 0;
    float meteorAngle = 0;
};

struct BackGround
{
    BackGroundData* data = nullptr;

    // scenery
    SDL_FRect sceneryRectOne;
    SDL_FRect sceneryRectTwo;

    // planet
    SDL_FRect planetRect;

    // mereor
    SDL_FRect meteorRect;

};

struct BackGroundDataBase
{
    BackGroundData one;
    BackGroundData two;
    BackGroundData three;
    void Init(BackgroundRes& res);
};

#endif
