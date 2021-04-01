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

  virtual void print(ostream &os) const;
  virtual string type() const;

};

class HollowBox : public Box {
public:
  HollowBox(int w, int h): Box(w, h) {

  }

  HollowBox(): Box(1,1) {

  }

  void print(ostream &os) const {
    for(int i=0; i<getWidth(); i++) os << "*";
    os << "\n";
  }

  string type() const {
    return "HollowBox";
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
    return "FilledBox";
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
    return "CheckeredBox";
  }
};

ostream& operator<<(ostream &os, const Box &b) {
  b.print(os);
  return os;
}

std::unique_ptr<Box> boxFactory(char c, int w, int h) {
  if(c == 'f') {
    return make_unique<Box>(FilledBox(w, h));
  }

  if(c == 'h') {
    return make_unique<Box>(HollowBox(w, h));
  }

  if(c == 'c') {
    return make_unique<Box>(CheckeredBox(w, h));
  }

  return nullptr;
}

#endif
