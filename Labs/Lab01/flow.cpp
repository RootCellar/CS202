#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

using std::vector;

//Function call and if/else
//Returns whether or not a given integer is even
bool isEven(int i) {
  if(i%2 == 0) return true;
  else return false;
}

int main() {

  //Simple for to count to 10
  cout << "Counting to 10..." << endl;
  for(int i=1; i<11; i++) {
    cout << i << endl;
  }
  cout << endl;

  //for each
  cout << "Printing pi... 3.";
  vector<int> nums = { 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9 };
  for(auto number : nums) {
    cout << number;
  }
  cout << endl;

  //while loop
  int number = 9;
  while(number % 7 != 0) {
    ++number;
  }

  //Do while
  number = 54;
  do {
    ++number;
  }while(number % 9 != 0);

  int choice;
  cout << "Choose a number from 1-3" << endl;
  cout << ">";
  cin >> choice;
  cout << endl;

  switch(choice) {
    case 1:
      cout << "You get pie!" << endl;
      break;
    case 2:
      cout << "You get cake!" << endl;
      break;
    case 3:
        cout << "You get candy!" << endl;
        break;
    default:
      cout << "You entered bad input. No surprise for you!" << endl;
      break;
  }

  cout << endl;
  cout << "Done!" << endl;
  return 1;

}
