#ifndef BOX_HPP
#define BOX_HPP

#include <iostream>
#include <string>
#include <memory>

using std::ostream;
using std::string;
using std::make_unique;

class Box {
private:
  int width;
  int height;

public:

  Box(int w, int h): width(w), height(h) {

  }

  virtual ~Box() {

  }

  int getWidth() const { return width; }
  int getHeight() const { return height; }

  void setWidth(int w) {
    width = w;
  }

  void setHeight(int h) {
    height = h;
  }

  virtual void print(ostream &os) const = 0;
  virtual string type() const = 0;

};

class HollowBox : public Box {
public:
  HollowBox(int w, int h): Box(w, h) {

  }

  HollowBox(): Box(1,1) {

  }

  void print(ostream &os) const {
    for(int i=0; i<getWidth(); i++) os << "x";
    os << "\n";

    for(int i=0; i<getHeight()-2; i++) {
      os << "x";
      for(int i=0; i<getWidth()-2; i++) os << " ";
      os << "x\n";
    }

    if(getHeight() > 1) {
      for(int i=0; i<getWidth(); i++) os << "x";
      os << "\n";
    }

  }

  string type() const {
    return "Hollow";
  }
};

class FilledBox : public Box {
public:
  FilledBox(int w, int h): Box(w, h) {

  }

  FilledBox(): Box(1,1) {

  }

  void print(ostream &os) const {

  }

  string type() const {
    return "Filled";
  }
};

class CheckeredBox : public Box {
public:
  CheckeredBox(int w, int h): Box(w, h) {

  }

  CheckeredBox(): Box(1,1) {

  }

  void print(ostream &os) const {

  }

  string type() const {
    return "Checkered";
  }
};

ostream& operator<<(ostream &os, const Box &b) {
  b.print(os);
  return os;
}

std::unique_ptr<Box> boxFactory(char c, int w, int h) {
  if(c == 'f') {
    return make_unique<FilledBox>(FilledBox(w, h));
  }

  if(c == 'h') {
    return make_unique<HollowBox>(HollowBox(w, h));
  }

  if(c == 'c') {
    return make_unique<CheckeredBox>(CheckeredBox(w, h));
  }

  return nullptr;
}

#endif
