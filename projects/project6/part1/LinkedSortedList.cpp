#include <string>
#include <new>

using namespace std;

// #define NDEBUG

#include <cassert>

#include "PrecondViolatedExcep.h"

template <typename ItemType>
LinkedSortedList<ItemType>::LinkedSortedList()
  : headPtr(nullptr),
    itemCount(0) {
}

template <typename ItemType>
LinkedSortedList<ItemType>::LinkedSortedList(const LinkedSortedList<ItemType>& aList) {

  try {
    headPtr = copyChain(aList.headPtr);

    itemCount = aList.itemCount;
  }
  catch (const bad_alloc&) {
    clear();
    throw;
  }
}

template <typename ItemType>
Node<ItemType>* LinkedSortedList<ItemType>::copyChain(const Node<ItemType>* origChainPtr) {

  Node<ItemType>* copiedChainPtr = nullptr;

  if (origChainPtr != nullptr) {
    copiedChainPtr = new Node<ItemType>(origChainPtr->getItem() );

    copiedChainPtr->setNext(copyChain(origChainPtr->getNext()) );
  }

  return copiedChainPtr;
}

template <typename ItemType>
LinkedSortedList<ItemType>::~LinkedSortedList() {

  clear();
}

template <typename ItemType>
bool LinkedSortedList<ItemType>::isEmpty() const {

  return headPtr == nullptr;
}

template <typename ItemType>
int LinkedSortedList<ItemType>::getLength() const {

  return itemCount;
}

template <typename ItemType>
bool LinkedSortedList<ItemType>::insertSorted(const ItemType& newEntry) {

  bool canInsert = true;

  try {
    Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
    Node<ItemType>* prevPtr = getNodeBefore(newEntry);

    if (isEmpty() || prevPtr == nullptr) {
      newNodePtr->setNext(headPtr);
      headPtr = newNodePtr;
    }
    else {
      Node<ItemType>* aftPtr = prevPtr->getNext();
      newNodePtr->setNext(aftPtr);
      prevPtr->setNext(newNodePtr);
    }

    ++itemCount;
  }
  catch (const bad_alloc&) {
    canInsert = false;
  }

  return canInsert;
}

template <typename ItemType>
Node<ItemType>* LinkedSortedList<ItemType>::getNodeBefore(const ItemType& anEntry) const {

  Node<ItemType>* curPtr = headPtr;
  Node<ItemType>* prevPtr = nullptr;

  while (curPtr != nullptr && anEntry > curPtr->getItem() ) {
    prevPtr = curPtr;
    curPtr = curPtr->getNext();
  }

  return prevPtr;
}

template <typename ItemType>
bool LinkedSortedList<ItemType>::removeSorted(const ItemType& anEntry) {

  bool ableToRemove = false;

  if (!isEmpty() ) {
    int position = getPosition(anEntry);

    if (position > 0) {
      Node<ItemType>* prevPtr = getNodeBefore(anEntry);
      // Line 134 will work instead of line 135 below, but line 134
      // is O(n) and line 135 is O(1).
      // Node<ItemType>* nodeToDeletePtr = getNodeAt(position);
      Node<ItemType>* nodeToDeletePtr = prevPtr->getNext();

      ableToRemove = true;

      prevPtr->setNext(nodeToDeletePtr->getNext() );

      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      nodeToDeletePtr = nullptr;

      --itemCount;
    }
  }

  return ableToRemove;
}

template <typename ItemType>
bool LinkedSortedList<ItemType>::remove(const int position) {

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
void LinkedSortedList<ItemType>::clear() {

  while (!isEmpty() ) {
    remove(1);
  }

  itemCount = 0;
}

template <typename ItemType>
ItemType LinkedSortedList<ItemType>::getEntry(const int position) const {

   const bool ableToGet = position >= 1 &&
     position <= itemCount;

   if (!ableToGet) {
     string message = "LinkedSortedList::getEntry() called with an empty ";
     message += "list or an invalid position.";

     throw PrecondViolatedExcep(message);
   }

   Node<ItemType>* nodePtr = getNodeAt(position);

   return nodePtr->getItem();
}

template <typename ItemType>
Node<ItemType>* LinkedSortedList<ItemType>::getNodeAt(const int position) const {

  assert(position >= 1 && position <= itemCount);

  Node<ItemType>* curPtr = headPtr;

  for (int skip = 1; skip < position; ++skip) {
    curPtr = curPtr->getNext();
  }

  return curPtr;
}

template <typename ItemType>
int LinkedSortedList<ItemType>::getPosition(const ItemType& anEntry) const {

  int pos = 1;
  Node<ItemType>* curPtr = headPtr;
  bool foundIt = false;

  while (!foundIt && curPtr != nullptr && anEntry >= curPtr->getItem() ) {
    if (curPtr->getItem() == anEntry) {
      foundIt = true;
    }
    else {
      curPtr = curPtr->getNext();
      ++pos;
    }
  }

  if (!foundIt) {
    pos = -pos;
  }

  return pos;
}
