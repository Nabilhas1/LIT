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

