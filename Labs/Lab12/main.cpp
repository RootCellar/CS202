#include <iostream>
using std::cout;

class Base {
public:
  virtual void fooVirtual() const { cout << "Base class virtual function\n"; }
  void fooNotVirtual() const { cout << "Base class non-virtual function\n"; }
};

class Derived : public Base {
public:
  void fooVirtual() const override { cout << "Derived class virtual function\n"; }
  void fooNotVirtual() const { cout << "Derived class non-virtual function\n"; }
};

int main() {
  Base b;
  Derived d;

  //  1) A base class pointer to the base class object.
  Base *bPb = &b;

  //  2) A base class pointer to the derived class object.
  Base *bPd = &d;

  //  3) A derived class pointer to the derived class object.
  Derived *dPd = &d;

  //  4) A base class reference to the base class object.
  Base& bRb = b;

  //  5) A base class reference to the derived class object.
  Base& bRd = d;

  //  6) A derived class reference to the derived class object.
  Derived& dRd = d;


  cout << "Calling non-virtual function from Base class pointer to base: ";
  bPb->fooNotVirtual();

  cout << "Calling virtual function from Base class pointer to base: ";
  bPb->fooVirtual();

  cout << "\n";

  //Call both functions from pointers 2-6
  //2
  cout << "A base class pointer to the derived class object\n";
  bPd->fooVirtual();
  bPd->fooNotVirtual();

  cout << "\n";

  //3
  cout << "A derived class pointer to the derived class object\n";
  dPd->fooVirtual();
  dPd->fooNotVirtual();

  cout << "\n\n";

  //4
  cout << "A base class reference to the base class object\n";
  bRb.fooVirtual();
  bRb.fooNotVirtual();

  cout << "\n";

  //5
  cout << "A base class reference to the derived class object\n";
  bRd.fooVirtual();
  bRd.fooNotVirtual();

  cout << "\n";

  //6
  cout << "A derived class reference to the derived class object\n";
  dRd.fooVirtual();
  dRd.fooNotVirtual();

  return 0;
}
