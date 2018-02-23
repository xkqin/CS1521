#include <iostream>
#include <string>
using namespace std;
bool precedence(char a, char b);
int main()
{
  cout << !precedence('/','+');
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
      value.push(operand1/operand2);
      break;
      // defult:
      //cout << "There is no match operator! "<< endl;
      //break;
    }

}


bool precedence(const char a, const char opr)
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

/*
bool precedence( char a, char b)
{
  string first = "/*";
  string second = "+-";
  string third = "()";
  bool p;
  if((first[0]== b || first[1] == b) &&
     ( first[0]== a || first[1] == a ))
    {
      p = true;
    }
  else if(first[0]== b||first[1] == b)
    {
      p = true;
    }
  else if(second[0] == b || second[1] == b &&(third[0] == a||third[1] ==a) )
    {
      p = true;
    }
  else p = false;

  return p;
}
*/
