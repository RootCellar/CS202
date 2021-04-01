#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

template<typename X>
X twice(X x) {
  return x + x;
}

string twice(const char * c) {
  return twice( string(c) );
}

int main() {

  cout << twice(2) << endl;
  cout << twice(2.2) << endl;
  cout << twice(string("Hello")) << endl;

  cout << twice("Hello") << endl;

}
