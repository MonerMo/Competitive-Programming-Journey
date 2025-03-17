//
// Created by orabi on 1/2/2025.
//
#include "NumberList.h"


/*
 *Steps when appending :
 *1)Go through all the list starting from the head pointer till we find the last node.
 *2)Change the next of the last node to be pointing to the new appended node.
 *3)make the last node next pointer point to null pointer.
 */
void NumberList::appendNode(double node_value) {


	//Now we should create a new node to hold the value.
	Node *New_Node = new Node ;
	New_Node->value = node_value ;
	New_Node->next = nullptr ;

	//Check if the Last_Node pointing to the head means that the list is empty so we need to handle
	// head--->New_Node ; , If the list is not empty so we just need to append it to the last element.
	if(head == nullptr) {
		head = New_Node ;
	}else {
		Node *Last_Node = head ;
		while(Last_Node->next)
			Last_Node = Last_Node->next ;
		Last_Node->next = New_Node ;
	}
}

/*
 *Functionality : This function displays the content of the list by traversing through the list.
 *
 */
void NumberList::displayList() const {
	Node *ptr = head ;
	while(ptr) {
		cout << ptr->value << " " ;
		ptr = ptr->next ;
	}
}


//Functionality
/*
 * We Already suppose that the list is sorted, and we should insert the current input value
 * before the first greater than or equal to the input value.
 */
void NumberList::insertNode(double node_value) {

	//create a new node to hold the input value.
	Node *newNode = new Node ;
	newNode->value = node_value ;
	newNode->next = nullptr ;

	if(head == nullptr) {
		//this means that the list is empty
		head = newNode ;
	}else {
		//traverse
		Node *inspectedNode = head ;
		Node *prevNode = head ;
		while(inspectedNode) {
			//can we jump
			if(inspectedNode->value < node_value) {
				prevNode = inspectedNode ;
				inspectedNode = inspectedNode->next ;
			}else {
				break;
			}
		}
		if(inspectedNode == prevNode) {
			head = newNode ;
			newNode->next = prevNode ;
		}else {
			prevNode->next = newNode ;
			newNode->next = inspectedNode ;
		}
	}
}

void NumberList::deleteNode(double node_value) {
	//first we need to check if the list is empty
	if(!head) {
		return ;
	}else {
		//check for the case that the element we want to delete is the first element in the list
		Node *inspectedNode = head ;
		if(inspectedNode->value == node_value) {
			head = inspectedNode->next ;
			delete inspectedNode ;
			return ;
		}

		//now we need to traverse for the input value if found then we need to remove it from the list
		Node *prevNode = nullptr ;

		while(inspectedNode && inspectedNode->value != node_value) {
			prevNode = inspectedNode ;
			inspectedNode = inspectedNode->next ;
		}

		if(inspectedNode) {
			prevNode->next = inspectedNode->next ;
			delete inspectedNode ;
		}
	}
}

//Destructor
 NumberList::~NumberList() {
	Node *ptr = head ;
	Node *holder = head ;
	while(ptr) {
		holder = ptr ;
		ptr = ptr->next ;
		delete holder ;
	}
}



