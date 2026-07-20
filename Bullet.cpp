#include "Bullet.h"

void BulletPlayer::Init(SDL_Texture* bulletplayer){
     btTexture = bulletplayer;
     btX = 500;
     btY = 500;

}

void BulletPlayer::Update(float deltaTime){
    btY = btY - BULLETPLAYER_SPEED * deltaTime;
}

void BulletPlayer::Render(SDL_Renderer* renderer){
      btRect = {btX, btY, 322/20, 609/20};
      SDL_RenderCopyF(renderer,btTexture,nullptr,&btRect);

}
