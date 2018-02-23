template <typename ItemType>
BagOfArray<ItemType>::BagOfArray()
  : itemCount(0),
    maxItems(DEFAULT_CAPACITY)
{
  for(int i=0; i<DEFAULT_CAPACITY; i++)
    {
      inUse[i]=false;
    }
}

template <typename ItemType>
int BagOfArray<ItemType>::getCurrentSize() const {

  return itemCount;
}

template <typename ItemType>
bool BagOfArray<ItemType>::isEmpty() const {

  return itemCount == 0;
}

template <typename ItemType>
int BagOfArray<ItemType>::add(const ItemType& newEntry) {

  for(int i=0; i<DEFAULT_CAPACITY; i++)
    {
      if (inUse[i] = false)
	itemCount = i;
	break;
    }
  bool hasRoomToAdd = itemCount < maxItems;

  if (hasRoomToAdd) {
    items[itemCount] = newEntry;
    inUse[itemCount] = true;
  }

  return itemCount;
}

template <typename ItemType>
ItemType BagOfArray<ItemType>::removeWithReceipt(const int receipt) {

   bool canRemoveItem = receipt > -1;
   int copy;
   if (canRemoveItem && (inUse[receipt] = true) ) {
     copy = receipt;
     items[receipt] = ' ';
     inUse[receipt] = false;
  }

  return items[copy];
}

template <typename ItemType>
void BagOfArray<ItemType>::clear() {

  itemCount = 0;
}

template <typename ItemType>
bool BagOfArray<ItemType>::contains(const ItemType& anEntry) const {

  bool found = false;
  int curIndex = 0;

  while (!found && curIndex < itemCount) {
    if (anEntry == items[curIndex]) {
      found = true;
    }
    ++curIndex;
  }
 
  return found; 
}

template <typename ItemType>
int BagOfArray<ItemType>::getFrequencyOf(const ItemType& anEntry) const {

  int frequency = 0;
  int curIndex = 0;

  while (curIndex < itemCount) {
    if (items[curIndex] == anEntry) {
      ++frequency;
    }
    ++curIndex;
  }

  return frequency;
}

template <typename ItemType>
vector<ItemType> BagOfArray<ItemType>::toVector() const {

  vector<ItemType> bagContents;

  for (int i = 0; i < itemCount; ++i) 
  {
    if( inUse[i] = false ) continue;
    bagContents.push_back(items[i]);
  }

  return bagContents;
}

template <typename ItemType>
int BagOfArray<ItemType>::getIndexOf(const ItemType& target) const {

  bool found = false;
  int result = -1;
  int searchIndex = 0;

  while (!found && searchIndex < itemCount) {
    if (items[searchIndex] == target) {
      found = true;
      result = searchIndex;
    }
    else {
      ++searchIndex;
    }
  }

  return result;
}
