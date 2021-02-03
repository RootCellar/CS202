#include "stopwatch.h"
#include <forward_list>
#include <list>
#include <fstream>

#define FILE_NAME "beowulf.txt"

using std::list;
using std::forward_list;

using std::ifstream;

int main() {
  //READING

  //VECTOR

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

  cout << "Vector Read: " << watch.getElapsedSeconds() << " seconds (" << data1.size() << " strings)"<< endl;

  //LIST

  ifstream input2(FILE_NAME);

  if(!input2) {
    cout << "ERROR ON OPENING FILE" << endl;
    return -1;
  }

  watch.start();
  while(true) {
    input2 >> data;
    if(!input2) {
      if(input2.eof()) {
        cout << "Reached end of file, done with read..." << endl;
        break;
      }
      cout << "ERROR ON READ" << endl;
      return -2;
    }

    data2.push_back(data);
  }
  watch.stop();

  cout << "List Read: " << watch.getElapsedSeconds() << " seconds (" << data2.size() << " strings)"<< endl;

  //FORWARD LIST

  ifstream input3(FILE_NAME);

  if(!input3) {
    cout << "ERROR ON OPENING FILE" << endl;
    return -1;
  }

  watch.start();
  while(true) {
    input3 >> data;
    if(!input3) {
      if(input3.eof()) {
        cout << "Reached end of file, done with read..." << endl;
        break;
      }
      cout << "ERROR ON READ" << endl;
      return -2;
    }

    data3.push_front(data);
  }
  watch.stop();

  cout << "Forward List Read: " << watch.getElapsedSeconds() << endl;

  //FIND

  string toFind = "z";

  watch.start();
  find(data1.begin(), data1.end(), toFind);
  watch.stop();

  cout << "Vector Find: " << watch.getElapsedSeconds() << " seconds" << endl;

  watch.start();
  find(data2.begin(), data2.end(), toFind);
  watch.stop();

  cout << "List Find: " << watch.getElapsedSeconds() << " seconds" << endl;

  watch.start();
  find(data3.begin(), data3.end(), toFind);
  watch.stop();

  cout << "Forward List Find: " << watch.getElapsedSeconds() << " seconds" << endl;

  //SORT

  watch.start();
  sort(data1.begin(), data1.end());
  watch.stop();

  cout << "Vector sort: " << watch.getElapsedSeconds() << " seconds" << endl;

  watch.start();
  //sort(data2.begin(), data2.end());
  data2.sort();
  watch.stop();

  cout << "List sort: " << watch.getElapsedSeconds() << " seconds" << endl;

  watch.start();
  //sort(data3.begin(), data3.end());
  data3.sort();
  watch.stop();

  cout << "Forward List sort: " << watch.getElapsedSeconds() << " seconds" << endl;

}
