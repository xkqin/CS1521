#ifndef _LINKED_SET
#define _LINKED_SET

#include "SetInterface.h"
#include "Node.h"

/** @class LinkedSet LinkedSet.h "LinkedSet.h"
 *
 *  Specification of a pointer-based ADT bag. */
template <typename ItemType>
class LinkedSet : public SetInterface<ItemType> {
 private:

  /** Pointer to first node. */
  Node<ItemType>* headPtr;

  /** Number of items in this bag. */
  int itemCount;

  /** Gets a pointer to the node containing the target in this bag.
   *
   * @pre None.
   *
   * @post None.
   *
   * @param target The ItemType value to find.
   *
   * @return A pointer to the node that contains the given target or
   *         nullptr if the bag does not contain the target. */
  Node<ItemType>* getPointerTo(const ItemType& target) const;
 public:

  /** Default constructor. */
  LinkedSet();

  /** Copy constructor. */
  LinkedSet(const LinkedSet<ItemType>& aBag);

  virtual ~LinkedSet();

  virtual int getCurrentSize() const;

  virtual bool isEmpty() const;

  virtual bool add(const ItemType& newEntry);

  virtual bool remove(const ItemType& anEntry);

  virtual void clear();

  virtual int getFrequencyOf(const ItemType& anEntry) const;

  virtual bool contains(const ItemType& anEntry) const;

  virtual vector<ItemType> toVector() const;
  /** find difference between the two LinkedSet ADT
   *
   *  @pre the class it pass maust be the same ADT which is LinkedSet
   *
   *  @post if successful, the difference between the 2 ADT will store in
   *        another same ADT which is the LinkedSet
   *
   *  @param a type of LinkedSet
   *
   *  @return The LinkedSet template which contain the difference items*/
  LinkedSet<ItemType> difference(const LinkedSet& bag);

};

#include "LinkedSet.cpp"

#endif
