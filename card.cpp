#include "card.h"
#include <iostream>
using namespace std;

int card::getNumber() {
  if (number <= 0 && !major) {
    cout << "[error, no number]";
  }
  return number;
}

bool card::getMajor() {
  return major;
}

bool card::getReverse() {
  return reverse;
}

std::string card::getSuit() {
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

std::string card::getName() {
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




card::card() {
  major = rand() % 2;
  reverse = rand() % 2;

  if (major) {
    number = rand() % 22;
    suit = 0;
  }
  else {
    number = (rand() % 14) + 1;
    suit = (rand() % 3) + 1;
  }
}
