template <typename ItemType>
PriorityQueue<ItemType>::PriorityQueue()
  : sListPtr(new LinkedSortedList<ItemType>() ) {
}

template <typename ItemType>
PriorityQueue<ItemType>::PriorityQueue(const PriorityQueue<ItemType>& pq)
  : sListPtr(new LinkedSortedList<ItemType>(*pq.sListPtr)) {
}

template <typename ItemType>
PriorityQueue<ItemType>::~PriorityQueue() {

  delete sListPtr;
}

template <typename ItemType>
bool PriorityQueue<ItemType>::isEmpty() const {

  return sListPtr->isEmpty();
}

template <typename ItemType>
bool PriorityQueue<ItemType>::add(const ItemType& newEntry) {

  return sListPtr->insertSorted(newEntry);
}

template <typename ItemType>
bool PriorityQueue<ItemType>::remove() {

  return sListPtr->remove(1);
}

template <typename ItemType>
ItemType PriorityQueue<ItemType>::peek() const {

  return sListPtr->getEntry(1);
}
