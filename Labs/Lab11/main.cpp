#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

//Base Class
class Foo {
public:

  Foo(): _id(0) {
    cout << "Constructed a Foo with no given ID" << endl;
  }

  Foo(int i): _id(i) {
    cout << "Constructed a Foo with ID " << i << endl;
  }

  ~Foo() {
    cout << "Foo " << _id << " is being destroyed" << endl;
  }


private:
  int _id;
};

//Derived Class
class Bar : public Foo {

public:

  Bar(): _name("") {
    cout << "Constructed a Bar with no given name" << endl;
  }

  Bar(string s, int i): Foo(i), _name(s) {
    cout << "Constructed a Bar called " << _name << endl;
  }

  ~Bar() {
    cout << "Destroyed Bar called " << _name << endl;
  }


private:
  string _name;

};

int main() {

  {
    Foo f;
  }

  {
    Foo f(6);
  }

  {
    Bar b;
  }

  {
    Bar b("Evan", 6);
  }



}
