Node<ItemType>* LinkedList::copychain (const Node<ItemType>* org)
{
  Node<ItemType>* copy = nullptr;
  if(org != nullptr)
    {
      copy = new Node<ItemType> (org -> getItem());
      copy -> setNext(copychain(org -> getNext()));
    }
  return copy;
}


void sort(int myA[], int size)
{
  int right = size -1;
  int left = 0;
  while(left < right)
    {
      for(left; myA[left] <= 0; ++left);
      for(right; myA[right] > 0; --right);
      if(left >= right)
	{
	  break;
	}
      else 
	{
	  swap (myA[left],myA[right]);
	}
    }
}

