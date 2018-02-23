#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

#include "BinaryNodeTree.h"

template <typename ItemType>
void display(ItemType& anItem) {
  
  cout << "Displaying item - "
       << anItem
       << endl;
}
int main() {
  
  BinaryNodeTree<int>* tree1 = new BinaryNodeTree<int>();
  tree1 -> add(50);
  tree1 -> add(80);
  tree1 -> add(40);
  tree1 -> add(30);
  tree1 -> add(10);
  tree1 -> add(70);
  tree1 -> add(60);
  tree1 -> add(20);

  //  tree1 -> preorderTraverse(display);
  //  cout << tree1 -> findMax() << endl;
  tree1 -> printTree();

  
  if(tree1 -> isBST())
    {
      cout << "It is BST " << endl;
    }
  else 
    {
      cout << "It is not a BST " << endl;
    }
  cout <<  "MAX is" <<tree1 -> findMax() << endl;
  cout <<  "Min is" <<tree1 -> findMin() << endl;
  cout << "Print root to leaf " << endl;
  tree1 -> printRootToLeafPaths();
  
  if(tree1 -> doesSomePathHaveSum(100))
    {
      cout << "It has the path sums to 100 " << endl;
    }
  else 
    {
      cout << "It does not has the path sums to 100" << endl;
      }
    if(tree1 -> doesSomePathHaveSum(120))
    {
     cout << "It has the path sums to 120 " << endl;
   }
   else 
   {
     cout << "It does not has the path sums to 120" << endl;
   }


  tree1 -> flip();
  cout << endl
       <<endl
       <<endl;
  cout << "After flip" << endl;
  tree1 -> printTree();


 cout << endl
       <<endl
       <<endl;
  cout << "Add another tree " << endl;
  BinaryNodeTree<int>* tree2 = new BinaryNodeTree<int>();
  tree2 -> add(50);
  tree2 -> add(30);
  tree2 -> add(70);
  tree2 -> add(20);
  tree2 -> add(60);
  tree2 -> add(40);
  tree2 -> add(10);
  tree2 -> add(80);

  tree2 -> printTree();

  if( tree2 -> isBST() )
    {
      cout << "It is BST " << endl;
    }
  else 
    {
      cout << "It is not a BST " << endl;
    }

  cout <<  "MAX is" <<tree2 -> findMax() << endl;
  cout <<  "Min is" <<tree2 -> findMin() << endl;


    if(tree1 -> doesSomePathHaveSum(120))
    {
     cout << "It has the path sums to 120 " << endl;
   }
   else 
   {
     cout << "It does not has the path sums to 120" << endl;
   }


 cout << endl
       <<endl
       <<endl;
  cout << "Add another  string tree " << endl;
  BinaryNodeTree<string>* tree3 = new BinaryNodeTree<string>();

  tree3 -> add("Anna");
  tree3 -> add("Bob");
  tree3 -> add("Ken");
  tree3 -> add("Petter");
  tree3 -> add("Kate");
  tree3 -> add("James");
  tree3 -> add("Cater");
  tree3 -> add("Master");

  tree3 -> printTree();
  cout << "Print root to leaf " << endl;
  tree3 -> printRootToLeafPaths();

  tree3 -> flip();
  cout << endl
       <<endl
       <<endl;
  cout << "After flip" << endl;
  tree3 -> printTree();


 cout << endl
       <<endl
       <<endl;
  cout << "Test empty tree " << endl;
  BinaryNodeTree<string>* tree4 = new BinaryNodeTree<string>();

  try{
    tree4 -> findMax();
  }
  catch (const PrecondViolatedExcep& e) 
    {   
      cerr << e.what()
	   << endl;
    }
  try{
       tree4 -> findMin();
  }    
  catch (const PrecondViolatedExcep& e) 
    {   
      cerr << e.what()
	   << endl;
    }

  try{
    tree4 -> printRootToLeafPaths();
  }
  catch (const PrecondViolatedExcep& e) 
    {   
      cerr << e.what()
	   << endl;
    }
  if( tree4 -> isBST() )
    {
      cout << "It is BST " << endl;
    }
  else 
    {
      cout << "It is not a BST " << endl;
    }


}




