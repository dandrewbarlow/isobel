// Andrew Barlow
// A tarot reading application
// v 0.01

// LIBRARIES//////////////////////////////////////////////

// Input / Output Streams
#include <iostream>
// File Streams
// #include <fstream>
// String Streams
// #include <sstream>
// Strings
#include <string>
// Vectors
// #include <vector>
// Random Number Generators
#include <random>
// Time
#include <time.h>

// card class header
#include "card.h"

using namespace std;


// HELPER FUNCTIONS///////////////////////////////////////

// print a 20 char line of unicode block elements
void linePrint() {
  for (int i = 0; i < 30; i++) {
    cout << "\u2500";
  }
  cout << endl;
}

void inputMarker() {
  //hey i like abstraction ok
  cout << "> ";
}

//borrowed from stackoverflow
bool isNumber(const char number[])
{
    int i = 0;

    for (; number[i] != 0; i++)
    {
        //if (number[i] > '9' || number[i] < '0')
        if (!isdigit(number[i]))
            return false;
    }
    return true;
}

// Print main menu
void menu() {
  linePrint();
  cout << "0 " << "\u2503" << " Exit Application" << endl;
  cout << "1 " << "\u2503" << " Draw a card" << endl;
  cout << "2 " << "\u2503" << " Draw multiple cards" << endl;
  linePrint();
}


// Ask user how many cards they want
int handHolder() {
  cout << "How many cards would you like to draw?" << endl;
  inputMarker();
  int input;
  cin >> input;
  return input;
}

// print info about a card
void cardInfo(card myCard) {
	if (myCard.getMajor()) {
		cout << "#" << myCard.getNumber();
    if (myCard.getReverse()) {
      cout << " reversed";
    }
    cout << " of the major arcana, ";
		cout << myCard.getName() << endl;

	}
	else {
		cout << "#" << myCard.getNumber();
    if (myCard.getReverse()) {
      cout << " reversed";
    }
    cout << " of " << myCard.getSuit();
		cout << " in the minor arcana." << endl;
	}
}


// CLI user interface
int ui() {
  inputMarker();
	int input;
	cin >> input;

  switch (input) {

    case 1:
    {
      linePrint();
      card myCard;
      cardInfo(myCard);
      break;
    }

    case 2:
	    {
        int number = handHolder();
        linePrint();
        card myCard[number];
        for (int i = 0; i < number; i++) {
          cardInfo(myCard[i]);
        }
        break;
	    }

    case 0:
      // 0 = exit condition, quit when user chooses this
      return 0;

    // if not 1 or 0, tell them they fricked up
    default:
      printf("Not a valid input\n");
      return 1;
  }
  return 1;
}

// INITIALIZE ////////////////////////////////////////////

void init() {
	// seed random number generator
	srand(time(NULL));

}


// MAIN //////////////////////////////////////////////////
int main(int argc, char const *argv[]) {


	// seed random and print menu
	init();
  const char * argument = argv[1];

  //called with no arguments
  if (argc == 0) {
    //initial menu function
    menu();
    // execute ui until it returns 0;
  	while (ui() != 0) {
      // print menu until exit condition
  		menu();
     }

     cout  << "Thank you, have a nice day" << endl;
   }
   //called w/ too many arguments
   else if (argc > 2){
     cout << "USAGE: isobel [n]" << endl << "n: number of cards to draw" << endl;
   }
   //called w/ 1 argument
   else if (argc == 1) {
     //check if arg is a number
     if (!isNumber(argument)) {
       cout << "error: NaN" << endl;
       cout << "USAGE: isobel [n]" << endl << "n: number of cards to draw" << endl;
     }
     //create hand based on
     int inCards = atoi(argument);
     card myCard[inCards];
     for (int i = 0; i < inCards; i++) {
       cardInfo(myCard[i]);
     }


   }

  return 0;
}
