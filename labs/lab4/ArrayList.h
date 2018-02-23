#ifndef _ARRAY_LIST
#define _ARRAY_LIST

#include "ListInterface.h"

/** @class ArrayList ArrayList.h "ArrayList.h"
 *
 *  Specification of an array-based ADT list. */
template <typename ItemType>
class ArrayList : public ListInterface<ItemType> {
 private:
  static const int DEFAULT_CAPACITY = 10;

  ItemType items[DEFAULT_CAPACITY];

  int itemCount;

  int maxItems;

 public:
  ArrayList();

  virtual ~ArrayList() {}

  virtual bool isEmpty() const;

  virtual int getLength() const;

  virtual bool insert(const int newPosition,
		      const ItemType& newEntry);

  virtual bool remove(const int postition);

  virtual void clear();

  virtual ItemType getEntry(const int postition) const;

  virtual void setEntry(const int postition,
			const ItemType& newEntry);
};

#include "ArrayList.cpp"

#endif
