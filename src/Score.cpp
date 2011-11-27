#include "Score.h"

const QString Score::filename = ".yagws";

Score::Score()
  :current(0), max(0), file(Score::filename)
{

  // file.open(QIODevice::ReadWrite);
  // unsigned int *_max = file.map(0, sizeof(max));
  // max = *_max;
}

inline unsigned int Score::getScore() const
{
  return current;
}

inline unsigned int Score::getMax() const
{
  return max;
}

void    Score::inc(int i)
{
  current += i;
  if (current > max)
    max = current;
}
