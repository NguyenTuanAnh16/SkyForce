#include "Menu.h"

void Button::Update(float deltaTime, float mouseX, float mouseY)
{
    hover =
        mouseX >= rect.x &&
        mouseX <= rect.x + rect.w &&
        mouseY >= rect.y &&
        mouseY <= rect.y + rect.h;


    if(hover)
    {
       scale = scale + 3 * deltaTime;
       if(scale > 1.2) scale = 1.2;
    }
    else
    {
       scale = scale - 3 * deltaTime;
       if(scale < 1) scale = 1;
    }
}


void Button::Render(SDL_Renderer* renderer)
{
    SDL_FRect dst;

    dst.w = rect.w * scale;
    dst.h = rect.h * scale;

    dst.x = rect.x - (dst.w - rect.w) / 2;
    dst.y = rect.y - (dst.h - rect.h) / 2;


    SDL_RenderCopyF(renderer, texture, nullptr, &dst);
}



void Menu::Init(MenuRes& res){
        backGround = res.backGround;
        rectBG = {0,0,1480,810};

        logo = res.logo;
        rectLG = {(SCREEN_WIDTH - 651/2)/2 ,30,651/2,391/2};

        play.texture = res.playGame;
        play.rect = {(SCREEN_WIDTH - 292) / 2, 350, 292, 60};

        select.texture = res.selectShip;
        select.rect = {(SCREEN_WIDTH - 292) / 2, 425, 292, 60};

        settings.texture = res.settings;
        settings.rect = {(SCREEN_WIDTH - 292) / 2, 500, 292, 60};

        exit.texture = res.exit;
        exit.rect = {(SCREEN_WIDTH - 292) / 2 , 575, 292, 60};

}


void Menu::Update(float deltaTime)
{
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);


    play.Update(deltaTime, mouseX, mouseY);
    select.Update(deltaTime, mouseX, mouseY);
    settings.Update(deltaTime, mouseX, mouseY);
    exit.Update(deltaTime, mouseX, mouseY);

}


void Menu::HandleEvent(SDL_Event& e, GameState& state)
{
    if(e.type == SDL_MOUSEBUTTONDOWN)
    {
        if(e.button.button == SDL_BUTTON_LEFT)
        {
            if(play.hover)
                state = GameState::SELECT_LEVEL;
            else if(select.hover)
                state = GameState::SELECT_SHIP;
            else if(exit.hover)
                state = GameState::EXIT;

        }
    }
}


void Menu::Render(SDL_Renderer* renderer)
{
    SDL_RenderCopyF(renderer,backGround,nullptr,&rectBG);
    SDL_RenderCopyF(renderer,logo,nullptr,&rectLG);
    play.Render(renderer);
    select.Render(renderer);
    settings.Render(renderer);
    exit.Render(renderer);
}
