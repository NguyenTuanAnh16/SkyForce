#include "Starship.h"

void Starship::Init(SDL_Texture* starship){
       spTexture = starship;
       spX = 0;
       spY = 0;

}

void Starship::Update(float deltaTime){

key = SDL_GetKeyboardState(NULL);

if (key[SDL_SCANCODE_LEFT])
{
    spX = spX - STARSHIP_SPEED * deltaTime;
    if(spX < 0) spX = 0;
}

if (key[SDL_SCANCODE_RIGHT])
{
     spX = spX + STARSHIP_SPEED * deltaTime;
}

if (key[SDL_SCANCODE_UP])
{
    spY = spY - STARSHIP_SPEED * deltaTime;
}

if (key[SDL_SCANCODE_DOWN])
{
    spY = spY + STARSHIP_SPEED * deltaTime;
}

}

void Starship::Render(SDL_Renderer* renderer){
    spRect = {spX,spY,108,146};
    SDL_RenderCopyF(renderer,spTexture,nullptr,&spRect);

}

