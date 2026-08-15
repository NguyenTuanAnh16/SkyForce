#ifndef _Player_H
#define _Player_H

#include <SDL.h>
#include "ResourceManager.h"
#include "Starship.h"
#include "WeaponSystem.h"
#include "SelectShip.h"
#include "EffectSystem.h"
#include "Menu.h"

struct Player
{
    // input
    const Uint8* key = nullptr;

    // máy bay
    Starship* starship = nullptr;
    float shoottime = 0;

    // điểm
    SDL_Texture* scoreTex = nullptr;
    SDL_Texture* numberTex = nullptr;
    SDL_FRect scoreRect;
    SDL_FRect numberRect;
    int score = 0;

    // máu
    SDL_Texture* hpTex = nullptr;
    SDL_FRect hpRect;
    SDL_FRect hpMaxRect;
    SDL_FRect hpNowRect;

    // dừng game
    Button pause;

    int customGunType = -1;       // -1: Đạn mặc định
    float customGunTimer = 0.0f;  // Đếm ngược 5s đổi đạn

    bool hasShield = false;       // Trạng thái khiên
    float shieldTimer = 0.0f;     // Đếm ngược 8s khiên
    float shieldHp = 0.0f;        // Máu khiên (200 HP)

    // Cơ chế vòng Hồi máu (Tương tự Khiên)
    bool hasHealing = false;
    float healTimer = 0.0f;       // Đếm ngược thời gian hiển thị vòng hồi máu (2s)

    // Các hàm tác động từ Item
    void heal(float amount, float duration = 2.0f) {
        if (starship) {
            starship->hpNow = std::min(starship->hpNow + amount, starship->hpMax);
        }
        hasHealing = true;        // Bật vòng hồi máu
        healTimer = duration;     // Thiết lập thời gian hiển thị (mặc định 2 giây)
    }

    void changeWeaponType(int newType, float duration = 5.0f) {
        customGunType = newType;
        customGunTimer = duration;
    }

    void activateShield(float duration = 8.0f, float maxHp = 200.0f) {
        hasShield = true;
        shieldTimer = duration;
        shieldHp = maxHp;
    }

    void takeDamage(float damage);

    void Reset();

    void Init(PlayerRes& player);

    void ChangeStarship(SelectShip& ship, StarshipDataBase& data, EffectSystem& effectSystem);

    void HandleEvent(SDL_Event& e, GameState& state);

    void Update(float deltaTime, WeaponSystem& weaponSystem, EffectSystem& effectSystem);

    void RenderScore(SDL_Renderer* renderer);

    void Render(SDL_Renderer* renderer);
};

#endif
