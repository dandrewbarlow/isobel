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
private:

	// indicate the card suit bc values are only 1-4, store in a char
		// 0 : major arcana
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
				return "no suit";
			case 1:
				return "pentacles";
			case 2:
				return "cups";
			case 3:
				return "swords";
			case 4:
				return "wands";
			default:
				return "error";
		}
	}
	char getNumber() {
		return number;
	}

	bool getMajor() {
		return major;
	}

	string getName() {
		if (!major) {
			printf("error: card belongs to the minor arcana");
		}
		else {
		switch (number){
			case 0:
				return "the fool"; 
			case 1:
				return "the magician";
			case 2:
				return "the high priestess";
			case 3:
				return "the empress";
			case 4:
				return "the emporer";
			case 5:
				return "the hierophant";
			case 6:
				return "the lovers";
			case 7:
				return "the chariot";
			case 8:
				return "strength";
			case 9:
				return "the hermit";
			case 10:
				return "the wheel of fortune";
			case 11:
				return "justice";
			case 12:
				return "the hanged man";
			case 13:
				return "death";
			case 14:
				return "temperance";
			case 15:
				return "the devil";
			case 16:
				return "the tower";
			case 17:
				return "the star";
			case 18:
				return "the moon";
			case 19:
				return "the sun";
			case 20:
				return "judgement";
			case 21:
				return "the world";
			default:
				return "error";



		}
		}
		return name;
	}

	card(char numberIn, bool majorIn);


};

card::card(char numberIn, bool majorIn) {
	number = numberIn;
	major = majorIn;
	if (!major) {
		suit = (rand() % 3) + 1;
	}
	else {
		suit = 0;
	}
}


// HELPER FUNCTIONS///////////////////////////////////////

card draw() {
	char number;
	bool major = rand() % 2;

	if (major) {
		char number = rand() % 22;
	}
	else {
		char number = rand() % 14;
	}
	return card(number, major);
}

void menu() {
  printf("0 | Exit Application\n");
  printf("1 | Draw a Card\n");

}

int ui() {
	int input;
	cin >> input;
  switch (input) {
    case 1:
	    {
			card myCard = draw();
			if (myCard.getMajor()) {
				printf("You picked #%d of the major arcana, %s\n", myCard.getNumber(), myCard.getName());
			}
			else {
				printf("You picked the %d of %s in the minor arcana.", myCard.getNumber(), myCard.getSuit());
			}
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

	init();
	while (ui()) {
	menu();
   }

  return 0;
}
