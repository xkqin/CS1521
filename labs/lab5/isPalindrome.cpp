#include<string>
#include<iostream>

#include "LinkedQueue.h"
#include "LinkedStack.h"
#include "isPalindrome.h"
using namespace std;

bool isPalindrome(const string& theString)
{
  char ans;
  LinkedQueue<char> Queue;
  LinkedStack<char> Stack;
  
  bool isPal = true;
  int size = theString.length();
  for(int i=0; i< size ; ++i)
    { 
      ans=theString[i];
      Queue.enqueue(ans);
      Stack.push(ans);
    }
 
  for(int i=0; i < size ; ++i)
    {   
      if(Queue.peekFront() == Stack.peek())
	{ 
	  Stack.pop();
	  Queue.dequeue();
	}
      else
	{
	  isPal = false;
	  break;
	}
    } 

  return isPal;    
}
