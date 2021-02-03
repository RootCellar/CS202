#include <iostream>
#include <string>

using std::cout;
using std::endl;

using std::string;

//#define DEBUG 1

//Duplicate from into dynamically allocated memory
char* strdup(const char* from) {
  //Find Size
  int size = 0;
  while(from[size] != '\0') ++size;
  ++size;

  //Make a new char*
  char* toRet = new char[size];

  //Copy
  for(int i=0; i<size; i++) {
    toRet[i] = from[i];
  }

  //Return!
  return toRet;
}

//Find x in s
const char* findx(const char* s, const char* x) {
  //Forgetting to set these initial values resulted in segmentation fault...whoops!
  int sizeS = 0;
  int sizeX = 0;

  #ifdef DEBUG
  cout << "Here1" << endl;
  #endif

  //Find sizes

  while(s[sizeS] != '\0') ++sizeS;
  ++sizeS;

  while(x[sizeX] != '\0') ++sizeX;
  ++sizeX;

  #ifdef DEBUG
  cout << "Here2" << endl;
  #endif

  //Find x in s!
  bool found;
  for(int i=0; i < sizeS; ++i) {
    found = true;

    #ifdef DEBUG
    cout << i << endl;
    #endif

    if(s[i] == x[0]) {

      for(int j=0; j+i < sizeS && j < sizeX-1; ++j) {

        if(s[i+j] != x[j]) {
          found = false;
          break;
        }

      }

      if(found) return &s[i];

    }

  }

  return nullptr;
}

int main() {
  string s = strdup("To be, or not to be?");
  cout << s << endl;

  cout << strdup("Sure") << endl;

  cout << (findx("To be, or not to be?", "?"))[0] << endl;
  cout << (findx("To be, or not to be?", "T"))[0] << endl;
}
