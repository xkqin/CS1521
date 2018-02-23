template <typename ItemType>
LinkedSet<ItemType>::LinkedSet()
  : headPtr(nullptr),
    itemCount(0) {
}

template <typename ItemType>
LinkedSet<ItemType>::LinkedSet(const LinkedSet<ItemType>& aBag) {

  itemCount = aBag.itemCount;

  if (aBag.headPtr == nullptr) {
    headPtr = nullptr;
  }
  else {
    Node<ItemType>* origChainPtr = aBag.headPtr;

    headPtr = new Node<ItemType>();
    headPtr->setItem(origChainPtr->getItem() );

    Node<ItemType>* newChainPtr = headPtr;

    origChainPtr = origChainPtr->getNext();

    while (origChainPtr != nullptr) {
      ItemType nextItem = origChainPtr->getItem();

      Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

      newChainPtr->setNext(newNodePtr);

      newChainPtr = newChainPtr->getNext();

      origChainPtr = origChainPtr->getNext();
    }

    newChainPtr->setNext(nullptr);
  }
}

template <typename ItemType>
LinkedSet<ItemType>::~LinkedSet() {

  clear();
}

template <typename ItemType>
int LinkedSet<ItemType>::getCurrentSize() const {

  return itemCount;
}

template <typename ItemType>
bool LinkedSet<ItemType>::isEmpty() const {

  return itemCount == 0;
}

template <typename ItemType>
bool LinkedSet<ItemType>::add(const ItemType& newEntry) {

  bool duplicate = true;
  Node<ItemType>* newNodePtr = new Node<ItemType>();
  Node<ItemType>* curPtr = headPtr;
  while(curPtr!=nullptr)
    {
      if(curPtr->getItem() == newEntry)
	{
	  duplicate = false;
	  break;
	}
      curPtr = curPtr -> getNext();
    }
	 
  if(duplicate)
  {
    newNodePtr->setItem(newEntry);

    newNodePtr->setNext(headPtr);
    headPtr = newNodePtr;
    
    ++itemCount;
  }
  return duplicate;
}

template <typename ItemType>
bool LinkedSet<ItemType>::remove(const ItemType& anEntry) {

  bool canRemoveItem = !isEmpty();

  if (canRemoveItem) {
    Node<ItemType>* entryNodePtr = getPointerTo(anEntry);

    canRemoveItem = entryNodePtr != nullptr;

    if (canRemoveItem) {
      entryNodePtr->setItem(headPtr->getItem() );

      Node<ItemType>* nodeToDeletePtr = headPtr;
      headPtr = headPtr->getNext();

      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      nodeToDeletePtr = nullptr;

      --itemCount;
    }
  }

  return canRemoveItem;
}

template <typename ItemType>
void LinkedSet<ItemType>::clear() {

  Node<ItemType>* nodeToDeletePtr = headPtr;

  while (headPtr != nullptr) {
    headPtr = headPtr->getNext();

    nodeToDeletePtr->setNext(nullptr);
    delete nodeToDeletePtr;

    nodeToDeletePtr = headPtr;
  }

  itemCount = 0;
}

template <typename ItemType>
bool LinkedSet<ItemType>::contains(const ItemType& anEntry) const {

  return getPointerTo(anEntry) != nullptr;
}

template <typename ItemType>
int LinkedSet<ItemType>::getFrequencyOf(const ItemType& anEntry) const {

  int frequency = 0;

  Node<ItemType>* curPtr = headPtr;

  while (curPtr != nullptr) {
    if (curPtr->getItem() == anEntry) {
      ++frequency;
    }

    curPtr = curPtr->getNext();
  }

  return frequency;
}

template <typename ItemType>
vector<ItemType> LinkedSet<ItemType>::toVector() const {

  vector<ItemType> bagContents;

  Node<ItemType>* curPtr = headPtr;

  while (curPtr != nullptr) {
    bagContents.push_back(curPtr->getItem() );

    curPtr = curPtr->getNext();
  }

  return bagContents;
}

template <typename ItemType>
Node<ItemType>* LinkedSet<ItemType>::getPointerTo(const ItemType& target) const {

  bool found = false;

  Node<ItemType>* curPtr = headPtr;

  while (!found && curPtr != nullptr) {
    if (curPtr->getItem() == target) {
      found = true;
    }
    else {
      curPtr = curPtr->getNext();
    }
  }

  return curPtr;
}
template <typename ItemType>
LinkedSet<ItemType> LinkedSet<ItemType>::difference(const LinkedSet<ItemType>& bag)
{
  LinkedSet<ItemType> final;
    Node<ItemType>* curPtr = headPtr;
       Node<ItemType>* curPtr2 = bag.headPtr;
  int count = 0;
   
 for(curPtr = headPtr; curPtr != nullptr; curPtr = curPtr -> getNext())
    {
      for (curPtr2 = bag.headPtr;  curPtr2 != nullptr ;curPtr2 = curPtr2 -> getNext()  )
        {
          if(curPtr -> getItem() == curPtr2 -> getItem()) continue;
          else ++count;
        }
      if(bag.itemCount == count)
        {
          final.add(curPtr -> getItem());
        }
      count = 0;
      
      }

  
 
  /*  while( curPtr != nullptr)
    {
      curPtr2 = bag.headPtr;
    
      while (curPtr2 != nullptr  )
        {
          if(curPtr -> getItem() == curPtr2 -> getItem()) continue;
          else ++count;
	  curPtr2 = curPtr2 -> getNext();
        }
      if(bag.itemCount == count)
        {
          final.add(curPtr -> getItem());
        }
      count = 0;
      curPtr = curPtr -> getNext();
      
      }*/

 /*   
  while(curPtr != nullptr)
    {
      if( ! bag.contains(curPtr -> getItem()))
	{
	  final.add(curPtr -> getItem());
	}
	curPtr = curPtr -> getNext();
	}  */
  return final;
}
