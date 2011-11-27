#ifndef SOUNDCENTER_H_
# define SOUNDCENTER_H_

#include <QString>
#include <QMap>
#include <QList>
#include <QObject>
#include <QSignalMapper>
#include "singleton.hpp"

// forward declarations
namespace Phonon {
class MediaObject;
class MediaSource;
}
class QSound;
// end of forward declarations

class SoundCenter: public QObject, public moost::singleton<SoundCenter>
{
    Q_OBJECT
    friend class moost::singleton<SoundCenter>;
    typedef QMap<QString, Phonon::MediaSource*> SoundRelationMap;
    static const int MAX_SOUNDS = 5;
  public:
    void play(const QString &name);
  public slots:
    void loop();
    void song_finished(QObject *);
  private:
    SoundCenter();
    SoundRelationMap data;
    Phonon::MediaObject *music;
    QSignalMapper signal_map;
    int current_sounds;
};

#endif /* !SOUNDCENTER_H_ */
