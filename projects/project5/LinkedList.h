#ifndef _LINKED_LIST
#define _LINKED_LIST

#include "ListInterface.h"
#include "Node.h"

/** @class LinkedList LinkedList.h "LinkedList.h"
 *
 *  Specification of a pointer-based ADT list. */
template <typename ItemType>
class LinkedList : public ListInterface<ItemType> {
 private:
  Node<ItemType>* headPtr;

  int itemCount;

  Node<ItemType>* getNodeAt(const int position) const;

 public:
  LinkedList();

  LinkedList(const LinkedList<ItemType>& aList);

  virtual ~LinkedList();

  virtual bool isEmpty() const;

  virtual int getLength() const;

  virtual bool insert(const int newPosition,
		      const ItemType& newEntry);

  virtual bool remove(const int position);

  virtual void clear();

  virtual ItemType getEntry(const int position) const;

  virtual void setEntry(const int position,
			const ItemType& newEntry);
};

#include "LinkedList.cpp"

#endif
