#ifndef _Effect_H
#define _Effect_H

#include <SDL.h>
#include "ResourceManager.h"

struct EffectData
{
    SDL_Texture* texture;
    int frame;
    float frameTime;
    int width, height;

};

struct Effect
{
    bool active = false;
    int type;
    SDL_FRect rect;
    SDL_Rect src;
    int frameNow;
    float timer;
    float maxDuration; // đếm thời gian cho khiên
};

struct EffectDataBase
{
    EffectData one;
    EffectData two;
    EffectData shipOne;
    //noti và khiên
    EffectData txtHeal;
    EffectData txtShield;
    EffectData txtChangeBullet;
    EffectData shieldAura;
    void Init(EffectRes& res);
    EffectData Effect(int type);
};
#endif

