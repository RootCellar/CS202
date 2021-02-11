/*
 * Darian Marvel
 * 2/10/2021
 * Test.cpp
 * Writing a basic class, testing with list
*/

#include "catch.hpp"
#include <list>


class Mob {

public:

  static int IDpoint;

  int ID;
  int level;
  int hp;
  int damage;
  int defense;
  int speed;

  Mob(): level(1), hp(100), damage(30), defense(30), speed(10) {
    ID = IDpoint;
    IDpoint++;
  }

};

bool operator==(const Mob& a, const Mob& b) {
  return a.ID == b.ID;
}

int Mob::IDpoint = 0;

TEST_CASE("List Tests") {

};
