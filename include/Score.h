//
// Score.h for Sakura <3 in /Users/Antoine/Yagw/include
//
// Made by Antoine Marandon
// Login   <Antoine@MBP-Antoine.local>
//
// Started on Sun Nov 27 20:26:26 2011 Antoine Marandon
// Last update Sun Nov 27 21:04:48 2011 Antoine Marandon
//

#ifndef SCORE_H_
# define SCORE_H_

#include <QString>
#include <QFile>
#include "singleton.hpp"

class Score: public moost::singleton<Score>
{
    static const QString filename;
    friend class moost::singleton<Score>;
  public:
    unsigned int getScore() const;
    unsigned int getMax() const;
    void        reset();
    void        inc(int);
  private:
    Score();
    unsigned int current;
    unsigned int max;
    QFile file;
};

#endif /* !SCORE_H_ */
