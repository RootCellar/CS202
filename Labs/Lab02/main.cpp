#include "other.h"

void doSomething(Foo f) {
  //copied
  //This will show copy constructor, then destructor
}

int main() {

  //Make a foo
  Foo f;

  //Make a foo and destroy it
  {
    Foo d;
  }

  //Copy a foo
  doSomething(f);

  return 1;
}
