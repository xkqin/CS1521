#include <iostream>
#include "infix.h"
#include "PrecondViolateExcep.h"
infix::infix()
  :infixString("")
{
}


void infix::setString(const string theString)
{
  infixString = theString;
}


string infix::getString() const
{
  return infixString;
}


bool infix::isLeft(const char a) const 
{
  return ( a == '(' );
}


bool infix::isRight(const char a) const
{
  return ( a == ')' );
}


bool infix::isOperator(const char a) const
{
  return ( a== '+' || a == '-' || a == '*' || a == '/' );
}


bool infix::precedence(const char a, const char opr) const
{
  string first = "/*";
  string second = "+-";
  string third = "()";
  bool p;

  if(((first[0] == opr||first[1] == opr) && (first[0] == a||first[1] == a))
     || ((second[0] == opr||second[1] == opr) && (second[0] == a||second[1] == a))
     || ((third[0] == opr||third[1] == opr) && (third[0] == a||third[1] == a)))
    {
      p = true;
    }
  else if(first[0] == opr||first[1] == opr)
    {
      p = true;
    }
  else if((second[0] == opr || second[1] == opr) &&(third[0] == a||third[1] ==a) )
    {
      p = true;
    }
  else p = false;

  return p;
}


void infix::execute(LinkedStack<int>& value, LinkedStack<char>& opr)
{
  int operand2 = value.peek();
  value.pop();
  int operand1 = value.peek();
  value.pop();
  char oprt = opr.peek();
  opr.pop();
  switch(oprt)
    {
    case '+':
      value.push(operand1+operand2);
      break;
    case '-':
      value.push(operand1-operand2);
      break;
    case '*':
      value.push(operand1*operand2);
      break;
    case '/':
      if(operand2 == 0)
	{
	  throw dividzero("Infinite result - Cannot handle division-by-zero.");
	}
      value.push(operand1/operand2);
      break;
    default:
      cout << "You enter a wrong operator " << endl;
      break;
    }
   
     
} 
      

int infix::value()
{
  LinkedStack<int> value;
  LinkedStack<char> opr;
  for(char ch:infixString)
    {
      if((int)ch >=48&&(int)ch <=57 )
	{
	  value.push((int)ch - 48);
	}
      else if(isLeft(ch))
	{
	  opr.push(ch);
	}
      else if(isOperator(ch))
	{
	  if(opr.isEmpty()|| (!precedence(ch,opr.peek())))
	    {
	      opr.push(ch);
	    }
	  else{
	    while ((!opr.isEmpty()) && precedence(ch,opr.peek()))
	      {
		execute(value,opr);
	      }
	    opr.push(ch);
	  }
	}
      else if(isRight(ch))
	{
	      
	  while(opr.peek() != '(')
	    {
	      execute(value,opr);
	    }
	  opr.pop();
	}
      //      else// if(opr.peek() != ' ')
	//	{
	//        throw PrecondViolateExcep("this is a wrong operator");	      
      //	} 
   }
  while( !opr.isEmpty() )
    {
      execute(value,opr);
    }

  return value.peek();
}
