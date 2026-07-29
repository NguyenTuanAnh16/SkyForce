#ifndef _EffectSystem_H
#define _EffectSystem_H

#include <SDL.h>
#include <vector>

#include "Effect.h"
#include "Starship.h"

struct EffectSystem
{
    EffectDataBase* data = nullptr;

    std::vector<Effect> blasts;
    std::vector<Effect> engines;


    void Init(EffectDataBase* data);

    void AddBlast(float x, float y, int type,float effectSize);

    void AddEngine(int type,float effectSize);
    void FollowEngine(Starship& starship);
    void ClearEngine();

    void Update(float dt);

    void Render(SDL_Renderer* renderer);
};


#endif
