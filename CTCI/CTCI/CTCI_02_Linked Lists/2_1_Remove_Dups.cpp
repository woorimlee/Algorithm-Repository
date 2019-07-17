#include <iostream>
#include <unordered_map>
#include <random>

using namespace std;

/*
Approach 1 : Use Runner Pointer. Time complextiy O(N^2), Space complexity O(1).
Approach 2 : Use Hashmap. Time complexity O(N), Space complexity O(N).
*/

//https://gabble-workers.tistory.com/7
int getRandomInt(int min, int max) {
	//1. Set seed.
	random_device rd;
	mt19937 mt(rd());
	//2. Set distribution.(int)
	uniform_int_distribution <int> range(min, max);
	//3. Return random value.
	return range(mt);
}

struct Node {
	int data = 0;
	Node * next = nullptr;
	Node(int d) : data{ d }, next{ nullptr } {}
};

void insertNode(Node *& head, int data) {
	Node * newnode = new Node(data);
	newnode->next = head;
	head = newnode;
	return;
}

void printList(Node * head) {
	while (head != nullptr) {
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << "nullptr\n";
	return;
}

void removeDups_a1(Node *& head) { //a1 = approach 1.
	if (head == nullptr || head->next == nullptr) {
		cout << "error\n";
		return;
	}

	Node * cur = head;
	Node * runner;
	while(cur){
	//while (cur->next != nullptr) { //this is uncorrect. in case of 2 -> 1 -> 3 -> 2 -> 3 -> nullptr.
		runner = cur;
		while (runner->next != nullptr) {
			if (cur->data == runner->next->data) {
				runner->next = runner->next->next;
			}
			else
				runner = runner->next;
		}
		cur = cur->next;
	}

	return;
}

void removeDups_a2(Node *& head) { //a2 = approach 2.
	if (head == nullptr || head->next == nullptr) {
		cout << "error\n";
		return;
	}

	unordered_map <int, int> hash_table;
	Node * cur = head;
	Node * previous = nullptr;
	while (cur) {
		if (hash_table.count(cur->data) > 0) {
			previous->next = cur->next;
		}
		else {
			hash_table[cur->data] = 1;
			previous = cur;
		}
		cur = cur->next;
	}

	return;
}

int main(void) {

	cout << "Approach 1. Use Runner Pointer.\n";
	Node * head = nullptr;
	for (int i = 0; i < 10; i++) {
		insertNode(head, getRandomInt(0, 5));
	}
	printList(head);
	removeDups_a1(head);
	printList(head);

	cout << "Approach 2. Use Hash Map.\n";
	Node * head2 = nullptr;
	for (int i = 0; i < 10; i++) {
		insertNode(head2, getRandomInt(0, 5));
	}
	printList(head2);
	removeDups_a2(head2);
	printList(head2);


	return 0;
}
