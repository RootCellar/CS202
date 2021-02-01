#include "stopwatch.h"
#include <forward_list>
#include <list>
#include <fstream>

#define FILE_NAME "test.txt"

using std::list;
using std::forward_list;

using std::ifstream;

int main() {
  ifstream input(FILE_NAME);

  if(!input) {
    cout << "ERROR ON OPENING FILE" << endl;
    return -1;
  }

  vector<string> data1;
  list<string> data2;
  forward_list<string> data3;

  string data;

  StopWatch watch;
  //vector first
  while(true) {
    input >> data;
    if(!input) {
      if(input.eof()) {
        cout << "Reached end of file, done with read..." << endl;
        break;
      }
      cout << "ERROR ON READ" << endl;
      return -2;
    }

    data1.push_back(data);
  }
  watch.stop();

  cout << "Vector Read: " << watch.getElapsedSeconds() << " seconds" << endl;

}
