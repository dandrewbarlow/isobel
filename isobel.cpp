// Andrew Barlow
// A tarot reading application
// v 0.01

// LIBRARIES//////////////////////////////////////////////

// Input / Output Streams
#include <iostream>
// Strings
#include <string>
// Random Number Generators
#include <random>
// Time
#include <time.h>
// Signal handling
#include <signal.h>

// card class header
#include "card.h"

using namespace std;

// SIGNAL HANDLERS////////////////////////////////////////
void signalHandler(int signum) {
  if (signum == SIGINT) {
    cout << "\nInterrupt Signal Recieved\nHave a nice day\n";
    exit(0);
  }
}

// HELPER FUNCTIONS///////////////////////////////////////

// print a 30 char line of unicode block elements
void linePrint(bool position) {
  //0 = top; 1 = bottom
  if (position){
    for (int i = 0; i < 30; i++) {
      cout << "\u2594";
    }
  }
  else {
    for (int i = 0; i < 30; i++) {
      cout << "\u2581";
    }
  }

  cout << endl;
}

void inputMarker() {
  //hey i like abstraction ok
  cout << "> ";
}

// Print main menu
void menu() {
  linePrint(0);
  // \u2503 is a vertical line in unicode
  cout << "0 " << "\u2503" << " Exit Application" << endl;
  cout << "1 " << "\u2503" << " Draw a card" << endl;
  cout << "2 " << "\u2503" << " Draw multiple cards" << endl;
  cout << "3 " << "\u2503" << " Draw a spread" << endl;
  linePrint(1);
}

int spreadMenu() {
  linePrint(0);
  //only one option for now, but
  cout << "0 " << "\u2503" << " Cancel" << endl;
	cout << "1 " << "\u2503" << " Celtic Cross" << endl;
  linePrint(1);
  inputMarker();
  int input;
  cin >> input;
  cout << endl;
  if (input != 0 && input != 1) {
    cout << "invalid input, please try again" << endl;
    // recursive gang represent
    input = spreadMenu();
  }
  return input;
}


// Ask user how many cards they want
int handHolder() {
  cout << "How many cards would you like to draw?" << endl;

  inputMarker();

  int input;
  cin >> input;
  // just for aesthetic reasons
  cout << endl;

  if (cin.fail()){
	cout << "Not a valid input" << endl;
	//clear cin
	cin.clear();
	//ignore characters that cause errors
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	//recursive error handling
    	input = handHolder();
  }
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

//lay out a celtic spread
void celticSpread() {
  string position[10];
  position[0] = "The Present";
  position[1] = "The Problem";
  position[2] = "The Past";
  position[3] = "The Future";
  position[4] = "Conscious";
  position[5] = "Unconscious";
  position[6] = "Your Influence";
  position[7] = "External Influence";
  position[8] = "Hopes and Fears",
  position[9] = "Outcome";
  card myCard[10];
  linePrint(1);
  for (int i = 0; i < 10; i++) {
    cout << position[i] << ":" << endl;
    cardInfo(myCard[i]);
    cout << endl;
  }
}

// CLI user interface
int ui() {
  inputMarker();
	int input;
	cin >> input;
  cout <<endl;

  switch (input) {

    //draw a card
    case 1:
    {
      linePrint(1);
      card myCard;
      cardInfo(myCard);
      break;
    }

    //draw multiple cards
    case 2:
	    {
        int number = handHolder();
        linePrint(1);
        card myCard[number];
        for (int i = 0; i < number; i++) {
          cardInfo(myCard[i]);
        }
        break;
	    }
    //draw a spread
    case 3:
	    {
		      int spread = spreadMenu();
          if (spread == 1) {
            celticSpread();
          }
          break;
      }
    case 0:
      // 0 = exit condition, quit when user chooses this
      return 0;

    // if not a valid input, tell them they fricked up
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
  // register signals
  signal(SIGINT, signalHandler);
}


// MAIN //////////////////////////////////////////////////
int main(int argc, char const *argv[]) {

	// seed random and register signal handlers
	init();

  //called with no arguments
  if (argc == 1) {
    //initial menu function
    menu();
    // execute ui until it returns 0;
  	while (ui() != 0) {
      // print menu until exit condition
  		menu();
     }

     cout  << "Thank you, have a nice day" << endl;
   }
   else if (argc == 2) {

     //create hand based on input
     int inCards = atoi(argv[1]);
     card myCard[inCards];
     for (int i = 0; i < inCards; i++) {
       cardInfo(myCard[i]);
     }
   }
   else if (argc > 2) {
     //called w/ too many arguments
       cout << "USAGE: isobel [n]" << endl << "n: number of cards to draw" << endl;
   }

  return 0;
}
