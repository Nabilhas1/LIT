#include <iostream>
#include <fstream>
#include <string>

using namespace std;


string getWhichChamp();


// read page 519 of c++ book

int main(){

  cout << "Hello, Welcome to League of Legends game stat tracker! " << endl;

  cout << "Woud you like to add a new game to your records? y or n" << endl;

  string addData;

  cin >> addData;

  if (addData == "y" ){

    ofstream dataFile("gameHistory.txt", ios::app);

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
    cout << "Once you are done enter 'done' to end." << endl;

    string complete;

    complete = "no" ;


    while ( complete != "done"){
      cout << "Champion name: " ;
      cin >> champName;

      cout << "lane: " ;
      cin >> lane ;

      cout << "kill: " ;
      cin >> kill;

      cout << "death: ";
      cin >> death ;

      cout << "assist: ";
      cin >> assist;

      cout << "cs: " ;
      cin >> creepScore;

      cout << "win/loss: ";
      cin >> result ;

      cin.ignore(); //helps clear buffer for getline
      
      cout << "enter any specific notes: ";
      getline (cin,notes);

      cout << "are you done entering game data? If so, type 'done' or else 'n': ";

      cin >> complete ;

      dataFile << champName <<' ' << lane <<' ' << kill <<' ' << death <<' ' << assist <<' ' << creepScore <<' ' << result <<' ' << notes << endl;


    }
    dataFile.close();
  }
  
  }

  cout << "Would you like to display previously entered data? y or n" << endl;

  string readData;

  cin >> readData;  

  cout << "Would you like to see a specific champion? y or n" << endl;

  string specificChamp;

  cin >> specificChamp;
  
  if (readData == "y" && specificChamp == "n" ){

    ifstream dataFile ("gameHistory.txt");

    string champName;
    string lane;
    int kill;
    int death;
    int assist;
    int creepScore;
    string result;
    string notes;

    if (dataFile.is_open()){

      while (dataFile>> champName >> lane >> kill >> death >> assist >> creepScore>> result && getline(dataFile, notes) ){

	cout << champName<<" " << lane << " " << kill << " " << death << " " << assist<< " "  << creepScore<< " " << result<< " " << notes << endl; }
    }
  }

  if (readData == "y" && specificChamp == "y"){

    string whichChamp;

    whichChamp = getWhichChamp();

    while (whichChamp != "done"){

      ifstream dataFile("gameHistory.txt");

      string champName;
      string lane;
      int kill;
      int death;
      int assist;
      int creepScore;
      string result;
      string notes;

      if (dataFile.is_open()){

	while (dataFile >> champName >> lane >> kill >> death >> assist >> creepScore >> result && getline(dataFile, notes) ) {

	  if (champName == whichChamp){

	    cout << champName << " " << lane << " " << kill << " " << death << " " << assist << " " << creepScore << " " << result << " " << notes << endl;

	  }
	}
      }

      whichChamp = getWhichChamp();

    }
  }

}

string getWhichChamp() {

    cout << "Which champion would you like to see? if done enter 'done'" << endl;

    string choice;

    cin >> choice;

    return choice;

}
