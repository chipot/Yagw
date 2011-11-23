#include "SoundCenter.h"
#include <QDebug>

SoundCenter::SoundCenter()
  :data(), background_music("ressource/background_music.wav")
{
      qDebug() << background_music.isAvailable();
  background_music.setLoops(-1);
  background_music.play();
  data["quack"] = new QSound("ressource/quack.wav");
  data["shoot"] = new QSound("ressource/shoot.wav");

}

void SoundCenter::play(const QString &name)
{
  data[name]->play();
}

