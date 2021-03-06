

template <typename ItemType>
BagOfArray<ItemType>::BagOfArray()
  : itemCount(0),
    maxItems(DEFAULT_CAPACITY)
    
{
  items = new ItemType[maxItems];
  inUse = new bool[maxItems];

    for(int i=0; i<DEFAULT_CAPACITY; i++)
    {
      *(inUse+i)=false;
      }
    
}
template <typename ItemType>
BagOfArray<ItemType>::~BagOfArray()
{ 
  delete [] items;
  delete [] inUse;
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
     int receipt = -1;
     int i = 0;
     for( i=0; i < maxItems; ++i)
      {
	if (*(inUse + i) == false)
	  {
	    *(items + i) = newEntry;
	    *(inUse + i) = true;
	    	    receipt = i;
	    ++itemCount;
	    break;
	  }
      }
    if(maxItems == i )
      {
	ItemType* oldArray = items;
	items = new ItemType[2*maxItems];
	bool* old = inUse;
	inUse = new bool[2*maxItems];
	for(int index = 0; index < maxItems; ++index)
	  {
	    *(items+index) = *(oldArray+index);
	    *(inUse+index) = *(old+index);
	  }
	delete [] oldArray;
	delete [] old;
	oldArray = nullptr;
	old = nullptr;
	maxItems *= 2;
      	receipt = add(newEntry);
      }
      return receipt;
      
}

template <typename ItemType>
ItemType BagOfArray<ItemType>::removeWithReceipt(const int receipt) {

  bool canRemoveItem = receipt > -1;
   if (canRemoveItem && (*(inUse + receipt) = true) ) {
     *(inUse+receipt) = false;
     --itemCount;
   }
   //     else  return EXIT_FAILURE;
   return *(items + receipt);
}

template <typename ItemType>
void BagOfArray<ItemType>::clear() {
  //  delete [] items;
  //delete [] inUse;
  //items = nullptr;
  //inUse = nullptr;
  itemCount = 0;
}

template <typename ItemType>
bool BagOfArray<ItemType>::contains(const ItemType& newEntry) const {

  bool found = false;
  int curIndex = 0;

  while ( !found && curIndex < itemCount ) {
    if (*(items + curIndex) == newEntry && inUse[curIndex] ==true )  {
      found = true;
    }
    ++curIndex;
  }
    
  return found;
}

template <typename ItemType>
int BagOfArray<ItemType>::getFrequencyOf(const ItemType& newEntry) const {

  int frequency = 0;
  for (int i=0; i<itemCount; ++i)
    {
      if(inUse[i] == true && items[i] == newEntry)
	++frequency;
    }

  return frequency;
}

template <typename ItemType>
vector<ItemType> BagOfArray<ItemType>::toVector() const {

 vector<ItemType> bagContents;

  for (int i = 0; i < maxItems; ++i) 
  {
    if( inUse[i] == false ) continue;
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

