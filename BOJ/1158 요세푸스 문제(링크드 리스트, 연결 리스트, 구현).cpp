#include <iostream>

using namespace std;

int N, K;
struct Node{
	int person;
	Node* next;
	Node(int i) : person{ i }, next{ nullptr } {};
};

void insertList(Node*& node, int i) {
	Node* temp = new Node(i);
	temp->next = node;
	node = temp;
	return;
}

void printList(Node* head) {
	while (head != nullptr) {
		cout << head->person << " -> ";
		head = head->next;
	}
	cout << "nullptr\n";
	return;
}

void solveJosephus(Node*& node) {
	cout << "<";
	for (int i = K; i <= N * K; i += K) {
		for (int j = 0; j < K; j++) {
			//처음에만 K-1번
			node = 
		}
		if (i == N * K) {
			
		}
		else {

		}

	}
	cout << ">";
}

int main() {
	cin >> N >> K;
	Node * head = nullptr;
	for (int i = N; i >= 1; i--) {
		insertList(head, i);
	}
	Node* temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = head;
	//printList(head);
	solveJosephus(head);
	return 0;
}