#pragma once

#include <iostream>
#include "Node.h"

using namespace std;

class CircularLinkedList {
private:
	//Attributes
	Node* head;
	int numNodes;

public:
	//Constructor
	CircularLinkedList(int numNodes) {
		this->head = nullptr;
		this->numNodes = numNodes;
		initializeNodes(numNodes);
	}

	//Methods
	private:
	void initializeNodes(int numNodes) {
		for (int i = 1; i <= numNodes; i++) {
			addNode(i);
		}
	}

	//Add at the end of the list
	void addNode(int position) {
		Node* newNode = new Node(position, head);
		
		//First node
		if (this->head == nullptr) {
			this->head = newNode;
			newNode->setNext(head);
		}
		//Not first node
		else {
			Node* tmp = head;
			while (tmp->getNext() != head) {
				tmp = tmp->getNext();
			}

			tmp->setNext(newNode);
		}
	}

	//Remove a node
	void removeNode(int position) {
		Node* tmp = head;
		//Removing head
		if (tmp->getPosition() == position) {
			while (tmp->getNext() != head) {
				tmp = tmp->getNext();
			}
			tmp->setNext(head->getNext());
			this->head = head->getNext();
		}
		//Removing other node
		else {
			while (tmp->getNext()->getPosition() != position) {
				tmp = tmp->getNext();
			}
			tmp->setNext(tmp->getNext()->getNext());
		}
	}

	int returnListLength() {
		int length = 1; Node* tmp = head;
		while (tmp->getNext() != head) {
			length++;
			tmp = tmp->getNext();
		}
		return length;
	}

	public: 
	void printList() {
		Node* tmp = head->getNext();
		cout << head->getPosition() << " ";
		while (tmp != head) {
			cout << tmp->getPosition() << " ";
			tmp = tmp->getNext();
		}
		cout << "\n";
	}

	//Solves the Flavius Josephus problem
	int returnLastElement() {
		Node* tmp = head, * next;
		while (returnListLength() > 1) {
			next = tmp->getNext();
			tmp = tmp->getNext()->getNext();
			removeNode(next->getPosition());
		}
		return head->getPosition();
	}
};