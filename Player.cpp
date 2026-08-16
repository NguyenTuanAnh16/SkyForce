#include "Player.h"


void Player::Init(PlayerRes& player)
{
    scoreTex = player.score;
    scoreRect = {0,0,93,30};

    numberTex = player.number;
    numberRect = {0,0,1500,162};

    hpTex = player.hp;
    hpRect = {0,35,67,30};
    hpMaxRect = {70,39,100,22};
    hpNowRect = hpMaxRect;

    pause.texture = player.pause;
    pause.rect = {0,70,30,30};
}


void Player::ChangeStarship(SelectShip& ship, StarshipDataBase& data, EffectSystem& effectSystem)
{

    if(ship.selectedShip == 1) starship = &data.one;
    if(ship.selectedShip == 2) starship = &data.two;
    if(ship.selectedShip == 3) starship = &data.three;

    effectSystem.ClearEngine();
    starship->defaultWeaponType = starship->weaponType;
    for(auto& engine : starship->engines)
{
    effectSystem.AddEngine(EffectType::SHIP_ONE,starship->engineSize);
}
}

void Player::Update(float deltaTime, WeaponSystem& weaponSystem, EffectSystem& effectSystem)
{
    // di chuyen
    key = SDL_GetKeyboardState(nullptr);

    if(key[SDL_SCANCODE_LEFT])
        {starship->rect.x = starship->rect.x - starship->speed * deltaTime;
         if(starship->rect.x < 0)
            starship->rect.x = 0;}

    if(key[SDL_SCANCODE_RIGHT])
        {starship->rect.x = starship->rect.x + starship->speed * deltaTime;
         if(starship->rect.x + starship->rect.w > SCREEN_WIDTH)
            starship->rect.x = SCREEN_WIDTH - starship->rect.w;}

    if(key[SDL_SCANCODE_UP])
        {starship->rect.y = starship->rect.y - starship->speed * deltaTime;
         if(starship->rect.y < 0)
            starship->rect.y = 0;}

    if(key[SDL_SCANCODE_DOWN])
        {starship->rect.y = starship->rect.y + starship->speed * deltaTime;
         if(starship->rect.y + starship->rect.h > SCREEN_HEIGHT)
            starship->rect.y = SCREEN_HEIGHT - starship->rect.h;}

// dong co
   effectSystem.FollowStarship(*starship);

// mau
    hpNowRect.w = (starship->hpNow / starship->hpMax) * hpMaxRect.w;
    if(hpNowRect.w < 0) hpNowRect.w = 0;


// ban
    shoottime = shoottime + deltaTime;

    if(shoottime >= starship->shootdelay)
    {
        for(auto gun : starship->guns)
        {
            weaponSystem.Shoot(
                starship->rect.x + gun.x,
                starship->rect.y + gun.y,
                starship->weaponType,
                'P');
        }

        shoottime = 0;
    }

// dung game
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    pause.Update(deltaTime, mouseX, mouseY);
}

void Player::HandleEvent(SDL_Event& e, GameState& state)
{
    if(e.type == SDL_MOUSEBUTTONDOWN)
    {
        if(e.button.button == SDL_BUTTON_LEFT)
        {
            if(pause.hover) state = GameState::PAUSE;

        }
    }
}


void Player::RenderScore(SDL_Renderer* renderer)
{
    int temp = score;

    int numbers[10];
    int sum = 0;
    int numberWidth = numberRect.w/ 10;

    if(temp == 0){numbers[0] = 0; sum = 1;}
    while(temp > 0)
    {
        numbers[sum] = temp%10;
        temp = temp / 10;
        sum++;
    }

    // Render từ trái sang phải
   for (int i = sum - 1; i >= 0; i--)
   {
    SDL_Rect src = {numbers[i] * numberWidth, 0, numberWidth, numberRect.h};
    SDL_FRect dst = {scoreRect.w  + (sum - i - 1)* 20 + 3, scoreRect.y + 6, 20, 22};

    SDL_RenderCopyF(renderer, numberTex, &src, &dst);
   }
}


void Player::Reset()
{
    starship->rect.x = (SCREEN_WIDTH - starship->rect.w) / 2;
    starship->rect.y =  SCREEN_HEIGHT * 0.8;

    score = 0;
    starship->hpNow = starship->hpMax;

}

void Player::Render(SDL_Renderer* renderer)
{

if(starship->hpNow > 0)  SDL_RenderCopyF(renderer,starship->texture,nullptr,&starship->rect);

    SDL_RenderCopyF(renderer,scoreTex,nullptr,&scoreRect);
    SDL_RenderCopyF(renderer,hpTex,nullptr,&hpRect);


    // khung mau
    SDL_SetRenderDrawColor(renderer,255,255,255,100);
    SDL_RenderFillRectF(renderer,&hpMaxRect);

    // máu còn lại
    SDL_SetRenderDrawColor(renderer,255,0,0,200);
    SDL_RenderFillRectF(renderer,&hpNowRect);

    RenderScore(renderer);
    pause.Render(renderer);
}
