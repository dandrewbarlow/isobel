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
		cout << "You picked number " << myCard.getNumber() << " of the major arcana, ";
		cout << myCard.getName() << endl;

	}
	else {
		cout << "You picked number " << myCard.getNumber() << " of " << myCard.getSuit();
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
	menu();
}


// MAIN //////////////////////////////////////////////////
int main(int argc, char const *argv[]) {


	// seed random and print menu
	init();

  // execute ui until it returns 0;
	while (ui() != 0) {
    // print menu until exit condition
		menu();
   }
   cout  << "Thank you, have a nice day" << endl;

  return 0;
}
