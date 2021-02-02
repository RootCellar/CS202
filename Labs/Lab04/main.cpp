#include <iostream>
#include <fstream>
#include <ios>
#include <sstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

using std::ofstream;
using std::ios;
using std::getline;
using std::istringstream;


int main() {
  string toWrite;
  string line;
  int n;

  cout << "Enter a number, and a line of text to write to the file n times: " << endl;
  getline(cin, line);
  string word;
  istringstream readString(line);

  if(! (readString >> n)) {
    cout << "Bad input" << endl;
    return -1;
  }

  while(readString >> word) {
    toWrite += word + " ";
    word = "";
  }

  cout << "Writing \"" << toWrite << "\" " << n << " times" << endl;

  ofstream fout("file.temp", ios::app);
  if(!fout) {
    cout << "Could not open file" << endl;
    return -2;
  }

  for(int i=0; i<n; i++) {
    fout << toWrite << endl;
  }
}
