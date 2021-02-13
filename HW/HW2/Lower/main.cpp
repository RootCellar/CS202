/*
 * Darian Marvel
 * 2/12/2021
 * main.cpp
 * Writing a to_lower function for C style strings
*/

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

void to_lower(char* data) {

}

int main() {
  cout << " ---- Helpful numbers ---- " << endl;
  cout << ( (int) 'a' ) << endl;
  cout << ( (int) 'z' ) << endl;
  cout << ( (int) 'A' ) << endl;
  cout << ( (int) 'Z' ) << endl;
  cout << " ---- End Helpful Numbers ---- " << endl << endl;

  string s = "hI, tHErE!";
  to_lower(s.c_str());
  cout << s << endl;

}
