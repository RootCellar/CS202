/*
 * Darian Marvel
 * 1/31/2021
 * main.cpp
 * Using the stopwatch class to test algorithms
*/

#define DATA_SIZE 10000000


#include "stopwatch.h"

vector<int> makeData(mt19937 &rand, uniform_int_distribution<> &dis) {
  vector<int> data;

  for(int i=0; i < DATA_SIZE; i++) {
    data.push_back( dis(rand) );
  }

  return data;
}

int main() {
  random_device dev;
  mt19937 random(dev());

  uniform_int_distribution<> distribution(1, 1000);

  vector<int> data = makeData(random, distribution);

  cout << "--- Sorting ---" << endl;

  StopWatch watch;
  sort(data.begin(), data.end());
  watch.stop();

  cout << "Sort: " << watch.getElapsedSeconds() << " seconds, " << watch.getElapsedMillis() << " milliseconds" << endl;

  cout << "--- Searching ---" << endl;

  watch.start();
  find(data.begin(), data.end(), 1000);
  watch.stop();

  cout << "Search: " << watch.getElapsedSeconds() << " seconds, " << watch.getElapsedMillis() << " milliseconds" << endl;

  cout << "--- Binary Searching ---" << endl;

  watch.start();
  binary_search(data.begin(), data.end(), 1000);
  watch.stop();

  cout << "Binary Search: " << watch.getElapsedSeconds() << " seconds, " << watch.getElapsedMillis() << " milliseconds" << endl;


  cout << "--- Reversing ---" << endl;

  watch.start();
  reverse(data.begin(), data.end());
  watch.stop();

  cout << "Reverse: " << watch.getElapsedSeconds() << " seconds, " << watch.getElapsedMillis() << " milliseconds" << endl;

}
