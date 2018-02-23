//#define NDEBUG

#include <string>
#include <new>

using namespace std;

#include <cassert>

#include "PrecondViolatedExcep.h"

template <typename ItemType>
LinkedList<ItemType>::LinkedList()
  : headPtr(nullptr),
    itemCount(0) {
}

template <typename ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList) {

  itemCount = 0; // Empty linked chain

  if (aList.headPtr == nullptr) {
    headPtr = nullptr;
  }
  else {
    Node<ItemType>* aListPtr = aList.headPtr;

    try {
      headPtr = new Node<ItemType>();
      headPtr->setItem(aListPtr->getItem() );

      ++itemCount; // Increment after successful call to new

      Node<ItemType>* thisListPtr = headPtr;

      aListPtr = aListPtr->getNext();

      while (aListPtr != nullptr) {
	ItemType nextItem = aListPtr->getItem();

	Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

	thisListPtr->setNext(newNodePtr);

	++itemCount; // Increment after each successful call to new

	thisListPtr = thisListPtr->getNext();

	aListPtr = aListPtr->getNext();
      }

      thisListPtr->setNext(nullptr);
    }
    catch (const bad_alloc&) {
      clear();
      throw;
    }
  }
}

template <typename ItemType>
LinkedList<ItemType>::~LinkedList() {

  clear();
}

template <typename ItemType>
bool LinkedList<ItemType>::isEmpty() const {

  return itemCount == 0;
}

template <typename ItemType>
int LinkedList<ItemType>::getLength() const {

  return itemCount;
}

template <typename ItemType>
bool LinkedList<ItemType>::insert(const int newPosition,
                                  const ItemType& newEntry) {

   bool ableToInsert = newPosition >= 1 &&
     newPosition <= itemCount + 1;

   if (ableToInsert) {
     try {
       Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

       if (newPosition == 1) {
	 newNodePtr->setNext(headPtr);
	 headPtr = newNodePtr;
       }
       else {
	 Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);

	 newNodePtr->setNext(prevPtr->getNext() );
	 prevPtr->setNext(newNodePtr);
       }
       ++itemCount;
     }
     catch (const bad_alloc&) {
       ableToInsert = false;
     }
   }

   return ableToInsert;
}

template <typename ItemType>
bool LinkedList<ItemType>::remove(const int position) {

   bool ableToRemove = position >= 1 &&
     position <= itemCount;

   if (ableToRemove) {
     Node<ItemType>* nodeToDeletePtr = nullptr;

     if (position == 1) {
       nodeToDeletePtr = headPtr;
       headPtr = headPtr->getNext();
     }
     else {
       Node<ItemType>* prevPtr = getNodeAt(position - 1);

       nodeToDeletePtr = prevPtr->getNext();

       prevPtr->setNext(nodeToDeletePtr->getNext() );
     }

     nodeToDeletePtr->setNext(nullptr);
     delete nodeToDeletePtr;
     nodeToDeletePtr = nullptr;

     --itemCount;
   }

   return ableToRemove;
}

template <typename ItemType>
void LinkedList<ItemType>::clear() {

  while (!isEmpty() ) {
    remove(1);
  }
}

template <typename ItemType>
ItemType LinkedList<ItemType>::getEntry(const int position) const {

   bool ableToGet = position >= 1 &&
     position <= itemCount;

   if (!ableToGet) {
     string message = "LinkedList::getEntry() called with an empty ";
     message += "list or an invalid position.";

     throw PrecondViolatedExcep(message);
   }

   Node<ItemType>* nodePtr = getNodeAt(position);

   return nodePtr->getItem();
}

template <typename ItemType>
void LinkedList<ItemType>::setEntry(const int position,
				    const ItemType& newEntry) {

   bool ableToSet = position >= 1 &&
     position <= itemCount;

   if (!ableToSet) {
     string message = "LinkedList::setEntry() called with an empty ";
     message += "list or an invalid position.";

     throw PrecondViolatedExcep(message);
   }

   Node<ItemType>* nodePtr = getNodeAt(position);

   nodePtr->setItem(newEntry);
}

template <typename ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(const int position) const {

  assert(position >= 1 && position <= itemCount);

  Node<ItemType>* curPtr = headPtr;

  for (int skip = 1; skip < position; ++skip) {
    curPtr = curPtr->getNext();
  }

  return curPtr;
}
