#include <iostream>

using namespace std;

struct Node {
	int data = 0;
	Node * next = nullptr;
	Node(int d) : data{ d }, next{ nullptr }{}
};

int getListLength(Node * head) {
	int res = 0;
	while (head != nullptr) {
		res++;
		head = head->next;
	}
	return res;
}

Node * getIntersectionNode(Node * fir_list, Node * sec_list) {
	int fl = getListLength(fir_list);
	int sl = getListLength(sec_list);
	int len_def = (fl - sl); //len_def = A difference of length
	
	if (len_def < 0) {
		Node * temp = fir_list;
		fir_list = sec_list;
		sec_list = temp;
		len_def *= -1;
	}

	//fir_list is always longer than sec_list.
	while (len_def > 0) {
		len_def--;
		fir_list = fir_list->next;
	}

	//find intersetction node 
	while (fir_list != nullptr && sec_list != nullptr) {
		if (fir_list == sec_list) {
			return fir_list;
		}
		fir_list = fir_list->next;
		sec_list = sec_list->next;
	}

	return nullptr;
}


int main() {
	Node * fir_list = new Node(1); //fir_list = first list
	fir_list->next = new Node(3);
	fir_list->next->next = new Node(5);
	fir_list->next->next->next = new Node(6);
	Node * sec_list = new Node(2); //sec_list = second list
	sec_list->next = fir_list->next->next->next;

	Node * int_Node = getIntersectionNode(fir_list, sec_list); //int_Node = intersection Node
	if (int_Node != nullptr) {
		cout << "Intersection Node : " << int_Node->data << "\n";
	}
	else cout << "There isn't Intersection Node\n";

	return 0;
}