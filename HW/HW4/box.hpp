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

  int getWidth() const { return width; }
  int getHeight() const { return height; }

  void setWidth(int w) {
    width = w;
  }

  void setHeight(int h) {
    height = h;
  }

  virtual void print(ostream &os) const;
  virtual string type() const;

};

class HollowBox : public Box {

};

class FilledBox : public Box {

};

class CheckeredBox : public Box {

};

ostream& operator<<(ostream &os, const Box &b) {
  b.print(os);
  return os;
}

#endif
