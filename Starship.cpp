#include "Starship.h"

void StarshipDataBase::Init(StarshipRes& res)
{

// may bay 1
    this->one.texture = res.one;
    this->one.rect = {(SCREEN_WIDTH - 145) / 2,
                               SCREEN_HEIGHT * 0.8 ,
                               145,
                               115};
  // toc do,hp
    this->one.speed = 1200;
    this->one.hpMax = 100;
    this->one.rectHpMax = {0,0,100,20};
    this->one.rectHpNow = {0,0,100,20};
  // sung
    this->one.guns = {{(145-13) / 2, -25}};
    this->one.shootdelay = 0.4f;


// may bay 2
    this->two.texture = res.two;
    this->two.rect = {(SCREEN_WIDTH - 161) / 2,
                              SCREEN_HEIGHT * 0.8,
                              161,
                              127};
    // toc do,hp
    this->two.speed = 1000;
    this->two.hpMax = 100;
    this->two.hpNow = 100;
    this->two.rectHpMax = {0,0,100,20};
    this->two.rectHpNow = {0,0,100,20};
    // sung
    this->two.guns ={{53, -25},{97, -25}};
    this->two.shootdelay = 0.4f;


// may bay 3
    this->three.texture = res.three;
    this->three.rect = {(SCREEN_WIDTH - 177) / 2,
                                 SCREEN_HEIGHT * 0.8,
                                 177,
                                 138};
    // toc do hp
    this->three.speed = 800;
    this->three.hpMax = 500;
    this->three.hpNow = 100;
    this->three.rectHpMax = {0,0,200,20};
    this->three.rectHpNow = {0,0,200,20};

    // sung
    this->three.guns ={{50, -25 + 17},{83, -25},{115, -25 + 17}};
    this->three.shootdelay = 0.4f;
    this->three.gunType = 1;

}
