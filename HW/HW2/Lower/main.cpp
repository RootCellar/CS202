/*
 * Darian Marvel
 * 2/12/2021
 * main.cpp
 * Writing a to_lower function for C style strings
*/

//#define DEBUG

#include <iostream>
#include <string>
#include <string.h>

using std::cout;
using std::endl;
using std::string;

//make "data" all lowercase
void to_lower(char* data) {

  int i = 0;
  while(data[i] != '\0') {

    #ifdef DEBUG
    cout << i << " " << data[i] << endl;
    #endif

    if(data[i] >= 'A' && data[i] <= 'Z') {
      char orig = data[i];

      #ifdef DEBUG
      cout << ( (char) orig ) << endl;
      cout << ( (char) (orig + 32) ) << endl;
      #endif

      data[i] = (orig + 32);
    }

    ++i;

  }

}

int main() {
  cout << " ---- Helpful numbers ---- " << endl;
  cout << ( (int) 'a' ) << endl;
  cout << ( (int) 'z' ) << endl;
  cout << ( (int) 'A' ) << endl;
  cout << ( (int) 'Z' ) << endl;
  cout << " ---- End Helpful Numbers ---- " << endl << endl;

  //Use strdup to copy the const string into something I can write into
  char* s = strdup("hI, tHErE!");
  to_lower( s );
  cout << s << endl;

}
