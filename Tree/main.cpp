#include <iostream>
#include "Tree.h"
using namespace std ;


int main() {
  IntBinaryTree tree ;
  tree.insertNode(5);
  tree.insertNode(8);
  tree.insertNode(3);
  tree.insertNode(12);
  tree.insertNode(9);

  tree.displayInOrder() ;
  cout << endl;
  tree.displayPreOrder();
  cout << endl;
  tree.displayPostOrder();
  cout << endl;

  (tree.searchNode(12)) ? cout << "value found" : cout << "value not found" ;

}
