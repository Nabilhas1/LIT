#include <iostream>
#include <fstream>
#include <string>

using namespace std;


string getWhichChamp();
int getLineCount();

// read page 519 of c++ book

int main(){

  cout << "Hello, Welcome to League of Legends game stat tracker! " << endl;

  cout << "Woud you like to add a new game to your records? y or n" << endl;

  string addData;

  cin >> addData;


  //add new data
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
  // display all data  
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

  //display specific champ

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



  // delete entered data
  cout << "Would you like to delete match record? y or n"<< endl;

  string deleteMatch;

  cin >> deleteMatch;

  if (deleteMatch == "y"){

    int lineCount;

    lineCount = getLineCount();

    cout << "You have a total of " << lineCount << " games entered" << endl;
    cout << "How many lines would you like to delete from the end? enter a number" << endl;

    int numbLines;
    cin >> numbLines;

    int newNumbLines;
    newNumbLines = lineCount - numbLines;

    //input file
    ifstream dataFileIn("gameHistory.txt");

    //temp output file
    ofstream dataFileOut("temp.txt");

    string champName;
    string lane;
    int kill;
    int death;
    int assist;
    int creepScore;
    string result;
    string notes;

    if (newNumbLines > 0){
    if (dataFileIn.is_open() && dataFileOut.is_open()){

      while (newNumbLines > 0){

	dataFileIn >> champName >> lane >> kill >> death >> assist >> creepScore >> result ;
	getline(dataFileIn, notes);

	dataFileOut << champName <<" " << lane <<" " << kill <<" " << death <<" " << assist <<" " << creepScore <<" " << result <<" " << notes << endl;

	newNumbLines = newNumbLines - 1;


      }
      dataFileOut.close();
      rename("gameHistory.txt" , "oldGameHistory.txt");
      rename("tempt.txt" , "gameHistory.txt");
    }
    }
  }
}


//get which champ 
string getWhichChamp() {

    cout << "Which champion would you like to see? if done enter 'done'" << endl;

    string choice;

    cin >> choice;

    return choice;

}

//get number of games entered

int getLineCount(){

  int count;
  count = 0;

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

    while ( dataFile >> champName >> lane >> kill >> death >> assist >> creepScore >> result && getline(dataFile, notes)){

      count = count + 1;

    }
  }
  return count;

}
