/*
 * Darian Marvel
 * 2/10/2021
 * Test.cpp
 * Writing a basic class, testing with list
*/

#include "catch.hpp"
#include <list>
#include <algorithm>

using std::list;
using std::find;

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

bool operator!=(const Mob& a, const Mob& b) {
  return a.ID != b.ID;
}

int Mob::IDpoint = 0;

TEST_CASE("List Tests") {

  list<Mob> queue;
  list<Mob> stack;

  Mob test;

  //Test Queue

  Mob dummy1;
  Mob dummy2;

  queue.push_back(dummy1);
  queue.push_back(dummy2);
  queue.push_back(test);

  auto get = queue.begin();
  get++;
  get++;

  REQUIRE( (*get) == test );

  queue.pop_front();

  auto found = find(queue.begin(), queue.end(), dummy1);

  REQUIRE( found == queue.end() );

  //Test Stack

  stack.push_back(dummy1);
  stack.push_back(dummy2);

  

};
