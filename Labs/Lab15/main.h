#ifndef MAIN_H
#define MAIN_H

#include <iostream>

using std::ostream;

template<typename T>
class Wrapper {

private:

  T data;

public:

  Wrapper(T d);

  T print();

};

template<typename T>
Wrapper<T>::Wrapper(T d): data(d) {

}

template<typename T>
T Wrapper<T>::print() {
  return data;
}

template<typename T>
ostream& operator<<(ostream &os, Wrapper<T> w) {
  return os << w.print();
}


#endif
