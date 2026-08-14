#include "EnemySystem.h"
#include <cmath>

void EnemySystem::Init(int sum, EnemyDataBase* data){
    this->data = data;
    enemys.resize(sum);
    moveGroups.resize(100, 0);
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
    // Khoảng cách an toàn cách mép trái/phải để Player dễ bắn trúng
    const float PADDING = 30.0f;

    if(moveGroups[enemy->groupId] == 0)
      {
        if(enemy->rect.y < 200)   enemy->rect.y = enemy->rect.y + enemy->data->speed * deltaTime;
      }
    else if(moveGroups[enemy->groupId] == 1) enemy->rect.y = enemy->rect.y + enemy->data->speed * deltaTime;
    else if(moveGroups[enemy->groupId] == 2)
           {
            enemy->rect.y = enemy->rect.y + enemy->data->speed/2 * deltaTime;
            enemy->rect.x = enemy->rect.x + enemy->data->speed/2 * deltaTime;
            // Đụng mép phải (trừ đi PADDING) thì nảy sang trái
            if(enemy->rect.x + enemy->rect.w >= SCREEN_WIDTH - PADDING) moveGroups[enemy->groupId] = 3;}
    else if(moveGroups[enemy->groupId] == 3)
           {
            enemy->rect.y = enemy->rect.y + enemy->data->speed/2 * deltaTime;
            enemy->rect.x = enemy->rect.x - enemy->data->speed/2 * deltaTime;
            // Đụng mép trái (PADDING) thì nảy sang phải
            if(enemy->rect.x <= PADDING) moveGroups[enemy->groupId] = 2;}
   else if(moveGroups[enemy->groupId] == 4)
          {
           enemy->rect.y += enemy->data->speed * deltaTime;
           float time = SDL_GetTicks() / 1000.0f;
           enemy->rect.x += sin(time * 3.0f) * 300.0f * deltaTime;
           }
// 1 kieeu
   else if(moveGroups[enemy->groupId] == 5)
           {
               if(enemy->rect.y < 250)   enemy->rect.y = enemy->rect.y + enemy->data->speed * deltaTime;
               else moveGroups[enemy->groupId] = 6;
           }
   else if(moveGroups[enemy->groupId] == 6)
           {
               float t = SDL_GetTicks() / 1000.0f;
               enemy->rect.x += cos(t * 1.2f) * 150.0f * deltaTime;
               enemy->rect.y += sin(t * 1.2f) * 150.0f * deltaTime;}

// dan 2 hang
   else if(moveGroups[enemy->groupId] == 7)
           {
               enemy->rect.y = enemy->rect.y + enemy->data->speed/1.5f * deltaTime;
               enemy->rect.x = enemy->rect.x + enemy->data->speed/2 * deltaTime;
               if(enemy->rect.y >= 150) moveGroups[enemy->groupId] = 9;
           }
   else if(moveGroups[enemy->groupId] == 8)
           {
               enemy->rect.y = enemy->rect.y + enemy->data->speed/1.5f * deltaTime;
               enemy->rect.x = enemy->rect.x - enemy->data->speed/2 * deltaTime;
               if(enemy->rect.y >= 250) moveGroups[enemy->groupId] = 10;
           }
   else if(moveGroups[enemy->groupId] == 9)
           {
               float t = SDL_GetTicks() / 1000.0f;
               enemy->rect.x += sin(t * 2.0f) * 80.0f * deltaTime;
           }
   else if(moveGroups[enemy->groupId] == 10)
           {
               float t = SDL_GetTicks() / 1000.0f;
               enemy->rect.x += cos(t * 2.0f) * 80.0f * deltaTime;
           }

    if(enemy->rect.y < 0) enemy->rect.y = 0;

    if(enemy->rect.x < PADDING)
        enemy->rect.x = PADDING;

    if(enemy->rect.x + enemy->rect.w > SCREEN_WIDTH - PADDING)
        enemy->rect.x = SCREEN_WIDTH - enemy->rect.w - PADDING;


    for(auto& other : enemys)
    {
        if(&other != enemy && other.active)
        {
            if(SDL_HasIntersectionF(&enemy->rect, &other.rect))
            {
                if(enemy->rect.x < other.rect.x)
                    enemy->rect.x -= 30.0f * deltaTime;
                else
                    enemy->rect.x += 30.0f * deltaTime;
            }
        }
    }
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
