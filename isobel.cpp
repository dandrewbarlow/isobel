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

using namespace std;


// CLASSES////////////////////////////////////////////////

class card {
	// indicate the card suit bc values are only 1-4, store in a char
		// 1 : pentacles
		// 2 : cups
		// 3 : swords
		// 4 : wands
	int suit;

	// card number
	int number;

	// indicate major / minor arcana
	bool major;

	// Card name
	string name;

	// access functions
public:
	string getSuit() {
		switch (suit) {
			case 0:
				return NULL;
			case 1:
				return "pentacles";
			case 2:
				return "cups";
			case 3:
				return "swords";
			case 4:
				return "wands";
		}
	}
	char getNumber() {
		return number;
	}
	bool getMajor() {
		return major;
	}


};

card::card(char suitIn, char numberIn, bool majorIn) {
	suit = suitIn;
	number = numberIn;
	major = majorIn;
}

// INITIALIZE ////////////////////////////////////////////

void init() {
	// seed random number generator
	srand(time(NULL));
}


// HELPER FUNCTIONS///////////////////////////////////////

card draw() {

	bool major = rand() % 2;

	if (major) {
		char number = rand() % 22;
		char suit = 0;
	}
	else {
		char number = rand() % 14;
		char suit = (rand() % 3) + 1;
	}
	return card(suit, number, major);
}

void menu() {
  printf("0 | Exit Application\n", );
  printf("1 | Draw a Card\n", );

}

int ui() {
	int input;
	cin >> input;
  switch (input) {
    case 1:
			card myCard = draw();
			if (myCard.major) {
				printf("You picked #%d of the major arcana, %s\n", myCard.getNumber, myCard.getName);
			}
			else {

			}
			printf("You picked #%d of the %s arcana.", myCard.getNumber, myCard.getMajor);
      printf("Test 1 Works\n", );
      break;
    case 0:
      // 0 = exit input, quit when user chooses this
      return 0;
  }
  return;
}

// MAIN //////////////////////////////////////////////////
int int main(int argc, char const *argv[]) {
  // execute ui until it returns 0;

   while (ui()) {
     menu();
   }

  return 0;
}
