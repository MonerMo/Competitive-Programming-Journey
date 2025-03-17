//
// Created by orabi on 1/31/2025.
//
#include <bits/stdc++.h>
#include "Tree.h"
using namespace std ;

void IntBinaryTree::makeDeletion(TreeNode *&nodePtr) {
	//temporary pointer to use it in reattaching
	 TreeNode *tempNodePtr = nullptr ;

	//for the search been made in deleteNode function just make a check if you have an empty node
	if(nodePtr == nullptr)
		cout << "Cannot delete empty node" << endl;
	else if(nodePtr->right == nullptr) {
		//if the node we want to delete doesn't have right child then
		//reattach the left child to the parent of the target node
		tempNodePtr = nodePtr ;
		nodePtr = nodePtr->left ;
		delete tempNodePtr ;
	}else if(nodePtr->left == nullptr) {
		tempNodePtr = nodePtr ;
		nodePtr = nodePtr->right ;
		delete tempNodePtr ;
	}else {
		//the target node have left and right child
		tempNodePtr = nodePtr->right ;
		while(tempNodePtr->left)
			tempNodePtr = tempNodePtr->left ;
		tempNodePtr->left = nodePtr->left ;
		tempNodePtr = nodePtr ;
		nodePtr = nodePtr->right ;
		delete tempNodePtr ; 
	}
}


void IntBinaryTree::deleteNode(int input, TreeNode *&nodePtr) {
	//search for the node we want to delete.
	if(input < nodePtr->value)
		deleteNode(input, nodePtr->left);
	else if (input > nodePtr->value)
		deleteNode(input, nodePtr->right);
	else
		makeDeletion(nodePtr);
}


void IntBinaryTree::remove(int input) {
	deleteNode(input, root) ;
}

bool IntBinaryTree::searchNode(int input) {
	//we should start with the root of the tree
	TreeNode *nodePtr = root ;

	while(nodePtr) {
		if(nodePtr->value == input)
			return true ;
		else if(nodePtr->value > input)
			nodePtr = nodePtr->left ;
		else
			nodePtr = nodePtr->right ;
	}
	return false ;
}


void IntBinaryTree::displayInOrder(TreeNode *nodePtr) const{
	//for displaying inorder we should have a base case
	if(nodePtr == nullptr) return ;

	displayInOrder(nodePtr->left) ;
	cout << nodePtr->value << " " ;
	displayInOrder(nodePtr->right);

}

void IntBinaryTree::displayPreOrder(TreeNode *nodePtr) const{
	//for displaying inorder we should have a base case
	if(nodePtr == nullptr) return ;

	cout << nodePtr->value << " " ;
	displayPreOrder(nodePtr->left) ;
	displayPreOrder(nodePtr->right);

}

void IntBinaryTree::displayPostOrder(TreeNode *nodePtr) const{
	//for displaying inorder we should have a base case
	if(nodePtr == nullptr) return ;

	displayPostOrder(nodePtr->left) ;
	displayPostOrder(nodePtr->right);
	cout << nodePtr->value << " " ;
}


void IntBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode) {
	//all nodes must be inserted as leaf nodes
	if(nodePtr == nullptr) {
		nodePtr = newNode ;
	}else if(nodePtr->value > newNode->value) {
		//this means that we should go left
		insert(nodePtr->left, newNode);
	}else {
		//that last possibility we will go right
		//note that if the input value equal to a value already existed will be inserted
		//to the right of the node.
		insert(nodePtr->right, newNode);
	}
}

void IntBinaryTree::insertNode(int input) {

	//Firstly, We should create a new node
	TreeNode *newNode = new TreeNode ;
	//Assigning the input to the value stored inside the node
	newNode->value = input ;
	//Also make the right and left pointer equal to null
	newNode->left = newNode->right = nullptr ;

	//Insert the node
	insert(root,newNode);
}

