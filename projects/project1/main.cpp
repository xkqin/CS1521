#include <iostream>//for cin and cout
#include "find.h"// for ADT find
using namespace std;
int main()
{
    Find u1;
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

	  cout << "Do you want to enter another none-empty sequence?(Y/N)" << endl;
	  cin >> b;
	    if(b == 'n' || b == 'N') break;
	}
    do{
      cout << "Enter the number you want " << endl;
      cin >> a;
      u1.cal(a);
      cout << "Do you want to continue (Y/N) " << endl;
      cin >> b;
    }while (b == 'y' || b == 'Y');


    cout << " The number of the sequence is " << u1.getN() << endl;
    cout << " The last number is " << u1.getLast() << endl;
    cout << " The sum of the sequence is " <<u1.getSum() << endl;
    cout << " The mean of the sequencs is "<< u1.getMean() << endl;
    cout << " The minimum of the sequencs is " << u1.getMin() << endl;
    cout << " The maximum of the sequencs is " << u1.getMax() << endl;
    cout << " Do you want to again? (Y/N)" << endl;
    cin >> b;
    if(b == 'y' || b == 'Y')
      {
	u1.clear();
      }
    }while(b == 'Y'  || b == 'y');
  //Print the data member on the monitor.
  return 0;
}//end main
    
