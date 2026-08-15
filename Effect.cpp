#include "Effect.h"
#include <iostream>

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
    //noti và khiên

    txtChangeBullet.texture = res.txtChangeBullet;
    txtChangeBullet.frame = 4;
    txtChangeBullet.frameTime = 0.05f;
    txtChangeBullet.width = 500;
    txtChangeBullet.height = 350;
    // Hiệu ứng vòng khiên
    shieldAura.texture = res.shieldAura;
    shieldAura.frame = 3;
    shieldAura.frameTime = 0.05f;
    shieldAura.width = 666;
    shieldAura.height = 759;

    healAura.texture = res.healAura;
    healAura.frame = 3;
    healAura.frameTime = 0.05f;
    healAura.width = 516;
    healAura.height = 1329;

}

EffectData EffectDataBase::Effect(int type)
{
    if(type == 1) return one;
    if(type == 2) return two;
    if(type == 3) return shipOne;
    if (type == 6) return txtChangeBullet;
    if (type == 7) return shieldAura;
    if (type == 8) return healAura;
    return EffectData();
}
