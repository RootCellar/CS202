#ifndef OTHER_H
#define OTHER_H

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Foo {
public:
  Foo();
  ~Foo();
  Foo(const Foo& original);
};


#endif
