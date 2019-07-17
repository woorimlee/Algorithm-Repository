#include <iostream>

using namespace std;

struct Node {
	int data = 0;
	Node * next = nullptr;
	Node(int d) : data{ d }, next{ nullptr }{};
};

Node * getLoopFirstNode(Node * head) {
	Node * slow = head;
	Node * fast = head;

	while (fast != nullptr && fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) break;
	}

	if (fast == nullptr && fast->next == nullptr) {
		return nullptr;
	}

	while (fast != head) {
		fast = fast->next;
		head = head->next;
	}

	return fast;
}

int main() {
	Node * head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);
	head->next->next->next->next->next = new Node(6);
	head->next->next->next->next->next->next = new Node(7);
	head->next->next->next->next->next->next->next = new Node(8);
	head->next->next->next->next->next->next->next->next = head->next->next;
	//1 -> 2 -> {3 -> 4 -> 5 -> 6 -> 7 -> 8} -> {3 -> 4 -> ...

	Node * res = getLoopFirstNode(head);

	if (res) {
		cout << "First Loop Node : " << res->data << "\n";
	}
	else cout << "There isn't Loop in this Linked list\n";

	return 0;
}