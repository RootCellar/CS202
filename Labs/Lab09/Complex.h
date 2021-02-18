#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {

  friend std::ostream& operator<<(std::ostream&, Complex c);

public:


  Complex(double, double=0);

  Complex& operator+=(const Complex& c);


private:
  double _real;
  double _imaginary;
};

Complex operator+(const Complex&, const Complex&);


#endif
