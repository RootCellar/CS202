#include "Complex.h"

using std::cout;
using std::endl;

int main() {
  Complex c(4,8);
  cout << c << endl;

  cout << 1+Complex(2, 3) << endl;
  cout << 1.0+Complex(2, 3) << endl;
  cout << c+Complex(2, 3) << endl;
}
