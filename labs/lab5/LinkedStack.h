#ifndef _LINKED_STACK
#define _LINKED_STACK

#include "StackInterface.h"
#include "Node.h"

/** @class LinkedStack LinkedStack.h "LinkedStack.h"
 *
 *  Specification of a pointer-based ADT stack. */
template <typename ItemType>
class LinkedStack : public StackInterface<ItemType> {
 private:
  Node<ItemType>* topPtr;

 public:
  LinkedStack();

  LinkedStack(const LinkedStack<ItemType>& aStack);

  virtual ~LinkedStack();

  virtual bool isEmpty() const;

  virtual bool push(const ItemType& newEntry);

  virtual bool pop();

  virtual ItemType peek() const;
};

#include "LinkedStack.cpp"

#endif
