#include "Player.h"


void Player::ChangeStarship(Starship ship)
{
        starship = ship;
}


void Player::Update(float deltaTime,WeaponSystem* weaponSystem)
{
    key = SDL_GetKeyboardState(nullptr);

// di chuyen

    if(key[SDL_SCANCODE_LEFT])
    {
        starship.rect.x -= starship.speed * deltaTime;

        if(starship.rect.x < 0)
            starship.rect.x = 0;
    }


    if(key[SDL_SCANCODE_RIGHT])
    {
        starship.rect.x += starship.speed * deltaTime;

        if(starship.rect.x + starship.rect.w > SCREEN_WIDTH)
            starship.rect.x = SCREEN_WIDTH - starship.rect.w;
    }


    if(key[SDL_SCANCODE_UP])
    {
        starship.rect.y -= starship.speed * deltaTime;

        if(starship.rect.y < 0)
            starship.rect.y = 0;
    }


    if(key[SDL_SCANCODE_DOWN])
    {
        starship.rect.y += starship.speed * deltaTime;

        if(starship.rect.y + starship.rect.h > SCREEN_HEIGHT)
            starship.rect.y = SCREEN_HEIGHT - starship.rect.h;
    }


// ban
    shoottime = shoottime + deltaTime;

    if(shoottime >= starship.shootdelay)
    {
        for(auto gun : starship.guns)
        {
            weaponSystem->Shoot(
                starship.rect.x + gun.x,
                starship.rect.y + gun.y,
                starship.gunType);
        }

        shoottime = 0;
    }


}


void Player::Render(SDL_Renderer* renderer)
{
    starship.Render(renderer);
}
