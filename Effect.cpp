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
}

EffectData EffectDataBase::Effect(int type)
{
    if(type == 1) return one;
    if(type == 2) return two;
    if(type == 3) return shipOne;
    return EffectData();
}
