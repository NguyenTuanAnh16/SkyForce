#include "EnemySystem.h"
#include <cmath>

void EnemySystem::Init(int sum, EnemyDataBase* data){
    this->data = data;
    enemys.resize(sum);
    moveGroups.reserve(sum);
}

// ren dich
void EnemySystem::Spawn(float x, float y,EnemyData* enemyData, int amount, int moveType){
    int sumenemy = 0;
    idGround++;
    if(idGround > 99) idGround = 0;
   for(auto& enemy : enemys){
     if(!enemy.active){
       enemy.groupId = idGround;
       enemy.active = true;
       enemy.data = enemyData;
       enemy.rect = {x + sumenemy*(40 + enemyData->rect.w),
                     y,
                     enemyData->rect.w,
                     enemyData->rect.h};
       moveGroups[enemy.groupId] = moveType;
       enemy.rectHpMax = {enemy.rect.x,
                       enemy.rect.y - enemy.rect.h/10,
                       enemy.rect.w,
                       enemy.rect.h/10};

       enemy.rectHp = enemy.rectHpMax;
       enemy.hpNow = enemyData->hpMax;
       sumenemy ++;
      }
    if(sumenemy == amount) return;
   }
}


// di chuyen
void EnemySystem::Move(Enemy* enemy, float deltaTime)
{
    if(moveGroups[enemy->groupId] == 0) enemy->rect.y = enemy->rect.y + enemy->data->speed * deltaTime;
    else if(moveGroups[enemy->groupId] == 1)
           {
            enemy->rect.y = enemy->rect.y + enemy->data->speed/3 * deltaTime;
            enemy->rect.x = enemy->rect.x + enemy->data->speed/2 * deltaTime;
            if(enemy->rect.x + enemy->rect.w >= SCREEN_WIDTH) moveGroups[enemy->groupId] = 2;}
    else if(moveGroups[enemy->groupId] == 2)
           {
            enemy->rect.y = enemy->rect.y + enemy->data->speed/3 * deltaTime;
            enemy->rect.x = enemy->rect.x - enemy->data->speed/2 * deltaTime;
            if(enemy->rect.x <= 0) moveGroups[enemy->groupId] = 1;}
}


void EnemySystem::Update(float deltatime, WeaponSystem* weaponSystem){
  for(auto& enemy : enemys){
    if(enemy.active){
        Move(&enemy, deltatime);
        enemy.rectHpMax.x = enemy.rect.x;
        enemy.rectHpMax.y = enemy.rect.y - enemy.rect.h/5;
        enemy.rectHp.x = enemy.rectHpMax.x;
        enemy.rectHp.y = enemy.rectHpMax.y;
        enemy.rectHp.w = (enemy.hpNow/enemy.data->hpMax) * enemy.rectHpMax.w;

        enemy.shoottime = deltatime + enemy.shoottime;

        if(enemy.shoottime >= enemy.data->shootDelay){
            for(auto gun : enemy.data->guns)
        {
            weaponSystem->Shoot(
                enemy.rect.x + gun.x,
                enemy.rect.y + gun.y,
                enemy.data->weaponType,
                'E');
        }
            enemy.shoottime = 0;
        }
        if(enemy.rect.y > 850) enemy.active = false;
    }
  }
}

void EnemySystem::Reset()
{
    for(auto& enemy : enemys) enemy.active = false;
}

void EnemySystem::Render(SDL_Renderer* renderer){
      for(auto& enemy : enemys){
        if(enemy.active){
        // khung mau
        SDL_SetRenderDrawColor(renderer, 50, 50, 50, 120);
        SDL_RenderFillRectF(renderer, &enemy.rectHpMax);

        // mau
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 120);
        SDL_RenderFillRectF(renderer, &enemy.rectHp);

        // may bay
        SDL_RenderCopyF(renderer,enemy.data->texture, nullptr, &enemy.rect);

        }
      }

}
