/*
 * Darian Marvel
 * 2/26/2021
 * main.cpp
 * Reading files/strings, converting to tokens
*/

#include "Token.h"

#include <fstream>

using std::ifstream;
using std::cout;
using std::endl;

int main(int argc, char** argv) {
  bool fileMode = false;
  string fileName = "";
  bool printing = true;

  for(int i=1; i<argc; i++) {

    if( string(argv[i]) == "--lineonly" ) {
      printing = false;
    }
    else {
      //must be file name
      fileName = argv[i];
      fileMode = true;
    }

  }

  if(!fileMode) {
    cout << "Expected a file as parameter" << endl;
    return 0;
  }

  vector<Token> tokens;
  ifstream is(fileName);

  tokens = readLines(is);

  if(printing) {
    printTokens(cout, tokens);
  }

}
