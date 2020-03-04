#include <string>

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
	card();
  std::string getSuit();
  int getNumber();
  bool getMajor();
  std::string getName();

};