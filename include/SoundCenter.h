#ifndef SOUNDCENTER_H_
# define SOUNDCENTER_H_

#include <QString>
#include <QSound>
#include <QMap>
#include <Phonon>
#include <Phonon/MediaSource>

#include "singleton.hpp"

class SoundCenter;

class SoundCenter: public QObject, public moost::singleton<SoundCenter>
{
    Q_OBJECT
    friend class moost::singleton<SoundCenter>;
  public:
    void play(const QString &name);
    void loop();
  private:
    SoundCenter();
    QMap<QString, QSound *> data;
    Phonon::MediaObject *music;
};

#endif /* !SOUNDCENTER_H_ */
