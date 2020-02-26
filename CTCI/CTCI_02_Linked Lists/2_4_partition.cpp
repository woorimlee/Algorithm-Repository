#include <iostream>
#include <random>
using namespace std;

/*
Ex. Linked List : 1 -> 3 -> 5 -> 1 -> 4 -> 9 -> 2 -> nullptr,
	X = 5;
	Node with data less than X is linked to Linked List A.
	1 -> 3 -> 1 -> 4 -> 2
	Node with data greater than X is linked to Linked List B.
	5 -> 9
	Now, the end of the Linked List A points B.
	1 -> 3 -> 1 -> 4 -> 2 -> 5 -> 9 -> nullptr;
	Done.
*/

struct Node {
	int data = 0;
	Node* next = nullptr;
	Node(int d) : data{ d }, next{ nullptr } {};
};

int getRandomInt(int min, int max) {
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution <int> range(min, max);
	return range(mt);
}

void insertNode(Node*& head, int x) {
	Node* cur = new Node(x);
	cur->next = head;
	head = cur;
	return;
}

void printList(Node* head) {
	while (head != nullptr) {
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << "nullptr\n";
	return;
}

void splitList(Node *& head, int x) {
	Node* LessHead = nullptr; //Data of Node is lesser than x.
	Node* LessTail = nullptr;
	Node* GreaterHead = nullptr; //Data of Node is greater than x.
	Node* GreaterTail = nullptr;

	while (head != nullptr) {
		if (head->data < x) {
			if (LessHead == nullptr) {
				LessHead = head;
				LessTail = head;
			}
			else {
				LessTail->next = head;
				LessTail = head;
			}
		}
		else {
			if (GreaterHead == nullptr) {
				GreaterHead = head;
				GreaterTail = head;
			}
			else {
				GreaterTail->next = head;
				GreaterTail = head;
			}
		}
		head = head->next;
	}
	LessTail->next = GreaterHead;
	GreaterTail->next = nullptr;
	head = LessHead;
	return;
}

int main(void) {
	Node* head = nullptr;
	for (int i = 0; i < 10; i++) {
		insertNode(head, getRandomInt(0, 10));
	}

	printList(head);
	int x = 5;
	splitList(head, x);

	printList(head);

	return 0;
}