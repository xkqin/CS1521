#include "lab2functions.h"
#include <iostream>
using namespace std;
int main()
{
   cout << "Test writeLine" << endl;
   writeLine( '@', 3);
   writeLine( '*', 3);
   cout << endl;
   writeLine( '*', -2);
   writeLine( '*', 0);
   writeLine( '*', 1);
   cout << endl;
   writeLine( '&', 2);
   cout << endl;
   writeLine( '@', 4);
   cout << endl;
   cout << "Test write Block " << endl;
   writeBlock( '#', 4, 1);
   writeBlock( '%', 4, 1);
   cout << endl;
   cout << "Test Block with a negative number of lines "<<endl;
   writeBlock( '*', -2, -1);
   writeBlock( '*', 0, -2);
   writeBlock( '*', 1, -2);
   writeBlock( '*', 3, -2);
   cout << "Test Block with zero number of lines " << endl;
   writeBlock( '*', -2, 0);
   writeBlock( '*', 0, 0);
   writeBlock( '*', 1, 0);
   writeBlock( '*', 3, 0);
   cout << "Test Block with positive number of lines ";
   writeBlock( '*', -2, 3);
   writeBlock( '*', 0, 3);
   cout << endl;
   writeBlock( '*', 1, 3);
   cout << endl;
   writeBlock( '*', 4, 3);
   cout << endl;
   cout << "Test the Pyramid " << endl;
   writePyramid(3);
   cout << endl;
   writePyramid(20);
  return 0;
}
