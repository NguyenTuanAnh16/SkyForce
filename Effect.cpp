#include "Effect.h"

void EffectDataBase::Init(EffectRes& res)
{
    one.texture = res.one;
    one.frame = 8;
    one.width = 128;
    one.height = 128;
    one.frameTime = 0.05f;

    two.texture = res.two;
    two.frame = 7;
    two.width = 128;
    two.height = 128;
    two.frameTime = 0.02f;

    shipOne.texture = res.shipOne;
    shipOne.frame = 4;
    shipOne.width = 100;
    shipOne.height = 105;
    shipOne.frameTime = 0.05f;

    shield.texture = res.shield;
    shield.frame = 8;
    shield.width = 180;
    shield.height = 180;
    shield.frameTime = 0.05f;


    hp.texture = res.hp;
    hp.frame = 8;
    hp.width = 263;
    hp.height = 407;
    hp.frameTime = 0.05f;

}

EffectData* EffectDataBase::Get(EffectType type)
{
    if (type == EffectType::ONE)
        return &one;

    else if (type == EffectType::TWO)
        return &two;

    else if (type == EffectType::SHIP_ONE)
        return &shipOne;
    else if(type == EffectType::SHIELD)
        return &shield;
    else if(type == EffectType::HP)
        return &hp;

    return nullptr;
}
