#ifndef OTHER_H
#define OTHER_H

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::ostream;

class Foo {

  friend ostream& operator<<(ostream& os, const Foo& f);

private:

  int _data;
  bool _isSet = false;

public:
  Foo();
  ~Foo();
  Foo(const Foo& original);
  Foo(int x);

  void setData(int x);
  int getData() const;
};


#endif
