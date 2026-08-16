#include "EffectSystem.h"


void EffectSystem::Init(EffectDataBase* data)
{
    this->data = data;
    blasts.resize(500);
    engines.resize(20);
    items.resize(50);
}

void EffectSystem::AddBlast(float x, float y, EffectType type, float effectSize)
{
    for(auto& blast : blasts)
    {
        if(!blast.active)
        {
            blast.active = true;
            blast.data = data->Get(type);
            blast.rect = {x - effectSize/2,
                          y - (blast.data->height/(blast.data->width/effectSize))/2,
                          effectSize,
                          blast.data->height/(blast.data->width/effectSize)};
            blast.frameNow = 0;
            blast.timer = 0;

            return;
        }

    }
}


void EffectSystem::AddEngine(EffectType type,float effectSize)
{
    for(auto& engine : engines)
    {
        if(!engine.active)
        {
            engine.active = true;
            engine.data = data->Get(type);
            engine.rect.w = effectSize;
            engine.rect.h = engine.data->height/(engine.data->width/effectSize);
            engine.frameNow = 0;
            engine.timer = 0;

            return;
        }

    }
}


void EffectSystem::AddItem(EffectType type,float effectSize)
{
// xem co hieu ung chua
      for (auto& item : items)
    {
        if (item.active && item.data == data->Get(type))
        { // đã có effect này → reset lại
            item.frameNow = 0;
            item.timer = 0;

            return;
        }
    }
// hieu ung moi
    for(auto& item : items)
    {
        if(!item.active)
        {
            item.active = true;
            item.data = data->Get(type);
            item.rect.w = effectSize;
            item.rect.h = item.data->height/(item.data->width/effectSize);
            item.frameNow = 0;
            item.timer = 0;

            return;
        }

    }
}


void EffectSystem::FollowStarship(Starship& starship)
{
    for(int i = 0; i < starship.engines.size(); i++)
    {
        if(engines[i].active)
        {
            engines[i].rect.x = starship.rect.x + starship.engines[i].x - engines[i].rect.w / 2;
            engines[i].rect.y = starship.rect.y + starship.engines[i].y;
        }
    }


    for (auto& item : items)
    {
        if (item.active)
        {
            item.rect.x = starship.rect.x + starship.rect.w / 2 - item.rect.w / 2;
            item.rect.y = starship.rect.y + starship.rect.h / 2 - item.rect.h / 2;
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


void EffectSystem::ClearItem(EffectType type)
{
    for(auto& item : items)
    {
        if(item.active && item.data == data->Get(type)) item.active = false;
    }
}



void EffectSystem::Update(float deltaTime)
{
// no
    for(auto& blast : blasts)
    {
        if(blast.active)
        {
            blast.timer = blast.timer + deltaTime;
            if(blast.timer >= blast.data->frameTime)
            {
                blast.timer = 0;
                blast.src =   { blast.frameNow * blast.data->width,
                                 0,
                                 blast.data->width,
                                 blast.data->height};
                blast.frameNow ++;
                if(blast.frameNow >= blast.data->frame)
                {
                    blast.active = false;
                }

            }
        }
    }

// dong co
    for(auto& engine : engines)
    {
        if(engine.active)
        {
            engine.timer = engine.timer + deltaTime;
            if(engine.timer >= engine.data->frameTime)
            {
                engine.timer = 0;

                engine.src =   { engine.frameNow * engine.data->width,
                                 0,
                                 engine.data->width,
                                 engine.data->height};
                engine.frameNow ++;
                 if(engine.frameNow >= engine.data->frame )
                {
                  engine.frameNow = 0;
                }
            }
        }
    }

// khien
    for(auto& item : items)
    {
        if(item.active)
        {
            item.timer = item.timer + deltaTime;
            if(item.timer >= item.data->frameTime)
            {
                item.timer = 0;
                item.src =   { item.frameNow * item.data->width,
                                 0,
                                 item.data->width,
                                 item.data->height};
                item.frameNow ++;
                if(item.frameNow >= item.data->frame)
                {
                    item.frameNow = 0;
                }

            }
        }
    }
}

void EffectSystem::Reset()
{
    for(auto& blast : blasts)  blast.active = false;
    ClearItem(EffectType::HP);
    ClearItem(EffectType::SHIELD);
}

void EffectSystem::Render(SDL_Renderer* renderer)
{
    for(auto& blast : blasts)
    {
        if(blast.active)
        {

            SDL_RenderCopyF(
                renderer,
                blast.data->texture,
                &blast.src,
                &blast.rect);
        }
    }

// dong co

    for(auto& engine : engines)
    {
        if(engine.active)
        {
            SDL_RenderCopyF(
                renderer,
                engine.data->texture,
                &engine.src,
                &engine.rect);
        }
    }

// item
     for(auto& item : items)
    {
        if(item.active)
        {

            SDL_RenderCopyF(
                renderer,
                item.data->texture,
                &item.src,
                &item.rect);
        }
    }
}
