// Andrew Barlow
// A tarot reading application
// v 0.01

// LIBRARIES//////////////////////////////////////////////

// Input / Output Streams
#include <iostream>
// File Streams
#include <fstream>
// String Streams
#include <sstream>
// Strings
#include <string>
// Vectors
#include <vector>
// Random Number Generators
#include <random>
// Time
#include <time.h>

// card class header
#include "card.h"

using namespace std;


// HELPER FUNCTIONS///////////////////////////////////////

void menu() {
  printf("0 | Exit Application\n");
  printf("1 | Draw a Card\n");
}


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


int ui() {
	int input;
	cin >> input;
  switch (input) {

    case 1:
	    {
			card myCard;
			cardInfo(myCard);
			break;
	    }

    case 0:
      // 0 = exit input, quit when user chooses this
      return 0;

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
  // execute ui until it returns 0;

	// seed random and print menu
	init();

	while (ui()) {
		menu();
   }

  return 0;
}
