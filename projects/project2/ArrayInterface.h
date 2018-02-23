#ifndef _ARRAY_INTERFACE
#define _ARRAY_INTERFACE

#include <vector>

using namespace std;

/** @class ArrayInterface ArrayInterface.h "ArrayInterface.h"
 *
 *  Definition of ArrayInterface class template. */
template <typename ItemType>
class ArrayInterface {
 public:

  /** Virtual destructor. */
  virtual ~ArrayInterface() {}
  /** Gets the current number of entries in this bag.
   *
   *  @return The integer number of entries currently in the bag. */
  virtual int getCurrentSize() const = 0;

  /** Sees whether this bag is empty.
   *
   *  @return True if the bag is empty, or false if not. */
  virtual bool isEmpty() const = 0;

  /** Adds a new entry to this bag.
   *
   *  @post If successful, newEntry is stored in the bag and the
   *        count of items in the bag has increased by 1, and if the
   *        array is full, double the size.
   *
   *  @param newEntry The object to be added as a new entry.
   *
   *  @return the receipt which is the index of the array */
  virtual int add(const ItemType& newEntry) = 0;

  /** Removes one occurrence of a given receipt which is the index from this bag, if
   *  possible.
   *
   *  @post If successful, the object associate with the receipt has been removed from 
   *        the bag and the count of items in the bag has decreased by 1.
   *
   *  @param receipt The value of the index of the array to be removed.
   *
   *  @return the objec that receipt associate with */
  virtual ItemType removeWithReceipt(const int receipt) = 0;

  /** Removes all entries from this bag.
   *
   *  @post This bag contains no items (thus the count is 0). */
  virtual void clear() = 0;


  /** Counts the number of times a given entry appears in bag.
   *
   *  @param anEntry The value of the entry to be counted.
   *
   *  @return The number of times anEntry appears in this bag. */
  virtual int getFrequencyOf(const ItemType& newEntry) const = 0;

  /** Tests whether this bag contains a given entry.
   *
   *  @param anEntry The value of the entry to locate.
   *
   *  @return True if this bag contains anEntry, or false
   *          otherwise. */
  virtual bool contains(const ItemType& newEntry) const = 0;

  /** Converts this bag into a vector.
   *
   *  @return A vector containing all the entries in this bag. */
  virtual vector<ItemType> toVector() const = 0;
};

#endif
