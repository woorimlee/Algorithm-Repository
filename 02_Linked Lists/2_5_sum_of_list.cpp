#include <iostream>
using namespace std;

struct Node {
	int data = 0;
	Node * next = nullptr;
	Node(int d) : data{ d }, next{ nullptr } {};
};

void insert(Node *& head, int data);
void printListRecursion(Node *& head);
void printList(Node *& head);
void deleteList(Node *& head);

Node * addListIterative(Node * A, Node * B) {
	//Assuming that the two Lists are the same length.

	bool flag = false;
	int data = 0;
	Node * temp = nullptr;
	
	while (A != nullptr || B != nullptr) {
		data = A->data + B->data;
		if (flag) {
			data++;
		}
		if (data >= 10) {
			flag = true;
			data = data % 10;
		}
		else
			flag = false;
		
		insert(temp, data);
		
		A = A->next;
		B = B->next;
	}

	//to do : Fill remaining elements in the long Linked List to Node * temp;

	return temp;
}

bool addListRecursive(Node *& A, Node *& B, Node *& Result) {
	//Assuming that the two Lists are the same length.

	//to do : Insert int 0 value to the short Linked List.

	if (A == nullptr) {
		return false;
	}

	bool flag = addListRecursive(A->next, B->next, Result);
	int data = A->data + B->data;
	if (flag) {
		data++;
	}
	if (data >= 10) {
		insert(Result, data % 10);
		return true;
	}
	else insert(Result, data);
	return false;
}


int main(void) {
	Node * head_A = nullptr;
	Node * head_B = nullptr;
	Node * head_Result = nullptr;

	insert(head_A, 6);
	insert(head_A, 1);
	insert(head_A, 7);
	insert(head_B, 2);
	insert(head_B, 9);
	insert(head_B, 5);

	head_Result = addListIterative(head_A, head_B);
	cout << "The answer to the first problem : ";
	printListRecursion(head_Result);
	cout << "nullptr\n";

	deleteList(head_A);
	deleteList(head_B);
	deleteList(head_Result);

	insert(head_A, 7);
	insert(head_A, 1);
	insert(head_A, 6);
	insert(head_B, 5);
	insert(head_B, 9);
	insert(head_B, 2);

	addListRecursive(head_A, head_B, head_Result);
	cout << "\nThe answer to the second problem : ";
	printList(head_Result);

	return 0;
}

void insert(Node *& head, int data) {
	Node * temp = new Node(data);
	temp->next = head;
	head = temp;
	return;
}

void printListRecursion(Node *& head) {
	if (head == nullptr) {
		return;
	}
	printListRecursion(head->next);
	cout << head->data << " -> ";
	return;
}

void deleteList(Node *& head) {
	Node * temp;
	while (head != nullptr) {
		temp = head->next;
		delete(head);
		head = temp;
	}
	return;
}

void printList(Node *& head) {
	while (head != nullptr) {
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << "nullptr\n";
	return;
}