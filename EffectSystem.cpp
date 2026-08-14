#include "EffectSystem.h"
#include "iostream"

void EffectSystem::Init(EffectDataBase* data)
{
    this->data = data;
    blasts.resize(500);
    engines.resize(20);
    notifs.resize(10);
}

void EffectSystem::AddBlast(float x, float y, int type,float effectSize)
{
    for(auto& blast : blasts)
    {
        if(!blast.active)
        {
            blast.active = true;
            blast.type = type;
            blast.rect = {x - effectSize/2,
                          y - (data->Effect(type).height/(data->Effect(type).width/effectSize))/2,
                          effectSize,
                          data->Effect(type).height/(data->Effect(type).width/effectSize)};
            blast.frameNow = 0;
            blast.timer = 0;
            return;
        }

    }
}


void EffectSystem::AddEngine(int type,float effectSize)
{
    for(auto& engine : engines)
    {
        if(!engine.active)
        {
            engine.active = true;
            engine.type = type;
            engine.rect.w = effectSize;
            engine.rect.h = data->Effect(type).height/(data->Effect(type).width/effectSize);
            engine.frameNow = 0;
            engine.timer = 0;
            return;
        }

    }
}


void EffectSystem::FollowEngine(Starship& starship)
{
    for(int i = 0; i < starship.engines.size(); i++)
    {
        if(engines[i].active)
        {
            engines[i].rect.x = starship.rect.x + starship.engines[i].x - engines[i].rect.w / 2;
            engines[i].rect.y = starship.rect.y + starship.engines[i].y;
        }
    }
}


void EffectSystem::ClearEngine()
{
    for(auto& engine : engines)
    {
        engine.active = false;
    }
}

// noti
void EffectSystem::AddItemNotif(float x, float y, int type, float duration)
{
    for(auto& notif : notifs)
    {
        if(!notif.active)
        {
            notif.active = true;
            notif.type = type;
            notif.timer = 0;
            notif.maxDuration = duration;
            return;
        }
    }
}

void EffectSystem::FollowNotif(Starship& starship)
{
    for(auto& notif : notifs)
    {
        if(notif.active)
        {
            // TĂNG KÍCH THƯỚC NOTI TO RÕ RÀNG (130x40)
            float notifW = 180.0f;
            float notifH = 80.0f;

            notif.rect.w = notifW;
            notif.rect.h = notifH;

            // Luôn căn giữa theo chiều ngang của phi thuyền
            notif.rect.x = starship.rect.x + (starship.rect.w - notifW) / 2.0f;

            // Bám theo đỉnh đầu phi thuyền + trôi dần lên trên theo thời gian
            notif.rect.y = starship.rect.y - 35.0f - (notif.timer * 30.0f);
        }
    }
}

//khien
void EffectSystem::FollowShield(Starship& starship, bool hasShield)
{
    shieldAura.active = hasShield;
    if(hasShield)
    {
        shieldAura.type = 7;
        float padding = 42.0f;
        shieldAura.rect = {
            starship.rect.x - padding,
            starship.rect.y - padding,
            starship.rect.w + padding * 2.0f,
            starship.rect.h + padding * 2.0f
        };
        shieldAura.src = {shieldAura.frameNow * data->Effect(7).width, 0, data->Effect(7).width, data->Effect(7).height};
    }
}


void EffectSystem::Update(float deltaTime)
{
    for(auto& blast : blasts)
    {
        if(blast.active)
        {
            blast.timer = blast.timer + deltaTime;
            if(blast.timer >= data->Effect(blast.type).frameTime)
            {
                blast.timer = 0;
                blast.src =   { blast.frameNow * data->Effect(blast.type).width,
                                 0,
                                 data->Effect(blast.type).width,
                                 data->Effect(blast.type).height};
                if(blast.frameNow >= data->Effect(blast.type).frame)
                {
                    blast.active = false;
                }
                blast.frameNow ++;
            }
        }
    }


    for(auto& engine : engines)
    {
        if(engine.active)
        {
            engine.timer = engine.timer + deltaTime;
            if(engine.timer >= data->Effect(engine.type).frameTime)
            {
                engine.timer = 0;

                engine.src =   { engine.frameNow * data->Effect(engine.type).width,
                                 0,
                                 data->Effect(engine.type).width,
                                 data->Effect(engine.type).height};
                engine.frameNow ++;
                 if(engine.frameNow >= data->Effect(engine.type).frame )
                {
                  engine.frameNow = 0;
                }
            }
        }
    }
    // noti và khiên
    for(auto& notif : notifs)
    {
        if(notif.active)
        {
            notif.timer = notif.timer + deltaTime;
            if(notif.timer >= notif.maxDuration)
            {
                notif.active = false;
            }
        }
    }

    if(shieldAura.active)
    {
        if(data->Effect(7).frame > 1)
        {
            shieldAura.timer = shieldAura.timer + deltaTime;
            if(shieldAura.timer >= data->Effect(7).frameTime)
            {
                shieldAura.timer = 0;
                shieldAura.frameNow++;
                if(shieldAura.frameNow >= data->Effect(7).frame)
                {
                    shieldAura.frameNow = 0;
                }
            }
        }
    }
}

void EffectSystem::Reset()
{
    for(auto& blast : blasts)  blast.active = false;
    for(auto& notif : notifs)  notif.active = false;
    shieldAura.active = false;
}

void EffectSystem::Render(SDL_Renderer* renderer)
{
    // 1. Vẽ Vòng khiên (Nằm bên dưới phi thuyền)
    if(shieldAura.active)
    {
        if(data->Effect(shieldAura.type).texture != nullptr)
        {
            SDL_RenderCopyF(renderer, data->Effect(shieldAura.type).texture, nullptr, &shieldAura.rect);
        }
        else
        {
            // Dự phòng: Vẽ ô màu xanh cyan
            SDL_SetRenderDrawColor(renderer, 0, 220, 255, 255);
            SDL_RenderDrawRectF(renderer, &shieldAura.rect);
        }
    }

    // 2. Vẽ Vụ nổ
    for(auto& blast : blasts)
    {
        if(blast.active)
        {
            SDL_RenderCopyF(renderer, data->Effect(blast.type).texture, &blast.src, &blast.rect);
        }
    }

    // 3. Vẽ Động cơ
    for(auto& engine : engines)
    {
        if(engine.active)
        {
            SDL_RenderCopyF(renderer, data->Effect(engine.type).texture, &engine.src, &engine.rect);
        }
    }

    // 4. Vẽ Chữ thông báo Item (Noti)
    for(auto& notif : notifs)
    {
        if(notif.active)
        {
            // Nếu đã load được file ảnh .png -> Vẽ ảnh
            if(data->Effect(notif.type).texture != nullptr)
            {
                SDL_RenderCopyF(renderer, data->Effect(notif.type).texture, nullptr, &notif.rect);
            }
            // DỰ PHÒNG CHẮC CHẮN HIỆN: Vẽ ô màu tương ứng trôi lên trên đầu phi thuyền
            else
            {
                if (notif.type == 4)      SDL_SetRenderDrawColor(renderer, 0, 255, 120, 255); // Type 4: Heal (Xanh lá)
                else if (notif.type == 5) SDL_SetRenderDrawColor(renderer, 0, 180, 255, 255); // Type 5: Shield (Xanh dương)
                else if (notif.type == 6) SDL_SetRenderDrawColor(renderer, 255, 215, 0, 255); // Type 6: Bullet (Vàng)

                SDL_RenderFillRectF(renderer, &notif.rect);
            }
        }
    }
}
