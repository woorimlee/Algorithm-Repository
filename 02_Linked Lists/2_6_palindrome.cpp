#include <iostream>

using namespace std;

struct Node{
	int data;
	Node * next;
	Node(int d) : data{ d }, next{ nullptr } {};
};

void insertNode(Node *& head, int d) {
	Node * temp = new Node(d);
	temp->next = head;
	head = temp;
	return;
}

bool isPalindromeRecursive(Node *cur, int length, Node *& comp) {
	//base condition
	if (length == 1) { //odd length
		comp = cur->next;
		return true;
	}
	else if (length == 0) { //even length
		comp = cur;
		return true;
	}
	
	bool result = isPalindromeRecursive(cur->next, length - 2, comp);
	if (!result) {
		return false;
	}
	
	if (cur->data == comp->data) {
		comp = comp->next;
	}
	else result = false;

	return result;
}

int main() {
	Node * head = nullptr;

	insertNode(head, 0);
	insertNode(head, 1);
	insertNode(head, 3);
	insertNode(head, 1);
	insertNode(head, 0);

	int length = 5;
	bool palindrome = isPalindromeRecursive(head, length, head);
	if (palindrome) {
		cout << "Palindrome\n";
	}
	else cout << "Not Palindrome\n";

	return 0;
}