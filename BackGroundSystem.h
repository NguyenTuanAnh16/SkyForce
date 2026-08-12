#ifndef _BackGroundSystem_H
#define _BackGroundSystem_H

#include <SDL.h>
#include "BackGround.h"


struct BackGroundSystem
{
    BackGround backGround;
    BackGroundDataBase* data;

    float time = 0;
    void Init(BackGroundDataBase* data);
    void Set(int type);
    void Update(float deltaTime);
    void Render(SDL_Renderer* renderer);

};


#endif

