#include "Music.h"

void Music::Init(MusicRes& res)
{

     music = res.music;

     burst = res.burst;

     win = res.win;

     lost = res.lost;

     click = res.click;

     item = res.item;

}

void Music::PlayMusic()
{
   Mix_PlayMusic(music, -1);
}

void Music::StopMusic()
{
      Mix_HaltMusic();
}


void Music::PlayBrust()
{
  if(sound)  Mix_PlayChannel(-1, burst, 0);
}

void Music::PlayWin()
{
  Mix_PlayChannel(-1, win, 0);
}

void Music::PlayLost()
{
  Mix_PlayChannel(-1, lost, 0);
}

void Music::PlayClick()
{
  if(sound)  Mix_PlayChannel(-1, click, 0);
}

void Music::PlayItem()
{
    if (sound) Mix_PlayChannel(-1, item, 0);
}
