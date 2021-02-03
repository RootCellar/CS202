#include <iostream>
#include <string>

using std::cout;
using std::endl;

using std::string;

char* strdup(const char* from) {
  int size = 0;
  while(from[size] != '\0') ++size;
  ++size;

  char* toRet = new char[size];

  for(int i=0; i<size; i++) {
    toRet[i] = from[i];
  }

  return toRet;
}

int main() {
  string s = strdup("Hi!");
  cout << s << endl;

  cout << strdup("Sure") << endl;
}
