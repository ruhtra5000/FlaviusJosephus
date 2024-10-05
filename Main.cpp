#include <iostream>
#include "CircularLinkedList.h"

using namespace std;

int main() {
	int numNodes;
	CircularLinkedList* list = nullptr;

	cout << "Type the amount of nodes: ";
	cin >> numNodes;

	list = new CircularLinkedList(numNodes);
	
	cout << "\n" << list->returnLastElement() << " is the last element 'alive'";

	return 0;
}