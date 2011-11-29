//
// GameIA.h for Sakura <3 in /Users/Antoine/Yagw
//
// Made by Antoine Marandon
// Login   <Antoine@MBP-Antoine.local>
//
// Started on Tue Nov 29 20:09:16 2011 Antoine Marandon
// Last update Tue Nov 29 21:08:34 2011 Antoine Marandon
//

#ifndef GAMEIA_H_
# define GAMEIA_H_

class GameProcessor;

class GameIA
{
  public:
    GameIA(GameProcessor &, int, int, Entity *&);
    virtual ~GameIA(){}
    void advance(const int turn, const int score);
  private:
    QPointF randomDirection();
    QPointF randomPosition();
    int calcLevel(const  int);
    GameProcessor &game;
    int width;
    int height;
    Entity  *&player;
};

#endif /* !GAMEIA_H_ */
