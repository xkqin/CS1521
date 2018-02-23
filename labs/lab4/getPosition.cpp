template <typename ItemType>
int getPosition(ArrayList<ItemType>& aList, ItemType  value)
{
  int position = aList.getLength() + 1;
  for(int i=1; i <= aList.getLength(); ++i)
    {
      if(value == aList.getEntry(i))
	{
	  position = i;
	}
	
    }

  return position;
}
    
