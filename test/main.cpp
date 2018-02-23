#include<iostream>
#include<string>
#include<fstream>
#include"infix.h"

using namespace std;

int main()
{
  ifstream fin;
  string filename,exp;
  infix infixString;
  char ans;
  do{
  cout << "Enter a file that you want to get input for " << endl;
  cin >> filename;
  fin.open(filename.c_str());
  while (!fin) {
    cerr << "file"
         << filename
         << " failed to open for input."
         << endl;
    cout << "Enter a file: ";
    cin >> filename;
    fin.open( filename.c_str() );
  }
  while(getline(fin,exp))
    {
      infixString.setString(exp);
      
      try{
	cout << infixString.getString()<<" = "<< infixString.value()<<endl;
      }
      catch(const dividzero& e)
	{
	  cout << infixString.getString() << " "<<e.what()<<endl;
	}
    }
      fin.close();

      cout << "Do you want to again? (Y/N)" << endl;
      cin >> ans;
  }while(ans == 'y'|| ans == 'Y');
}
