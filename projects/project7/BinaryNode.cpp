
template<typename ItemType>
BinaryNode<ItemType>::BinaryNode()
{

}


template<typename ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem,
		       BinaryNode<ItemType>* leftPtr,
		       BinaryNode<ItemType>* rightPtr)
{
  item = anItem;
  leftChildPtr = leftPtr;
  rightChildPtr = rightPtr;

}
