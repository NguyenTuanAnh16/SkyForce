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
    std::vector<Effect> notifs; //thông báo nhặt item
    Effect shieldAura;
    Effect healAura;


    void Init(EffectDataBase* data);

    // hieu ung no
    void AddBlast(float x, float y, int type,float effectSize);

    // hieu ung dong co
    void AddEngine(int type,float effectSize);

    // theo may bay
    void FollowEngine(Starship& starship);
    void ClearEngine();

    // hieu ung item
    void AddItemNotif(float x, float y, int type, float duration = 1.5f);
    void FollowShield(Starship& starship, bool hasShield);
    void FollowNotif(Starship& starship);
    void FollowHealing(Starship& starship, bool hasHealing);

    void Update(float dt);
    void Reset();
    void Render(SDL_Renderer* renderer);
};


#endif
