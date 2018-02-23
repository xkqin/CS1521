#ifndef _INFIX
#define _INFIX
#include "LinkedStack.h"
#include "PrecondViolateExcep.h"
#include "dividzero.h"
#include <string>
/** @class infix infix.h "infix.h"
 *
 *  Definition of infix class. */


class infix{
 private:
  /** private data member */
  string infixString;
  /** See whether this char is a left parenthese
   *
   * @param a the character of the string
   *
   * @return True if the character is the left parenthese.*/
  bool isLeft(const char a) const;
  /** See whether this char is a right parenthese
   *  
   *  @param a the character of the string
   *
   * @return True if the character is the left parenthese.*/
  bool isRight(const char a) const;
  /** See whether this char is a operator
   *
   * @param a the character of the string
   *
   * @return True if the character is the left parenthese.*/
  bool isOperator(const char a) const;
  /** comparing the operator precedence 
   *
   *  @param a the character of the string opr the opreator in the operator stack
   *
   *  @retrun Ture if the precedence of  'a' is smaller than the opr*/ 
  bool precedence(const char a, const char opr) const;
  /** calculating the value by using the operator stack and the value stack
   *
   *  @pre if the opr is '/' the second value stack should not be 0 because 1/0 is infinity
   *
   *  @param value the vlues stack and the operator stack opr
   *
   *  @throws dividbyzero If the precondition is violated.*/
  void execute(LinkedStack<int>& value, LinkedStack<char>& opr);

 public:
  /** constructor */
  infix();
  /** mutator of the private data member. */
  void setString(const string theString);
  /** getter of the Pricate data member. */
  string getString() const ;
  /** calculating the result of the value which was inputed in the program.
   *
   *  @return the result of the calculation. */
  int value();



};
    
  
#endif
