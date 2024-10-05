#pragma once

class Node {
private:
	//Attributes
	int position;
	Node* next;

public:
	//Constructor
	Node(int position, Node* next) {
		this->position = position;
		this->next = next;
	}

	//Getters and setters
	int getPosition() {
		return this->position;
	}

	Node* getNext() {
		return this->next;
	}

	void setNext(Node* next){
		this->next = next;
	}
};