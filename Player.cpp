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

void Player::Reset()
{
    if (starship != nullptr) {
        starship->rect.x = (SCREEN_WIDTH - starship->rect.w) / 2.0f;
        starship->rect.y = SCREEN_HEIGHT * 0.8f;
        starship->hpNow = starship->hpMax;
    }

    score = 0;
    shoottime = 0;

    // Reset sạch các trạng thái Item
    customGunType = -1;
    customGunTimer = 0.0f;
    hasShield = false;
    shieldTimer = 0.0f;
    shieldHp = 0.0f;
}

void Player::ChangeStarship(SelectShip& ship, StarshipDataBase& data, EffectSystem& effectSystem)
{
    if(ship.selectedShip == 1) starship = &data.one;
    if(ship.selectedShip == 2) starship = &data.two;
    if(ship.selectedShip == 3) starship = &data.three;

    effectSystem.ClearEngine();
    for(size_t i = 0; i < starship->engines.size(); i++)
    {
        effectSystem.AddEngine(3, starship->engineSize);
    }
}

void Player::Update(float deltaTime, WeaponSystem& weaponSystem, EffectSystem& effectSystem)
{
    // Di chuyển
    key = SDL_GetKeyboardState(nullptr);

    if(key[SDL_SCANCODE_LEFT]) {
        starship->rect.x -= starship->speed * deltaTime;
        if(starship->rect.x < 0) starship->rect.x = 0;
    }
    if(key[SDL_SCANCODE_RIGHT]) {
        starship->rect.x += starship->speed * deltaTime;
        if(starship->rect.x + starship->rect.w > SCREEN_WIDTH)
            starship->rect.x = SCREEN_WIDTH - starship->rect.w;
    }
    if(key[SDL_SCANCODE_UP]) {
        starship->rect.y -= starship->speed * deltaTime;
        if(starship->rect.y < 0) starship->rect.y = 0;
    }
    if(key[SDL_SCANCODE_DOWN]) {
        starship->rect.y += starship->speed * deltaTime;
        if(starship->rect.y + starship->rect.h > SCREEN_HEIGHT)
            starship->rect.y = SCREEN_HEIGHT - starship->rect.h;
    }

    // Động cơ & Máu
    effectSystem.FollowEngine(*starship);
    effectSystem.FollowShield(*starship, hasShield);
    effectSystem.FollowNotif(*starship);
    hpNowRect.w = (starship->hpNow / starship->hpMax) * hpMaxRect.w;
    if(hpNowRect.w < 0) hpNowRect.w = 0;

    // thời gian duy trì nâng cấp
    if (customGunTimer > 0) {
        customGunTimer -= deltaTime;
        if (customGunTimer <= 0) {
            customGunTimer = 0.0f;
            customGunType = -1; // Trở về đạn gốc
        }
    }

    // 4. Đếm ngược thời gian Khiên (8s)
    if (hasShield) {
        shieldTimer -= deltaTime;
        if (shieldTimer <= 0.0f || shieldHp <= 0.0f) {
            hasShield = false;
            shieldTimer = 0.0f;
            shieldHp = 0.0f;
        }
    }

    // 5. Bắn đạn
    shoottime = shoottime + deltaTime;

    if (shoottime >= starship->shootdelay)
    {
    // Lấy loại đạn đang đổi (nếu còn timer) hoặc đạn gốc của tàu
        int currentType = (customGunType != -1) ? customGunType : starship->gunType;

        for (auto gun : starship->guns)
        {
            weaponSystem.Shoot(
                starship->rect.x + gun.x,
                starship->rect.y + gun.y,
                currentType, //
                'P');
        }

    shoottime = 0;
    }

    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    pause.Update(deltaTime, mouseX, mouseY);
}

void Player::HandleEvent(SDL_Event& e, GameState& state)
{
    if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
    {
        if(pause.hover) state = GameState::PAUSE;
    }
}

void Player::RenderScore(SDL_Renderer* renderer)
{
    int temp = score;
    int numbers[10];
    int sum = 0;
    int numberWidth = numberRect.w / 10;

    if(temp == 0) { numbers[0] = 0; sum = 1; }
    while(temp > 0) {
        numbers[sum] = temp % 10;
        temp /= 10;
        sum++;
    }

    for (int i = sum - 1; i >= 0; i--) {
        SDL_Rect src = {numbers[i] * numberWidth, 0, numberWidth, static_cast<int>(numberRect.h)};
        SDL_FRect dst = {scoreRect.w + (sum - i - 1) * 20 + 3, scoreRect.y + 6, 20, 22};
        SDL_RenderCopyF(renderer, numberTex, &src, &dst);
    }
}

void Player::Render(SDL_Renderer* renderer)
{
    SDL_RenderCopyF(renderer, starship->texture, nullptr, &starship->rect);
    SDL_RenderCopyF(renderer, scoreTex, nullptr, &scoreRect);
    SDL_RenderCopyF(renderer, hpTex, nullptr, &hpRect);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 100);
    SDL_RenderFillRectF(renderer, &hpMaxRect);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 200);
    SDL_RenderFillRectF(renderer, &hpNowRect);

    RenderScore(renderer);
    pause.Render(renderer);
}
