#include "Score.h"

const QString Score::filename = ".yagws";

Score::Score()
  :current(0), max(0), file(Score::filename)
{

  // file.open(QIODevice::ReadWrite);
  // unsigned int *_max = file.map(0, sizeof(max));
  // max = *_max;
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
