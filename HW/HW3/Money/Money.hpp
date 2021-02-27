#ifndef MONEY_HPP
#define MONEY_HPP

#define MONEY_DEBUG 1

#include <iostream>
#include <ostream>

#ifdef MONEY_DEBUG
using std::cout;
using std::endl;
#endif

class Money {

  //Boolean Operators
  friend bool operator==(const Money &one, const Money &two);
  friend bool operator!=(const Money &one, const Money &two);
  friend bool operator>(const Money &one, const Money &two);
  friend bool operator<(const Money &one, const Money &two);
  friend bool operator>=(const Money &one, const Money &two);
  friend bool operator<=(const Money &one, const Money &two);

  //Math Operators
  friend Money operator/(const Money &one, const double two);
  friend Money operator+(const Money &one, const Money &two);
  friend Money operator-(const Money &one, const Money &two);
  friend Money operator*(const Money &one, const double two);

  //Other
  friend std::ostream& operator<<(std::ostream &, const Money &);

private:
  int value;

public:

  Money(): value(0) {

  }

  Money(int i): value(i) {
  }

  Money(double d) {
    #ifdef MONEY_DEBUG
    cout << d << endl;
    #endif

    d *= 100;

    #ifdef MONEY_DEBUG
    cout << d + 0.5 << endl;
    #endif

    if(d<0) value = (int)(d - 0.5);
    else value = (int)(d + 0.5);

    #ifdef MONEY_DEBUG
    cout << value << endl;
    #endif
  }

  Money(int d, int c) {
    value = d * 100;
    value += c;
  }

  Money& operator+=(const Money &two) {
    value += two.value;
    return *this;
  }

  Money& operator-=(const Money &two) {
    value -= two.value;
    return *this;
  }

  Money& operator/=(const double two) {
    value /= two;
    return *this;
  }

  Money& operator*=(const double two) {
    value *= two;
    return *this;
  }

};

std::ostream& operator<<(std::ostream &one, const Money &two) {
  int value = two.value;
  bool isNegative = value < 0;
  if(isNegative) {
    one << "-";
    value*=-1;
  }

  one << "$" << (value/100) << ".";
  if(value%100 < 10) {
    one << "0" << (value%100);
  }
  else one << (value%100);
  return one;
}

Money operator/(const Money &one, const double two) {
  auto temp = one;
  temp /= two;
  return temp;
}

Money operator+(const Money &one, const Money &two) {
  auto temp = one;
  temp.value += two.value;
  return temp;
}

Money operator-(const Money &one, const Money &two) {
  auto temp = one;
  temp.value -= two.value;
  return temp;
}

Money operator*(const Money &one, const double two) {
  auto temp = one;
  temp.value *= two;
  return temp;
}

Money operator*(const double two, const Money &one) {
  return one * two;
}

bool operator==(const Money &one, const Money &two) {
  return one.value == two.value;
}

bool operator!=(const Money &one, const Money &two) {
  return !(one==two);
}

bool operator>(const Money &one, const Money &two) {
  return one.value > two.value;
}

bool operator<(const Money &one, const Money &two) {
  return !(one>two || one==two);
}

bool operator>=(const Money &one, const Money &two) {
  return one > two || one == two;
}

bool operator<=(const Money &one, const Money &two) {
  return !(one > two);
}


#endif
