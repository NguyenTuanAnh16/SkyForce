#include "BackGround.h"
#include "Config.h"


void BackGround::Init(SDL_Texture* backGround, SDL_Texture* nibiru, SDL_Texture* asteroid){
  bgTexture = backGround;
  ptTexture = nibiru;
  adTexture = asteroid;
  SDL_SetTextureColorMod(bgTexture, 180, 180, 180);
  SDL_SetTextureColorMod(ptTexture, 255, 255, 255);
}
void BackGround::Update(float deltaTime){
   // cuon nen
   bgY = bgY + BACKGROUND_SPEED * deltaTime;
   if(bgY >= SCREEN_HEIGHT)  bgY = 0;

   // cuon hanh tinh
   ptY = ptY + PLANET_SPEED * deltaTime;
   if(ptY >= SCREEN_HEIGHT)  ptY = -300;

   // bay thien thach
   time = time + deltaTime;
   adX = adX + ASTEROID_SPEED * deltaTime;
   adY = adY + (ASTEROID_SPEED / 2.86) * deltaTime;
   if(time >= 3){adX = rand() % SCREEN_WIDTH;adY = 0; time = rand()%3;}

}
void BackGround::Render(SDL_Renderer* renderer){

// ve nen
   bgRect1 = {bgX,bgY,SCREEN_WIDTH,SCREEN_HEIGHT};
   bgRect2 = {bgX,bgY-SCREEN_HEIGHT,SCREEN_WIDTH,SCREEN_HEIGHT};
   SDL_RenderCopyF(renderer,bgTexture,nullptr,&bgRect1);
   SDL_RenderCopyF(renderer,bgTexture,nullptr,&bgRect2);


// ve hanh tinh
   ptRect = {ptX+1000,ptY,180,180};
   SDL_RenderCopyF(renderer,ptTexture,nullptr,&ptRect);

// ve sao
   adRect = {adX,adY,30,30};
   SDL_RenderCopyExF(renderer,adTexture,NULL,&adRect,-40,NULL,SDL_FLIP_NONE);
}
