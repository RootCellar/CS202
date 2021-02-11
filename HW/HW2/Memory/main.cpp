/*
 * Darian Marvel
 * 2/10/2021
 * main.cpp
 * Checking out how the compiler lays out memory
*/

#include <iostream>

using std::cout;
using std::endl;

void printPointer(int& i) {
  cout << "i: " << i << endl;
  cout << "&i: " << &i << endl;
}

static int a = 1;
static int b = 2;

int main() {
  cout << "----" << " Static Data " << "----" << endl;
  printPointer(a);
  printPointer(b);

  cout << "----" << " Stack" << "----" << endl;
  int x = 3;
  int y = 4;
  printPointer(x);
  printPointer(y);


  cout << "----" << " Free Store " << "----" << endl;
  int* nums = new int[2];
  nums[0] = 6;
  nums[1] = 7;

  printPointer(nums[0]);
  printPointer(nums[1]);

  delete [] nums; //why not?

  return 0;
}
