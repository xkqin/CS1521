#include <iostream>


#include <string>
#include "DiscList.h"
using namespace std;
int main()
{

  char ans;
  DiscList* listPtr = new DiscList();
  Disc* newDisc;
  do{
  cout << "(A)dd a new disc." << endl;
  cout << "(R)emove an disc." << endl;
  cout << "(P)rint an disc." << endl;
  cout << "(L)ist discs." << endl;
  cout << "(Q)uit" << endl;
  cout << "Enter A CAPITAL letter please ! " << endl;  
  cin >> ans;
  cout << endl;
  cout << endl;
  ans = toupper(ans);
  switch (ans)
    {
      
    case 'A':
    case'a':
      {
	newDisc = new Disc();
	newDisc -> readDisc();
        listPtr -> insertDisc(newDisc);
	cout << endl
	     << endl;
	cout << "You have already insert!!" << endl;
	cout << endl
	     << endl;
      }
      break;
    case'r':
    case 'R':
      {
	try{
	  int number;
	  cout << "Ther are(is) " << listPtr -> getNumberOfDiscs() << " discs in the list" 
	       << endl;
	  for(int i=1; i <= listPtr -> getNumberOfDiscs(); ++i)
	    {
	      cout <<"The " << i << " disc is " 
		   << (listPtr ->retrieveDisc(i)) -> getTitle() << endl;
	    }
	  cout << "Which number of disc you want to remove? " << endl;
	  cin >> number;
	  if(listPtr -> removeDisc( listPtr -> retrieveDisc( number )))
	    {
	      cout << "Already remove !" << endl;
	      cout << endl
		   << endl;	
	    }
	  else
	    {
	      cout << "Can't remove !" << endl;
	      cout << endl
		   << endl;
	    }
	}
      
      catch (PrecondViolatedExcep& e){
	cerr << "Error :"
	     << e.what()
	     << endl;
      }
      }
      break;
    case'p':
    case 'P':
      {
	try{
	  if(listPtr -> getNumberOfDiscs() == 0)
	    {
	      cout << "It is empty!" << endl;
	      cout << endl;
	    }
	  
	  for(int i=1; i<= listPtr -> getNumberOfDiscs(); ++i)
	    {
	      cout << "No." << i << " Disc " 
		   << endl
		   << endl;
	      (listPtr -> retrieveDisc(i)) -> printDisc();
	      cout << endl
		   << endl
		   << endl;
	    }
	}
	catch (PrecondViolatedExcep& e){
	  cerr << "Error :"
	       << e.what()
	       << endl;
	}

      }
      break;
    case'l':
    case 'L':
      {
	try{
	  if(listPtr -> getNumberOfDiscs() == 0)
	    {
	      cout << "It is empty!" << endl;
	      cout << endl;
	    }
	  for(int i=1; i <= listPtr -> getNumberOfDiscs(); ++i)
	    {
	      cout <<"The " << i << " disc is " 
		   << (listPtr ->retrieveDisc(i)) -> getTitle() << endl;
	    }
	}
	catch (PrecondViolatedExcep& e){
	  cerr << "Error :"
	       << e.what()
	       << endl;
	}
      }
      break;
    case'q':
    case 'Q':
      {
	cout << "See you!!!" << endl
	     << endl;
      }
      break;
    default:
      cout << "You enter a wrong letter please enter again" << endl;
      break;
    }
  }while(ans != 'Q' );
}
