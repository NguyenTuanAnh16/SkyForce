#include "SelectLevel.h"


void SelectLevel::Init(MenuRes& res)
{
    backGround = res.backGround;
    rectBG = {0, 0, 1480, 810};

    logo = res.logo;
    rectLG = {(SCREEN_WIDTH - 651/2)/2 ,30,651/2,391/2};

    levelOne.texture = res.levelOne;
    levelOne.rect = {(SCREEN_WIDTH - 292) / 2, 350, 292, 60};

    levelTwo.texture = res.levelTwo;
    levelTwo.rect = {(SCREEN_WIDTH - 292) / 2, 425, 292, 60};

    levelThree.texture = res.levelThree;
    levelThree.rect = {(SCREEN_WIDTH - 292) / 2, 500, 292, 60};

    goBack.texture = res.goBack;
    goBack.rect = {(SCREEN_WIDTH - 292) / 2 , 575, 292, 60};
}


void SelectLevel::Update(float deltaTime)
{
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    levelOne.Update(deltaTime, mouseX, mouseY);
    levelTwo.Update(deltaTime, mouseX, mouseY);
    levelThree.Update(deltaTime, mouseX, mouseY);
    goBack.Update(deltaTime,mouseX,mouseY);
}

void SelectLevel::SetTargetScore()
{
    if(level == 1)
        targetScore = 100;
    else if(level == 2)
        targetScore = 150;
    else if(level == 3)
        targetScore = 200;
}

void SelectLevel::HandleEvent(SDL_Event& e, GameState& state)
{
    if(e.type == SDL_MOUSEBUTTONDOWN)
    {
        if(e.button.button == SDL_BUTTON_LEFT)
        {
            if(levelOne.hover)
               {   level = 1;
                   state = GameState::PLAYING;}
            else if(levelTwo.hover)
                    {   level = 2;
                        state = GameState::PLAYING;}
            else if(levelThree.hover)
                     {  level = 3;
                        state = GameState::PLAYING;}
            else if(goBack.hover)
                state = GameState::MENU;

        }
    }
}


void SelectLevel::Render(SDL_Renderer* renderer)
{
    SDL_RenderCopyF(renderer, backGround, nullptr, &rectBG);
    SDL_RenderCopyF(renderer, logo, nullptr, &rectLG);

    levelOne.Render(renderer);
    levelTwo.Render(renderer);
    levelThree.Render(renderer);
    goBack.Render(renderer);
}
