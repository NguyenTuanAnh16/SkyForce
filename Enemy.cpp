#include "Enemy.h"

void EnemyDataBase::Init(EnemyRes& res){
    // one
          one.texture = res.one;
          one.speed = 300;
          one.hpMax = 200;
          one.rect = {0,0,48,54};
          one.weaponType = 2;
          one.guns = {{21,55}};
          one.shootDelay = 0.5f;
          one.score = 1;
    // two
          two.texture = res.two;
          two.speed = 600;
          two.hpMax = 200;
          two.rect = {0,0,56,60};
          two.guns = {{28,62}};
          two.weaponType = 2;
          two.shootDelay = 0.3f;
          two.score = 2;
    // three
          three.texture = res.three;
          three.speed = 600;
          three.hpMax = 200;
          three.rect = {0,0,66,70};
          three.guns = {{33,72}};
          three.weaponType = 2;
          three.shootDelay = 0.3f;
          three.score = 3;
}

