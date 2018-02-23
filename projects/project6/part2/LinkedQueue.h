#ifndef _LINKED_QUEUE
#define _LINKED_QUEUE

#include "QueueInterface.h"
#include "Node.h"

/** @class LinkedQueue LinkedQueue.h "LinkedQueue.h"
 *
 *  Specification of a pointer-based ADT queue. */
template <typename ItemType>
class LinkedQueue : public QueueInterface<ItemType> {
 private:
  Node<ItemType>* backPtr;
  Node<ItemType>* frontPtr;
  int count;
 public:
  LinkedQueue();

  LinkedQueue(const LinkedQueue<ItemType>& aQueue);

  virtual ~LinkedQueue();

  virtual bool isEmpty() const;

  virtual bool enqueue(const ItemType& newEntry);

  virtual bool dequeue();

  virtual ItemType peekFront() const;
  
  void setCount(const int theCount);

  virtual int getLength() const;

};

#include "LinkedQueue.cpp"

#endif
