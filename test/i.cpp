#include <iostream>
 #include <string>
 #include <deque>
 #include <cstdlib>
 
 using namespace std;
 
 int main() {
 
    deque<string> groceryList;
 
    deque<string>::iterator iter = groceryList.begin();
 
     groceryList.insert(iter, "apples");
     groceryList.insert(iter, "bread");
    groceryList.insert(iter, "juice");
 
    cout << "Number of items on my grocery list: "
         << groceryList.size()
         << endl;
 
    cout << "Items are:"
         << endl;
 
    iter = groceryList.begin();

     while (iter != groceryList.end() ) {
        cout << *iter
             << endl;
        iter++;
     }
 
     return EXIT_SUCCESS;
  }
