#include <Phonon>
#include <Phonon/MediaSource>
#include <QSound>
#include <QDebug>
#include <QPair>
#include <QFileInfo>
#include "SoundCenter.h"

namespace {
template <typename T, typename U>
class MyPair : public QObject, public QPair<T, U>
{
 public:
  MyPair(T const &t, U const &u) :QObject(), QPair<T,U>(t, u)
  {
  }
};
}

SoundCenter::SoundCenter()
  :data(),
    music(Phonon::createPlayer(
            Phonon::MusicCategory,
            Phonon::MediaSource("ressource/background_music.mp3"))),
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
  return;
  SoundRelationMap::const_iterator it = data.constFind(name);
  if (it != this->data.constEnd() && current_sounds < MAX_SOUNDS)
  {
    MyPair<Phonon::MediaObject*,Phonon::AudioOutput*> *pair =
        new MyPair<Phonon::MediaObject*,Phonon::AudioOutput*>(
            new Phonon::MediaObject(),
            new Phonon::AudioOutput(Phonon::GameCategory));

    Phonon::createPath(pair->first, pair->second);
    pair->first->setCurrentSource(**it);

    connect(pair->first, SIGNAL(finished()), &signal_map, SLOT(map()));
    signal_map.setMapping(pair->first, static_cast<QObject*>(pair));

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
  MyPair<Phonon::MediaObject*,Phonon::AudioOutput*>  *pair =
      static_cast<MyPair<Phonon::MediaObject*,Phonon::AudioOutput*>*>(obj);
  pair->first->clear();
  signal_map.removeMappings(pair->first);
  pair->first->disconnect();
  //delete pair->first;
  //delete pair->second;
  //delete pair;
  current_sounds--;
}
