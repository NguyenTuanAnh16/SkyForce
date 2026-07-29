#include "EffectSystem.h"
#include "iostream"

void EffectSystem::Init(EffectDataBase* data)
{
    this->data = data;
    blasts.resize(500);
    engines.resize(20);
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
}

void EffectSystem::Render(SDL_Renderer* renderer)
{
    for(auto& blast : blasts)
    {
        if(blast.active)
        {

            SDL_RenderCopyF(
                renderer,
                data->Effect(blast.type).texture,
                &blast.src,
                &blast.rect);
        }
    }


    for(auto& engine : engines)
    {
        if(engine.active)
        {
            SDL_RenderCopyF(
                renderer,
                data->Effect(engine.type).texture,
                &engine.src,
                &engine.rect);
        }
    }
}
