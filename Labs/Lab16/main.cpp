#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>

using std::cout;
using std::endl;

using std::string;
using std::vector;

using std::generate;

int gen() {
  static int i = 71;
  i*=6;
  return i;
}

int main() {

  cout << "Using generate() to fill a vector with numbers from successive funciton calls" << endl;

  vector<int> stuff(8);

  generate(begin(stuff), end(stuff), gen);

  for(int i : stuff) {
    cout << i << " ";
  }
  cout << endl;

}
