#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <stdexcept>
using std::runtime_error;

#include <vector>
using std::vector;

class Foo {
private:

    static int _count;

public:

  Foo() {
    cout << "Created a foo" << endl;

    _count++;
    if(_count > 5) {
      throw runtime_error("Attempted to create too many Foos (5 max)");
    }
  }

  ~Foo() {
    cout << "Destroyed a foo" << endl;
  }
};

int Foo::_count = 0;

void functionC(){
    throw runtime_error("functionC() threw runtime_error");
}

void functionB(){
    Foo f;
    cout << "Starting functionB()" << endl;
    functionC();
    cout << "Ending functionB()" << endl;
}

void functionA(){
    try {
      functionB();
    }
    catch( const std::exception &e) {
    cout << "Caught an exception: " << e.what() << endl;
  }
}
int main() {
    cout << "Starting main()" << endl;
    functionA();
    cout << "Ended normally." << endl;


    cout << "----- Bonus -----" << endl;

    try{
      vector<Foo> vector(10);
    }catch(const std::exception &e) {
      cout << e.what() << endl;
    }

    return 0;
}
