/*
 * Darian Marvel
 * 2/10/2021
 * Test.cpp
 * Writing a basic class, testing with list
*/

#include "catch.hpp"
#include <list>
#include <algorithm>
#include <iostream>

using std::list;
using std::find;

using std::cout;
using std::endl;

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

bool operator>(const Mob& a, const Mob& b) {
  return a.ID > b.ID;
}

bool operator<(const Mob& a, const Mob& b) {
  return a.ID < b.ID;
}

int Mob::IDpoint = 0;

void print(list<Mob> mobs) {
  for(auto i = mobs.begin(); i != mobs.end(); i++) {
    Mob current = (*i);

    cout << current.ID << endl;
  }
}

TEST_CASE("List Tests") {

  list<Mob> queue;
  list<Mob> stack;

  Mob test;

  //Test Queue

  Mob dummy1;
  Mob dummy3; //used later for placing the right spot
  Mob dummy2;

  queue.push_back(dummy1);
  queue.push_back(dummy2);
  queue.push_back(test);

  print(queue);

  auto get = queue.begin();
  get++;
  get++;

  REQUIRE( (*get) == test );

  auto found = find(queue.begin(), queue.end(), dummy1);

  REQUIRE( (*found) == dummy1 );

  queue.pop_front();

  found = find(queue.begin(), queue.end(), dummy1);

  REQUIRE( found == queue.end() );

  //Test Stack

  stack.push_back(dummy1);
  stack.push_back(dummy2);
  stack.push_back(test);

  get = stack.begin();
  get++;
  get++;

  REQUIRE( (*get) == test );

  found = find(stack.begin(), stack.end(), test);

  REQUIRE( (*found) == test );

  stack.pop_back();

  found = find(stack.begin(), stack.end(), test);

  REQUIRE( found == stack.end() );

  //Test finding and placing

  list<Mob> mobs;

  mobs.push_back(test);
  mobs.push_back(dummy1);
  mobs.push_back(dummy2);

  //search for dummy1
  bool didFind = false;

  size_t i;
  auto it = mobs.begin();
  for(i=0, it = mobs.begin(); i<mobs.size(); i++, it++) {
    Mob current = *it;

    if(current == dummy1) {
      didFind = true;
      break;
    }

  }

  REQUIRE( didFind );

  //place dummy3
  bool placed = false;
  auto end = mobs.end()--;
  for(auto i = mobs.begin(); i != end; i++) {
    if( (*i) < dummy3 && (*(i++)) > dummy3 ) {
      mobs.insert(i, dummy3);
    }
  }
  if(!placed) mobs.push_back(dummy3);

  //dummy3 should be at spot 2
  get = mobs.begin();
  get++;
  get++;

  print(mobs);

  REQUIRE( (*get) == dummy3 );

};
