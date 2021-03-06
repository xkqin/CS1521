#include <iostream>
#include <cstdlib>
 
using namespace std;


#include "getPosition.h"
 
int main() {
 
   ArrayList<int> iList;
 
   iList.insert(1, 5);
   iList.insert(2, 9);
   iList.insert(1, 4);
   iList.insert(2, 7);
   iList.insert(4, 6);

   int position = 0;
   int value = 0;

   while (cin >> value) {

      if ((position = getPosition(iList, value)) <= iList.getLength() ) {
         cout << "iList["
              << position
              << "] = "
              << value
              << "."
              << endl;
      }
     else {
         cout << "iList does NOT contain "
              << value
              << "."
              << endl;
      }
   }

   return EXIT_SUCCESS;
}
