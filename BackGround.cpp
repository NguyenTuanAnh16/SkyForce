#include "BackGround.h"

void BackGroundDataBase::Init(BackgroundRes& res)
{
// man 1
    // nen
    one.sceneryTex  = res.sceneryOne;
    one.sceneryStart = {0,0,SCREEN_WIDTH,SCREEN_HEIGHT};
    one.scenerySpeed = 250;

    //hanh tinh
    one.planetTex = res.nibiru;
    one.planetStart = {1000,0,180,180};
    one.planetSpeed = 25;

    // sao
    one.meteorTex = res.asteroid;
    one.meteorStart = {0,0,30,30};
    one.meteorSpeed = 1000;
    one.meteorVelocityX = 1.0f;
    one.meteorVelocityY = 0.35f;
    one.meteorAngle = -40;


// man 2
    // nen
    two.sceneryTex  = res.sceneryTwo;
    two.sceneryStart = {0,0,SCREEN_WIDTH,SCREEN_HEIGHT};
    two.scenerySpeed = 250;

    //hanh tinh
    two.planetTex = res.nibiru;
    two.planetStart = {900,0,180,180};
    two.planetSpeed = 25;

    // sao
    two.meteorTex = res.asteroid;
    two.meteorStart = {0,0,30,30};
    two.meteorSpeed = 1000;
    two.meteorVelocityX = 1.0f;
    two.meteorVelocityY = 0.35f;
    two.meteorAngle = -40;

// man 3
    // nen
    three.sceneryTex  = res.sceneryThree;
    three.sceneryStart = {0,0,SCREEN_WIDTH,SCREEN_HEIGHT};
    three.scenerySpeed = 250;

    //hanh tinh
    three.planetTex = res.nibiru;
    three.planetStart = {800,0,180,180};
    three.planetSpeed = 25;

    // sao
    three.meteorTex = res.asteroid;
    three.meteorStart = {0,0,30,30};
    three.meteorSpeed = 1000;
    three.meteorVelocityX = 1.0f;
    three.meteorVelocityY = 0.35f;
    three.meteorAngle = -40;
}
