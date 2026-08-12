#include "Pause.h"
#include "iostream"

void Pause::Init(MenuRes& res)
{

    boxTex = res.box;
    boxRect = {(SCREEN_WIDTH - 355) / 2 , 150, 355, 510};

    pauseLogoTex = res.pauseLogo;
    pauseLogoRect = {boxRect.x + (boxRect.w -170) / 2, boxRect.y  + 40, 170, 48};

    settings.texture = res.settings;
    settings.rect = {boxRect.x + (boxRect.w -244) / 2, boxRect.y  + 160, 244, 50};

    goBack.texture = res.goBack;
    goBack.rect = settings.rect;   goBack.rect.y = goBack.rect.y + 60;


}


void Pause::Update(float deltaTime)
{
    int mouseX, mouseY;

    SDL_GetMouseState(&mouseX,&mouseY);
    settings.Update(deltaTime, mouseX, mouseY);
    goBack.Update(deltaTime, mouseX, mouseY);

}


void Pause::HandleEvent(SDL_Event& e, GameState& state)
{

     if(e.type == SDL_MOUSEBUTTONDOWN)
    {
        if(e.button.button == SDL_BUTTON_LEFT)
        {   if(goBack.hover) state = GameState::MENU;
            if(settings.hover) state = GameState::PLAYING;
        }
    }
}


void Pause::Render(SDL_Renderer* renderer)
{
    SDL_RenderCopyF(renderer,boxTex,nullptr,&boxRect);


    SDL_RenderCopyF(renderer,pauseLogoTex,nullptr,&pauseLogoRect);

    settings.Render(renderer);

    goBack.Render(renderer);

}
