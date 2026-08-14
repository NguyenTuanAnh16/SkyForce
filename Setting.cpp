#include "Setting.h"


void Setting::Init(MenuRes& res)
{
    backGround = res.backGround;
    rectBG = {0, 0, 1480, 810};

    logo = res.logo;
    rectLG = {(SCREEN_WIDTH - 651/2)/2 ,30,651/2,391/2};

    fpsMaxTex = res.FpsMax;
    fpsMinTex = res.FpsMin;
    fps.texture = fpsMaxTex;
    fps.rect = {(SCREEN_WIDTH - 292) / 2, 350, 292, 60};
    fpsValue = 300;


    musicOnTex = res.musicOn;
    musicOffTex = res.musicOff;
    music.texture = musicOnTex;
    music.rect = {(SCREEN_WIDTH - 292) / 2, 425, 292, 60};



    soundOnTex = res.soundOn;
    soundOffTex = res.soundOff;
    sound.texture = soundOnTex;
    sound.rect = {(SCREEN_WIDTH - 292) / 2, 500, 292, 60};

    goBack.texture = res.goBack;
    goBack.rect = {(SCREEN_WIDTH - 292) / 2 , 575, 292, 60};
}


void Setting::Update(float deltaTime)
{
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    fps.Update(deltaTime, mouseX, mouseY);
    music.Update(deltaTime, mouseX, mouseY);
    sound.Update(deltaTime, mouseX, mouseY);
    goBack.Update(deltaTime,mouseX,mouseY);
}


void Setting::HandleEvent(SDL_Event& e, GameState& state, Music& musicValue)
{
    if(e.type == SDL_MOUSEBUTTONDOWN &&
       e.button.button == SDL_BUTTON_LEFT)
    {
        if(fps.hover)
        {
            if(fpsValue == 300)
            {
                fpsValue = 120;
                fps.texture = fpsMinTex;
                musicValue.PlayClick();
            }
            else
            {
                fpsValue = 300;
                fps.texture = fpsMaxTex;
                musicValue.PlayClick();
            }
        }

        if(music.hover)
        {
            if(music.texture == musicOnTex)
               {
                   music.texture = musicOffTex;
                   musicValue.StopMusic();
                   musicValue.PlayClick();
               }
            else
                {
                  music.texture = musicOnTex;
                  musicValue.PlayMusic();
                  musicValue.PlayClick();
                }
        }

        if(sound.hover)
        {
            if(sound.texture == soundOnTex)
                {
                    sound.texture = soundOffTex;
                    musicValue.sound = false;
                    musicValue.PlayClick();
                }
            else
               {
                   sound.texture = soundOnTex;
                   musicValue.sound = true;
                   musicValue.PlayClick();
               }
        }

        if(goBack.hover)
            state = GameState::MENU;
    }
}

void Setting::Render(SDL_Renderer* renderer)
{
    SDL_RenderCopyF(renderer, backGround, nullptr, &rectBG);
    SDL_RenderCopyF(renderer, logo, nullptr, &rectLG);

    fps.Render(renderer);
    music.Render(renderer);
    sound.Render(renderer);
    goBack.Render(renderer);
}
