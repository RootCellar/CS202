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
using std::sort;
using std::unique;

int gen() {
  static int i = 71;
  i*=6;
  return i;
}

void print(vector<int> v) {
  for(int i : v) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {

  cout << "Using generate() to fill a vector with numbers from successive function calls" << endl;

  vector<int> stuff(8);

  generate(begin(stuff), end(stuff), gen);

  print(stuff);

  cout << endl << endl;

  cout << "Sorting a vector then calling unique() to remove consecutive duplicate elements" << endl;
  cout << "Starting with this: ";

  vector<int> stuff2 = {1, 2, 3, 6, 2, 3, 2, 1, 5, 1, 2, 3, 5};

  print(stuff2);

  sort(begin(stuff2), end(stuff2));

  cout << "Sorted: ";
  print(stuff2);

  auto last = unique(begin(stuff2), end(stuff2));
  stuff2.erase(last, stuff2.end());

  cout << "Unique: ";
  print(stuff2);

}
