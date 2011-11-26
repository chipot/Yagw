#include <Phonon/MediaSource>
#include "SoundCenter.h"
#include <QDebug>

SoundCenter::SoundCenter()
  :data(),   music(Phonon::createPlayer(Phonon::MusicCategory,
                                        Phonon::MediaSource("./ressource/background_music.wav")))
{
  this->music->play();
  data["shoot"] = new QSound("ressource/shoot.wav");
  data["quack"] = new QSound("ressource/quack.wav");
  data["kill"] = new QSound("ressource/kill.wav");
  connect(this->music, SIGNAL(aboutToFinish()), this, SLOT(loop()));
}

void SoundCenter::play(const QString &name)
{
  qDebug() << "playing " << name;
  data[name]->play();
}

void    SoundCenter::loop()
{
  this->music->enqueue(Phonon::MediaSource("./ressource/background_music.wav"));
}
