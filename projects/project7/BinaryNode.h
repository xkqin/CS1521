#ifndef _BINARY_NODE
#define _BINARY_NODE

/** @class BinaryNode BinaryNode.h "BinaryNode.h"
 *
 *  Specification of a node for a link-based ADT binary tree. */
template <typename ItemType>
class BinaryNode {
 private:
  ItemType item;

  BinaryNode<ItemType>* leftChildPtr;
  BinaryNode<ItemType>* rightChildPtr;


  BinaryNode();
  BinaryNode(const ItemType& anItem,
	     BinaryNode<ItemType>* leftPtr = nullptr,
	     BinaryNode<ItemType>* rightPtr = nullptr);

   template <typename FriendItemType>
     friend class BinaryNodeTree;
};

#include "BinaryNode.cpp"

#endif
