#include "ArraySet.h"
#include <iostream>
void check(ArraySet<char> bag1,ArraySet<char> bag1bag2,ArraySet<char> bag1c);
using namespace std;
int main()
{
  ArraySet<char> bag1, bag2, c;
  char x[]={'a','b','b','c','c'};
  char y[]={'a','b','c'};
  char z[]={'d','e','f'};
  char w[]={'a','r','f'};
   for(int i=0; i<5; ++i)
    {
          bag1.add(x[i]);
    }
  cout << "Add 'a','b','b','c','c' to the bag and display " << endl;
 
  vector<char> bagItem = bag1.toVector();
  int count = bagItem.size();
  for (int i = 0; i < count; ++i) {
    cout << bagItem[i]
	 << " ";
  }
    cout <<"shoule be a b c" <<endl;
    bag1.clear();
    cout << "Result from difference when both sets are empty." <<endl;
    check(bag1,bag2,c);
    cout << endl;
    cout << "Result from difference when this (left-hand side) set is empty"
	 << endl
	 << "but the set passed in as an argument (right-hand side) has items in it."<<endl;
    for(int i=0; i<5; ++i)
    {
          bag2.add(x[i]);
    }
    
    check(bag1,bag2,c);
    bag2.clear();
    cout << endl;
    cout << "Result from difference when the right-hand side set is empty" << endl
    << "but the left-hand side set has items in it."<< endl;
    for(int i=0; i<5; ++i)
      {
	bag1.add(x[i]);
      }
    check(bag1,bag2,c);
    cout << endl;
    cout << "Result from difference when the sets have no intersection"
	 << endl;
    for(int i=0; i<5; ++i)
      {
        bag2.add(z[i]);
      }
    check(bag1,bag2,c);
    bag2.clear();
}


void check(ArraySet<char> bag1,ArraySet<char> bag2,ArraySet<char> c)
{
  c = bag1.difference(bag2);
  if(bag1.isEmpty()&& !bag2.isEmpty())
    {
      cout << "Left-hand side is empty" <<endl;
    }
  /* if(bag2.isEmpty()&& !bag1.isEmpty())
    {
      cout << "Right-hand side is empty" <<endl;
      }*/

  if((c.isEmpty()&& !bag1.isEmpty())||bag1.isEmpty())
    {
      cout << "There are no difference items" << endl;
    }
  if(bag1.isEmpty()&& bag2.isEmpty())
    {
      cout << "Both side bag are empty" << endl;
    }
  vector<char> bagItems = c.toVector();
  int count =  bagItems.size();
  for (int i = 0; i < count; ++i) {
    cout << bagItems[i]
	 << " ";
  }

}
