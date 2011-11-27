#ifndef SOUNDCENTER_H_
# define SOUNDCENTER_H_

#include <QString>
#include <QMultiMap>
#include <QList>
#include <QObject>
#include <QSignalMapper>
#include "singleton.hpp"
#include <Phonon>
#include <Phonon/MediaSource>

class SoundPair : public QObject
{
  Q_OBJECT
 public:
  SoundPair(Phonon::MediaSource const &ms) : QObject(), _mo(0), 
    _ao(0), source(ms)
  {
    _mo = new Phonon::MediaObject();
    _ao = new Phonon::AudioOutput(Phonon::GameCategory);
    Phonon::createPath(_mo, _ao);
    _mo->setCurrentSource(source);
    QObject::connect(_mo, SIGNAL(finished()), this, SLOT(loop_prepare()));
  }

  void play()
  {
    _mo->play();
  }
  Phonon::State state()
  {
    return _mo->state();
  }
 private slots:
  void loop_prepare()
  {
    _mo->clear();
    _mo->enqueue(source);
  }
 private:
  Phonon::MediaObject* _mo;
  Phonon::AudioOutput* _ao;
  Phonon::MediaSource source;
};

class SoundCenter: public QObject, public moost::singleton<SoundCenter>
{
    Q_OBJECT
    friend class moost::singleton<SoundCenter>;
    typedef QMultiMap<QString, SoundPair*> SoundRelationMap;
    static const int MAX_SOUNDS = 5;
  public:
    void play(const QString &name);
  public slots:
    void loop();
  private:
    SoundCenter();
    ~SoundCenter();
    SoundRelationMap data;
    Phonon::MediaObject *music;
};

#endif /* !SOUNDCENTER_H_ */
