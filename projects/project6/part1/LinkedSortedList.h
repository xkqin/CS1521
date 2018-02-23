#ifndef _LINKED_SORTED_LIST
#define _LINKED_SORTED_LIST

#include "SortedListInterface.h"
#include "Node.h"

/** @class LinkedSortedList LinkedSortedList.h "LinkedSortedList.h"
 *
 *  Specification of a pointer-based ADT sorted list. */
template <typename ItemType>
class LinkedSortedList : public SortedListInterface<ItemType> {
 private:
  Node<ItemType>* headPtr;

  int itemCount;

  /** Locates the node that is before the node that does or should
   *  contain the given entry.
   *
   * @pre None.
   *
   * @post None.
   *
   * @param anEntry The entry to find.
   *
   * @return Either a pointer to the node before the node that
   *         contains or should contain the given entry, or nullptr
   *         if no prior node exists. */
  Node<ItemType>* getNodeBefore(const ItemType& anEntry) const;

  Node<ItemType>* getNodeAt(const int position) const;

  /** Copy the chain of nodes pointed to by origChainPtr.
   *
   * @pre None.
   *
   * @post None.
   *
   * @param origChainPtr A pointer to the chain of nodes to copy.
   *
   * @return A pointer to a copy of the nodes pointed to by
   *         origChainPtr. */
  Node<ItemType>* copyChain(const Node<ItemType>* origChainPtr);

 public:
  LinkedSortedList();

  LinkedSortedList(const LinkedSortedList<ItemType>& aList);

  virtual ~LinkedSortedList();

  virtual bool isEmpty() const;

  virtual int getLength() const;

  virtual bool insertSorted(const ItemType& newEntry);

  virtual bool removeSorted(const ItemType& anEntry);

  virtual bool remove(const int position);

  virtual void clear();

  virtual ItemType getEntry(const int position) const;

  virtual int getPosition(const ItemType& newEntry) const;
};

#include "LinkedSortedList.cpp"

#endif
