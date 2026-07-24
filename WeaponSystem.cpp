#include "WeaponSystem.h"

void WeaponSystem::Init(SDL_Texture* bulletOne,SDL_Texture* bulletTwo){
    data.Init(bulletOne,bulletTwo);
    weapons.resize(50);
}

void WeaponSystem::Shoot(float x, float y, int type){
   for(auto& weapon : weapons){
     if(!weapon.active){
       weapon.active = true;
       weapon.type = type;
       weapon.rect.x = x;
       weapon.rect.y = y;
       weapon.rect.w = data.weapon(type).width;
       weapon.rect.h = data.weapon(type).height;
       return;
      }
   }
}

void WeaponSystem::Update(float deltaTime){
  for(auto& weapon : weapons){
    if(weapon.active){
        weapon.rect.y = weapon.rect.y - data.weapon(weapon.type).speed * deltaTime;
        if(weapon.rect.y < - 50 || weapon.rect.y > 810) weapon.active = false;
    }
  }
}

void WeaponSystem::Render(SDL_Renderer* rerderer){
      for(auto& weapon : weapons){
        if(weapon.active){
            SDL_RenderCopyF(rerderer,data.weapon(weapon.type).texture, nullptr, &weapon.rect);
        }
      }

}
