#ifndef _PRIORITY_QUEUE
#define _PRIORITY_QUEUE

#include "PriorityQueueInterface.h"
#include "LinkedSortedList.h"

/** @class PriorityQueue PriorityQueue.h "PriorityQueue.h"
 *
 *  Specification of a sorted list-based ADT priority queue. */
template <typename ItemType>
class PriorityQueue : public PriorityQueueInterface<ItemType> {
 private:
  LinkedSortedList<ItemType>* sListPtr;

 public:
  PriorityQueue();

  PriorityQueue(const PriorityQueue<ItemType>& pq);

  virtual ~PriorityQueue();

  virtual bool isEmpty() const;

  virtual bool add(const ItemType& newEntry);

  virtual bool remove();

  virtual ItemType peek() const;
};

#include "PriorityQueue.cpp"

#endif
