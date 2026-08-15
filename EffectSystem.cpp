#include "EffectSystem.h"
#include <algorithm>

void EffectSystem::Init(EffectDataBase* data)
{
    this->data = data;
    blasts.resize(500);
    engines.resize(20);
    notifs.resize(10);
}

void EffectSystem::AddBlast(float x, float y, int type, float effectSize)
{
    if (!data) return;
    const auto& fx = data->Effect(type);
    float height = static_cast<float>(fx.height) / (static_cast<float>(fx.width) / effectSize);

    for (auto& blast : blasts)
    {
        if (!blast.active)
        {
            blast.active = true;
            blast.type = type;
            blast.rect = { x - effectSize / 2.0f, y - height / 2.0f, effectSize, height };
            blast.frameNow = 0;
            blast.timer = 0.0f;
            blast.src = { 0, 0, fx.width, fx.height };
            return;
        }
    }
}

void EffectSystem::AddEngine(int type, float effectSize)
{
    if (!data) return;
    const auto& fx = data->Effect(type);

    for (auto& engine : engines)
    {
        if (!engine.active)
        {
            engine.active = true;
            engine.type = type;
            engine.rect.w = effectSize;
            engine.rect.h = static_cast<float>(fx.height) / (static_cast<float>(fx.width) / effectSize);
            engine.frameNow = 0;
            engine.timer = 0.0f;
            engine.src = { 0, 0, fx.width, fx.height };
            return;
        }
    }
}

void EffectSystem::AddItemNotif(float x, float y, int type, float duration)
{
    if (!data || type == 4 || type == 5) return;

    const auto& fx = data->Effect(type);

    for (auto& eff : notifs)
    {
        if (!eff.active)
        {
            eff.active = true;
            eff.type = type;
            eff.timer = 0.0f;
            eff.maxDuration = duration;
            eff.frameNow = 0;
            eff.rect = { x - fx.width / 2.0f, y - fx.height, static_cast<float>(fx.width), static_cast<float>(fx.height) };
            eff.src = { 0, 0, fx.width, fx.height };
            return;
        }
    }
}

void EffectSystem::FollowEngine(Starship& starship)
{
    size_t count = std::min(starship.engines.size(), engines.size());
    for (size_t i = 0; i < count; ++i)
    {
        if (engines[i].active)
        {
            engines[i].rect.x = starship.rect.x + starship.engines[i].x - engines[i].rect.w / 2.0f;
            engines[i].rect.y = starship.rect.y + starship.engines[i].y;
        }
    }
}

void EffectSystem::FollowNotif(Starship& starship)
{
    constexpr float notifW = 180.0f;
    constexpr float notifH = 80.0f;

    for (auto& notif : notifs)
    {
        if (notif.active)
        {
            notif.rect.w = notifW;
            notif.rect.h = notifH;
            notif.rect.x = starship.rect.x + (starship.rect.w - notifW) / 2.0f;
            notif.rect.y = starship.rect.y - 35.0f - (notif.timer * 30.0f);
        }
    }
}

void EffectSystem::FollowShield(Starship& starship, bool hasShield)
{
    shieldAura.active = hasShield;
    if (hasShield && data)
    {
        shieldAura.type = 7;
        constexpr float padding = 42.0f;
        shieldAura.rect = {
            starship.rect.x - padding,
            starship.rect.y - padding,
            starship.rect.w + padding * 2.0f,
            starship.rect.h + padding * 2.0f
        };

        const auto& fx = data->Effect(7);
        shieldAura.src = { shieldAura.frameNow * fx.width, 0, fx.width, fx.height };
    }
}

void EffectSystem::FollowHealing(Starship& starship, bool hasHealing)
{
    healAura.active = hasHealing;
    if (hasHealing && data)
    {
        healAura.type = 8;
        constexpr float padding = 42.0f;
        healAura.rect = {
            starship.rect.x - padding,
            starship.rect.y - padding,
            starship.rect.w + padding * 2.0f,
            starship.rect.h + padding * 2.0f
        };

        const auto& fx = data->Effect(8);
        healAura.src = { healAura.frameNow * fx.width, 0, fx.width, fx.height };
    }
}

void EffectSystem::ClearEngine()
{
    for (auto& engine : engines) engine.active = false;
}

void EffectSystem::Update(float deltaTime)
{
    if (!data) return;

    // Blasts
    for (auto& blast : blasts)
    {
        if (!blast.active) continue;

        blast.timer += deltaTime;
        const auto& fx = data->Effect(blast.type);

        if (blast.timer >= fx.frameTime)
        {
            blast.timer = 0.0f;
            blast.frameNow++;

            if (blast.frameNow >= fx.frame)
            {
                blast.active = false;
            }
            else
            {
                blast.src = { blast.frameNow * fx.width, 0, fx.width, fx.height };
            }
        }
    }

    // Engines
    for (auto& engine : engines)
    {
        if (!engine.active) continue;

        engine.timer += deltaTime;
        const auto& fx = data->Effect(engine.type);

        if (engine.timer >= fx.frameTime)
        {
            engine.timer = 0.0f;
            engine.frameNow = (engine.frameNow + 1) % fx.frame;
            engine.src = { engine.frameNow * fx.width, 0, fx.width, fx.height };
        }
    }

    //Notif
    for (auto& notif : notifs)
    {
        if (!notif.active) continue;

        notif.timer += deltaTime;
        if (notif.timer >= notif.maxDuration)
        {
            notif.active = false;
            continue;
        }

        const auto& fx = data->Effect(notif.type);
        if (fx.frame > 1 && fx.frameTime > 0.0f)
        {
            notif.frameNow = static_cast<int>(notif.timer / fx.frameTime) % fx.frame;
            notif.src = { notif.frameNow * fx.width, 0, fx.width, fx.height };
        }
    }

    //Shield
    if (shieldAura.active)
    {
        const auto& fx = data->Effect(7);
        if (fx.frame > 1 && fx.frameTime > 0.0f)
        {
            shieldAura.timer += deltaTime;
            shieldAura.frameNow = static_cast<int>(shieldAura.timer / fx.frameTime) % fx.frame;
            shieldAura.src = { shieldAura.frameNow * fx.width, 0, fx.width, fx.height };
        }
    }

    //Heal
    if (healAura.active)
    {
        const auto& fx = data->Effect(8);
        if (fx.frame > 1 && fx.frameTime > 0.0f)
        {
            healAura.timer += deltaTime;
            healAura.frameNow = static_cast<int>(healAura.timer / fx.frameTime) % fx.frame;
            healAura.src = { healAura.frameNow * fx.width, 0, fx.width, fx.height };
        }
    }
}

void EffectSystem::Reset()
{
    for (auto& blast : blasts) blast.active = false;
    for (auto& engine : engines) engine.active = false;
    for (auto& notif : notifs)   notif.active = false;
    shieldAura.active = false;
    healAura.active = false;
}

void EffectSystem::Render(SDL_Renderer* renderer)
{
    if (!data) return;

    if (healAura.active)
    {
        const auto& fx = data->Effect(healAura.type);
        if (fx.texture)
            SDL_RenderCopyF(renderer, fx.texture, &healAura.src, &healAura.rect);
        else
        {
            SDL_SetRenderDrawColor(renderer, 0, 255, 100, 255);
            SDL_RenderDrawRectF(renderer, &healAura.rect);
        }
    }

    if (shieldAura.active)
    {
        const auto& fx = data->Effect(shieldAura.type);
        if (fx.texture)
            SDL_RenderCopyF(renderer, fx.texture, &shieldAura.src, &shieldAura.rect);
        else
        {
            SDL_SetRenderDrawColor(renderer, 0, 220, 255, 255);
            SDL_RenderDrawRectF(renderer, &shieldAura.rect);
        }
    }

    for (const auto& blast : blasts)
    {
        if (blast.active)
            SDL_RenderCopyF(renderer, data->Effect(blast.type).texture, &blast.src, &blast.rect);
    }

    for (const auto& engine : engines)
    {
        if (engine.active)
            SDL_RenderCopyF(renderer, data->Effect(engine.type).texture, &engine.src, &engine.rect);
    }

    for (const auto& notif : notifs)
    {
        if (notif.active && data->Effect(notif.type).texture)
        {
            SDL_RenderCopyF(renderer, data->Effect(notif.type).texture, &notif.src, &notif.rect);
        }
    }
}
