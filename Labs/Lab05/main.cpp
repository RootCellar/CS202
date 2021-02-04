#include <iostream>
#include <fstream>
#include <ios>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

using std::ifstream;

using std::ios;

int main() {
  ifstream in("data.dat", ios::binary | ios::in);

  vector<int> data;
  int i;

  while(true) {
    in.read(reinterpret_cast<char*>(&i), sizeof(int));
    if(!in) {
      if(in.eof()) {
        break;
      }
      cout << "ERROR ON READ" << endl;
      return -1;
    }
    data.push_back(i);
  }

  //Now we have data, time to use...
  cout << "We have " << data.size() << " ints" << endl;

  int sum = 0;
  double average = 0;
  for(int n : data) sum+=n;

  average = ( (double) sum ) / data.size();

  cout << "Sum: " << sum << endl;
  cout << "Average: " << average << endl;

  return 0;
}
