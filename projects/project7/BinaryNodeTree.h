#ifndef _BINARY_NODE_TREE
#define _BINARY_NODE_TREE

#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include <limits>
/** @class BinaryNodeTree BinaryNodeTree.h "BinaryNodeTree.h"
 *
 *  Specification of a link-based ADT binary tree. */
template <typename ItemType>
class BinaryNodeTree : public BinaryTreeInterface<ItemType> {
 private:
  BinaryNode<ItemType>* rootPtr;

 protected:
  //------------------------------------------------------------
  // Protected Utility Methods Section:
  // Recursive helper methods for the public methods.
  //------------------------------------------------------------
  void flippingTheNodesHelper(BinaryNode<ItemType>* subTreePtr);
 
  void print(BinaryNode<ItemType>* node, int depth);

  bool isBSTHelper(BinaryNode<ItemType>* subTreePtr,ItemType min,ItemType max);
  
  BinaryNode<ItemType>* findMaxHelper(BinaryNode<ItemType>* subTreePtr);

  BinaryNode<ItemType>* findMinHelper(BinaryNode<ItemType>* subTreePtr);

  void  printRootToLeafPathsHelper(BinaryNode<ItemType>* subTreePtr,
				   ItemType pathArray[],
				   int curNumber);

  bool  doesSomePathHaveSumHelper(BinaryNode<ItemType>* subTreePtr,
				  ItemType pathArray[],
				  int curNumber,
				  int sum);
  
  int getHeightHelper(BinaryNode<ItemType>* subTreePtr) const;

  int getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const;

  // Recursively deletes all nodes from the tree.
  void destroyTree(BinaryNode<ItemType>* subTreePtr);

  // Recursively adds a new node to the tree in a left/right fashion to
  // keep the tree balanced.
  BinaryNode<ItemType>* balancedAdd(BinaryNode<ItemType>* subTreePtr,
				    BinaryNode<ItemType>* newNodePtr);

  // Removes the target value from the tree by calling moveValuesUpTree
  // to overwrite value with value from child.
  BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr,
				    const ItemType& target,
				    bool& success);

  // Copies values up the tree to overwrite value in current node until
  // a leaf is reached; the leaf is then removed, since its value is
  // stored in the parent.
  BinaryNode<ItemType>* moveValuesUpTree(BinaryNode<ItemType>* subTreePtr);

  // Recursively searches for target value in the tree by using a
  // preorder traversal.
  BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr,
				 const ItemType& target,
				 bool& success) const;

  // Copies the tree rooted at treePtr and returns a pointer to
  // the copy.
  BinaryNode<ItemType>* copyTree(BinaryNode<ItemType>* treePtr) const;

  // Recursive traversal helper methods:
  void preorder(void visit(ItemType&),
		BinaryNode<ItemType>* treePtr);
  void inorder(void visit(ItemType&),
	       BinaryNode<ItemType>* treePtr);
  void postorder(void visit(ItemType&),
		 BinaryNode<ItemType>* treePtr);

  // Tools for manipulating BinaryNodes:

  void setItem(BinaryNode<ItemType>* nodePtr,
	       const ItemType& anItem);

  ItemType getItem(const BinaryNode<ItemType>* nodePtr) const;

  bool isLeaf(const BinaryNode<ItemType>* nodePtr) const;

  BinaryNode<ItemType>* getLeftChildPtr(const BinaryNode<ItemType>* nodePtr) const;
  BinaryNode<ItemType>* getRightChildPtr(const BinaryNode<ItemType>* nodePtr) const;

  void setLeftChildPtr(BinaryNode<ItemType>* nodePtr,
		       BinaryNode<ItemType>* leftPtr);
  void setRightChildPtr(BinaryNode<ItemType>* nodePtr,
			BinaryNode<ItemType>* rightPtr);

  BinaryNode<ItemType>* getRootPtr() const;
  void setRootPtr(BinaryNode<ItemType>* newRootPtr);

  BinaryNode<ItemType>* createNewNode(const ItemType& anItem,
				      BinaryNode<ItemType>* leftPtr = nullptr,
				      BinaryNode<ItemType>* rightPtr = nullptr) const;

 public:
  //------------------------------------------------------------
  // Constructor and Destructor Section.
  //------------------------------------------------------------
  BinaryNodeTree();
  BinaryNodeTree(const ItemType& rootItem);
  BinaryNodeTree(const ItemType& rootItem,
		 const BinaryNodeTree<ItemType>* leftTreePtr,
		 const BinaryNodeTree<ItemType>* rightTreePtr);
  BinaryNodeTree(const BinaryNodeTree<ItemType>& tree);

  virtual ~BinaryNodeTree();

  //------------------------------------------------------------
  // Public BinaryTreeInterface Methods Section.
  //------------------------------------------------------------
  virtual bool isEmpty() const;

  virtual int getHeight() const;

  virtual int getNumberOfNodes() const;

  virtual ItemType getRootData() const;

  virtual void setRootData(const ItemType& newData);

  virtual bool add(const ItemType& newData);

  virtual bool remove(const ItemType& data);

  virtual void clear();

  virtual ItemType getEntry(const ItemType& anEntry) const;

  virtual bool contains(const ItemType& anEntry) const;

  //------------------------------------------------------------
  // Public Traversals Section.
  //------------------------------------------------------------
  virtual void preorderTraverse(void visit(ItemType&) );
  virtual void inorderTraverse(void visit(ItemType&) );
  virtual void postorderTraverse(void visit(ItemType&) );

  //------------------------------------------------------------
  // Overloaded Operator Section.
  //------------------------------------------------------------
  BinaryNodeTree& operator=(const BinaryNodeTree& rhs);
  void flip();
  bool isBST();
  ItemType findMax();
  ItemType findMin();
  void  printRootToLeafPaths();
  bool doesSomePathHaveSum(int sum);
  void printTree();

};

#include "BinaryNodeTree.cpp"

#endif
