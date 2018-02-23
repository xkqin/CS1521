#ifndef _RATIONAL
#define _RATIONAL

#include <iostream>

using namespace std;

class Complex {
 private:
  double real;
  double img;
 public:
  Complex(double r, double i);
  friend const Complex operator+(const Complex&,
				 const Complex&);

  friend const Complex operator-(const Complex&,
                                 const Complex&);
  friend istream& operator>>(istream&,
			     Complex&);
};
#endif
