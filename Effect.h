#ifndef _EFFECT_H
#define _EFFECT_H

#include <SDL.h>
#include "ResourceManager.h"

enum class EffectType
{
    ONE,
    TWO,
    SHIP_ONE,
    SHIELD,
    HP
};

struct EffectData
{
    SDL_Texture* texture;
    int frame;
    float frameTime;
    int width, height;

};

struct Effect
{
    EffectData* data = nullptr;
    bool active = false;
    SDL_FRect rect;
    SDL_Rect src;
    int frameNow;
    float timer;
};

struct EffectDataBase
{
    EffectData one;
    EffectData two;
    EffectData shipOne;
    EffectData shield;
    EffectData hp;
    void Init(EffectRes& res);
    EffectData* Get(EffectType type);
};
#endif

