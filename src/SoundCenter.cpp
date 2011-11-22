#include "SoundCenter.h"

SoundCenter::SoundCenter()
  :data(), background_music("ressource/background_music.wav")
{
  background_music.setLoops(-1);
  background_music.play();
}

void SoundCenter::play(const QString &name)
{
  data[name]->play();
}

