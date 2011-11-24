#ifndef SOUNDCENTER_H_
# define SOUNDCENTER_H_

#include <QString>
#include <QSound>
#include <QMap>
#include <Phonon>
#include <Phonon/MediaSource>

#include "singleton.hpp"

class SoundCenter;

class SoundCenter: public moost::singleton<SoundCenter>
{
    friend class moost::singleton<SoundCenter>;
  public:
    void play(const QString &name);
  private:
    SoundCenter();
    QMap<QString, Phonon::MediaObject *> data;
    //QSound        background_music;
    Phonon::MediaObject *music;
};

#endif /* !SOUNDCENTER_H_ */
