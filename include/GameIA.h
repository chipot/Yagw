//
// GameIA.h for Sakura <3 in /Users/Antoine/Yagw
//
// Made by Antoine Marandon
// Login   <Antoine@MBP-Antoine.local>
//
// Started on Tue Nov 29 20:09:16 2011 Antoine Marandon
// Last update Wed Nov 30 20:27:06 2011 Antoine Marandon
//

#ifndef GAMEIA_H_
# define GAMEIA_H_


class ProfileFactory;
class Profile;
class GameProcessor;

class GameIA
{
  public:
    GameIA(GameProcessor &, int, int, Entity *&);
    virtual ~GameIA(){}
    void advance(const int turn, const int score);
    void setProfile(QString, Profile*);
    void designProfiles();
  private:
    QPointF randomDirection();
    QPointF randomPosition();
    void calcLevel(const  int);
    GameProcessor &game;
    ProfileFactory *profileFactory;
    int width;
    int height;
    Entity  *&player;
    int level;
};

#endif /* !GAMEIA_H_ */
