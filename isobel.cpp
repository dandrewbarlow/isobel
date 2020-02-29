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

	// indicate the card suit bc values are only 1-4
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
	int getNumber() {
		if (number <= 0 && !major) {
			cout << "[error, no number]";
		}
		return number;
	}

	bool getMajor() {
		return major;
	}

	string getName() {
		if (!major) {
			printf("error: card belongs to the minor arcana\n");
			return "error";
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
	}

	card();


};
card::card() {
	major = rand() % 2;

	if (major) {
		number = rand() % 22;
		suit = 0;
	}
	else {
		number = rand() % 14 + 1;
		suit = (rand() % 3) + 1;
	}
}



// HELPER FUNCTIONS///////////////////////////////////////

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
			card myCard;
			if (myCard.getMajor()) {
				cout << "You picked number " << myCard.getNumber() << " of the major arcana, ";
				cout << myCard.getName() << endl;

			}
			else {
				cout << "You picked number " << myCard.getNumber() << " of " << myCard.getSuit();
				cout << " in the minor arcana." << endl;
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

	// seed random and print menu
	init();

	while (ui()) {
	menu();
   }

  return 0;
}
