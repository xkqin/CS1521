#include<iostream>
#include<string>
#include"infix.h"
bool check(string tocheck);
using namespace std;

int main()
{
  string exp;
  infix infixString;
  cout << "Enter the claculation that you want, and enter 'stop'  to exit " << endl;
  while(getline(cin,exp) && check(exp)){
  infixString.setString(exp);
    try{
	cout << infixString.getString()<<" = "<< infixString.value()<<endl;
      }
      catch(const dividzero& e)
	{
	  cout << infixString.getString() << " "<<e.what()<<endl;
	}
      catch(const PrecondViolateExcep& e)
	{
	  cout << e.what() << endl;
	}
  
  }
}

bool check (string tocheck)
{
  return !(tocheck[0] == 's' && tocheck[1] == 't' && tocheck[2] == 'o' && tocheck[3] == 'p');
}
