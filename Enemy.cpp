#include "Enemy.h"

void EnemyDataBase::Init(EnemyRes& res){
    // one
          this->one.texture = res.one;
          this->one.speed = 200;
          this->one.hpMax = 200;
          this->one.width = 48;
          this->one.height = 54;
          this->one.moveType = 1;
          this->one.guns = {{21,55}};
          this->one.shootType = 2;
          this->one.shootDelay = 0.3f;

    // two
          this->two.texture = res.two;
          this->two.speed = 600;
          this->two.hpMax = 200;
          this->two.width = 66;
          this->two.height = 70;
          this->two.moveType = 1;
          this->two.guns = {{0,0}};
          this->two.shootType = 2;
          this->two.shootDelay = 0.3f;

    // three
          this->three.texture = res.three;
          this->three.speed = 600;
          this->three.hpMax = 200;
          this->three.width = 66;
          this->three.height = 70;
          this->three.moveType = 1;
          this->three.guns = {{0,0}};
          this->three.shootType = 2;
          this->three.shootDelay = 0.3f;

}

EnemyData EnemyDataBase::Enemy(int type){
    if(type == 0) return one;
    if(type == 1) return two;
    if(type == 2) return three;
    return EnemyData();

}
