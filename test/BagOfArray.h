#ifndef _BAG_OF_ARRAY
#define _BAG_OF_ARRAY

#include "ArrayInterface.h"

/** @class ArrayBag ArrayBag.h "ArrayBag.h"
 *
 *  Specification of an array-based ADT bag. */
template <typename ItemType>
class BagOfArray : public ArrayInterface<ItemType> {
 private:
  /** Maximum capacity of this bag. */
  static const int DEFAULT_CAPACITY = 6;

  /** Data storage. */
  ItemType* item = new ItemType[size];

  int size;

  bool* inUse = new bool[size];

  /** Number of items in this bag. */
  int itemCount;

  /** Maximum capacity of this bag. */
  int maxItems;

  /** Gets the index of target in the array 'items' in this bag.
   *
   * @param target The ItemType value to retrieve the index of.
   *
   * @return The index of the element in the array 'items' that
   *         contains 'target' or -1 if the array does not contain
   *         'target'. */
  int getIndexOf(const ItemType& target) const;

 public:
  /** Default constructor. */
  BagOfarray();

  int getCurrentSize() const;

  bool isEmpty() const;

  int  add(const ItemType& newEntry);

  ItemType removeWithReceipt(const int receipt);

  void clear();

  int getFrequencyOf(const ItemType& anEntry) const;

  bool contains(const ItemType& anEntry) const;

  vector<ItemType> toVector() const;
};

#include "BagOfArray.cpp"

#endif
