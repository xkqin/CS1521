
#include <new>

using namespace std;

#include "PrecondViolateExcep.h"
template <typename ItemType>
LinkedStack<ItemType>::LinkedStack()
  : topPtr(nullptr) {
}

template <typename ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& aStack) {

  if (aStack.topPtr == nullptr) {
    topPtr = nullptr;
  }
  else {
    Node<ItemType>* origChainPtr = aStack.topPtr;

    try {
      topPtr = new Node<ItemType>();
      topPtr->setItem(origChainPtr->getItem() );

      Node<ItemType>* newChainPtr = topPtr;

      origChainPtr = origChainPtr->getNext();

      while (origChainPtr != nullptr) {
	ItemType nextItem = origChainPtr->getItem();

	Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

	newChainPtr->setNext(newNodePtr);

	newChainPtr = newChainPtr->getNext();

	origChainPtr = origChainPtr->getNext();
      }

      newChainPtr->setNext(nullptr);
    }
    catch(const bad_alloc&) {
      while (!isEmpty() ) {
	pop();
      }
      throw;
    }
  }
}

template <typename ItemType>
LinkedStack<ItemType>::~LinkedStack() {

  while (!isEmpty() ) {
    pop();
  }
}

template <typename ItemType>
bool LinkedStack<ItemType>::isEmpty() const {

  return topPtr == nullptr;
}

template <typename ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newItem) {

  bool result = true;

  try {
    Node<ItemType>* newNodePtr = new Node<ItemType>(newItem, topPtr);

    topPtr = newNodePtr;

    newNodePtr = nullptr;
  }
  catch(const bad_alloc&) {
    result = false;
  }

  return result;
}

template <typename ItemType>
bool LinkedStack<ItemType>::pop() {

  bool result = false;

  if (!isEmpty() ) {
    Node<ItemType>* nodeToDeletePtr = topPtr;

    topPtr = topPtr->getNext();

    nodeToDeletePtr->setNext(nullptr);
    delete nodeToDeletePtr;
    nodeToDeletePtr = nullptr;

    result = true;
  }

  return result;
}

template <typename ItemType>
ItemType LinkedStack<ItemType>::peek() const {

  if(isEmpty())
    {
      throw PrecondViolateExcep ("You enter a wrong input or you didn't match the parenthsis ");
    }
  return topPtr->getItem();
}
