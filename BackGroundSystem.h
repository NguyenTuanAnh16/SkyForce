#ifndef _BACKGROUNDSYSTEM_H
#define _BACKGROUNDSYSTEM_H

#include <SDL.h>
#include "BackGround.h"


struct BackGroundSystem
{
    BackGround backGround;
    BackGroundDataBase* data = nullptr;

    float time = 0;

    void Init(BackGroundDataBase* data);
    void Set(int level);
    void Update(float deltaTime);
    void Render(SDL_Renderer* renderer);
};


#endif
