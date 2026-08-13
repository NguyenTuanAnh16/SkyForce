#include "Starship.h"

void StarshipDataBase::Init(StarshipRes& res)
{

// may bay 1
   // render
    one.texture = res.one;
    one.nameTexture = res.nameOne;
    one.rect = {(SCREEN_WIDTH - 145) / 2,
                 SCREEN_HEIGHT * 0.8 ,
                 145,
                 115};
   // va cham
    one.hitboxes = {{0,82, 12, 33},
                    {12, 60, 14, 45},
                    {26, 54, 16, 61},
                    {42, 22, 21, 90},
                    {63, 0, 20, 115},
                    {83, 22, 21, 90},
                    {104, 54, 16, 61},
                    {120, 60, 14, 45},
                    {134,82, 12, 33},};
   // trang thai
    one.speed = 1000;
    one.hpMax = 500;

  // vu khi
    one.guns = {{(145-13) / 2, -25}};
    one.shootdelay = 0.15f;
    one.gunType = 1;
  // dong co
    one.engineSize = 55;
    one.engines = {{one.rect.w /2,112}};


// may bay 2
    // renderer
    two.texture = res.two;
    two.nameTexture = res.nameTwo;
    two.rect = {(SCREEN_WIDTH - 161) / 2,
                 SCREEN_HEIGHT * 0.8,
                 161,
                 127};

    // vacham
     two.hitboxes = {{0,70, 28, 33},
                    {28, 35, 21, 60},
                    {49, 0, 63, 120},
                    {112, 35, 21, 60},
                    {133,70, 28, 33}};

    // toc do,hp
    two.speed = 900;
    two.hpMax = 800;

    // vu khi
    two.guns ={{53, -25},{97, -25}};
    two.shootdelay = 0.18f;
    two.gunType = 1;

    // dong co
    two.engineSize = 38;
    two.engines = {{52,110},{107,110}};



// may bay 3
    // renderer
    three.texture = res.three;
    three.nameTexture = res.nameThree;
    three.rect = {(SCREEN_WIDTH - 177) / 2,
                   SCREEN_HEIGHT * 0.8,
                   177,
                   138};


    // va cham
    three.hitboxes = {{0,64, 21, 56},
                    {21, 35, 25, 80},
                    {46, 14, 18, 106},
                    {64, 22, 18, 115},
                    {82, 0, 14, 138},
                    {96, 22, 18, 115},
                    {114, 14, 18, 106},
                    {132, 35, 25, 80},
                    {157,64, 21, 56}};


    // toc do hp
    three.speed = 700;
    three.hpMax = 1000;

    // sung
    three.guns ={{50, -25 + 17},{83, -25},{115, -25 + 17}};
    three.shootdelay = 0.22f;
    three.gunType = 1;

    three.engineSize = 40;
    three.engines = {{52,114},{124,114}};

}
