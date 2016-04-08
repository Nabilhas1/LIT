#include <iostream>
#include <fstream>

using namespace std;

// read page 519 of c++ book

int main(){

  ofstream dataFile("gameHistory.txt");

  string champName;

  string lane;

  int kill;

  int death;

  int assist;

  int creepScore;

  string result;

  string notes;

  if (dataFile.is_open()) {

    cout << "Please enter champion name, lane, kill, death, assist, cs, result, notes: " << endl;
    cout << "Once you are done enter done to end." << endl;

    while ( cin


  

}
