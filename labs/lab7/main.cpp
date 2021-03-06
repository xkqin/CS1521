#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


void displayOneItem(char& itemToDisplay)
{
  cout << itemToDisplay << endl;
}

void moveUp5 (char& item)
{
  if((int)item >= 48 && (int)item <= 52)
    {
      item = (int)item + 5;
    }
  else if((int)item >= 53 && (int)item <= 57)
    {
      item = (int)item -5;
    }
}
void moveUp13(char& item)
{
  if((int)item >= 65 && (int)item <= 77)
    {
      item = (int)item + 13;
    }
  else if((int)item >= 78 && (int)item <= 90)
    {
      item = (int)item -13;
    }
  else if ((int)item >=97 && (int)item <= 109)
    {
      item = (int)item + 13;
    }
  else if((int)item >= 110 && (int)item <= 122)
    {
      item = (int)item -13;
    }
}


void encrypted(char& item)
{
    if((int)item >= 48 && (int)item <= 57)
    {
      moveUp5(item);
    }
  else if (((int)item >=65 && (int)item <=89) ||((int)item >= 97 && (int)item <= 122))
    {
      moveUp13(item);
    }
}

int main()
{
  string theString;
  cout << "Enter the string you want " << endl;
  getline(cin,theString);
  cout <<endl
       <<endl
       <<endl;
  cout << "The string you enter is " << endl;
  cout << theString << endl;
  for_each(theString.begin(),theString.end(),encrypted);
  cout << "The string after encrypted " << endl;
  cout << theString << endl;
  for_each(theString.begin(),theString.end(),encrypted);
  cout << "The string after decrypted " << endl;
  cout << theString << endl;
}
