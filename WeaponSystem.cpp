#include "WeaponSystem.h"

void WeaponSystem::Init(WeaponDataBase* data){
    this->data = data;
    weapons.resize(100);
}

void WeaponSystem::Shoot(float x, float y, WeaponType type, char owner){
   for(auto& weapon : weapons){
     if(!weapon.active){
       weapon.active = true;
       weapon.data = data->Get(type);
       weapon.owner = owner;
       weapon.rect.w = weapon.data->width;
       weapon.rect.h = weapon.data->height;
       weapon.rect.x = x - weapon.rect.w / 2;
       weapon.rect.y = y - weapon.rect.h / 2;
       return;
      }
   }
}

void WeaponSystem::Update(float deltaTime){
  for(auto& weapon : weapons){
    if(weapon.active){
        weapon.rect.y = weapon.rect.y - weapon.data->speed * deltaTime;
        if(weapon.rect.y < - 50 || weapon.rect.y > 810) weapon.active = false;
    }
  }
}

void WeaponSystem::Reset()
{
     for(auto& weapon : weapons)  weapon.active = false;
}

void WeaponSystem::Render(SDL_Renderer* rerderer){
      for(auto& weapon : weapons){
        if(weapon.active){
            SDL_RenderCopyF(rerderer,weapon.data->texture, nullptr, &weapon.rect);
        }
      }
}
