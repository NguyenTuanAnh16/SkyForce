#include "EnemySystem.h"

void EnemySystem::Init(SDL_Texture* enemyOne,
                       SDL_Texture* enemyTwo,
                       SDL_Texture* enemyThree){
    data.Init(enemyOne,enemyTwo,enemyThree);
    enemys.resize(50);
}

void EnemySystem::Spawn(float x, float y,int type, int amount){
    int sumenemy = 0;
   for(auto& enemy : enemys){
     if(!enemy.active){
       enemy.active = true;  enemy.type = type;
       enemy.rect.x = x + sumenemy*(40 + data.Enemy(type).width);
       enemy.rect.y = y;
       enemy.rect.w = data.Enemy(type).width;
       enemy.rect.h = data.Enemy(type).height;
       sumenemy ++;
      }
    if(sumenemy == amount) return;
   }
}

void EnemySystem::Update(float deltatime, WeaponSystem* weaponSystem){
  for(auto& enemy : enemys){
    if(enemy.active){
        enemy.rect.y = enemy.rect.y + data.Enemy(enemy.type).speed * deltatime;
        enemy.shoottime = deltatime + enemy.shoottime;

        if(enemy.shoottime >= data.Enemy(enemy.type).shootDelay){
            for(auto gun : data.Enemy(enemy.type).guns)
        {
            weaponSystem->Shoot(
                enemy.rect.x + gun.x,
                enemy.rect.y + gun.y,
                data.Enemy(enemy.type).shootType);
        }
            enemy.shoottime = 0;
        }
        if(enemy.rect.y > 850) enemy.active = false;
    }
  }
}

void EnemySystem::Render(SDL_Renderer* rerderer){
      for(auto& enemy : enemys){
        if(enemy.active){
            SDL_RenderCopyF(rerderer,data.Enemy(enemy.type).texture, nullptr, &enemy.rect);
        }
      }

}
