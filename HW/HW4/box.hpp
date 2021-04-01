#ifndef BOX_HPP
#define BOX_HPP

#include <iostream>
#include <string>

using std::ostream;
using std::string;

class Box {
private:
  int width;
  int height;

public:

  Box(int w, int h): width(w), height(h) {

  }

  int getWidth() { return width; }
  int getHeight() { return height; }

  void setWidth(int w) {
    width = w;
  }

  void setHeight(int h) {
    height = h;
  }

  virtual void print(ostream &os);
  virtual string type();

};

class HollowBox : public Box {

};

class FilledBox : public Box {

};

class CheckeredBox : public Box {

};

#endif
