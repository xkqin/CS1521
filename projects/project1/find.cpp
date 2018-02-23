#include "find.h"
#include <iostream>
using namespace std;


Find::Find()
{
  count = 0;
  last = 0;
  mean = 0;
  min = 0;
  max = 0;

}

Find::Find(int c, double la, double su, double me, double mi, double ma)
  :count(c),
   last(la),
   sum(su),
   mean(me),
   min(mi),
   max(ma)
{

}



double Find::getN() const
{
  return count;
}


double Find::getLast() const
{
  return last;
}

double Find::getMin() const
{
  return min;
}

double Find::getMax() const
{
  return max;
}

double Find::getSum() const
{
  return sum;
}

double  Find::getMean() const
{
  return mean;
}



void Find::cal(double a)
{
  count++;
  last = a;
  sum += a;
  mean = sum/count;
  if( min == 0) min = a;
  else if (a < min ) min = a;
  /*if (max == 0) max = a;
  else */if (a > max ) max = a;
}


void Find::clear()
{
  last = 0;
  sum = 0;
  mean = 0;
  min = 0;
  max = 0;
  count = 0;
}
