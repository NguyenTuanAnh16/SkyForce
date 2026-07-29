#include "EnemySystem.h"

void EnemySystem::Init(int sum, EnemyDataBase* data){
    this->data = data;
    enemys.resize(sum);
}

// ren dich
void EnemySystem::Spawn(float x, float y,int type, int amount){
    int sumenemy = 0;
   for(auto& enemy : enemys){
     if(!enemy.active){
       enemy.active = true;
       enemy.type = type;
       enemy.rect = {x + sumenemy*(40 + data->Enemy(type).width),
                     y,
                     data->Enemy(type).width,
                     data->Enemy(type).height};

       enemy.rectHpMax = {enemy.rect.x,
                       enemy.rect.y - enemy.rect.h/10,
                       enemy.rect.w,
                       enemy.rect.h/10};

       enemy.rectHp = enemy.rectHpMax;
       enemy.hpNow = data->Enemy(type).hpMax;
       sumenemy ++;
      }
    if(sumenemy == amount) return;
   }
}

void EnemySystem::Update(float deltatime, WeaponSystem* weaponSystem){
  for(auto& enemy : enemys){
    if(enemy.active){
        enemy.rect.y = enemy.rect.y + data->Enemy(enemy.type).speed * deltatime;
        enemy.rectHpMax.y = enemy.rect.y - enemy.rect.h/5;
        enemy.rectHp.y = enemy.rectHpMax.y;
        enemy.rectHp.w = (enemy.hpNow/data->Enemy(enemy.type).hpMax) * enemy.rectHpMax.w;

        enemy.shoottime = deltatime + enemy.shoottime;

        if(enemy.shoottime >= data->Enemy(enemy.type).shootDelay){
            for(auto gun : data->Enemy(enemy.type).guns)
        {
            weaponSystem->Shoot(
                enemy.rect.x + gun.x,
                enemy.rect.y + gun.y,
                data->Enemy(enemy.type).shootType,
                'E');
        }
            enemy.shoottime = 0;
        }
        if(enemy.rect.y > 850) enemy.active = false;
    }
  }
}


void EnemySystem::Render(SDL_Renderer* renderer){
      for(auto& enemy : enemys){
        if(enemy.active){
        // khung mau
        SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
        SDL_RenderFillRectF(renderer, &enemy.rectHpMax);

        // mau
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderFillRectF(renderer, &enemy.rectHp);

        // may bay
        SDL_RenderCopyF(renderer,data->Enemy(enemy.type).texture, nullptr, &enemy.rect);

        }
      }

}
