#include "Score.h"
#include <QTextStream>

const QString Score::filename = "score.yagws";

Score::Score()
  :current(0), max(0), file(Score::filename)
{
    if (file.exists()) {
       file.open(QIODevice::ReadOnly);
       QTextStream stream(&file);
       if (!stream.atEnd())
           max = stream.readLine().toInt();
       file.close();
    }
}

void Score::reset()
{
  current = 0;
}

unsigned int Score::getScore() const
{
  return current;
}

 unsigned int Score::getMax() const
{
  return max;
}

void    Score::inc(int i)
{
  current += i;
  if (current > max)
    max = current;
}

void Score::saveScore() {
    file.open(QIODevice::ReadWrite);
    file.flush();
    file.write(QString::number(max).toStdString().c_str());
    file.close();
}
