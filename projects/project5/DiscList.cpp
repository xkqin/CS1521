#include <iostream>
#include <string>


#include "DiscList.h"

using namespace std;

DiscList::DiscList()
  :discListPtr(new LinkedList<Disc*>())
{
}  

DiscList::~DiscList()
{
  discListPtr -> clear();
  delete discListPtr;
  discListPtr = nullptr;
}

int DiscList::findDiscPosition(Disc* discPtr) const
{
  int i;
  for ( i=1; i <= getNumberOfDiscs(); ++i  )
    {
      if( retrieveDisc(i) == discPtr)
	{
	  break;
	}
    }
  return i;
}
bool DiscList::isEmpty() const
{
  return discListPtr -> isEmpty();
}
int DiscList::getNumberOfDiscs() const
{
  return discListPtr -> getLength();
} 
bool DiscList::insertDisc( Disc* aDiscPtr)
{
  bool result = false;
  int count=0;
  if(isEmpty())
    {
       discListPtr -> insert(1, aDiscPtr);
       result = true;
    }
  else
    {
	  if( retrieveDisc(getNumberOfDiscs()) -> isLessThan(aDiscPtr) )
	    {
	      discListPtr -> insert(getNumberOfDiscs()+1, aDiscPtr);
	      result = true;
	    }
	
	  else
	    {
	      for(int i=getNumberOfDiscs(); i >=1; --i)
		{
		  if(aDiscPtr -> isLessThan(retrieveDisc(i)))
		    {
		      count++; 
		    }
		}
	      discListPtr -> insert(getNumberOfDiscs()-count+1, aDiscPtr);
	      result = true;	      
	    }
    }
  return result;
}
bool DiscList::removeDisc(const Disc* aDiscPtr)
{
  bool remove = false;
  for(int i=1; i<= getNumberOfDiscs(); ++i)
    {
      if (retrieveDisc(i) == aDiscPtr)
	{
	  discListPtr -> remove(i);
	  remove = true;
	  break;
	}
    }
  return remove;
}
Disc* DiscList::retrieveDisc(const int number) const
{
  if(number < 1 || number > getNumberOfDiscs())
    {
      string message ="Can not retrieve disc with wrong number !";
      throw PrecondViolatedExcep(message);
    }
  return discListPtr -> getEntry(number);
}
