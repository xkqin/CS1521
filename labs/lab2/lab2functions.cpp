#include "lab2functions.h"
#include <iostream>
using namespace std;
void writeLine(const char x, const int m)
{
  if(m > 0) 
    {
      cout << x;
      writeLine(x, m-1);
    }
  else cout << "";
}


void writeBlock(const char x, const int m, const int s)
{
  if(m <= 0) cout << ""; 
  else if(s == 1)
    {
      writeLine(x, m);
    }
  else if(s > 1)
    {
      writeLine(x, m);
      cout << endl;
      writeBlock(x, m, s-1);
    }
  else cout << "";
      
}

void writePyramid( int l)
{
   writeP(l, 0);
}

void writeP( int l, int i)
{
  if(l>0)
    {
      writeLine(' ', l-1);     
      writeLine('*', 2*i+1);
      i++;
      cout << endl;
      writeP( l-1,i );
    }
  else cout << "";
}
