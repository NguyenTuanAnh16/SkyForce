#ifndef _EFFECTSYSTEM_H
#define _EFFECTSYSTEM_H

#include <SDL.h>
#include <vector>

#include "Effect.h"
#include "Starship.h"

struct EffectSystem
{
    EffectDataBase* data = nullptr;

    std::vector<Effect> blasts;
    std::vector<Effect> engines;
    std::vector<Effect> items;

    void Init(EffectDataBase* data);

    // hieu ung no
    void AddBlast(float x, float y, EffectType type, float effectSize);

    // hieu ung dong co
    void AddEngine(EffectType type,float effectSize);

    void AddItem (EffectType type, float effectSize);

    // theo may bay
    void FollowStarship(Starship& starship);

    void ClearEngine();

    void ClearItem(EffectType type);

    void Update(float detalTime);
    void Reset();
    void Render(SDL_Renderer* renderer);
};


#endif
