#include "ArraySet.h"
#include <iostream>
void findDifference(ArraySet<char> bag1,ArraySet<char> bag2);
void displayBag(ArraySet<char>& bag);
using namespace std;
int main()
{
  ArraySet<char> bag1, bag2;
  char x[]={'a','e','d'};
  char y[]={'a','b','c'};
  char z[]={'d','e','f'};
   for(int i=0; i<3; ++i)
    {
          bag1.add(y[i]);
    }
    cout << "Add ";
    displayBag(bag1);
    cout <<" to the bag " << endl;
    cout <<" add c in to the set bag"<<endl;
    cout <<"return "
	 << bag1.add('c');
    cout << "  Should be 0;which is false"<< endl;
    cout << "Clear the bag"<< endl;
    bag1.clear();
    cout << " Is left hand side empty: returns "
	 << bag1.isEmpty()
	 <<"; should be 1 (true)"
	 << endl;
    cout << " Is right hand side empty: returns "
	 << bag2.isEmpty()
	 <<"; should be 1 (true)"
	 << endl;
    cout << "Result from difference when both sets are empty." <<endl;
    findDifference(bag1,bag2);
    cout <<endl;
    cout <<endl;

   for(int i=0; i<3; ++i)
    {
          bag2.add(y[i]);
    }

   cout << "Add ";
   displayBag(bag2);
    cout <<" to the right-hand bag " << endl;
    cout << " Is left hand side empty: returns "
	 << bag1.isEmpty()
	 <<"; should be 1 (ture)"
	 << endl;
    cout << " Is right hand side empty: returns "
	 << bag2.isEmpty()
	 <<"; should be 0 (false)"
	 << endl;
 
    cout << "Result from difference when this (left-hand side) set is empty"
	 << endl
	 << "but the set passed in as an argument (right-hand side) has items in it."<<endl;
    findDifference(bag1,bag2);
    cout << "Clear the bag " << endl;
    bag2.clear();
    cout << endl
	 << endl;


   for(int i=0; i<3; ++i)
    {
          bag1.add(y[i]);
    }

   cout << "Add ";
   displayBag(bag1);
    cout <<" to the left-hand bag " << endl;
    cout << " Is left hand side empty: returns "
	 << bag1.isEmpty()
	 <<"; should be 0 (false)"
	 << endl;
    cout << " Is right hand side empty: returns "
	 << bag2.isEmpty()
	 <<"; should be 1 (true)"
	 << endl;

    cout << "Result from difference when the right-hand side set is empty" << endl
	 << "but the left-hand side set has items in it."<< endl;
    findDifference(bag1,bag2);
    cout << endl;
    cout << endl;


   for(int i=0; i<3; ++i)
    {
          bag2.add(z[i]);
    }

   cout << "Add ";
   displayBag(bag2);
    cout <<" to the right-hand bag " << endl;
    cout << " Is left hand side empty: returns "
	 << bag1.isEmpty()
	 <<"; should be 0 (false)"
	 << endl;
    cout << " Is right hand side empty: returns "
	 << bag2.isEmpty()
	 <<"; should be 0 (false)"
	 << endl;
    cout << "The left-hand bag has ";
      displayBag(bag1);
      cout << endl;
    cout << "Result from difference when the sets have no intersection"
	 << endl;
    findDifference(bag1,bag2);
    cout << "Clear the bag"<< endl;
    bag2.clear();
    bag1.clear();
    cout << endl
	 << endl;



   for(int i=0; i<3; ++i)
    {
          bag2.add(x[i]);
    }

   for(int i=0; i<3; ++i)
    {
          bag1.add(y[i]);
    }

   cout << "Add ";
   displayBag(bag2);
   cout <<" to the right-hand bag " << endl;
   cout << "Add ";
   displayBag(bag1);
    cout <<" to the left-hand bag " << endl;

    cout << " Is left hand side empty: returns "
	 << bag1.isEmpty()
	 <<"; should be 0 (false)"
	 << endl;
    cout << " Is right hand side empty: returns "
	 << bag2.isEmpty()
	 <<"; should be 0 (false)"
	 << endl;
    cout << "The left-hand bag has ";
      displayBag(bag1);
      cout << endl;
    cout << "Result from difference when the sets have an intersection"
	 << endl
	 << "but they do not contain identical sets of items."<<endl;
    findDifference(bag1,bag2);
    cout << endl;
    cout << "Clear the bag"<< endl;
    bag2.clear();
    bag1.clear();
    cout << endl
	 << endl;




   for(int i=0; i<3; ++i)
    {
          bag2.add(y[i]);
    }

   for(int i=0; i<3; ++i)
    {
          bag1.add(y[i]);
    }

   cout << "Add ";
   displayBag(bag2);
   cout <<" to the right-hand bag " << endl;
   cout << "Add ";
   displayBag(bag1);
    cout <<" to the left-hand bag " << endl;

    cout << " Is left hand side empty: returns "
	 << bag1.isEmpty()
	 <<"; should be 0 (false)"
	 << endl;
    cout << " Is right hand side empty: returns "
	 << bag2.isEmpty()
	 <<"; should be 0 (false)"
	 << endl;
    cout << "Result from difference when the sets contain the same sets of items"
	 << endl;
    findDifference(bag1,bag2);
    cout << endl;
    cout << "Clear the bag"<< endl;
    bag2.clear();
    bag1.clear();




}


void findDifference(ArraySet<char> bag1,ArraySet<char> bag2)
{
  ArraySet<char> a = bag1.difference(bag2);
  vector<char> bagItems = a.toVector();
  int count = (int) bagItems.size();
  for (int i = 0; i < count; ++i) {
    cout << bagItems[i]
	 << " ";
  }

}
   
void displayBag(ArraySet<char>& bag)
{
     vector<char> bagItem = bag.toVector();
   int count = bagItem.size();
   for (int i = 0; i < count; ++i) {
     cout << bagItem[i]
	  << " ";
   }
}
