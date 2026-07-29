#include "Enemy.h"

void EnemyDataBase::Init(EnemyRes& res){
    // one
          one.texture = res.one;
          one.speed = 200;
          one.hpMax = 200;
          one.width = 48;
          one.height = 54;
          one.moveType = 1;
          one.guns = {{21,55}};
          one.shootType = 2;
          one.shootDelay = 0.3f;

    // two
          two.texture = res.two;
          two.speed = 600;
          two.hpMax = 200;
          two.width = 66;
          two.height = 70;
          two.moveType = 1;
          two.guns = {{0,0}};
          two.shootType = 2;
          two.shootDelay = 0.3f;

    // three
          three.texture = res.three;
          three.speed = 600;
          three.hpMax = 200;
          three.width = 66;
          three.height = 70;
          three.moveType = 1;
          three.guns = {{0,0}};
          three.shootType = 2;
          three.shootDelay = 0.3f;

}

EnemyData EnemyDataBase::Enemy(int type){
    if(type == 0) return one;
    if(type == 1) return two;
    if(type == 2) return three;
    return EnemyData();

}
