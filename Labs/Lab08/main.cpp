#include <iostream>

using std::cout;
using std::endl;

namespace {
  int _globalX = 0;
}

void staticTest() {
  static int timesCalled = 0;

  timesCalled++;
  cout << "staticTest() has been called " << timesCalled << " time(s)" << endl;
  cout << "_globalX happens to be " << _globalX << " right now" << endl;
}

class Stuff {
public:

  Stuff() {
    cout << "Constructing some new stuff" << endl;
    _stuffInExistence++;
    cout << "There is now " << _stuffInExistence << " stuff in existence" << endl;
  }

  ~Stuff() {
    cout << "Destructing some stuff" << endl;
    _stuffInExistence--;
    cout << "There is now " << _stuffInExistence << " stuff in existence" << endl;
  }

  static int howManyAreThere() {
    return _stuffInExistence;
  }

private:
  static int _stuffInExistence;
};

int Stuff::_stuffInExistence = 0;

int main() {
  staticTest();

  Stuff s;

  staticTest();

  _globalX = 6;

  {
    Stuff f;
    staticTest();
  }

  Stuff f;
  Stuff t;

  //This is why we write copy constructors
  Stuff x(t);

  staticTest();

  cout << "There happens to be " << Stuff::howManyAreThere() << " things right now" << endl;
}
