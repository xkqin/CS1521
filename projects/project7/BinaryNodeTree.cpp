#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;

#include "PrecondViolatedExcep.h"
#include "NotFoundException.h"

//////////////////////////////////////////////////////////////
//      Protected Utility Methods Section
//////////////////////////////////////////////////////////////

template <typename ItemType>
void BinaryNodeTree<ItemType>::printTree()
{
  print(rootPtr,1);
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::print(BinaryNode<ItemType>* node, int depth)
{
  if(node != nullptr)
    {
      print(node -> rightChildPtr,depth+1);
      cout << setw(depth*25+5) << node -> item << endl;
      print(node -> leftChildPtr,depth+1);
    }
}
template <typename ItemType>
void BinaryNodeTree<ItemType>::flippingTheNodesHelper(BinaryNode<ItemType>* subTreePtr)
{
  BinaryNode<ItemType>* temp ;
  temp = subTreePtr -> rightChildPtr;
  subTreePtr -> rightChildPtr = subTreePtr -> leftChildPtr;
  subTreePtr -> leftChildPtr = temp;
  if(subTreePtr -> rightChildPtr != nullptr)
    {
      flippingTheNodesHelper(subTreePtr -> rightChildPtr);
    }
  if(subTreePtr -> leftChildPtr != nullptr)
    {
      flippingTheNodesHelper(subTreePtr -> leftChildPtr);
    }
}

template <typename ItemType>
bool BinaryNodeTree<ItemType>::isBSTHelper(BinaryNode<ItemType>* subTreePtr,
					   ItemType min,
					   ItemType max)
{
  bool isBST = true;
    if(subTreePtr == nullptr)
   {
     isBST =  true;
   }
    else if(getItem(subTreePtr) > min && getItem(subTreePtr) < max)
    {
      if( isBSTHelper(subTreePtr -> leftChildPtr,min,getItem(subTreePtr))&&
	  isBSTHelper(subTreePtr -> rightChildPtr,getItem(subTreePtr),max))
	{
	  isBST = true;
	}
      else isBST = false;
    }
    else isBST = false;
  return isBST;
}

template <typename ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::findMaxHelper(BinaryNode<ItemType>* subTreePtr)
{
  BinaryNode<ItemType>* curMax = subTreePtr;
  if(subTreePtr -> leftChildPtr != nullptr)
    {
      BinaryNode<ItemType>* curValue = findMaxHelper(subTreePtr -> leftChildPtr);
      if(getItem(curValue) > getItem(curMax))
	{
	  curMax = curValue;
	}
    }
  if(subTreePtr -> rightChildPtr != nullptr)
    {
      BinaryNode<ItemType>* curValue = findMaxHelper(subTreePtr -> rightChildPtr);
      if(getItem(curValue) > getItem(curMax))
	{
	  curMax = curValue;
	}
    }
  return curMax;
}

template <typename ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::findMinHelper(BinaryNode<ItemType>* subTreePtr)
{
  BinaryNode<ItemType>* curMin = subTreePtr;
  if(subTreePtr -> leftChildPtr != nullptr)
    {
      BinaryNode<ItemType>* curValue = findMinHelper(subTreePtr -> leftChildPtr);
      if(getItem(curValue) < getItem(curMin))
	{
	  curMin = curValue;
	}
    }
  if(subTreePtr -> rightChildPtr != nullptr)
    {
      BinaryNode<ItemType>* curValue = findMinHelper(subTreePtr -> rightChildPtr);
      if(getItem(curValue) < getItem(curMin))
	{
	  curMin = curValue;
	}
    }
  return curMin;
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::printRootToLeafPathsHelper(BinaryNode<ItemType>* subTreePtr,
							  ItemType pathArray[],
							  int curNumber)
{
  if(subTreePtr != nullptr)
    {
      pathArray[curNumber] = getItem(subTreePtr);
      if(subTreePtr -> leftChildPtr != nullptr)
	{
	  printRootToLeafPathsHelper(subTreePtr -> leftChildPtr, pathArray, curNumber+1);
	}
      if(subTreePtr -> rightChildPtr != nullptr)
	{
	  printRootToLeafPathsHelper(subTreePtr -> rightChildPtr, pathArray, curNumber+1);
	}
    }
  if(subTreePtr -> rightChildPtr == nullptr && subTreePtr -> leftChildPtr == nullptr)
    {
      for(int i=0; i <= curNumber; i++)
	{
	  cout << pathArray[i] << ' ';
	}
	  cout << endl;
    }
}

template <typename ItemType>
bool BinaryNodeTree<ItemType>::doesSomePathHaveSumHelper(BinaryNode<ItemType>* subTreePtr,
							 ItemType pathArray[],							  
							 int curNumber,
							 int sum)
{
  if(subTreePtr != nullptr)
    {
      pathArray[curNumber] = getItem(subTreePtr);
      if(subTreePtr -> rightChildPtr == nullptr && subTreePtr -> leftChildPtr == nullptr)
	{
	  int result = 0 ;
	  for(int i=0; i <= curNumber; ++i)
	    {
	      result =  pathArray[i] + result;
	    }
	  
	  if(result == sum)
	    {
	       return true;
	    }
	  else 
	    {
	      return false;
	    }
	}
    }
  else return false;
 if(doesSomePathHaveSumHelper( subTreePtr -> leftChildPtr,pathArray, curNumber+1, sum) ||   
     doesSomePathHaveSumHelper( subTreePtr -> rightChildPtr,pathArray, curNumber+1, sum))
    {
       return true;
    }
  else return false;
}

template <typename ItemType>
bool BinaryNodeTree<ItemType>::doesSomePathHaveSum(int sum)
{
  int* array = new int[getHeight()];
  bool yup = doesSomePathHaveSumHelper(rootPtr, array, 0, sum);
  delete[] array;
  array = nullptr;
  return yup;
}


template <typename ItemType>
void BinaryNodeTree<ItemType>::printRootToLeafPaths()
{
  if (isEmpty() )
    {
      throw PrecondViolatedExcep("Can't print root to leaf as an empty tree");
    }
  ItemType* array = new ItemType[getHeight()];
  printRootToLeafPathsHelper(rootPtr, array, 0);
  delete[] array;
  array = nullptr;
}


template <typename ItemType>
ItemType BinaryNodeTree<ItemType>::findMin()
{
  if (isEmpty() ) 
    {
      throw PrecondViolatedExcep("findMin() called with empty tree.");
    }
  ItemType min = getItem(findMinHelper(rootPtr));
  
  return min;
}


template <typename ItemType>
ItemType BinaryNodeTree<ItemType>::findMax()
{
  if (isEmpty() ) {
    throw PrecondViolatedExcep("findMax() called with empty tree.");
  }

  ItemType max = getItem(findMaxHelper(rootPtr));
  return max;
}


template <typename ItemType>
void BinaryNodeTree<ItemType>::flip()
{
  flippingTheNodesHelper(rootPtr);
}

template <typename ItemType>
bool BinaryNodeTree<ItemType>::isBST()
{
  bool isBST;
  isBST=isBSTHelper(rootPtr,
		    numeric_limits<ItemType>::min(),
		    numeric_limits<ItemType>::max());
  return isBST;
}  
  

template <typename ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(BinaryNode<ItemType>* subTreePtr) const {

  int height = 0;

  if (subTreePtr != nullptr) {
    height = 1 + max(getHeightHelper(subTreePtr->leftChildPtr),
		     getHeightHelper(subTreePtr->rightChildPtr) );
  }

  return height;
}

template <typename ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const {

  int numNodes = 0;

  if (subTreePtr != nullptr) {
      numNodes = 1 +
	getNumberOfNodesHelper(subTreePtr->leftChildPtr) +
	getNumberOfNodesHelper(subTreePtr->rightChildPtr);
  }

  return numNodes;
}

template <typename ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::balancedAdd(BinaryNode<ItemType>* subTreePtr,
                                                            BinaryNode<ItemType>* newNodePtr) {

  BinaryNode<ItemType>* returnPtr = newNodePtr;

  if (subTreePtr != nullptr) {
    BinaryNode<ItemType>* leftPtr = subTreePtr->leftChildPtr;
    BinaryNode<ItemType>* rightPtr = subTreePtr->rightChildPtr;

    if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr) ) {
      rightPtr = balancedAdd(rightPtr, newNodePtr);
      subTreePtr->rightChildPtr = rightPtr;
    }
    else {
      leftPtr = balancedAdd(leftPtr, newNodePtr);
      subTreePtr->leftChildPtr = leftPtr;
    }

    returnPtr = subTreePtr;
  }

  return returnPtr;
}

template <typename ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::moveValuesUpTree(BinaryNode<ItemType>* subTreePtr) {

  BinaryNode<ItemType>* leftPtr = subTreePtr->leftChildPtr;
  BinaryNode<ItemType>* rightPtr = subTreePtr->rightChildPtr;

  int leftHeight = getHeightHelper(leftPtr);
  int rightHeight = getHeightHelper(rightPtr);

  BinaryNode<ItemType>* returnPtr = nullptr;

  if (leftHeight > rightHeight) {
    subTreePtr->item =  leftPtr->item;
    leftPtr = moveValuesUpTree(leftPtr);
    subTreePtr->leftChildPtr = leftPtr;
    returnPtr = subTreePtr;
  }
  else if (rightPtr != nullptr) {
    subTreePtr->item = rightPtr->item;
    rightPtr = moveValuesUpTree(rightPtr);
    subTreePtr->rightChildPtr = rightPtr;
    returnPtr = subTreePtr;
  }
  else {
    // This is a leaf - Remove it from this tree.
    delete subTreePtr;
  }

  return returnPtr;
}

/** Depth-first search of tree for item.
 *
 *  @param subTreePtr The tree to search.
 *
 *  @param target The target item to find.
 *
 *  @param success Communicate to client whether we found the target.
 *
 *  @return A pointer to the node containing the target. */
template <typename ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr,
                                                            const ItemType& target,
                                                            bool& success) {

  // Assume target cannot be found.
  BinaryNode<ItemType>* returnPtr = nullptr;
  success = false;

  if(subTreePtr != nullptr) {
    if (subTreePtr->item == target) {
      subTreePtr = moveValuesUpTree(subTreePtr);
      success = true;
      returnPtr = subTreePtr;
    }
    else {
      BinaryNode<ItemType>* targetNodePtr = removeValue(subTreePtr->leftChildPtr,
							target,
							success);
      subTreePtr->leftChildPtr = targetNodePtr;

      if (!success) {
	targetNodePtr = removeValue(subTreePtr->rightChildPtr,
				    target,
				    success);
	subTreePtr->rightChildPtr = targetNodePtr;
      }

      returnPtr = subTreePtr;
    }
  }

  return returnPtr;
}

template <typename ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::findNode(BinaryNode<ItemType>* subTreePtr,
                                                         const ItemType& target,
                                                         bool& success) const {

  // Assume that target cannot be found:
  BinaryNode<ItemType>* returnPtr = nullptr;
  success = false;

  if (subTreePtr != nullptr) {
    if (subTreePtr->item == target) {
      success = true;
      returnPtr = subTreePtr;
    }
    else {
      BinaryNode<ItemType>* targetNodePtr = findNode(subTreePtr->leftChildPtr,
						     target,
						     success);
      if (!success) {
	targetNodePtr = findNode(subTreePtr->rightChildPtr,
				 target,
				 success);
      }

      returnPtr = targetNodePtr;
    }
  }

  return returnPtr;
}

template <typename ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::copyTree(BinaryNode<ItemType>* subTreePtr) const {

  BinaryNode<ItemType>* newTreePtr = nullptr;

  // Copy tree nodes during a preorder traversal
  if (subTreePtr != nullptr) {
    newTreePtr = new BinaryNode<ItemType>(subTreePtr->item,
					  copyTree(subTreePtr->leftChildPtr),
					  copyTree(subTreePtr->rightChildPtr) );
  }

  return newTreePtr;
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::destroyTree(BinaryNode<ItemType>* subTreePtr) {

  if (subTreePtr != nullptr) {
    destroyTree(subTreePtr->leftChildPtr);
    destroyTree(subTreePtr->rightChildPtr);
    delete subTreePtr;
  }
}

//////////////////////////////////////////////////////////////
//      Protected Tree Traversal Sub-Section
//////////////////////////////////////////////////////////////

template <typename ItemType>
void BinaryNodeTree<ItemType>::preorder(void visit(ItemType&),
                                        BinaryNode<ItemType>* subTreePtr) {

  if (subTreePtr != nullptr) {
    visit(subTreePtr->item);

    preorder(visit, subTreePtr->leftChildPtr);
    preorder(visit, subTreePtr->rightChildPtr);
  }
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::inorder(void visit(ItemType&),
                                       BinaryNode<ItemType>* subTreePtr) {

  if (subTreePtr != nullptr) {
    inorder(visit, subTreePtr->leftChildPtr);

    visit(subTreePtr->item);

    inorder(visit, subTreePtr->rightChildPtr);
  }
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::postorder(void visit(ItemType&),
                                         BinaryNode<ItemType>* subTreePtr) {

  if (subTreePtr != nullptr) {
    postorder(visit, subTreePtr->leftChildPtr);
    postorder(visit, subTreePtr->rightChildPtr);

    visit(subTreePtr->item);
  }
}

//////////////////////////////////////////////////////////////
//      Protected Node Access Sub-Section
//////////////////////////////////////////////////////////////

template <typename ItemType>
void BinaryNodeTree<ItemType>::setItem(BinaryNode<ItemType>* nodePtr,
                                       const ItemType& anItem) {

  nodePtr->item = anItem;
}

template <typename ItemType>
ItemType BinaryNodeTree<ItemType>::getItem(const BinaryNode<ItemType>* nodePtr) const {

  return nodePtr->item;
}

template <typename ItemType>
bool BinaryNodeTree<ItemType>::isLeaf(const BinaryNode<ItemType>* nodePtr) const {

   return nodePtr->leftChildPtr == nullptr &&
     nodePtr->rightChildPtr == nullptr;
}

template <typename ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::getLeftChildPtr(const BinaryNode<ItemType>* nodePtr) const {

  return nodePtr->leftChildPtr;
}

template <typename ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::getRightChildPtr(const BinaryNode<ItemType>* nodePtr) const {

  return nodePtr->rightChildPtr;
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::setLeftChildPtr(BinaryNode<ItemType>* nodePtr,
                                               BinaryNode<ItemType>* leftPtr) {

  nodePtr->leftChildPtr = leftPtr;
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::setRightChildPtr(BinaryNode<ItemType>* nodePtr,
                                                BinaryNode<ItemType>* rightPtr) {

  nodePtr->rightChildPtr = rightPtr;
}

template <typename ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::getRootPtr() const {

  return rootPtr;
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::setRootPtr(BinaryNode<ItemType>* newRootPtr) {

  rootPtr = newRootPtr;
}

template <typename ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::createNewNode(const ItemType& anItem,
                                                              BinaryNode<ItemType>* leftPtr,
                                                              BinaryNode<ItemType>* rightPtr) const {
  return new BinaryNode<ItemType>(anItem,
				  leftPtr,
				  rightPtr);
}

//////////////////////////////////////////////////////////////
//      PUBLIC METHODS BEGIN HERE
//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////
//      Constructor and Destructor Section
//////////////////////////////////////////////////////////////

template <typename ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree()
  : rootPtr(nullptr) {
}

template <typename ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem)
  : rootPtr(new BinaryNode<ItemType>(rootItem) ) {
}

template <typename ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem,
                                         const BinaryNodeTree<ItemType>* leftTreePtr,
                                         const BinaryNodeTree<ItemType>* rightTreePtr)
  : rootPtr(new BinaryNode<ItemType>(rootItem,
				     copyTree(leftTreePtr->rootPtr),
				     copyTree(rightTreePtr->rootPtr)) ) {
}

template <typename ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const BinaryNodeTree<ItemType>& treePtr) {

  try {
    rootPtr = copyTree(treePtr.rootPtr);
  }
  catch (const bad_alloc&) {
    clear();
    throw;
  }
}

template <typename ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree() {

  clear();
}

//////////////////////////////////////////////////////////////
//      Public BinaryTreeInterface Methods Section
//////////////////////////////////////////////////////////////

template <typename ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const {

  return rootPtr == nullptr;
}

template <typename ItemType>
int BinaryNodeTree<ItemType>::getHeight() const {

  return getHeightHelper(rootPtr);
}

template <typename ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodes() const {

  return getNumberOfNodesHelper(rootPtr);
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::clear() {

  destroyTree(rootPtr);
  rootPtr = nullptr;
}

template <typename ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const {

  if (isEmpty() ) {
    throw PrecondViolatedExcep("getRootData() called with empty tree.");
  }

  return rootPtr->item;
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::setRootData(const ItemType& newItem) {

  if (isEmpty() ) {
    try {
      rootPtr = new BinaryNode<ItemType>(newItem);
    }
    catch (const bad_alloc&) {
      // What should we do with this? Return something? Crash?
    }
  }
  else {
    rootPtr->item = newItem;
  }
}

template <typename ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType& newData) {

  bool canAdd = true;

  try {
    BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newData);

    rootPtr = balancedAdd(rootPtr, newNodePtr);
  }
  catch (const bad_alloc&) {
    canAdd = false;
  }

  return canAdd;
}

template <typename ItemType>
bool BinaryNodeTree<ItemType>::remove(const ItemType& target) {

  bool isSuccessful = false;

  rootPtr = removeValue(rootPtr, target, isSuccessful);

  return isSuccessful;
}

template <typename ItemType>
ItemType BinaryNodeTree<ItemType>::getEntry(const ItemType& anEntry) const {

  bool isSuccessful = false;

  BinaryNode<ItemType>* binaryNodePtr = findNode(rootPtr, anEntry, isSuccessful);

  if (!isSuccessful) {
    throw NotFoundException("Entry not found in tree!");
  }

  return binaryNodePtr->item;
}

template <typename ItemType>
bool BinaryNodeTree<ItemType>:: contains(const ItemType& anEntry) const {

  bool isSuccessful = false;

  findNode(rootPtr, anEntry, isSuccessful);

  return isSuccessful;
}

//////////////////////////////////////////////////////////////
//      Public Traversals Section
//////////////////////////////////////////////////////////////

template <typename ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType&) ) {

  preorder(visit, rootPtr);
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType&) ) {

  inorder(visit, rootPtr);
}

template <typename ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse(void visit(ItemType&) ) {

  postorder(visit, rootPtr);
}

//////////////////////////////////////////////////////////////
//      Overloaded Operator
//////////////////////////////////////////////////////////////

template <typename ItemType>
BinaryNodeTree<ItemType>& BinaryNodeTree<ItemType>::operator=(const BinaryNodeTree<ItemType>& rhs) {

  if (!isEmpty() ) {
    clear();
  }

  this->rootPtr = copyTree(rhs->rootPtr);

  return *this;
}
