#ifndef MONEY_HPP
#define MONEY_HPP

#include <iostream>

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
  friend ostream operator<<(ostream &one, const Money &two);

private:
  int value;

public:

  Money(): value(0) {

  }

  Money(double d) {
    d *= 100;
    value = (int)(d + 0.5);
  }

  Money(int d, int c) {
    value = d * 100;
    value += c;
  }

  Money operator+=(const Money &two) {
    this.value += two.value;
    return *this;
  }

  Money operator-=(const Money &two) {
    this.value -= two.value;
    return *this;
  }

  Money operator/=(const double two) {
    this.value /= two;
    return *this;
  }

  Money operator*=(const double two) {
    this.value *= two;
    return *this;
  }

};

Money operator/(const Money &one, const double two) {
  temp = one;
  temp /= two;
  return temp;
}

Money operator+(const Money &one, const Money &two) {
  temp = one;
  temp.value += two.value;
  return temp;
}

Money operator-(const Money &one, const Money &two) {
  temp = one;
  temp.value -= two.value;
  return temp;
}

Money operator*(const Money &one, const double two) {
  temp = one;
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


#endif
