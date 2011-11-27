#include <Phonon>
#include <Phonon/MediaSource>
#include <QSound>
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
         ),
    signal_map(),
    current_sounds(0)
{
  this->music->play();
  current_sounds++;
  data["shoot"] = new Phonon::MediaSource("ressource/shoot.wav");
  data["kill"] = new Phonon::MediaSource("./ressource/kill.wav");
  connect(this->music, SIGNAL(aboutToFinish()), this, SLOT(loop()));
  connect(&signal_map, SIGNAL(mapped(QObject *)),
          this, SLOT(song_finished(QObject*)));
}

void SoundCenter::play(const QString &name)
{
  SoundRelationMap::const_iterator it = data.constFind(name);
  if (it != this->data.constEnd() && current_sounds < MAX_SOUNDS)
  {
    QPair<Phonon::MediaObject*,Phonon::AudioOutput*> *pair =
        new QPair<Phonon::MediaObject*,Phonon::AudioOutput*>(
            new Phonon::MediaObject(), 
            new Phonon::AudioOutput(Phonon::GameCategory));

    Phonon::createPath(pair->first, pair->second);
    pair->first->setCurrentSource(**it);

    connect(pair->first, SIGNAL(finished()), &signal_map, SLOT(map()));
    signal_map.setMapping(pair->first, reinterpret_cast<QObject*>(pair));

    pair->first->play();
    current_sounds++;
    qDebug() << "[SoundCenter]" << "Play" << name;
  }
}

void    SoundCenter::loop()
{
  this->music->enqueue(Phonon::MediaSource("./ressource/background_music.wav"));
}

void    SoundCenter::song_finished(QObject *obj)
{
  QPair<Phonon::MediaObject*,Phonon::AudioOutput*>  *pair =
      reinterpret_cast<QPair<Phonon::MediaObject*,Phonon::AudioOutput*>*>(obj);
  pair->first->clear();
  pair->first->disconnect(SIGNAL(finished()), &signal_map, SLOT(map()));
  delete pair->first;
  delete pair->second;
  delete pair;
  current_sounds--;
}
