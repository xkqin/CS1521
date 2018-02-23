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



void Find::getInput()
{
  double a;
  char b;
  do{
    cout << "Do you want to enter an sequence? (Y/N)" << endl;
    cin >> b;
    if(b == 'n'|| b == 'N') 
      {
	cout << "count = 0" << endl;
	cout << "sum = 0" << endl;
	cout << "This is an empty sequence " << endl;
      }
  }while(b =='n' ||b == 'n');
  do{
    cout << "Enter the number you want " << endl;
    cin >> a;
    cal(a);
    cout << "Do you want to continue (Y/N) " << endl;
    cin >> b;
  }while (b == 'y' || b == 'Y');
}

void Find::cal(double a)
{
  count++;
  last = a;
  sum += a;
  mean = sum/count;
  if( min == 0) min = a;
  else if (a < min ) min = a;
  if (max == 0) max = a;
  else if (a > max ) max = a;
}



void Find::print() const
{
  cout << " The number of the sequence is " << count << endl;
  cout << " The last number is " << last << endl; 
  cout << " The sum of the sequence is " << sum << endl;
  cout << " The mean of the sequencs is "<< mean << endl;
  cout << " The minimum of the sequencs is " << min << endl;
  cout << " The maximum of the sequencs is " << max << endl;
}
