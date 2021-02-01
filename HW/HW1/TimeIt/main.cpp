/*
 * Darian Marvel
 * 1/31/2021
 * main.cpp
 * Using the stopwatch class to test algorithms
*/

#define DATA_SIZE 10


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



}
