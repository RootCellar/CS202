#include "other.h"


Foo::Foo() {
  cout << "Made the call to the default constructor" << endl;
}

Foo::~Foo() {
  cout << "Called the destructor" << endl;
}

Foo::Foo(const Foo& original) {
  cout << "Called copy constructor " << endl;
}
