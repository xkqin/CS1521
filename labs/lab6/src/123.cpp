#inlcude <iostream>
using namespace std;
#include"123.h"

Complex::Complex(double r, double i)
  :real(r),
   img(i){

}

const Complex operator+(const Complex& lhs,
			const Complex& rhs){
  Complex sum(lhs.real+rhs.real, lhs.img+rhs.img);
  return sum;
}

