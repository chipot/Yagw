#include <Phonon/MediaSource>
#include "SoundCenter.h"
#include <QDebug>

SoundCenter::SoundCenter()
  :data(),   music(Phonon::createPlayer(Phonon::MusicCategory,
                                        Phonon::MediaSource("./ressource/background_music.wav")))
// background_music("ressource/background_music.wav")
{
  qDebug() << "valid :" << this->music->isValid();

  this->music->play();
  Phonon::MediaSource media  = Phonon::MediaSource("ressource/quack.wav");
  media.setAutoDelete(false);
  data["quack"] = Phonon::createPlayer(Phonon::MusicCategory,
                                       media);
  // data["shoot"] = new QSound("ressource/shoot.wav");
}

void SoundCenter::play(const QString &name)
{
  qDebug() << "playing " << name;
  data[name]->play();
}

