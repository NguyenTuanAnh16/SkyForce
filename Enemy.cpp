#include "Enemy.h"

void EnemyDataBase::Init(SDL_Texture* enemyOne,
                          SDL_Texture* enemyTwo,
                          SDL_Texture* enemyThree){
    // one
          this->enemyOne.texture = enemyOne;
          this->enemyOne.speed = 200;
          this->enemyOne.hp = 200;
          this->enemyOne.dame = 30;
          this->enemyOne.width = 48;
          this->enemyOne.height = 54;
          this->enemyOne.moveType = 1;
          this->enemyOne.guns = {{21,55}};
          this->enemyOne.shootType = 2;
          this->enemyOne.shootDelay = 0.3f;

    // two
          this->enemyTwo.texture = enemyTwo;
          this->enemyTwo.speed = 600;
          this->enemyTwo.hp = 200;
          this->enemyTwo.dame = 30;
          this->enemyTwo.width = 66;
          this->enemyTwo.height = 70;
          this->enemyTwo.moveType = 1;
          this->enemyTwo.guns = {{0,0}};
          this->enemyTwo.shootType = 2;
          this->enemyTwo.shootDelay = 0.3f;

    // three
          this->enemyThree.texture = enemyThree;
          this->enemyThree.speed = 600;
          this->enemyThree.hp = 200;
          this->enemyThree.dame = 30;
          this->enemyThree.width = 66;
          this->enemyThree.height = 70;
          this->enemyThree.moveType = 1;
          this->enemyThree.guns = {{0,0}};
          this->enemyThree.shootType = 2;
          this->enemyThree.shootDelay = 0.3f;

}

EnemyData EnemyDataBase::Enemy(int type){
    if(type == 0) return enemyOne;
    if(type == 1) return enemyTwo;
    if(type == 2) return enemyThree;
    return EnemyData();

}
