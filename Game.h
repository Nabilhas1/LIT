/* constructors still need to be constructed

additional functions may be needed

I am not even sure if this is gonna work properly

maybe add overloaded >> and << operators 

*/


#ifndef GAME_H
#define GAME_H

class Game {

 private:

  string m_champ;
  string m_lane;
  int m_kill;
  int m_death;
  int m_assist;
  int m_creepScore;
  string result;
  string notes;


  int kda;



 public:

  Game();
  Game();

  void setChamp(string champName);
  string getChamp();

  void setLane(string lane);
  string getLane();

  void setKill(int kill);
  int getKill();

  void setDeath(int death);
  int getDeath();

  void setAssist(int assist);
  int getAssist();

  void setCS(int creepScore);
  int getCS();

  void setResult(string result);
  string getResult();

  void setNotes(string notes);
  string getNotes();

  void setKDA(double KDA);
  double getKDA();



};

#endif
