#include <iostream>
 #include <list>
 #include <stdexcept>
using namespace std;
int main()
{
  list<int> arr;
  list<int>:: iterator iter = arr.begin();
  iter=arr.insert(iter, 1);
  iter=arr.insert(iter, 2);
  iter=arr.insert(iter, 3);
  iter=arr.insert(iter, 4);
  iter=arr.insert(iter, 5);
   iter = arr.begin();
  for(iter;iter != arr.end(); ++ iter)
    {
      cout << *iter;
    }
}
