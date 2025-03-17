//
// Created by orabi on 1/2/2025.
//

#ifndef NUMBERLIST_H
#define NUMBERLIST_H

#include <bits/stdc++.h>
using namespace std ;

//we will start by doing the class
class NumberList {
	//first we start with the private members
private:
	struct Node {
		double value ;
		struct Node *next ;
	};

	Node *head ;

public:
	//Constructor
	/*
	 *Functionality : we need to initialize the head pointer to null pointer when creating a new node
	 *				  this establishes an empty list.
	 *
	 *Implementation Type : also we will implement and inline constructor
	 */
	NumberList() {
		head = nullptr ;
	}

	//Destructor
	/*
	 *Functionality : Delete the list by removing all the elements in the list.
	 */
	~NumberList() ;

	//Member Functions
	void appendNode(double);
	void insertNode(double);
	void deleteNode(double);
	void displayList() const ;
};

#endif //NUMBERLIST_H
