#include "other.h"

int main() {
  const Foo f;
  cout << f << endl;

  //Also try with set data
  const Foo f2(5);
  cout << f2 << endl;
}
