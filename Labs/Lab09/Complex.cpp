#include "Complex.h"

Complex::Complex(double r, double i): _real(r), _imaginary(i) {

}

Complex& Complex::operator+=(const Complex& c) {
  _real += c._real;
  _imaginary += c._imaginary;
  return *this;
}

Complex operator+(const Complex& x, const Complex& c) {
  Complex temp(x);
  temp+=c;
  return temp;
}

std::ostream& operator<<(std::ostream& os, Complex c) {
  return os << c._real << " + " << c._imaginary << "i";
}
