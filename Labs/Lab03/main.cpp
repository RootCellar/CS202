#include <iostream>
#include <memory>
#include <string>

#include "other.h"

using std::cout;
using std::endl;
using std::string;

using std::unique_ptr;
using std::shared_ptr;

using std::make_unique;
using std::make_shared;
using std::move;

int main() {
  cout << "Making raw Foo" << endl;
  Foo* foo = new Foo(6);

  cout << "Making a unique foo pointer" << endl;
  unique_ptr<Foo> fPtr = make_unique<Foo>(7);

  cout << "Moving foo to a new unique pointer" << endl;
  unique_ptr<Foo> fPtr2 = move(fPtr);

  cout << "Changing Foo through the pointer" << endl;
  fPtr2->setData(8);

  cout << "Making a shared pointer to Foo object" << endl;
  shared_ptr<Foo> sfPtr = make_shared<Foo>(16);

  {
    cout << "Making a copy of sfPtr, but it shouldn't destroy the object when this goes out of scope!" << endl;
    shared_ptr<Foo> sfPtrTemp = sfPtr;
  }

  cout << "Copying our shared Foo pointer over" << endl;
  auto sfPtr2 = sfPtr;
  cout << endl << endl;

}
