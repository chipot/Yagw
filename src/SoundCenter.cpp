#include <Phonon>
#include <Phonon/MediaSource>
#include <QSound>
#include <QDebug>
#include <QFileInfo>
#include "SoundCenter.h"

SoundCenter::SoundCenter()
  :data(),
  music(Phonon::createPlayer(
          Phonon::MusicCategory,
          Phonon::MediaSource("ressource/background_music.mp3")
          )
      ),
   sfx(Phonon::createPlayer(Phonon::GameCategory))
   
{
  this->music->play();
  //data["shoot"] = new QSound("./ressource/shoot.wav");
  //data["quack"] = new QSound("./ressource/quack.wav");
  //data["kill"] = new QSound("./ressource/kill.wav");
  data["shoot"] = new Phonon::MediaSource("ressource/shoot.wav");
  data["kill"] = new Phonon::MediaSource("./ressource/kill.wav");
  connect(this->music, SIGNAL(aboutToFinish()), this, SLOT(loop()));
}

void SoundCenter::play(const QString &name)
{
  SoundRelationMap::const_iterator it = data.constFind(name);
  if (it != this->data.constEnd())
  {
    sfx->setCurrentSource(**it);
    sfx->play();
    qDebug() << "[SoundCenter]" << "Play" << name;
  }
}

void    SoundCenter::loop()
{
  this->music->enqueue(Phonon::MediaSource("./ressource/background_music.wav"));
}
