#ifndef _MUSIC_H
#define _MUSIC_H

#include "ResourceManager.h"
#include <SDL_mixer.h>

struct Music
{
    Mix_Music* music = nullptr;
    Mix_Chunk* burst = nullptr;
    Mix_Chunk* win = nullptr;
    Mix_Chunk* lost = nullptr;
    Mix_Chunk* click = nullptr;

    bool sound = true;

    void Init(MusicRes& res);
    void PlayMusic();
    void StopMusic();

    void PlayBrust();
    void PlayWin();
    void PlayLost();
    void PlayClick();
};

#endif
