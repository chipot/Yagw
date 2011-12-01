#include <QDebug>
#include <QPair>
#include <QFileInfo>
#include "SoundCenter.h"

SoundCenter::SoundCenter()
  :data(),
    music(Phonon::createPlayer(
            Phonon::MusicCategory,
            Phonon::MediaSource("ressource/background_music.mp3")))
{
  this->music->play();
  data.insert("shoot", new SoundPair(Phonon::MediaSource("./ressource/shoot.mp3")));
  data.insert("shoot", new SoundPair(Phonon::MediaSource("./ressource/shoot.mp3")));
  data.insert("shoot", new SoundPair(Phonon::MediaSource("./ressource/shoot.mp3")));
  data.insert("shoot", new SoundPair(Phonon::MediaSource("./ressource/shoot.mp3")));
  data.insert("shoot", new SoundPair(Phonon::MediaSource("./ressource/shoot.mp3")));
  data.insert("shoot", new SoundPair(Phonon::MediaSource("./ressource/shoot.mp3")));
  data.insert("kill", new SoundPair(Phonon::MediaSource("./ressource/kill.mp3")));
  data.insert("kill", new SoundPair(Phonon::MediaSource("./ressource/kill.mp3")));
  data.insert("kill", new SoundPair(Phonon::MediaSource("./ressource/kill.mp3")));
  data.insert("quack", new SoundPair(Phonon::MediaSource("./ressource/quack.mp3")));
  connect(this->music, SIGNAL(aboutToFinish()), this, SLOT(loop()));
}

SoundCenter::~SoundCenter()
{
  this->quit();
  SoundRelationMap::mapped_type media_ptr;
  foreach(media_ptr, data)
  {
    delete media_ptr;
  }
  data.clear();
}


void SoundCenter::run()
{
  this->_mut.lock();
  QString name = this->to_play;
  QList<SoundRelationMap::mapped_type> l = data.values(name);
  SoundRelationMap::mapped_type v;
  foreach (v, l)
    {
      if (v->state() == Phonon::PlayingState)
        continue;
      else
        {
          v->play();
          break;
        }
    }
  this->_mut.unlock();
}

void SoundCenter::play(const QString &name)
{
  this->_mut.lock();
  this->to_play = name;
  this->start();
  this->_mut.unlock();
}

void    SoundCenter::loop()
{
  this->music->enqueue(Phonon::MediaSource("./ressource/background_music.mp3"));
  //delete pair;
}
