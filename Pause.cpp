#include "Pause.h"
#include "iostream"

void Pause::Init(MenuRes& res)
{

    boxTex = res.box;
    boxRect = {(SCREEN_WIDTH - 355) / 2 , 150, 355, 410};

// pause
    pauseLogoTex = res.pauseLogo;
    pauseLogoRect = {boxRect.x + (boxRect.w -194) / 2, boxRect.y  + 40, 194, 55};

    continueBt.texture = res.continues;
    continueBt.rect = {boxRect.x + (boxRect.w -244) / 2, boxRect.y  + 150, 244, 50};

// win
    winLogoTex = res.winLogo;
    winLogoRect = {boxRect.x + (boxRect.w - 214) / 2, boxRect.y  + 40, 214, 114};

    nextLever.texture = res.nextLever;
    nextLever.rect = {boxRect.x + (boxRect.w -244) / 2, boxRect.y  + 150, 244, 50};

// lost

    lostLogoTex = res.lostLogo;
    lostLogoRect = {boxRect.x + (boxRect.w - 214) / 2, boxRect.y  + 40, 214, 114};

    retry.texture = res.retry;
    retry.rect = {boxRect.x + (boxRect.w -244) / 2, boxRect.y  + 150, 244, 50};

    goBack.texture = res.goBack;
    goBack.rect = continueBt.rect;   goBack.rect.y = goBack.rect.y + 70;

    exit.texture = res.exit;
    exit.rect = goBack.rect; exit.rect.y = exit.rect.y + 70;

}


void Pause::Update(float deltaTime, GameState& state)
{
    int mouseX, mouseY;

    SDL_GetMouseState(&mouseX,&mouseY);
if(state == GameState::PAUSE)    continueBt.Update(deltaTime, mouseX, mouseY);
else if(state == GameState::WIN) nextLever.Update(deltaTime, mouseX, mouseY);
else if(state == GameState::LOST) retry.Update(deltaTime, mouseX, mouseY);
    goBack.Update(deltaTime, mouseX, mouseY);
    exit.Update(deltaTime,mouseX,mouseY);

}


void Pause::HandleEvent(SDL_Event& e, GameState& state)
{

     if(e.type == SDL_MOUSEBUTTONDOWN)
    {
        if(e.button.button == SDL_BUTTON_LEFT)
        {
            if(state == GameState::PAUSE && continueBt.hover) state = GameState::PLAYING;
            else if(state == GameState::WIN && nextLever.hover) state = GameState::PLAYING;
            else if(state == GameState::LOST && retry.hover) state = GameState::PLAYING;
            if(goBack.hover) state = GameState::MENU;
            if(exit.hover) state = GameState::EXIT;
        }
    }
}


void Pause::Render(SDL_Renderer* renderer, GameState& state)
{
    SDL_RenderCopyF(renderer,boxTex,nullptr,&boxRect);

if(state == GameState::PAUSE)
{
    SDL_RenderCopyF(renderer,pauseLogoTex,nullptr,&pauseLogoRect);
    continueBt.Render(renderer);
}
else if (state == GameState::WIN)
{
    SDL_RenderCopyF(renderer,winLogoTex,nullptr,&winLogoRect);
    nextLever.Render(renderer);
}

else if (state == GameState::LOST)
{
    SDL_RenderCopyF(renderer,lostLogoTex,nullptr,&lostLogoRect);
    retry.Render(renderer);
}

    goBack.Render(renderer);

    exit.Render(renderer);

}
