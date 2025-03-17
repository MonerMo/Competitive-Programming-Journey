//
// Created by orabi on 1/31/2025.
//

#ifndef TREE_H
#define TREE_H

class IntBinaryTree {

private:
	struct TreeNode {
		int value ;			//value stored in the node
		TreeNode *left ;	//pointer pointing to left child
		TreeNode *right ;	//pointer pointing to right child
	};
	TreeNode *root ;		//pointer pointing to the root of the tree

	void insert(TreeNode *&, TreeNode *&);
	void destroySubTree(TreeNode *);
	void deleteNode(int, TreeNode *&);
	void makeDeletion(TreeNode *&);
	void displayInOrder(TreeNode *) const ;
	void displayPreOrder(TreeNode *) const ;
	void displayPostOrder(TreeNode *) const ;

public:
	//for the constructor we will make the root pointer empty
	IntBinaryTree() {
		root = nullptr ;
	}

	//for the destructor we will destroy the tree
	//~IntBinaryTree() {
	//	destroySubTree(root);
	//}

	//Binary Tree Operations
	void insertNode(int) ;
	bool searchNode(int) ;
	void remove(int) ;

	void displayInOrder() const {
		displayInOrder(root) ;
	}

	void displayPreOrder() const {
		displayPreOrder(root) ;
	}

	void displayPostOrder() const {
		displayPostOrder(root) ;
	}

};


#endif //TREE_H
