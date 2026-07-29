#include "Player.h"


void Player::ChangeStarship(SelectShip& ship, StarshipDataBase& data, EffectSystem& effectSystem)
{

    if(ship.selectedShip == 1) starship = &data.one;
    if(ship.selectedShip == 2) starship = &data.two;
    if(ship.selectedShip == 3) starship = &data.three;

    effectSystem.ClearEngine();
    for(auto& engine : starship->engines)
{
    effectSystem.AddEngine(3,starship->engineSize);
}
}

void Player::Update(float deltaTime, WeaponSystem& weaponSystem, EffectSystem& effectSystem)
{
    key = SDL_GetKeyboardState(nullptr);

// di chuyen

    if(key[SDL_SCANCODE_LEFT])
    {
        starship->rect.x = starship->rect.x - starship->speed * deltaTime;

        if(starship->rect.x < 0)
            starship->rect.x = 0;
    }


    if(key[SDL_SCANCODE_RIGHT])
    {
        starship->rect.x = starship->rect.x + starship->speed * deltaTime;

        if(starship->rect.x + starship->rect.w > SCREEN_WIDTH)
            starship->rect.x = SCREEN_WIDTH - starship->rect.w;
    }


    if(key[SDL_SCANCODE_UP])
    {
        starship->rect.y = starship->rect.y - starship->speed * deltaTime;

        if(starship->rect.y < 0)
            starship->rect.y = 0;
    }


    if(key[SDL_SCANCODE_DOWN])
    {
        starship->rect.y = starship->rect.y + starship->speed * deltaTime;

        if(starship->rect.y + starship->rect.h > SCREEN_HEIGHT)
            starship->rect.y = SCREEN_HEIGHT - starship->rect.h;
    }

// dong co
   effectSystem.FollowEngine(*starship);

// mau
      starship->rectHpNow.w = (starship->hpNow / starship->hpMax) * starship->rectHpMax.w;


// ban
    shoottime = shoottime + deltaTime;

    if(shoottime >= starship->shootdelay)
    {
        for(auto gun : starship->guns)
        {
            weaponSystem.Shoot(
                starship->rect.x + gun.x,
                starship->rect.y + gun.y,
                starship->gunType,
                'P');
        }

        shoottime = 0;
    }

}


void Player::Render(SDL_Renderer* renderer)
{
    SDL_RenderCopyF(renderer,starship->texture,nullptr,&starship->rect);

    // khung mau
    SDL_SetRenderDrawColor(renderer,255,255,255,100);
    SDL_RenderFillRectF(renderer,
                        &starship->rectHpMax);

    // máu còn lại
    SDL_SetRenderDrawColor(renderer,255,0,0,200);
    SDL_RenderFillRectF(renderer,
                        &starship->rectHpNow);


}
