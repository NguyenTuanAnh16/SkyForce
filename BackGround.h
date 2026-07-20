#ifndef _BackGround_H
#define _BackGround_H

#include <SDL.h>

struct BackGround
{
    // nen
    SDL_Texture*  bgTexture;
    float bgX = 0,bgY = 0;
    SDL_FRect bgRect1,bgRect2;

    // hanh tinh
    SDL_Texture* ptTexture;
    float ptX = 0,ptY = 0;
    SDL_FRect ptRect;

    // sao
    SDL_Texture* adTexture;
    float adX = 0,adY = 0;
    float time;
    SDL_FRect adRect;


    void Init(SDL_Texture* backGround,
              SDL_Texture* nibiru,
              SDL_Texture* asteroid);
    void Update(float deltaTime);
    void Render(SDL_Renderer* renderer);

};
#endif
