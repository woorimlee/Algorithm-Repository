#include <iostream>
using namespace std;

/*
1. Brute Force : 
if (middle node ?) {
	then middle node = next node
	}

2. BCR : 
Time O(1), Space O(1)

3. BUD : 
bottlenecks : x,
unnecessary work : x,
duplicated work : x
*/

struct Node {
	char data = '\0';
	Node * next = nullptr;
	Node(char c) : data{ c }, next{ nullptr } {};
};

void insertNode(Node *& head, char c) {
	Node * newnode = new Node(c);
	newnode->next = head;
	head = newnode;
	return;
}

void printList(Node *head) {
	while (head != nullptr) {
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << "nullptr\n";
	return;
}

void deleteNode(Node *& curr) {
	Node * temp = curr;
	curr = curr->next;

	delete temp;

	return;
}

int main() {
	Node * head = nullptr;
	for (int i = 0; i < 5; i++) {
		insertNode(head, 'a' + i);
	}
	printList(head);
	deleteNode(head->next->next);
	printList(head);
	return 0;
}