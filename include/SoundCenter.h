#ifndef SOUNDCENTER_H_
# define SOUNDCENTER_H_

#include <QString>
#include <QMap>
#include <QObject>
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
  public:
    void play(const QString &name);
  public slots:
    void loop();
  private:
    SoundCenter();
    SoundRelationMap data;
    Phonon::MediaObject *music;
    Phonon::MediaObject *sfx;
};

#endif /* !SOUNDCENTER_H_ */
