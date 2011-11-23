#include "SoundCenter.h"
#include <QDebug>

SoundCenter::SoundCenter()
  :data(),   music(Phonon::createPlayer(Phonon::MusicCategory,
                                        Phonon::MediaSource("./ressource/background_music.mp3")))
// background_music("ressource/background_music.wav")
{
  this->music->play();
  data["quack"] = new QSound("ressource/quack.wav");
  data["shoot"] = new QSound("ressource/shoot.wav");
}



void SoundCenter::play(const QString &name)
{
  data[name]->play();
}

