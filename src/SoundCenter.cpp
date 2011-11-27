#include <QDebug>
#include <QPair>
#include <QFileInfo>
#include "SoundCenter.h"

SoundCenter::SoundCenter()
  :data(),
    music(Phonon::createPlayer(
            Phonon::MusicCategory,
            Phonon::MediaSource("ressource/background_music.mp3")
            )
         )
{
  this->music->play();
  data.insert("shoot", new SoundPair(Phonon::MediaSource("./ressource/shoot.wav")));
  data.insert("shoot", new SoundPair(Phonon::MediaSource("./ressource/shoot.wav")));
  data.insert("shoot", new SoundPair(Phonon::MediaSource("./ressource/shoot.wav")));
  data.insert("shoot", new SoundPair(Phonon::MediaSource("./ressource/shoot.wav")));
  data.insert("shoot", new SoundPair(Phonon::MediaSource("./ressource/shoot.wav")));
  data.insert("kill", new SoundPair(Phonon::MediaSource("./ressource/kill.wav")));
  data.insert("kill", new SoundPair(Phonon::MediaSource("./ressource/kill.wav")));
  data.insert("kill", new SoundPair(Phonon::MediaSource("./ressource/kill.wav")));
  data.insert("quack", new SoundPair(Phonon::MediaSource("./ressource/quack.wav")));
  connect(this->music, SIGNAL(aboutToFinish()), this, SLOT(loop()));
}

SoundCenter::~SoundCenter()
{
  SoundRelationMap::mapped_type media_ptr;
  foreach(media_ptr, data)
  {
    delete media_ptr;
  }
  data.clear();
}

void SoundCenter::play(const QString &name)
{
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
}

void    SoundCenter::loop()
{
  this->music->enqueue(Phonon::MediaSource("./ressource/background_music.wav"));
}
