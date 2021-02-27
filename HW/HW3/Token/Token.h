#ifndef TOKEN_H
#define TOKEN_H

#include <ostream>
#include <istream>
#include <string>
#include <vector>

using std::ostream;
using std::istream;
using std::string;
using std::find;
using std::vector;

struct Token {
  string token;
  int line;
  int column;
};

vector<string> lineToTokens(const string &line);
vector<Token> readLines(istream &is);
void printTokens(ostream &os, const vector<Token> &tokens);

#endif
