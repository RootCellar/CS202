#include "other.h"


Foo::Foo() {
  cout << "Made the call to the default constructor" << endl;
}

Foo::~Foo() {
  if(!_isSet) cout << "Called the destructor" << endl;
  else cout << "Called the destructor on " << _data << endl;
}

Foo::Foo(const Foo& original) {
  cout << "Called copy constructor " << endl;

  if(original._isSet) {
    cout << "Original was set, copying data..." << original.getData() << endl;
    _data = original.getData();
    _isSet = true;
  }
}

Foo::Foo(int x) : _data(x)
{
  _isSet = true;
  cout << "Called \"other\" constructor with data: " << x << endl;
}

void Foo::setData(int x) {
  if(!_isSet) cout << "Setting data on nameless..." << x << endl;
  else cout << "Data was " << _data << ", will become " << x << endl;
  _isSet = true;
  _data = x;
}

int Foo::getData() const { return _data; }
