#include "other.h"

//Pass by value
void doSomething(Foo f) {
  //copied
  //This will show copy constructor, then destructor
}

//Passed the reference!
void doSomethingElse(Foo &f) {
  f.setData(7);
}

//Passed by reference to const
void doAnotherThing(const Foo &f) {
  //f.setData(8);
}

Foo returnAFoo() {
  Foo foo(61);
  return foo;
}

int main() {

  //Make a foo
  Foo f;
  f.setData(2);

  //Make a foo and destroy it
  {
    Foo d;
  }

  //Copy f to bar
  Foo bar = f;
  bar.setData(3);

  //Make a foo with some data
  Foo dataFoo(6);

  //Copy a foo
  doSomething(f);

  doSomethingElse(dataFoo);

  doAnotherThing(dataFoo);

  returnAFoo();
  cout << endl << endl;

  cout << "Time for vector stuff" << endl << endl;
  //Vector stuff
  vector<Foo> fooList;

  for(int i=25; i<30; i++) {
    Foo theFoo(i);
    fooList.push_back(theFoo);
  }

  cout << endl << endl;
  cout << "Program done, everything will now be destroyed" << endl;

  return 1;
}
