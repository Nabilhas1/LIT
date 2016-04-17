// check header file for what needs to be worked on
// as of now implement the header file properly and 
// initialize constructors with proper paramenters



#include <iostream>
#include <string>
#include "Game.h"

using namespace std;

Game::Game():
{            }

Game::Game():
{          }

void Game::setChamp(string champName){

  m_champ = champName;
}

string Game::getChamp(){

  return m_champ;
}

void game::setLane(string lane){
  m_lane = lane;
}

string game::getLane(){

  return m_lane;
}

void game::setKill( int kill){

  m_kill = kill ;
}

int game::getKill(){

  return m_kill;
}

void game::setDeath( int death){

m_death = death;
}

int game::getDeath(){

  return m_death;
}

void game::setAssist(int assist){

  m_assist = assist;
}

int game::getAssist(){

  return m_assist;
}

void game::setCS( int creepScore){

  m_creepScore = creepScore;
}

int game::getCS(){

  return m_creepScore;
}

void game::setResult(string result){

  m_result = result;
}

string game::getResult(){

  return m_result;
}

void game::setNotes(string notes){

  m_notes = notes;
}

string game::getNotes(){

  return m_notes;
}

void game::setKDA(double KDA){

  m_KDA = KDA;
}

int game::getKDA(){

  return m_KDA;
}

