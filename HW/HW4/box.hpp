#ifndef BOX_HPP
#define BOX_HPP

#include <iostream>

class Box {
private:
  int width;
  int height;

public:

  Box(int w, int h): width(w), height(h) {

  }

  int getWidth() { return width; }
  int getHeight() { return height; }

};

class HollowBox : public Box {

};

class FilledBox : public Box {

};

class CheckeredBox : public Box {

};

#endif
