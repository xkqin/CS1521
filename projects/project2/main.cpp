#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

#include "BagOfArray.h"

void displayBag(BagOfArray<string>& bag) {

  cout << "The bag contains "
       << bag.getCurrentSize()
       << " items:"
       << endl;

  vector<string> bagItems = bag.toVector();

  int numberOfEntries = (int)bagItems.size();

  for (int i = 0; i < numberOfEntries; ++i) {
    cout << bagItems[i]
	 << " ";
  }

  cout << endl
       << endl;
}

void bagTester(BagOfArray<string>& bag) {

  cout << "isEmpty: returns "
       << bag.isEmpty()
       << "; should be 1 (true)"
       << endl;

  displayBag(bag);

  string items[] = {"one", "two", "three", "four", "five", "one"};

  cout << "Add 6(One,two,three,four,five,one) items to the bag: "
       << endl;

  for (int i = 0; i < 6; ++i) {
    bag.add(items[i]);
  }

  displayBag(bag);

  cout << "isEmpty(): returns "
       << bag.isEmpty()
       << "; should be 0 (false)"
       << endl;

  cout << "getCurrentSize(): returns "
       << bag.getCurrentSize()
       << "; should be 6"
       << endl;

  cout << "Try to add another entry: add(\"extra\") returns "
       << bag.add("extra")
       << "; should return the index of the extra which is 6"
       << endl;
  displayBag(bag);
  cout << "if contains the one in the array: returns "
       << bag.contains("one")
       << "; should be 1 (true)"
       << endl;

  cout << "remove the second item : returns "
       << bag.removeWithReceipt(1)
       << "; should return two"
       << endl;
  displayBag(bag);
  cout << "add an item to the gap which the second position in bag: returns "
       << bag.add("Extra2")
       << "; should return 1 which is the index of the gap"
       << endl;
  displayBag(bag);
  cout << "remove the last iteme: returns "
       << bag.removeWithReceipt(6)
       << "; should be extra"
       << endl;
  displayBag(bag);
  cout << "getFrequencyOf the one  : returns "
       << bag.getFrequencyOf("one")
       << "; should be 2"
       << endl;

  cout << "remove the third item: returns "
       << bag.removeWithReceipt(2)
       << "; should be three"
       << endl;
    

  cout << endl;

  displayBag(bag);
  cout << "should be one Extra2 four five one " << endl;
  cout << "After clearing the bag, ";

  bag.clear();

  cout << "isEmpty(): returns "
       << bag.isEmpty()
       << "; should be 1 (true)"
       << endl;
}

int main() {

  BagOfArray<string> bag;

  cout << "Testing the Array-Based Bag:"
       << endl
       << "The initial bag is empty."
       << endl;

  bagTester(bag);

  cout << "All done!"
       << endl;

  return EXIT_SUCCESS;
}
