#ifndef READWRITE_HPP
#define READWRITE_HPP

#include <fstream>

template<typename T>
void myWrite(std::ofstream& w, const T& x) {
  w.write(reinterpret_cast<const char *>(&x), sizeof(T));
}


template<typename T>
void myRead(std::ifstream& r, T& x) {
  r.read(reinterpret_cast<char *>(&x), sizeof(T));
}

#endif
