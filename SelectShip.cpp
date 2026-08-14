#include "SelectShip.h"
#include "iostream"

void SelectShip::Init(MenuRes& res, StarshipDataBase* starship)
{
    backGround = res.backGround;
    rectBG = {0,0,SCREEN_WIDTH,SCREEN_HEIGHT};

    rectBox = {(SCREEN_WIDTH - 1000) / 2 , (SCREEN_HEIGHT - 550) / 2, 1000, 550};

    data = starship;
    rectShip = {rectBox.x + 100, rectBox.y + 50 , 500, 0};

    shipInfo = res.shipInfo;
    rectShipInfo = {rectShip.x + rectShip.w + 50, rectShip.y , 1328/4, 852/4};
    rectName = {rectShipInfo.x + (rectShipInfo.w - 153) / 2, rectShipInfo.y - 45 , 153, 35};


    play.texture = res.playGame;
    play.rect = {rectBox.x + (rectBox.w - 292 * 2 - 70) / 2, rectBox.y + rectBox.h + 20, 292, 60};

    goBack.texture = res.goBack;
    goBack.rect = {play.rect.x + play.rect.w + 70, rectBox.y + rectBox.h + 20, 292, 60};

    rightShip.texture = res.right;
    rightShip.rect = {rectBox.x + rectBox.w + 30, rectBox.y + (rectBox.h - 85) / 2, 92, 85};

    leftShip.texture = res.left;
    leftShip.rect = {rectBox.x - 92 - 30, rectBox.y + (rectBox.h - 85) / 2, 92, 85};


}


void SelectShip::Update(float deltaTime)
{

    int mouseX, mouseY;

    SDL_GetMouseState(&mouseX,&mouseY);

    play.Update(deltaTime, mouseX, mouseY);
    goBack.Update(deltaTime, mouseX, mouseY);

    rightShip.Update(deltaTime,mouseX,mouseY);
    leftShip.Update(deltaTime,mouseX,mouseY);

}


void SelectShip::DrawBar(SDL_Renderer* renderer, int value, int maxValue, float x, float y)
{
    int size = value * 10 / maxValue;

    for(int i = 0; i < 10; i++)
    {
        SDL_FRect rect = {x + i * 16, y, 15, 20};

        if(i < size)
        {
            SDL_SetRenderDrawColor(renderer,0,200,255,255);
        }
        else
        {
            SDL_SetRenderDrawColor(renderer,80,80,80,255);
        }

        SDL_RenderFillRectF(renderer,&rect);
    }
}


void SelectShip::HandleEvent(SDL_Event& e, GameState& state, Music& musicValue)
{

     if(e.type == SDL_MOUSEBUTTONDOWN)
    {
        if(e.button.button == SDL_BUTTON_LEFT)
        {
            if(play.hover)  state = GameState::SELECT_LEVEL;
            if(goBack.hover) state = GameState::MENU;
            if(rightShip.hover)
                 {  selectedShip++;
                    if(selectedShip > 3)
                    selectedShip = 1;
                    musicValue.PlayClick();
                 }
            if(leftShip.hover)
                 {  selectedShip--;
                    if(selectedShip < 1)
                    selectedShip = 3;
                    musicValue.PlayClick();
                 }
        }
    }
}


void SelectShip::Render(SDL_Renderer* renderer)
{
    SDL_RenderCopyF(renderer, backGround, nullptr, &rectBG);


    SDL_SetRenderDrawColor(renderer,255,255,255,100);
    SDL_RenderFillRectF(renderer,&rectBox);


    Starship* current = nullptr;

    if(selectedShip == 1)
        current = &data->one;

    else if(selectedShip == 2)
        current = &data->two;

    else
        current = &data->three;


    rectShip.h = (rectShip.w / current->rect.w) * current->rect.h;
    SDL_RenderCopyF(renderer, current->texture, nullptr, &rectShip );
    SDL_RenderCopyF(renderer, current->nameTexture, nullptr,&rectName);

    SDL_RenderCopyF(renderer,shipInfo,nullptr,&rectShipInfo);


    play.Render(renderer);
    goBack.Render(renderer);
    rightShip.Render(renderer);
    leftShip.Render(renderer);
    DrawBar(renderer, current->hpMax, MAX_SHIP_HP, rectShipInfo.x + 76, rectShipInfo.y + 42);
    DrawBar(renderer, current->speed, MAX_SHIP_SPEED, rectShipInfo.x + 120, rectShipInfo.y + 96);
    DrawBar(renderer, 1.0f/current->shootdelay, 1.0f/MAX_SHOOT_DELAY, rectShipInfo.x + 147, rectShipInfo.y + 150);


}
