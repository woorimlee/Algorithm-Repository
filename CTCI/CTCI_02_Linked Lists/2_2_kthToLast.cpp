#include <iostream>
using namespace std;

struct Node {
	int data = 0;
	Node * next = nullptr;
	Node(int d) : data{ d }, next{ nullptr } {};
};

int N, K;

void printList(Node * head) {
	while (head != nullptr) {
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << "nullptr\n";
	return;
}

bool findKthRecursive(Node * curr) {
	if (curr == nullptr) {
		K--;
		return true;
	}

	if (findKthRecursive(curr->next)) {
		if (K == 0) {
			cout << "Kth node from the last Node : " << curr->data << "\n";
			return false;
		}
		else {
			K--;
			return true;
		}
	}

	return false;
}

int main(void) {
	Node * head = nullptr;

	cout << "Input the value N, K : ";
	cin >> N >> K;
	if (K > N) {
		cout << "K couldn't be bigger than N\n";
		return -1;
	}

	Node * temp = nullptr;
	for (int i = N; i > 0; i--) {
		temp = new Node(i);
		temp->next = head;
		head = temp;
	}

	printList(head);
	findKthRecursive(head);

	return 0;
}