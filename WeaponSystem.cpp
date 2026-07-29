#include "WeaponSystem.h"

void WeaponSystem::Init(int sum,WeaponDataBase* data){
    this->data = data;
    weapons.resize(sum);
}

void WeaponSystem::Shoot(float x, float y, int type, char owner){
   for(auto& weapon : weapons){
     if(!weapon.active){
       weapon.active = true;
       weapon.type = type;
       weapon.owner = owner;
       weapon.rect.x = x;
       weapon.rect.y = y;
       weapon.rect.w = data->weapon(type).width;
       weapon.rect.h = data->weapon(type).height;
       return;
      }
   }
}

void WeaponSystem::Update(float deltaTime){
  for(auto& weapon : weapons){
    if(weapon.active){
        weapon.rect.y = weapon.rect.y - data->weapon(weapon.type).speed * deltaTime;
        if(weapon.rect.y < - 50 || weapon.rect.y > 810) weapon.active = false;
    }
  }
}

void WeaponSystem::Render(SDL_Renderer* rerderer){
      for(auto& weapon : weapons){
        if(weapon.active){
            SDL_RenderCopyF(rerderer,data->weapon(weapon.type).texture, nullptr, &weapon.rect);
        }
      }

}
