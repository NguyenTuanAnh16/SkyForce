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
    //noti và khiên
    txtHeal.texture = res.txtHeal;
    txtHeal.frame = 1;
    txtHeal.width = 120;
    txtHeal.height = 40;

    txtShield.texture = res.txtShield;
    txtShield.frame = 1;
    txtShield.width = 120;
    txtShield.height = 40;

    txtChangeBullet.texture = res.txtChangeBullet;
    txtChangeBullet.frame = 1;
    txtChangeBullet.width = 140;
    txtChangeBullet.height = 40;

    // Hiệu ứng vòng khiên
    shieldAura.texture = res.shieldAura;
    shieldAura.frame = 1; // Nếu có sprite sheet xoay vòng khiên thì đổi số frame ở đây
    shieldAura.width = 128;
    shieldAura.height = 128;
    shieldAura.frameTime = 0.05f;

}

EffectData EffectDataBase::Effect(int type)
{
    if(type == 1) return one;
    if(type == 2) return two;
    if(type == 3) return shipOne;
    if (type == 4) return txtHeal;         // Chữ "Heal Up"
    if (type == 5) return txtShield;       // Chữ "Shield Up"
    if (type == 6) return txtChangeBullet; // Chữ "Change Bullet"
    if (type == 7) return shieldAura;
    return EffectData();
}
