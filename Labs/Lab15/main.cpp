#include "main.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ostream;
using std::string;

int main() {
  Wrapper<string> stuff("Hello, World!");
  Wrapper<int> num(6);

  cout << num << " " << stuff << endl;
}
